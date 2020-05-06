#include<iostream>
#include"modules/ModuleFactory.h"
#include<cassert>

int main(int argc, char* argv[]) {
	Config* config = new Config();
	Parameters* params = new Parameters();
	Module* module = nullptr;

	std::string ins = argv[1];
	if (ins == "-t") {
		std::string fileName = argv[2];
		std::string trackIdxMax = argv[3];
		std::string dataIdxMax = argv[4];

		
		Request::TransFormat(fileName, trackIdxMax, dataIdxMax);
	}
	else if (ins == "-r") {
		std::string configFileName = argv[2];
		std::string requestFileName = argv[3];
		config->Read(configFileName);
		params->SetParams(config);
		params->Print();
		module = ModuleFactory::CreateMoudule(params->writeMode);
		module->Initialize(params);
		module->Sim(requestFileName);
		module->Print();
		size_t pos; 
		std::string postfix;
		pos = requestFileName.find("uniform");
		if (pos != std::string::npos) {
			postfix = requestFileName.substr(pos,11);
		}
		else {
			pos = requestFileName.find("zipf");
			if (pos != std::string::npos) {
				postfix = requestFileName.substr(pos,8);
			}
			else{
				std::cout << "[error] main.cpp, requestFile Name" << std::endl;
				exit(1);
			}
		}
		std::string resultFileName = "./outputFile/results/"+config->GetFileName()+"_"+postfix+"."+config->GetFileNameExtension();
		std::cout<<resultFileName<<std::endl;
		module->WriteResultFile(resultFileName);
	}
	return 0;
}