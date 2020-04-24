#ifndef FLIP_N_WRITE_MODULE_H
#define FLIP_N_WRITE_MODULE_H
#include"../Module.h"
class Flip_N_Write_Module: public Module {
public:
	Flip_N_Write_Module ();
	~Flip_N_Write_Module ();
	void Initialize(Config* config);
	uint64_t Read(Request* request);
	void Write(Request* request);
};

#endif // !FLIP_N_WRITE_MODULE_H