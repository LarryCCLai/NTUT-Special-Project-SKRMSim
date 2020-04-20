#include"Domain.h"

Domain::Domain() {
	data = -1;
}

Domain::Domain(int d = 0) {
	data = d;
}

Domain::~Domain() {}

void Domain::setData(int num) {
	data = num;
}

int Domain::getData() {
	return data;
}