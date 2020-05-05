#include<iostream>
#include<cmath>
#include<cassert>

#include"Module.h"


Module::Module() {
}

void Module::Sim(std::string fileName) {
	std::string line;
	std::string subline;
	std::ifstream configFile(fileName.c_str());
	int cou = 0;
	if (configFile.is_open()) {
		while (!configFile.eof()) {
			getline(configFile, line);
			size_t pos;
			std::string operation;
			int trackIdx;
			int dataIdx;
			uint64_t data;

			std::string::size_type sz = 0;
			pos = line.find(" ");
			assert(pos != std::string::npos);
			operation = line.substr(0, pos);
			line = line.substr(pos + 1, line.size());

			pos = line.find(" ");
			assert(pos != std::string::npos);
			trackIdx = std::stoull(line.substr(0, pos), &sz, 0);
			line = line.substr(sz + 1);

			pos = line.find(" ");
			assert(pos != std::string::npos);
			dataIdx = std::stoi(line.substr(0, pos), &sz, 0);
			line = line.substr(sz + 1);

			pos = line.find(" ");
			assert(pos == std::string::npos);
			data = std::stoull(line.substr(0, pos), &sz, 0);
			Request request(operation, trackIdx, dataIdx, data);
			if (request.operation == "W") {
				this->Write(request);
			}
			else {
				std::cout << this->Read(request);
			}
			cou++;
		}
	}
	else {
		std::cout << "[error] Could not read request file." << std::endl;
		std::cout << fileName << std::endl;
		exit(1);
	}
}

void Module::Print() {
	std::cout << "shift = " << this->shift << std::endl;
	std::cout << "injection = " << this->injection << std::endl;
	std::cout << "detect = " << this->detect << std::endl;
	std::cout << "remove = " << this->remove << std::endl;
}

void Module::WriteResultFile(std::string fileName) {
	std::ofstream file(fileName.c_str());
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