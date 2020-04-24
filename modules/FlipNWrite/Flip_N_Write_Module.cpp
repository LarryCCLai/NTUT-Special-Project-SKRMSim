#include"Flip_N_Write_Module.h"
#include<iostream>
#define R true
#define L false

Flip_N_Write_Module::Flip_N_Write_Module() {
	this->injection = 0;
	this->remove = 0;
	this->shift = 0;
	this->detect = 0;

	this->initialized = false;
	this->track = nullptr;
	this->params = nullptr;
}

Flip_N_Write_Module::~Flip_N_Write_Module() {
	delete[]track;
	delete params;
}

void Flip_N_Write_Module::Initialize(Config* config) {
	if (!this->initialized) {
		this->params = new Parameters();
		this->params->SetParams(config);
		this->track = new MarcoCell[this->params->N_racetrack];
		for (int i = 0; i < params->N_racetrack; i++) {
			this->track[i].Initialize(params);
		}
		this->initialized = true;
	}
}


uint64_t Flip_N_Write_Module::Read(Request* request) {

}

void Flip_N_Write_Module::Write(Request* request) {

}