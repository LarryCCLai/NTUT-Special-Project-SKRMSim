#include<iostream>
#include<cmath>
#include"Module.h"


Module::Module() {
}


void Module::Print() {
	std::cout << "shift = " << this->shift << std::endl;
	std::cout << "injection = " << this->injection << std::endl;
	std::cout << "detect = " << this->detect << std::endl;
	std::cout << "remove = " << this->remove << std::endl;
	std::cout << a << " " << b << std::endl;
}

void Module::WriteResultFile(std::string fileName) {
	size_t pos = fileName.find_last_of("/");
	if (pos != std::string::npos) {
		fileName = fileName.substr(pos + 1, fileName.size());
	}
	std::string resultFileName = "./result/" + fileName.substr(0, fileName.find(".")) + "_result" + fileName.substr(fileName.find("."), fileName.size());

	std::ofstream file(resultFileName.c_str());
	if (file.is_open()) {
		file << "Shift " << this->shift << std::endl;
		file << "Detect " << this->detect << std::endl;
		file << "Remove " << this->remove << std::endl;
		file << "Injection " << this->injection << std::endl;
		file.close();
	}
	else {
		std::cout << "Could not open Result file" << std::endl;
		std::cout << fileName << std::endl;
		exit(1);
	}
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