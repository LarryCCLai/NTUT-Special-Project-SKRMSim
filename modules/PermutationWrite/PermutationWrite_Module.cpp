#include"PermutationWrite_Module.h"

#include<iostream>
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
}

PermutationWrite_Module::~PermutationWrite_Module() {
	delete[]track;
	delete params;
}

void PermutationWrite_Module::Initialize(Config* config) {
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

uint64_t PermutationWrite_Module::Read(Request* request) {
	int startPN = (request->dataIdx + 1) * params->N_DataSegment - 1;
	int endPN = request->dataIdx * params->N_DataSegment;
	int* binaryData = new int[params->dataWidthSegment];
	for (int PN = startPN; PN >= endPN; PN--) {
		for (int i = params->dataWidthSegment - 1; i >= 0; i--) {
			binaryData[i] = this->track[request->trackIdx].Read(PN);
			this->detect++;
			this->track[request->trackIdx].Shift(R);
			this->shift++;
		}
		for (int i = params->dataWidthSegment - 1; i >= 0; i--) {
			this->track[request->trackIdx].Shift(L);
			this->shift++;
		}
	}
	uint64_t data = this->ToDecimal(binaryData, params->dataWidth);
	delete[]binaryData;
	return data;
}

void PermutationWrite_Module::Write(Request* request) {
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
	this->track[request->trackIdx].Print();
	delete[]data;
}
