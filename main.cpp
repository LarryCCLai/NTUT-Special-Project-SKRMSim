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

	//std::string configFileName = "Combine_PW_FNW.txt";
	std::string configFileName = argv[1];
	config->Read(configFileName);
	params->SetParams(config);
	params->Print();
	module = ModuleFactory::CreateMoudule(params->writeMode);
	module->Initialize(params);
	//std::string fileName = "load_a.txt";
	std::string fileName = argv[2];
	std::string requestFileName = Request::TransFormat(fileName, params->N_racetrack, params->NDR);

	module->Sim(requestFileName);

	module->Print();
	std::string resultFileName = configFileName.substr(0, configFileName.find(".")) + "_result" + configFileName.substr(configFileName.find("."), configFileName.size());
	module->WriteResultFile(resultFileName);
	params->CreateParamsFile(configFileName);
	delete config;
	delete module;
	return 0;
}