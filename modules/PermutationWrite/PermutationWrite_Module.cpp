#include"PermutationWrite_Module.h"
#define R true
#define L false
PermutationWrite_Module::PermutationWrite_Module() {
	this->injection = 0;
	this->remove = 0;
	this->shift = 0;
	this->detect = 0;

	this->initialized = false;
	this->track = nullptr;
	this->params = nullptr;
	this->datas = nullptr;
}

PermutationWrite_Module::~PermutationWrite_Module() {
	delete[]track;
	delete params;
	delete[]datas;
}

void PermutationWrite_Module::Initialize(Parameters* params) {
	if (!this->initialized) {
		this->params = params;
		this->track = new MarcoCell[this->params->N_racetrack];
		for (int i = 0; i < params->N_racetrack; i++) {
			this->track[i].Initialize(params);
		}
		this->datas = new uint64_t[params->NDR];
		for(int i = 0; i < params->NDR; i++){
			this->datas[i] = 0;
		}
		this->initialized = true;
	}
}

uint64_t PermutationWrite_Module::Read(Request* request) {
	int PN = request->dataIdx;
	int* binaryData = new int[params->dataWidthSegment];
	this->track[request->trackIdx].Shift(R);
	//this->shift++;

	for (int i = params->dataWidthSegment - 1; i >= 0; i--) {
		binaryData[i] = this->track[request->trackIdx].Read(PN);
		//this->detect++;
		this->track[request->trackIdx].Shift(R);
		//this->shift++;
	}
	for (int i = params->dataWidthSegment - 1; i >= 0; i--) {
		this->track[request->trackIdx].Shift(L);
		//this->shift++;
	}
	this->track[request->trackIdx].Shift(L);
	//this->shift++;
	uint64_t data = this->ToDecimal(binaryData, params->dataWidth);
	delete[]binaryData;
	return data;
}

void PermutationWrite_Module::Write(Request* request) {
	int PN = request->dataIdx;
	int* data = this->ToBinary(request->data, params->dataSegmentLength);
	int skyCount = 0;
	this->track[request->trackIdx].Shift(R);
	this->shift++;
	for (int i = params->dataSegmentLength - 1; i >= 0; i--) {
		this->detect++;
		if (this->track[request->trackIdx].Read(PN) == 0) {
			this->track[request->trackIdx].Delete_SHR(PN);
			this->shift++;
		}
		else {
			this->track[request->trackIdx].Shift(R);
			this->shift++;
			skyCount++;
		}
	}
	
	for (int i = 0; i < params->dataSegmentLength; i++) {
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
	this->track[request->trackIdx].Shift(L);
	this->shift++;
	while (skyCount > 0) {
		this->track[request->trackIdx].Delete_SHL(PN);
		this->shift++;
		this->remove++;
		skyCount--;
	}
	delete[]data;
	/*
	int startPN = (request->dataIdx + 1) * params->N_DataSegment - 1;
	int endPN = request->dataIdx * params->N_DataSegment;
	int* data = this->ToBinary(request->data, params->dataSegmentLength);
	int skyCount = 0;
	for (int PN = startPN; PN >= endPN; PN--) {
		for (int i = params->dataSegmentLength - 1; i >= 0; i--) {
			this->detect++;
			if (this->track[request->trackIdx].Read(PN) == 0) {
				this->track[request->trackIdx].Delete_SHR(PN);
				this->shift++;
			}
			else {
				this->track[request->trackIdx].Shift(R);
				this->shift++;
				skyCount++;
			}
		}
		for (int i = 0; i < params->dataSegmentLength; i++) {
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
			if (i == params->dataSegmentLength - 1 && data[i] == 0) {
				skyCount++;
			}
		}
		while (skyCount > 0) {
			this->track[request->trackIdx].Delete_SHL(PN);
			this->shift++;
			this->remove++;
			skyCount--;
		}
	}
	delete[]data;*/
}

void PermutationWrite_Module::Sim(std::string fileName){
	std::string line;
	std::string subline;
	std::string operation;
	uint64_t preData = NULL;
	uint64_t curData = NULL;
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
				this->shift++;
				preData = this->datas[curDataIdx];
				this->shift += this->params->dataWidthSegment;
				this->detect += this->params->dataWidthSegment;
				int skyCount = this->CountOnes(preData);
				int ones = this->CountOnes(curData);
				if(skyCount > ones){
					this->remove += (skyCount-ones);
				}
				else{
					this->injection += (ones-skyCount);
				}
				this->shift += this->params->dataWidthSegment;
				this->shift++;
				
				this->datas[curDataIdx] = curData;
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