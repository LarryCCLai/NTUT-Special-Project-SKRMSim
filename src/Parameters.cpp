#include"Parameters.h"
#include<iostream>
#include<fstream>
Parameters::Parameters() {
	M_N_Table.insert(std::pair<int, std::pair<int, int>>(4, std::pair<int, int>(6, 3)));
	M_N_Table.insert(std::pair<int, std::pair<int, int>>(8, std::pair<int, int>(11, 4)));
	M_N_Table.insert(std::pair<int, std::pair<int, int>>(16, std::pair<int, int>(19, 8)));
	M_N_Table.insert(std::pair<int, std::pair<int, int>>(32, std::pair<int, int>(35, 17)));
	M_N_Table.insert(std::pair<int, std::pair<int, int>>(64, std::pair<int, int>(68, 31)));
	
	this->dataWidth = 64;
	this->dataWidthSegment = 16;
	this->writeMode = WriteMode::M_Out_Of_N_Write;
	this->NDR = 1;
	
	this->N_DataSegment = this->dataWidth / this->dataWidthSegment;
	this->N_dataSegmentR = this->NDR * this->N_DataSegment;
	this->dataSegmentLength = M_N_Table[dataWidthSegment].first;
	this->N_onesDataSegment = M_N_Table[dataWidthSegment].second;
	
	this->NSDR = dataSegmentLength;
	this->NPR = N_dataSegmentR;
	this->racetrackLength = this->NDR * this->N_DataSegment * this->dataSegmentLength + this->NSDR;
	
}

void Parameters::SetParams(Config* c) {
	c->GetValue("dataWidth", this->dataWidth);
	c->GetValue("dataWidthSegment", this->dataWidthSegment);
	c->GetValue("NDR", this->NDR);
	c->GetValue("N_racetrack", this->N_racetrack);
	c->GetMode("writeMode", this->writeMode);

	this->N_DataSegment = this->dataWidth / this->dataWidthSegment;
	this->N_dataSegmentR = this->NDR * this->N_DataSegment;
	if (this->writeMode == WriteMode::M_Out_Of_N_Write) {
		this->dataSegmentLength = M_N_Table[dataWidthSegment].first;
		this->N_onesDataSegment = M_N_Table[dataWidthSegment].second;
	}
	else if (this->writeMode == WriteMode::Flip_N_Write) {
		this->dataSegmentLength = dataWidthSegment + 1;
		this->N_onesDataSegment = NULL;
	}
	else if (this->writeMode == WriteMode::Naive || this->writeMode == WriteMode::DCW || this->writeMode == WriteMode::Permutation_Write) {
		this->dataSegmentLength = dataWidthSegment;
		this->N_onesDataSegment = NULL;
	}
	else {
		std::cout << "[error] config file: write mode value" << std::endl;
		exit(1);
	}

	this->NSDR = dataSegmentLength;
	this->NPR = N_dataSegmentR;
	this->racetrackLength = this->NDR * this->N_DataSegment * this->dataSegmentLength + this->NSDR;
}


void Parameters::Print() {
	std::cout << "N_racetrack = " << this->N_racetrack << std::endl;
	std::cout << "dataWidth = " << this->dataWidth << std::endl;
	std::cout << "dataWidthSegment = " << this->dataWidthSegment << std::endl;
	std::cout << "NDR = " << this->NDR << std::endl;
	std::cout << "writeMode = " << this->writeMode << std::endl;
	std::cout << "N_DataSegment = " << this->N_DataSegment << std::endl;
	std::cout << "N_dataSegmentR = " << this->N_dataSegmentR << std::endl;
	std::cout << "dataSegmentLength = " << this->dataSegmentLength << std::endl;
	std::cout << "N_onesDataSegment = " << this->N_onesDataSegment << std::endl;
	std::cout << "racetrackLength = " << this->racetrackLength << std::endl;
	std::cout << "NPR = " << this->NPR << std::endl;
	std::cout << "NSDR = " << this->NSDR << std::endl;
}

void Parameters::CreateParamsFile(std::string fileName) {
	std::string filename= fileName.substr(0, fileName.find(".")) + "_Parameters" + fileName.substr(fileName.find("."), fileName.size());
	std::fstream file;
	file.open(filename, std::ios::out);
	file << ";***********************************************************************\n" << std::endl;
	file << ";Number of tracks" << std::endl;
	file << "N_racetrack = " << this->N_racetrack << std::endl;

	file << ";Number of bits per data, Uint: bit" << std::endl;
	file << "dataWidth = " << this->dataWidth << std::endl;

	file << ";Number of bits per data segment, Uint: bit" << std::endl;
	file << "dataWidthSegment = " << this->dataWidthSegment << std::endl;

	file << ";Number of data per racetrack" << std::endl;
	file << "NDR = " << this->NDR << std::endl;

	file << ";Write mode" << std::endl;
	file << "writeMode = " << this->writeMode << std::endl;

	file << ";Number of data segments per data: dataWidth / dataWidthSegment" << std::endl;
	file << "N_DataSegment = " << this->N_DataSegment << std::endl;

	file << ";Number of data segment per racetrack: NDR * N_DataSegment" << std::endl;
	file << "N_dataSegmentR = " << this->N_dataSegmentR << std::endl;

	file << ";dataSegmentLength: n (m-out-of-n), dataWidthSegment + 1 (flip-N-write) or dataWidthSegment (the others)" << std::endl;
	file << "dataSegmentLength = " << this->dataSegmentLength << std::endl;

	file << ";Number of bits are one per DataSegment: m" << std::endl;
	file << "N_onesDataSegment = " << this->N_onesDataSegment << std::endl;

	file << ";racetrackLength: NDR * N_DataSegment * dataSegmentLength + NSDR" << std::endl;
	file << "racetrackLength = " << this->racetrackLength << std::endl;

	file << ";Number of Port per racetrack" << std::endl;
	file << "NPR = " << this->NPR << std::endl;

	file << ";Number of spare domain per racetrack" << std::endl;
	file << "NSDR = " << this->NSDR << std::endl;
	file << "\n;***********************************************************************" << std::endl;
	file.close();
}