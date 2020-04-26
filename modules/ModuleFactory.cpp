#include"ModuleFactory.h"

Module* ModuleFactory::CreateMoudule(WriteMode writeMode) {
	Module* module = nullptr;
	if (writeMode == WriteMode::Naive) {
		module = new Naive_Module();
	}
	else if (writeMode == WriteMode::DCW) {
		module = new DCW_Module();
	}
	else if (writeMode == WriteMode::Flip_N_Write) {
		module = new Flip_N_Write_Module();
	}
	else if (writeMode == WriteMode::Permutation_Write) {
		module = new PermutationWrite_Module();
	}
	else if (writeMode == WriteMode::M_Out_Of_N_Write) {
		module = new M_Out_Of_N_Module();
	}
	return module;
}