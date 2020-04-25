#include"modules/Module.h"
#include<iostream>

Module::Module() {
}

void Module::Initialize(Parameters* params) {
	if (!this->initialized) {
		this->params = params;
		this->track = new MarcoCell[this->params->N_racetrack];
		for (int i = 0; i < params->N_racetrack; i++) {
			this->track[i].Initialize(params);
		}
		this->initialized = true;
	}
}

void Module::Print() {
	std::cout << "shift = " << this->shift << std::endl;
	std::cout << "injection = " << this->injection << std::endl;
	std::cout << "detect = " << this->detect << std::endl;
	std::cout << "remove = " << this->remove << std::endl;
}

int* Module::ToBinary(uint64_t num, int Nbits) {
	int* res = new int[Nbits];
	int idx = Nbits - 1;
	for (uint64_t n = num; n != 0; n /= 2) {
		int b = n % 2;
		res[idx--] = b;
	}
	while (idx >= 0) {
		res[idx--] = 0;
	}
	return res;
}

uint64_t Module::ToDecimal(int* num, int Nbits) {
	int weight = 0;
	uint64_t res = 0;
	for (int idx = Nbits - 1; idx >= 0; idx--, weight++) {
		if (num[idx]) {
			res += static_cast<uint64_t>(pow(2, weight));
		}
	}
	return res;
}

uint64_t Module::GetInjection() {
	return this->injection;
}

uint64_t Module::GetRemove() {
	return this->remove;
}

uint64_t Module::GetShift() {
	return this->shift;
}

uint64_t Module::GetDetect() {
	return this->detect;
}