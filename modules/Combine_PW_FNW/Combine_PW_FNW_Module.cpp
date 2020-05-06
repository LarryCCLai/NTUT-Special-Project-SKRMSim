#include"Combine_PW_FNW_Module.h"
#define R true
#define L false
#include<iostream>
Combine_PW_FNW_Module::Combine_PW_FNW_Module() {
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

Combine_PW_FNW_Module::~Combine_PW_FNW_Module() {
	delete[]track;
	delete params;
	delete[]datas;
	delete[]flipBits;
}

void Combine_PW_FNW_Module::Initialize(Parameters* params) {
	if (!this->initialized) {
		this->params = params;
		this->track = new MarcoCell[this->params->N_racetrack];
		for (int i = 0; i < params->N_racetrack; i++) {
			this->track[i].Initialize(params);
		}

		this->datas = new uint64_t[params->NDR];
		this->flipBits = new int[params->NDR];
		for(int i = 0; i < params->NDR; i++){
			this->datas[i] = 0;
			this->flipBits[i] = 0;
		}
		
		this->initialized = true;
	}
}
int* Combine_PW_FNW_Module::FlipNWrite(uint64_t newData, int& newFlip, int skyCount) {
	int count1 = 0;
	uint64_t data = newData;
	for (int i = 0; i < params->dataWidthSegment; i++) {
		if ((newData & 1) == 1) {
			count1++;
		}
		newData = newData >> 1;
	}
	int count0 = params->dataWidthSegment - count1 + 1;
	
	if (std::abs(count0 - skyCount) < std::abs(count1 - skyCount)) {
		newFlip = 1;
		data = ~data;
		std::cout<<"flip"<<std::endl;
	}
	else {
		newFlip = 0;
	}
	return ToBinary(data, params->dataWidthSegment);
}

uint64_t Combine_PW_FNW_Module::Read(Request* request) {
	int PN = request->dataIdx;
	int* binaryData = new int[params->dataWidthSegment];
	int flip = 0;
	//align access port
	this->track[request->trackIdx].Shift(R);
	//this->shift++;
	//read
	flip = this->track[request->trackIdx].Read(PN);
	this->detect++;
	this->track[request->trackIdx].Shift(R);
	this->shift++;

	for (int i = params->dataWidthSegment - 1; i >= 0; i--) {
		binaryData[i] = this->track[request->trackIdx].Read(PN);
		//this->detect++;
		this->track[request->trackIdx].Shift(R);
		//this->shift++;
	}

	for (int i = 0; i < params->dataSegmentLength; i++) {
		this->track[request->trackIdx].Shift(L);
		//this->shift++;
	}
	//leave access port
	this->track[request->trackIdx].Shift(L);
	//this->shift++;
	uint64_t data = this->ToDecimal(binaryData, params->dataWidth);
	if (flip == 1) {
		data = ~data;
	}
	delete[]binaryData;
	return data;
}

void Combine_PW_FNW_Module::Write(Request* request) {
	int PN = request->dataIdx;
	int* data;
	int* oldData = new int[params->dataWidthSegment];
	int oldFlip = 0, newFlip = 0;
	int skyCount = 0;
	//align access port
	this->track[request->trackIdx].Shift(R);
	this->shift++;
	//read old data;
	oldFlip = this->track[request->trackIdx].Read(PN);
	this->detect++;
	if (oldFlip == 0) {
		this->track[request->trackIdx].Delete_SHR(PN);
		this->shift++;
	}
	else {
		this->track[request->trackIdx].Shift(R);
		this->shift++;
		skyCount++;
	}
	for (int i = params->dataWidthSegment - 1; i >= 0; i--) {
		oldData[i] = this->track[request->trackIdx].Read(PN);
		this->detect++;
		if (oldData[i] == 0) {
			this->track[request->trackIdx].Delete_SHR(PN);
			this->shift++;
		}
		else {
			this->track[request->trackIdx].Shift(R);
			this->shift++;
			skyCount++;
		}
	}
		
	data = FlipNWrite(request->data, newFlip, skyCount);
	for (int i = 0; i < params->dataWidthSegment; i++) {
		if (data[i] == 0) {
			this->track[request->trackIdx].Insert_SHL(PN, 0);
			this->shift++;
		}
		else {
			if (skyCount > 0) {
				this->track[request->trackIdx].Shift(L);
				this->shift++;
				skyCount--;
			}
			else {
				this->track[request->trackIdx].Insert_SHL(PN, 1);
				this->injection++;
				this->shift++;
			}
		}
	}

	if (newFlip == 0) {
		this->track[request->trackIdx].Insert_SHL(PN, 0);
		this->shift++;
	}
	else {
		if (skyCount > 0) {
			this->track[request->trackIdx].Shift(L);
			this->shift++;
			skyCount--;
		}
		else {
			this->track[request->trackIdx].Insert_SHL(PN, 1);
			this->injection++;
			this->shift++;
		}
	}
	//leave access port
	this->track[request->trackIdx].Shift(L);
	this->shift++;
	while (skyCount > 0) {
		this->track[request->trackIdx].Delete_SHL(PN);
		this->shift++;
		this->remove++;
		skyCount--;
	}
	delete[]data;
	delete[]oldData;

}


void Combine_PW_FNW_Module::Sim(std::string fileName){
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
				//algin port;
				this->shift++;
				//detect flip and shift 
				preFlip = this->flipBits[curDataIdx];
				this->shift++;
				this->detect++;
				//detect data and shift
				preData = this->datas[curDataIdx];
				this->shift += this->params->dataWidthSegment;
				this->detect += this->params->dataWidthSegment;
				//get skyCount;
				int skyCount = this->CountOnes(preData);
				if(preFlip == 1) skyCount++;
				//get #bits of new data;
				int ones = this->CountOnes(curData);
				//compare;
				if(std::abs(skyCount- (ones))  > std::abs(skyCount - (this->params->dataWidth - ones + 1))){
					curData = ~curData;
					curFlip = 1;
					ones = this->params->dataWidth- ones + 1;
				}
				else{
					curFlip = 0;
				}
				//write and shift
				if(skyCount > ones){
					this->remove += (skyCount-ones);
				}
				else{
					this->injection += (ones-skyCount);
				}
				this->shift += this->params->dataWidthSegment;
				//leave port
				this->shift++;
				this->datas[curDataIdx] = curData;
				this->flipBits[curDataIdx] = curFlip;
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