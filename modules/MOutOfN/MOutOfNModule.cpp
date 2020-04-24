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

M_Out_Of_N_Module::~M_Out_Of_N_Module() {

}

uint64_t M_Out_Of_N_Module::Read(Request* request) {
	return 0;

}

void M_Out_Of_N_Module::Write(Request* request) {
	track[request->trackIdx].Print();
	std::cout << "\n";
	int startPN = (request->dataIdx + 1) * params->N_DataSegment - 1;
	int EndPN = request->dataIdx * params->N_DataSegment;
	uint64_t sampling = 0;
	for (int i = 0; i < params->dataWidthSegment; i++) {
		sampling = (sampling << 1) | 1;
	}
	for (int PN = startPN; PN != EndPN; PN--) {
		for (int i = 0; i < params->dataSegmentLength; i++) {
			//this->detect++;
			if (this->track[request->trackIdx].Read(PN) == 1) {
				//this->shift++;
				this->track->Shift(R);
			}
			else {
				//this->shift++;
				this->track[request->trackIdx].Delete_SHR(PN);
			}
		}
		uint64_t dataS = (sampling & request->data) >> ((startPN - PN) * params->dataWidthSegment);
		int* MOutOfNCode = this->Encode(dataS, params->dataSegmentLength, params->N_onesDataSegment);
		for (int i = 0; i < params->dataSegmentLength; i++) {
			if (MOutOfNCode[i] == 1) {
				//this->shift++;
				this->track[request->trackIdx].Shift(L);
			}
			else {
				//this->shift++;
				this->track[request->trackIdx].Insert_SHL(PN, 0);
			}
		}
		for (int j = 0; j < params->dataSegmentLength; j++) {
			std::cout << MOutOfNCode[j];
		}
		std::cout << " ";
		sampling = sampling << params->dataWidthSegment;
		delete[]MOutOfNCode;
	}
}

void M_Out_Of_N_Module::Access(Request* request) {

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
	delete[]MOutOfNCode;
	return res;
}