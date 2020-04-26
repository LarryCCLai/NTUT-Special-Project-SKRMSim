#include"MOutOfNModule.h"
#define R true
#define L false
M_Out_Of_N_Module::M_Out_Of_N_Module() {
	this->injection = 0;
	this->remove = 0;
	this->shift = 0;
	this->detect = 0;

	this->initialized = false;
	this->track = nullptr;
	this->params = nullptr;
}

void M_Out_Of_N_Module::Initialize(Parameters* params) {
	if (!this->initialized) {
		this->params = params;
		this->track = new MarcoCell[this->params->N_racetrack];
		for (int i = 0; i < params->N_racetrack; i++) {
			this->track[i].Initialize(params);
		}
		this->GenerateEncodeAndDecodeTable();
		this->initialized = true;
	}
}

M_Out_Of_N_Module::~M_Out_Of_N_Module() {
	delete[]track;
	delete params;
}

uint64_t M_Out_Of_N_Module::Read(Request* request) {
	int startPN = (request->dataIdx + 1) * params->N_DataSegment - 1;
	int endPN = request->dataIdx * params->N_DataSegment;
	uint64_t data = 0;
	for (int PN = startPN; PN >= endPN; PN--) {
		uint64_t MOutOfNCode = 0;
		for (int i = 0; i < params->dataSegmentLength; i++) {
			MOutOfNCode = MOutOfNCode | static_cast<uint64_t>(this->track[request->trackIdx].Read(PN)) << (params->dataSegmentLength - i - 1);
			this->track[request->trackIdx].Shift(R);
		}
		
		for (int i = 0; i < params->dataSegmentLength; i++) {
			this->track[request->trackIdx].Shift(L);
		}
		uint64_t dataPartition = decodeTable[MOutOfNCode];
		data = data | (dataPartition << ((startPN - PN) * params->dataWidthSegment));
	}
	return data;
}

void M_Out_Of_N_Module::Write(Request* request) {
	int startPN = (request->dataIdx + 1) * params->N_DataSegment - 1;
	int endPN = request->dataIdx * params->N_DataSegment;
	uint64_t sampling = 0;
	for (int i = 0; i < params->dataWidthSegment; i++) {
		sampling = (sampling << 1) | 1;
	}

	for (int PN = startPN; PN >= endPN; PN--) {
		for (int i = 0; i < params->dataSegmentLength; i++) {
			this->detect++;
			if (this->track[request->trackIdx].Read(PN) == 1) {
				this->track[request->trackIdx].Shift(R);
				this->shift++;
			}
			else {
				this->track[request->trackIdx].Delete_SHR(PN);
				this->shift++;
			}
		}

		uint64_t dataS = (sampling & request->data) >> ((startPN - PN) * params->dataWidthSegment);
		uint64_t MOutOfNCode = encodeTable[dataS];
		for (int i = 0; i < params->dataSegmentLength; i++) {
			if ((MOutOfNCode & 1) == 1) {
				this->track[request->trackIdx].Shift(L);
				this->shift++;
			}
			else {
				this->track[request->trackIdx].Insert_SHL(PN, 0);
				this->shift++;
			}
			MOutOfNCode = MOutOfNCode >> 1;
		}
		sampling = sampling << params->dataWidthSegment;
	}
}

void M_Out_Of_N_Module::GenerateEncodeAndDecodeTable() {
	int n = params->dataSegmentLength;
	int m = params->N_onesDataSegment;
	uint64_t* mnCode = new uint64_t[n];
	for (int i = 0; i < n - m; i++) {
		mnCode[i] = 0;
	}
	for (int i = n - m; i < n; i++) {
		mnCode[i] = 1;
	}
	uint64_t status = static_cast<uint64_t>(std::pow(2, params->dataWidthSegment));
	std::sort(mnCode, mnCode + n);
	for (uint64_t i = 0; i < status; i++) {
		uint64_t mnCodeU64 = 0;
		for (int j = 0; j < n; j++) {
			mnCodeU64 = mnCodeU64 | mnCode[j] << (n - j - 1);
		}
		/*std::cout << i << " ";
		for (int j = 0; j < n; j++) {
			std::cout << mnCode[j];
		}
		std::cout << " " << mnCodeU64<<std::endl;*/
		this->encodeTable.insert(std::pair<uint64_t, uint64_t>(i, mnCodeU64));
		this->decodeTable.insert(std::pair<uint64_t, uint64_t>(mnCodeU64, i));
		std::next_permutation(mnCode, mnCode + n);
	}
	delete[]mnCode;
}

int* M_Out_Of_N_Module::Encode(uint64_t data, int n, int m) {
	int* nums = new int[n];
	for (int i = 0; i < m; i++) {
		nums[i] = 1;
	}
	for (int i = m; i < n; i++) {
		nums[i] = 0;
	}
	std::sort(nums, nums + n);
	for (uint64_t j = 0; j < data; j++) {
		std::next_permutation(nums, nums + n);
	}
	return nums;
}

uint64_t M_Out_Of_N_Module::Decode(int* MOutOfNCode, int n, int m) {
	int* nums = new int[n];
	for (int i = 0; i < m; i++) {
		nums[i] = 1;
	}
	for (int i = m; i < n; i++) {
		nums[i] = 0;
	}
	std::sort(nums, nums + n);
	uint64_t res = 0;
	while (!std::equal(MOutOfNCode, MOutOfNCode + n, nums)) {
		std::prev_permutation(MOutOfNCode, MOutOfNCode + n);
		res++;
	}
	delete[]nums;
	return res;
}