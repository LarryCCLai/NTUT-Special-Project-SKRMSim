#include"Request.h"

Request::Request() {
	this->trackIdx = -1;
	this->PN = -1;
}

Request::Request(int trackIdx, int PN, uint64_t data) {
	this->trackIdx = trackIdx;
	this->PN = PN;
	this->data = data;
}

Request::~Request() {

}