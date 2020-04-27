#ifndef COMBINE_PW_FNW_MODULE_H
#define COMBINE_PW_FNW_MODULE_H
#include"../Module.h"
class Combine_PW_FNW_Module : public Module {
public:
	Combine_PW_FNW_Module();
	~Combine_PW_FNW_Module();
	void Initialize(Parameters* params);
	uint64_t Read(Request* request);
	void Write(Request* request);

private:
	int HammingDistance(uint64_t oldData, int oldFlip, uint64_t newData, int newFlip);
};

#endif // !COMBINE_PW_FNW_MODULE_H
