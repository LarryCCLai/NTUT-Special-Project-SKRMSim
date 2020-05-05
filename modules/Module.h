#ifndef MODULE_H
#define MODULE_H

#include"../src/MarcoCell.h"
#include"../requests/Request.h"
#include"../src/Parameters.h"
class Module {
protected: 
	bool initialized;
	MarcoCell* track;
	Parameters* params;

	uint64_t injection;
	uint64_t remove;
	uint64_t shift;
	uint64_t detect;
public:
	Module();
	
	virtual ~Module() {};
	virtual uint64_t Read(Request) = 0;
	virtual void Write(Request) = 0;
	
	virtual void Initialize(Parameters*) = 0;
	void Sim(std::string filename);
	void Print();
	void WriteResultFile(std::string fileName);
	int* ToBinary(uint64_t num, int Nbits);
	uint64_t ToDecimal(int* num, int Nbits);
	uint64_t GetInjection();
	uint64_t GetRemove();
	uint64_t GetShift();
	uint64_t GetDetect();
   
};

#endif // !MODULE_H
