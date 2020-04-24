#include"MOutOfNModule.h"
#include<iostream>
#define R true
#define L false
M_Out_Of_N_Module::M_Out_Of_N_Module() {
	this->injection = 0;
	this->remove = 0;
	this->shift = 0;
	this->detect = 0;

	this->initialized = false;
	this->track = nullptr;
	this->params = nullptr;
}

M_Out_Of_N_Module::~M_Out_Of_N_Module() {
	delete[]track;
	delete params;
}

void M_Out_Of_N_Module::Initialize(Config* config) {
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

uint64_t M_Out_Of_N_Module::Read(Request* request) {
	int startPN = (request->dataIdx + 1) * params->N_DataSegment - 1;
	int endPN = request->dataIdx * params->N_DataSegment;
	int* MOutOfNCode = new int[params->dataSegmentLength];
	int* binaryData = new int[params->dataWidth];
	int dataIdx = params->dataWidth - 1;
	uint64_t data = 0;
	for (int PN = startPN; PN >= endPN; PN--) {
		for (int i = params->dataSegmentLength - 1; i >= 0; i--) {
			MOutOfNCode[i] = this->track[request->trackIdx].Read(PN);
			this->track[request->trackIdx].Shift(R);
		}
		int* dataPatition = ToBinary(this->Decode(MOutOfNCode, params->dataSegmentLength, params->N_onesDataSegment), params->dataWidthSegment);
		
		for (int i = params->dataWidthSegment - 1; i >= 0; i--) {
			binaryData[dataIdx--] = dataPatition[i];
		}
		
		for (int i = 0; i < params->dataSegmentLength; i++) {
			this->track[request->trackIdx].Shift(L);
		}
	}
	data = this->ToDecimal(binaryData, params->dataWidth);
	delete[]MOutOfNCode;
	delete[]binaryData;
	return data;
}

void M_Out_Of_N_Module::Write(Request* request) {
	int startPN = (request->dataIdx + 1) * params->N_DataSegment - 1;
	int endPN = request->dataIdx * params->N_DataSegment;
	uint64_t sampling = 0;
	for (int i = 0; i < params->dataWidthSegment; i++) {
		sampling = (sampling << 1) | 1;
	}
	for (int PN = startPN; PN >= endPN; PN--) {
		for (int i = 0; i < params->dataSegmentLength; i++) {
			this->detect++;
			if (this->track[request->trackIdx].Read(PN) == 1) {
				this->track[request->trackIdx].Shift(R);
				this->shift++;
			}
			else {
				this->track[request->trackIdx].Delete_SHR(PN);
				this->shift++;
			}
		}
		uint64_t dataS = (sampling & request->data) >> ((startPN - PN) * params->dataWidthSegment);
		int* MOutOfNCode = this->Encode(dataS, params->dataSegmentLength, params->N_onesDataSegment);
		for (int i = 0; i < params->dataSegmentLength; i++) {
			if (MOutOfNCode[i] == 1) {
				this->track[request->trackIdx].Shift(L);
				this->shift++;
			}
			else {
				this->track[request->trackIdx].Insert_SHL(PN, 0);
				this->shift++;
			}
		}
		sampling = sampling << params->dataWidthSegment;
		delete[]MOutOfNCode;
	}
}


int* M_Out_Of_N_Module::Encode(uint64_t data, int n, int m) {
	int* nums = new int[n];
	for (int i = 0; i < m; i++) {
		nums[i] = 1;
	}
	for (int i = m; i < n; i++) {
		nums[i] = 0;
	}
	std::sort(nums, nums + n);
	for (uint64_t j = 0; j < data; j++) {
		std::next_permutation(nums, nums + n);
	}
	return nums;
}

uint64_t M_Out_Of_N_Module::Decode(int* MOutOfNCode, int n, int m) {
	int* nums = new int[n];
	for (int i = 0; i < m; i++) {
		nums[i] = 1;
	}
	for (int i = m; i < n; i++) {
		nums[i] = 0;
	}
	std::sort(nums, nums + n);
	uint64_t res = 0;
	while (!std::equal(MOutOfNCode, MOutOfNCode + n, nums)) {
		std::prev_permutation(MOutOfNCode, MOutOfNCode + n);
		res++;
	}
	delete[]nums;
	return res;
}