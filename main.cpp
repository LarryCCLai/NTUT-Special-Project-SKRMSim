#include"Config.h"
#include"Parameters.h"
#include"Request.h"
#include<iostream>
#include "modules/MOutOfN/MOutOfNModule.h"

int main() {
	Config* c = new Config();
	Request* request = new Request(0,0,0);
	c->Read("config.txt");
	c->Print();
	std::cout << "\n";
	Parameters* params = new Parameters();
	params->SetParams(c);
	params->Print();
	MarcoCell* track = new MarcoCell();
	track->Initialize(params);
	track->Information();

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