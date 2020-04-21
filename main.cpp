#include"Config.h"
#include<iostream>
int main() {
	Config* p = new Config();
	p->Read("config.txt");
	p->Print();
}