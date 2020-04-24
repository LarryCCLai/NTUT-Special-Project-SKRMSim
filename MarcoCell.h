#ifndef MARCOCELL_H
#define MARCOCELL_H
#include"AccessPort.h"
#include"Parameters.h"
class MarcoCell{
private:
	int* bits;
	AccessPort* ports;
	int NDR, NPR, NSDR, racetrackLength, dataSegmentLength;
	bool initialized;
public:
	MarcoCell();
	~MarcoCell();
	void Initialize(Parameters* p);
	void Print();
	
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

