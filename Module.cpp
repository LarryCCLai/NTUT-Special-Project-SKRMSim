#include"modules/Module.h"

Module::Module() {
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