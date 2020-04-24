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
}

Naive_Module::~Naive_Module() {
	delete[]track;
	delete params;
}

void Naive_Module::Initialize(Config* config) {
	if (!this->initialized) {
		this->params = new Parameters();
		this->params->SetParams(config);
		this->track = new MarcoCell[this->params->N_racetrack];
		for (int i = 0; i < params->N_racetrack; i++) {
			this->track[i].Initialize(params);
		}
		this->initialized = true;
	}
}

uint64_t Naive_Module::Read(Request* request) {
	int startPN = (request->dataIdx + 1) * params->N_DataSegment - 1;
	int endPN = request->dataIdx * params->N_DataSegment;
	int* binaryData = new int[params->dataSegmentLength];
	for (int PN = startPN; PN >= endPN; PN--) {
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
	}
	uint64_t data = this->ToDecimal(binaryData, params->dataWidth);
	delete[]binaryData;
	return data;
}

void Naive_Module::Write(Request* request) {
	int startPN = (request->dataIdx + 1) * params->N_DataSegment - 1;
	int endPN = request->dataIdx * params->N_DataSegment;
	int* data = this->ToBinary(request->data, params->dataSegmentLength);
	for (int PN = startPN; PN >= endPN; PN--) {
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
	}
	delete[]data;
}
