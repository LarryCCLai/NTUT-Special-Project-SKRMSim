#ifndef MARCOCELL_H
#define MARCOCELL_H
#include"Domain.h"
#include"AccessPort.h"
#include"Parameter.h"
class MarcoCell{
private:
	Domain* bits;
	AccessPort* ports;
	int NPR, NBR, NSDR;
	bool initialized;
public:
	MarcoCell();

	~MarcoCell();

	void Initialize(Parameter* p);
	void Information();
	
	void Shift(bool dir); //dir: true = righr, false = left;
	int Read(int portNumber);
	void Write(int PN, int data);
	void Insert_SHR(int PN, int data);
	void Insert_SHL(int PN, int data);
	void Delete_SHR(int PN, int data);
	void Delete_SHL(int PN, int data);
	void RandomUpdate(int PN, int data);
};


#endif // !MARCOCELL_H

