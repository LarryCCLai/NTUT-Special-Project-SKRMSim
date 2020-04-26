#ifndef PERMUTATIONWRITE_MODULE_H
#define PERMUTATIONWRITE_MODULE_H
#include"../Module.h"

class PermutationWrite_Module: public Module {
public:
	PermutationWrite_Module ();
	~PermutationWrite_Module ();
	void Initialize(Parameters* params);
	uint64_t Read(Request* request);
	void Write(Request* request);

};

#endif // PERMUTATIONWRITE_MODULE_H

