#include"Naive_Module.h"

Naive_Module::Naive_Module() {
	this->injection = 0;
	this->remove = 0;
	this->shift = 0;
	this->detect = 0;

	this->initialized = false;
	this->track = nullptr;
	this->params = nullptr;
}

Naive_Module::~Naive_Module() {
	delete[]track;
	delete params;
}

void Naive_Module::Initialize(Config* config) {
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

uint64_t Naive_Module::Read(Request* request) {

}

void Naive_Module::Write(Request* request) {
	int startPN = (request->dataIdx + 1) * params->N_DataSegment - 1;
	int endPN = request->dataIdx * params->N_DataSegment;
}
