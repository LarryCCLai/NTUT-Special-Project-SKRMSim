#include"MOutOfNModule.h"


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
		this->initialized = true;
	}
}

M_Out_Of_N_Module::~M_Out_Of_N_Module() {

}

uint64_t M_Out_Of_N_Module::Read(Request* request) {
	return 0;
}

void M_Out_Of_N_Module::Write(Request* request) {

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