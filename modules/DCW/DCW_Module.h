#ifndef DCW_MODULE_H
#define DCW_MODULE_H
#include"../Module.h"
class DCW_Module:public Module{
public:
	DCW_Module ();
	~DCW_Module ();
	void Initialize(Parameters* params);
	uint64_t Read(Request* request);
	void Write(Request* request);

};


#endif // !DCW_MODULE_H

