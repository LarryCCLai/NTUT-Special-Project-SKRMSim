#include<iostream>
#include"modules/ModuleFactory.h"
#include<cassert>
int* ToBinary(uint64_t num, int Nbits) {
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

int main(int argc, char* argv[]) {
	Config* config = new Config();
	Parameters* params = new Parameters();
	RequestQueue* requests = new RequestQueue();
	Module* module = nullptr;
	std::string configFileName = "Combine_PW_FNW.txt";
	config->Read(configFileName);
	params->SetParams(config);	
	params->Print();
	module = ModuleFactory::CreateMoudule(params->writeMode);
	module->Initialize(params);
	
	std::string line;
	std::string subline;
	std::string fileName = "requests.txt";
	std::ifstream configFile(fileName.c_str());
	if (configFile.is_open()) {
		while (!configFile.eof()) {
			getline(configFile, line);
			size_t pos = line.find_first_not_of("\t\r\n");
			if (pos == std::string::npos) {
				continue;
			}
			else if (line[pos] == ';') { 
				continue;				
			}
			else {
				size_t colonPos = line.find_first_of(";");
				if (colonPos == std::string::npos) {
					subline = line.substr(pos);
				}
				else {
					assert(colonPos > pos);
					subline = line.substr(pos, colonPos - pos);
				}
			}
			std::string operation;
			int trackIdx; 
			int dataIdx; 
			uint64_t data;

			

			std::string::size_type sz = 0;
			pos = subline.find(" ");
			assert(pos != std::string::npos);
			operation = subline.substr(0, pos);
			subline = subline.substr(pos + 1, subline.size());

			pos = subline.find(" ");
			assert(pos != std::string::npos);
			trackIdx = std::stoull(subline.substr(0, pos), &sz, 0);
			subline = subline.substr(sz + 1);

			pos = subline.find(" ");
			assert(pos != std::string::npos);
			dataIdx = std::stoi(subline.substr(0, pos), &sz, 0);
			subline = subline.substr(sz + 1);

			pos = subline.find(" ");
			assert(pos == std::string::npos);
			data = std::stoull(subline.substr(0, pos), &sz, 0);
			
			Request* request = new Request(operation, trackIdx, dataIdx, data);
			if (request->operation == "W") {
				module->Write(request);
			}
			else {
				std::cout << module->Read(request);
			}
			delete request;
		}
	}
	else {
		std::cout << "[error] Could not read request file." << std::endl;
		exit(1);
	}
	module->Print();
	std::string resultFileName = configFileName.substr(0, configFileName.find("."))+"_result"+ configFileName.substr(configFileName.find("."), configFileName.size());
	module->WriteResultFile(resultFileName);
	params->CreateParamsFile(configFileName);
	delete config;
	delete module;
	return 0;
}