#include"Flip_N_Write_Module.h"
#include<iostream>
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
}

Flip_N_Write_Module::~Flip_N_Write_Module() {
	delete[]track;
	delete params;
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
	int startPN = (request->dataIdx + 1) * params->N_DataSegment - 1;
	int endPN = request->dataIdx * params->N_DataSegment;
	int* binaryData = new int[params->dataWidthSegment];
	int flip = 0;
	for (int PN = startPN; PN >= endPN; PN--) {
		
		flip = this->track[request->trackIdx].Read(PN);
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

	}
	uint64_t data = this->ToDecimal(binaryData, params->dataWidth);
	if (flip == 1) {
		data = ~data;
	}
	delete[]binaryData;
	return data;
}

void Flip_N_Write_Module::Write(Request* request) {
	int startPN = (request->dataIdx + 1) * params->N_DataSegment - 1;
	int endPN = request->dataIdx * params->N_DataSegment;
	int* data;
	int* oldData = new int[params->dataWidthSegment];
	int oldFlip = 0, newFlip = 0;
	for (int PN = startPN; PN >= endPN; PN--) {
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
	}
	delete[]oldData;
}