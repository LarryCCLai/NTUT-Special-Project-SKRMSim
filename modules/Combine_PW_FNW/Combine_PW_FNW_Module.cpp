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
}

Combine_PW_FNW_Module::~Combine_PW_FNW_Module() {
	delete[]track;
	delete params;
}

void Combine_PW_FNW_Module::Initialize(Parameters* params) {
	if (!this->initialized) {
		this->params = params;
		this->track = new MarcoCell[this->params->N_racetrack];
		for (int i = 0; i < params->N_racetrack; i++) {
			this->track[i].Initialize(params);
		}
		this->initialized = true;
	}
}

int Combine_PW_FNW_Module::HammingDistance(uint64_t oldData, int oldFlip, uint64_t newData, int newFlip) {
	uint64_t XOR = newData ^ oldData;
	uint64_t count = 0;
	while (XOR > 0) {
		(XOR % 2 == 0) ? count : count++;
		XOR /= 2;
	}
	(oldFlip == newFlip) ? count : count++;
	return count;
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
	}
	else {
		newFlip = 0;
	}
	return ToBinary(data, params->dataWidthSegment);
}

uint64_t Combine_PW_FNW_Module::Read(Request* request) {
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
			//this->detect++;
			this->track[request->trackIdx].Shift(R);
			//this->shift++;
		}

		for (int i = 0; i < params->dataSegmentLength; i++) {
			this->track[request->trackIdx].Shift(L);
			//this->shift++;
		}

	}
	uint64_t data = this->ToDecimal(binaryData, params->dataWidth);
	if (flip == 1) {
		data = ~data;
	}
	delete[]binaryData;
	return data;
}

void Combine_PW_FNW_Module::Write(Request* request) {
	int startPN = (request->dataIdx + 1) * params->N_DataSegment - 1;
	int endPN = request->dataIdx * params->N_DataSegment;
	int* data;
	int* oldData = new int[params->dataWidthSegment];
	int oldFlip = 0, newFlip = 0;
	int skyCount = 0;
	for (int PN = startPN; PN >= endPN; PN--) {
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
		
		//calculate hamming distance
		/*int hamingDistance = HammingDistance(this->ToDecimal(oldData, params->dataWidthSegment), oldFlip, request->data, newFlip);
		//Flip or not
		if (hamingDistance > params->dataWidthSegment/2) {
			data = this->ToBinary(~request->data, params->dataWidthSegment);
			newFlip = 1;
		}
		else {
			data = this->ToBinary(request->data, params->dataWidthSegment);
			newFlip = 0;
		}*/
		data = FlipNWrite(request->data, newFlip, skyCount);
		//====
		//std::cout << "skyCount "<<skyCount << std::endl;
		int aa = 0;
		for (int i = 0; i < params->dataWidthSegment; i++) {
			if (data[i] == 1) {
				aa++;;
			}
		}
		if (aa > skyCount) {
			a += aa - skyCount;
		}
		else {
			b += skyCount - aa;
		}
		//std::cout<< "#datas "<< aa << std::endl;
		
		//write data
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
		if (newFlip == 0) {
			skyCount++;
		}
		
		while (skyCount > 0) {
			this->track[request->trackIdx].Delete_SHL(PN);
			this->shift++;
			this->remove++;
			skyCount--;
		}


		delete[]data;
	}
	delete[]oldData;
}