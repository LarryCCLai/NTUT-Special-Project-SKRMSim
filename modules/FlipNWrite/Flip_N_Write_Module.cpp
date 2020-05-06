#include"Flip_N_Write_Module.h"
#define R true
#define L false

Flip_N_Write_Module::Flip_N_Write_Module() {
	this->injection = 0;
	this->remove = 0;
	this->shift = 0;
	this->detect = 0;

	this->initialized = false;
	this->track = nullptr;
	this->params = nullptr;
	this->datas = nullptr;
	this->flipBits = nullptr;
}

Flip_N_Write_Module::~Flip_N_Write_Module() {
	delete[]track;
	delete params;
	delete[]datas;
	delete[]flipBits;
}

void Flip_N_Write_Module::Initialize(Parameters* params) {
	if (!this->initialized) {
		this->params = params;
		this->track = new MarcoCell[this->params->N_racetrack];
		for (int i = 0; i < params->N_racetrack; i++) {
			this->track[i].Initialize(params);
		}
		this->flipBits = new int[params->NDR];
		this->datas = new uint64_t[params->NDR];
		for(int i = 0; i < params->NDR; i++){
			this->datas[i] = 0;
			this->flipBits[i] = 0;
		}
		this->initialized = true;
	}
}

int Flip_N_Write_Module::HammingDistance(uint64_t oldData, int oldFlip, uint64_t newData, int newFlip) {
	uint64_t XOR = newData ^ oldData;
	uint64_t count = 0;
	while (XOR > 0) {
		(XOR % 2 == 0) ? count : count++;
		XOR /= 2;
	}
	(oldFlip == newFlip) ? count : count++;
	return count;
}

uint64_t Flip_N_Write_Module::Read(Request* request) {
	int PN = request->dataIdx;
	int* binaryData = new int[params->dataWidthSegment];
	int flip = this->track[request->trackIdx].Read(PN);
	this->detect++;
	this->track[request->trackIdx].Shift(R);
	this->shift++;

	for (int i = params->dataWidthSegment - 1; i >= 0; i--) {
		binaryData[i] = this->track[request->trackIdx].Read(PN);
		this->detect++;
		this->track[request->trackIdx].Shift(R);
		this->shift++;
	}

	for (int i = 0; i < params->dataSegmentLength; i++) {
		this->track[request->trackIdx].Shift(L);
		this->shift++;
	}
	uint64_t data = this->ToDecimal(binaryData, params->dataWidth);
	if (flip == 1) {
		data = ~data;
	}
	delete[]binaryData;
	return data;
}

void Flip_N_Write_Module::Write(Request* request) {
	int PN = request->dataIdx;
	int* data;
	int* oldData = new int[params->dataWidthSegment];
	int oldFlip = 0, newFlip = 0;
	
	//read old data;
	oldFlip = this->track[request->trackIdx].Read(PN);
	this->detect++;
	this->track[request->trackIdx].Shift(R);
	this->shift++;
	for (int i = params->dataWidthSegment - 1; i >= 0; i--) {
		oldData[i] = this->track[request->trackIdx].Read(PN);
		this->detect++;
		this->track[request->trackIdx].Shift(R);
		this->shift++;
	}
	//calculate hamming distance
	int hamingDistance = HammingDistance(this->ToDecimal(oldData, params->dataWidthSegment), oldFlip, request->data, newFlip);
	//Flip or not
	if (hamingDistance > params->dataWidthSegment / 2) {
		data = this->ToBinary(~request->data, params->dataWidthSegment);
		newFlip = 1;
	}
	else {
		data = this->ToBinary(request->data, params->dataWidthSegment);
		newFlip = 0;
	}
	//write data
	for (int i = 0; i < params->dataWidthSegment; i++) {
		this->track[request->trackIdx].Shift(L);
		this->shift++;
		if (this->track[request->trackIdx].Read(PN) == data[i]) {
			continue;
		}
		else if (data[i] == 1) {
			this->track[request->trackIdx].RandomUpdate(PN, data[i]);
			this->injection++;
		}
		else {
			this->track[request->trackIdx].RandomUpdate(PN, data[i]);
			this->remove++;
		}
	}
	this->track[request->trackIdx].Shift(L);
	this->shift++;
	if (newFlip != oldFlip) {
		if (newFlip == 1) {
			this->track[request->trackIdx].RandomUpdate(PN, newFlip);
			this->injection++;
		}
		else {
			this->track[request->trackIdx].RandomUpdate(PN, newFlip);
			this->remove++;
		}
	}
	delete[]data;
	delete[]oldData;
}

void Flip_N_Write_Module::Sim(std::string fileName){
	std::string line;
	std::string subline;
	std::string operation;
	uint64_t preData = NULL;
	int preFlip = NULL;
	uint64_t curData = NULL;
	int curFlip = 0;
	int curDataIdx = NULL;
	int curTrackIdx = NULL;
	
	std::ifstream configFile(fileName.c_str());
	if (configFile.is_open()) {
		while (!configFile.eof()) {
			getline(configFile, line);
			size_t pos;
			if(line[0]!='W' && line[0]!='R'){
				continue;
			}
			std::string::size_type sz = 0;
			pos = line.find(" ");
			assert(pos != std::string::npos);
			operation = line.substr(0, pos);
			line = line.substr(pos + 1, line.size());

			pos = line.find(" ");
			assert(pos != std::string::npos);
			curTrackIdx = std::stoull(line.substr(0, pos), &sz, 0);
			line = line.substr(sz + 1);

			pos = line.find(" ");
			assert(pos != std::string::npos);
			curDataIdx = std::stoi(line.substr(0, pos), &sz, 0);
			line = line.substr(sz + 1);

			pos = line.find(" ");
			assert(pos == std::string::npos);
			curData = std::stoull(line.substr(0, pos), &sz, 0);

			if(!params->RealWrite){
				this->shift += this->params->dataSegmentLength;
				this->detect += this->params->dataSegmentLength;
				this->shift += this->params->dataSegmentLength;
				preData = this->datas[curDataIdx];
				preFlip = this->flipBits[curDataIdx];
				curFlip = 0;
				int hamingDistance = HammingDistance(preData, preFlip, curData, curFlip);
				if(hamingDistance > params->dataWidthSegment / 2){
					curFlip = 1;
					curData = ~curData;
				}
				else{
					curFlip = 0;
				}
				int* preDataB = ToBinary(preData,this->params->dataSegmentLength);
				int* curDataB = ToBinary(curData,this->params->dataSegmentLength);
				for (int i = 0; i < this->params->dataSegmentLength; i++) {
					if (preDataB[i] == 0 && curDataB[i] == 1){
						this->injection++;
					}
					else if (preDataB[i] == 1 && curDataB[i] == 0) {
						this->remove++;
					}
				}
				this->datas[curDataIdx] = curData;
				this->flipBits[curDataIdx] = curFlip;
				delete[]preDataB;
				delete[]curDataB;
			}
			else {
				Request* request = new Request(operation, curTrackIdx, curDataIdx, curData);
				if (request->operation == "W") {
					this->Write(request);
				}
				else {
					std::cout << this->Read(request);
				}
			}
		}
	}
	else {
		std::cout << "[error] Could not read request file." << std::endl;
		std::cout << fileName << std::endl;
		exit(1);
	}
}