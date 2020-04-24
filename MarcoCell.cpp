#include"MarcoCell.h"
#include<iostream>
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

		int interval = (this->racetrackLength - this->NSDR) / this->NPR;
		int count = interval - 1;
		for (int i = 0; i < this->NPR; i++) {
			this->ports[i].setAlign(count);
			count += interval;
		}
		for (int i = 0; i < this->racetrackLength; i++) {
			this->bits[i] = 0;
		}
		if (p->writeMode == "M_Out_Of_N_Write") {
			for (int i = this->NPR - 1; i >= 0; i--) {
				for (int j = 0; j < p->N_onesDataSegment; j++) {
					this->Insert_SHL(i, 1);
				}
			}
		}
		

		this->initialized = true;
		

	}
}

void MarcoCell::Print() {
	std::cout << "racetrackLength = " << this->racetrackLength << std::endl;
	std::cout << "dataSegmentLength = " << this->dataSegmentLength << std::endl;
	std::cout << "NDR = " << this->NDR << std::endl;
	std::cout << "NPR = " << this->NPR << std::endl;
	std::cout << "NSDR = " << this->NSDR << std::endl;
	

	std::cout << "Domains: ";
	for (int i = 0; i < this->racetrackLength; i++) {
		std::cout << this->bits[i] << " ";
	}

	std::cout << std::endl;
	std::cout << "Ports: ";
	for (int i = 0; i < this->NPR; i++) {
		std::cout << this->ports[i].getAlign() << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;
}

void MarcoCell::Shift(bool dir) {//dir: true = righr, false = left;
	if (dir) {
		for (int idx = this->racetrackLength - 1; idx > 0; idx--) {
			this->bits[idx] = this->bits[idx - 1];
		}
	}
	else {
		for (int idx = 0; idx < this->racetrackLength - 1; idx++) {
			this->bits[idx] = this->bits[idx + 1];
		}
	}
} 

int MarcoCell::Read(int PN) {
	return this->bits[this->ports[PN].getAlign()];
}

void MarcoCell::Write(int PN, int data) {
	if (data == 1) {
		this->bits[this->ports[PN].getAlign()] = data;
	}
}

void MarcoCell::Insert_SHR(int PN, int data) {
	for (int idx = this->racetrackLength - 1; idx > this->ports[PN].getAlign(); idx--) {
		this->bits[idx] = this->bits[idx - 1];
	}
	this->bits[this->ports[PN].getAlign()] = data;
}

void MarcoCell::Insert_SHL(int PN, int data) {
	for (int idx = 0; idx < this->ports[PN].getAlign(); idx++) {
		this->bits[idx] = this->bits[idx + 1];
	}
	this->bits[this->ports[PN].getAlign()] = data;
}

void MarcoCell::Delete_SHR(int PN, int data) {
	for (int idx = this->ports[PN].getAlign(); idx >= 0; idx--) {
		this->bits[idx] = this->bits[idx - 1];
	}
}

void MarcoCell::Delete_SHL(int PN, int data) {
	for (int idx = this->ports[PN].getAlign(); idx < this->racetrackLength; idx++) {
		this->bits[idx] = this->bits[idx + 1];
	}
}

void MarcoCell::RandomUpdate(int PN, int data) {
	this->bits[this->ports[PN].getAlign()] = data;
}