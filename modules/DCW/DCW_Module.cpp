#include"DCW_Module.h"
#include<iostream>
#define R true
#define L false

DCW_Module::DCW_Module() {
	this->injection = 0;
	this->remove = 0;
	this->shift = 0;
	this->detect = 0;

	this->initialized = false;
	this->track = nullptr;
	this->params = nullptr;
}

DCW_Module::~DCW_Module() {
	delete[]track;
	delete params;
}

void DCW_Module::Initialize(Parameters* params) {
	if (!this->initialized) {
		this->params = params;
		this->track = new MarcoCell[this->params->N_racetrack];
		for (int i = 0; i < params->N_racetrack; i++) {
			this->track[i].Initialize(params);
		}
		this->initialized = true;
	}
}

uint64_t DCW_Module::Read(Request* request) {
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

void DCW_Module::Write(Request* request) {
	int startPN = (request->dataIdx + 1) * params->N_DataSegment - 1;
	int endPN = request->dataIdx * params->N_DataSegment;
	int* data = this->ToBinary(request->data, params->dataSegmentLength);
	for (int PN = startPN; PN >= endPN; PN--) {
		for (int i = params->dataSegmentLength - 1; i >= 0; i--) {
			this->track[request->trackIdx].Shift(R);
			this->shift++;
		}
		for (int i = 0; i < params->dataSegmentLength; i++) {
			this->track[request->trackIdx].Shift(L);
			this->shift++;
			this->detect++;
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
	}
	delete[]data;
}
