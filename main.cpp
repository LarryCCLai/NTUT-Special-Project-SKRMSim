#include"Config.h"
#include"Parameters.h"
#include"Request.h"
#include<iostream>
#include "modules/MOutOfN/MOutOfNModule.h"
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
int main() {
	Config* c = new Config();
	Request* request = new Request('W',0,0,63);
	c->Read("config.txt");
	c->Print();
	std::cout << "\n";
	Parameters* params = new Parameters();
	params->SetParams(c);
	params->Print();
	MarcoCell* track = new MarcoCell();
	//track->Initialize(params);
	//track->Print();
	M_Out_Of_N_Module* m = new M_Out_Of_N_Module();
	m->Initialize(c);
	m->Write(request);
	std::cout<<m->Read(request);
	std::cout << m->Read(request);
	
	//RequestQueue* r = new RequestQueue();
	//r->Read("requests.txt");
	/*Request* re = r->getNextRequest();
	std::cout << re->trackIdx << " " << re->PN << " " << re->data << std::endl;
	re = r->getNextRequest();
	std::cout << re->trackIdx << " " << re->PN << " " << re->data << std::endl;
	re = r->getNextRequest();
	std::cout << re->trackIdx << " " << re->PN << " " << re->data << std::endl;
	re = r->getNextRequest();*/
	

	/*Request* re = nullptr;
	r->getNextRequest(&re);
	std::cout << re->trackIdx << " " << re->PN << " " << re->data << std::endl;
	r->getNextRequest(&re);
	std::cout << re->trackIdx << " " << re->PN << " " << re->data << std::endl;
	r->getNextRequest(&re);
	std::cout << re->trackIdx << " " << re->PN << " " << re->data << std::endl;*/
}