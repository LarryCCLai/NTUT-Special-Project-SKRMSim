#include"Naive_Module.h"
#define R true
#define L false
Naive_Module::Naive_Module() {
	this->injection = 0;
	this->remove = 0;
	this->shift = 0;
	this->detect = 0;

	this->initialized = false;
	this->track = nullptr;
	this->params = nullptr;
	this->datas = nullptr;
}

Naive_Module::~Naive_Module() {
	delete[]track;
	delete params;
	delete[]datas;
}

void Naive_Module::Initialize(Parameters* params) {
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

uint64_t Naive_Module::Read(Request* request) {
	int PN = request->dataIdx;
	int* binaryData = new int[params->dataSegmentLength];
	for (int i = params->dataSegmentLength - 1; i >= 0; i--) {
		binaryData[i] = this->track[request->trackIdx].Read(PN);
		this->detect++;
		this->track[request->trackIdx].Shift(R);
		this->shift++;
	}
	for (int i = params->dataSegmentLength - 1; i >= 0; i--) {
		this->track[request->trackIdx].Shift(L);
		this->shift++;
	}
	
	uint64_t data = this->ToDecimal(binaryData, params->dataWidth);
	delete[]binaryData;
	return data;
}

void Naive_Module::Write(Request* request) {
	int PN = request->dataIdx;
	int* data = this->ToBinary(request->data, params->dataSegmentLength);
	
	for (int i = params->dataSegmentLength - 1; i >= 0; i--) {
		this->track[request->trackIdx].Delete_SHR(PN);
		this->shift++;
		this->remove++;
	}
	for (int i = 0; i < params->dataSegmentLength; i++) {
		this->track[request->trackIdx].Insert_SHL(PN, data[i]);
		this->shift++;
		if (data[i] == 1) {
			this->injection++;
		}
	}
	delete[]data;
}

void Naive_Module::Sim(std::string fileName){
	std::string line;
	std::string subline;
	std::string operation;
	uint64_t preData = NULL;
	int preDataIdx = NULL;
	int preTrackIdx = NULL;
	uint64_t curData = NULL;
	int curDataIdx = NULL;
	int curTrackIdx = NULL;
	//int cou = 0;
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
				//std::cout<<cou++;
				this->shift += this->params->dataSegmentLength;	
				this->remove += this->params->dataSegmentLength;
				this->injection+= this->CountOnes(curData);
				this->shift += this->params->dataSegmentLength;	
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