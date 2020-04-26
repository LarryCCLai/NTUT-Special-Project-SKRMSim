#ifndef M_OUT_OF_N
#define M_OUT_OF_N
#include"../module.h"

class M_Out_Of_N_Module: public Module {
private:
	std::map<int, int*> encodeTable;
	std::map<int*, int> decodeTable;
public:
	
	M_Out_Of_N_Module();
	~M_Out_Of_N_Module();
	void Initialize(Parameters*);
	uint64_t Read(Request* request);
	void Write(Request* request);
	void GenerateEncodeAndDecodeTable();
	int* Encode(uint64_t data, int n, int m);
	uint64_t Decode(int* MOutOfNCode, int n, int m);
};

#endif // !M_OUT_OF_N

