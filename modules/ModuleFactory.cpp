#include"ModuleFactory.h"

Module* ModuleFactory::CreateMoudule(std::string writeMode) {
	Module* module = nullptr;
	if (writeMode == "Naive") {
		module = new Naive_Module();
	}
	else if (writeMode == "DCW") {
		module = new DCW_Module();
	}
	else if (writeMode == "Flip_N_Write") {
		module = new Flip_N_Write_Module();
	}
	else if (writeMode == "Permutation_Write") {
		module = new PermutationWrite_Module();
	}
	else if (writeMode == "M_Out_Of_N_Write") {
		module = new M_Out_Of_N_Module();
	}
	return module;
}