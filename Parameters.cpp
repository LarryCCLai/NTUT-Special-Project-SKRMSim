#include"Parameters.h"
#include<iostream>
Parameters::Parameters() {
	M_N_Table.insert(std::pair<int, std::pair<int, int>>(4, std::pair<int, int>(6, 3)));
	M_N_Table.insert(std::pair<int, std::pair<int, int>>(8, std::pair<int, int>(11, 4)));
	M_N_Table.insert(std::pair<int, std::pair<int, int>>(16, std::pair<int, int>(19, 8)));
	M_N_Table.insert(std::pair<int, std::pair<int, int>>(32, std::pair<int, int>(35, 17)));
	M_N_Table.insert(std::pair<int, std::pair<int, int>>(64, std::pair<int, int>(68, 31)));
	
	this->dataWidth = 64;
	this->dataWidthSegment = 16;
	this->writeMode = WriteMode::M_out_of_N_Write;
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
	c->GetString("writeMode", this->writeMode);

	this->N_DataSegment = this->dataWidth / this->dataWidthSegment;
	this->N_dataSegmentR = this->NDR * this->N_DataSegment;
	if (this->writeMode == "M_out_of_N_Write") {
		this->dataSegmentLength = M_N_Table[dataWidthSegment].first;
		this->N_onesDataSegment = M_N_Table[dataWidthSegment].second;
	}
	else if (this->writeMode == "Flip_N_Write") {
		this->dataSegmentLength = dataWidthSegment + 1;
		this->N_onesDataSegment = NULL;
	}
	else if (this->writeMode == "Permutation_Write" || this->writeMode == "DCW" || this->writeMode == "General") {
		this->dataSegmentLength = dataWidthSegment;
		this->N_onesDataSegment = NULL;
	}
	else {
		std::cout << "[error] config file: write mode value" << std::endl;
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