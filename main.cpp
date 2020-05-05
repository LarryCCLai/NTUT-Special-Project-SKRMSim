#include<iostream>
#include"modules/ModuleFactory.h"
#include<cassert>

int main(int argc, char* argv[]) {
	Config* config = new Config();
	Parameters* params = new Parameters();
	Module* module = nullptr;

	std::string ins = "-r";
	if (ins == "-t") {
		std::string fileName = argv[2];
		std::string trackIdxMaxStr = argv[3];
		std::string dataIdxMaxStr = argv[4];

		Request::TransFormat(fileName, trackIdxMaxStr, dataIdxMaxStr);
	}
	else if (ins == "-r") {
		std::string configFileName = "Flip_N_Write_4096.txt";
		std::string resultFileName, paramsFileName;
		config->Read(configFileName);
		params->SetParams(config);
		module = ModuleFactory::CreateMoudule(params->writeMode);
		module->Initialize(params);
		std::string requestFileName = "req.txt";


		size_t pos = configFileName.find_last_of("/");
		if (pos != std::string::npos) {
			resultFileName = configFileName.substr(pos + 1, configFileName.size());
			paramsFileName = configFileName.substr(pos + 1, configFileName.size());
		}
		resultFileName = "./result/" + resultFileName.substr(0, resultFileName.find(".")) + "_Result_" + requestFileName.substr(requestFileName.find("workload_") + 9, 1) + resultFileName.substr(resultFileName.find("."), resultFileName.size());
		paramsFileName = "./result/" + paramsFileName.substr(0, paramsFileName.find(".")) + "_Params_" + requestFileName.substr(requestFileName.find("workload_") + 9, 1) + paramsFileName.substr(paramsFileName.find("."), paramsFileName.size());
		
		module->Sim(requestFileName);
		module->Print();
		module->WriteResultFile(resultFileName);
		params->CreateParamsFile(paramsFileName);
	}
	delete config;
	delete module;
	return 0;
	
	/*Config* config = new Config();
	Parameters* params = new Parameters();
	Module* module = nullptr;

	std::string ins = argv[1];
	if (ins == "-t") {
		std::string fileName = argv[2];
		std::string trackIdxMaxStr = argv[3];
		std::string dataIdxMaxStr = argv[4];

		Request::TransFormat(fileName, trackIdxMaxStr, dataIdxMaxStr);
	}
	else if (ins == "-r") {
		std::string configFileName = argv[2];
		std::string resultFileName, paramsFileName;
		config->Read(configFileName);
		params->SetParams(config);
		module = ModuleFactory::CreateMoudule(params->writeMode);
		module->Initialize(params);
		std::string requestFileName = argv[3];


		size_t pos = configFileName.find_last_of("/");
		if (pos != std::string::npos) {
			resultFileName = configFileName.substr(pos + 1, configFileName.size());
			paramsFileName = configFileName.substr(pos + 1, configFileName.size());
		}
		resultFileName = "./result/" + resultFileName.substr(0, resultFileName.find(".")) + "_Result_" + requestFileName.substr(requestFileName.find("workload_") + 9, 1) + resultFileName.substr(resultFileName.find("."), resultFileName.size());
		paramsFileName = "./result/" + paramsFileName.substr(0, paramsFileName.find(".")) + "_Params_" + requestFileName.substr(requestFileName.find("workload_") + 9, 1) + paramsFileName.substr(paramsFileName.find("."), paramsFileName.size());

		module->Sim(requestFileName);
		module->Print();
		module->WriteResultFile(resultFileName);
		params->CreateParamsFile(paramsFileName);
	}
	delete config;
	delete module;
	return 0;*/
}