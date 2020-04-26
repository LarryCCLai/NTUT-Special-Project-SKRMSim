#ifndef MODULEFACTORY_H
#define MODULEFACTORY_H
#include"Naive/Naive_Module.h"
#include"DCW/DCW_Module.h"
#include"FlipNWrite/Flip_N_Write_Module.h"
#include"PermutationWrite/PermutationWrite_Module.h"
#include"MOutOfN/MOutOfNModule.h"

class ModuleFactory {
public:
	ModuleFactory ();
	~ModuleFactory ();
	static Module* CreateMoudule(WriteMode writeMode);
private:

};
#endif // !MODULEFACTORY_H
