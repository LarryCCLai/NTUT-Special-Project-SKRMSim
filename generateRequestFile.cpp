#include"generateRequestFile.h"
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<random>
#include <chrono>
void GenerateRequestFile() {
	std::fstream file;
	
	std::string operation = "W";
	int trackIdx = 0;
	int dataIdx = 0;
	uint64_t data = 0;
	
	uint64_t NRequests = 0;
	
	uint64_t seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937_64  generator(seed);
	std::uniform_int_distribution<uint64_t> UniformDistribution(0, generator.max()/4);
	NRequests = 1000000;
	file.open("requests.txt", std::ios::out);
	if (!file) {
		std::cout << "[error] file open";
	}
	else {
		std::cout << "success";
		file << ";**************************************************************" << std::endl;
		file << "; Format" << std::endl;
		file << "; Operation, TrackIdx, DataIdx, Data" << std::endl;
		for (uint64_t i = 0; i < NRequests; ++i) {
			data = UniformDistribution(generator);
			file << operation << " " << trackIdx << " " << dataIdx << " " << data << std::endl;
		}
		file << ";**************************************************************" << std::endl;

	}
}
