#ifndef M_OUT_OF_N
#define M_OUT_OF_N
#include"../module.h"

class M_Out_Of_N_Module: public Module {

public:
	M_Out_Of_N_Module();
	~M_Out_Of_N_Module();
	uint64_t Read(Request*);
    uint64_t Write(Request*);


};

#endif // !M_OUT_OF_N

