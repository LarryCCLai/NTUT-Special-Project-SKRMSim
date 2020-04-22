#ifndef REQUEST_H
#define REQUEST_H
#include"typedef.h"
class Request {
private:

public:
	int trackIdx;
	int PN;
	uint64_t data;
	Request();
	Request(int trackIdx, int PN, uint64_t data);
	~Request ();
};

#endif // !REQUEST_H

