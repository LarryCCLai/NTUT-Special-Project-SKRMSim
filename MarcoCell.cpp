#include"MarcoCell.h"

MarcoCell::MarcoCell() {
	this->bits = nullptr;
	this->ports = nullptr;
	this->initialized = false;
	this->racetrackLength = 0;
	this->dataSegmentLength = 0;
	this->NDR = 0;
	this->NPR = 0;
	this->NSDR = 0;
	this->initialized = false;
};

MarcoCell::~MarcoCell() {

}

void MarcoCell::Initialize(Parameters* p) {
	if (!this->initialized) {
		this->racetrackLength = p->racetrackLength;
		this->dataSegmentLength = p->dataSegmentLength;
		this->NDR = p->NDR;
		this->NPR = p->NPR;
		this->NSDR = p->NSDR;
		this->bits = new int[this->racetrackLength];
		this->ports = new AccessPort[this->NPR];

		if (p->writeMode == "M_Out_Of_N_Write") {

		}

	}
}

void MarcoCell::Information() {

}

void MarcoCell::Shift(bool dir) {//dir: true = righr, false = left;

} 

int MarcoCell::Read(int portNumber) {
	return 0;
}
void MarcoCell::Write(int PN, int data) {

}

void MarcoCell::Insert_SHR(int PN, int data) {

}

void MarcoCell::Insert_SHL(int PN, int data) {

}

void MarcoCell::Delete_SHR(int PN, int data) {

}

void MarcoCell::Delete_SHL(int PN, int data) {

}

void MarcoCell::RandomUpdate(int PN, int data) {

}