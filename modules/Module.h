#ifndef MODULE_H
#define MODULE_H

#include<iostream>
#include"../MarcoCell.h"
#include"../Request.h"
#include"../Parameters.h"
class Module {
public:
	
	uint64_t injection;
	uint64_t remove;
	uint64_t shift;
	uint64_t detect;

	MarcoCell* track;
	Parameters* params;

	virtual uint64_t Read(Request* )=0;
	virtual uint64_t Write(Request* )=0;

	Module ();
	~Module ();

};

#endif // !MODULE_H
