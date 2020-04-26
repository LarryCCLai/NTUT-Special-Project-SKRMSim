#include"Config.h"
#include"Parameters.h"
#include"Request.h"
#include<iostream>
#include"modules/ModuleFactory.h"
#include"../Factory/Factory/generateRequestFile.h"
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
	config->Read("config.txt");
	//requests->Read("requests.txt");
	//config->Read(argv[1]);
	//requests->Read(argv[2]);
	params->SetParams(config);	
	module = ModuleFactory::CreateMoudule(params->writeMode);
	module->Initialize(params);
	
	/*while (true){
		Request* request = requests->getNextRequest();
		if (request == nullptr) {
			break;
		}
		if (request->operation == "W")
			module->Write(request);
		else {
			std::cout<<module->Read(request);
		}
	}*/
	module->Print();
	//GenerateRequestFile();
}