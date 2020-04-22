#include"Config.h"
#include"Parameters.h"
#include<iostream>
int main() {
	Config* c = new Config();
	c->Read("config.txt");
	c->Print();
	std::cout << "\n\n";
	Parameters* p = new Parameters();
	p->SetParams(c);
	p->Print();
}