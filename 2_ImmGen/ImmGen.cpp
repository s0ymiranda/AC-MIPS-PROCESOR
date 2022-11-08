#include "ImmGen.h"

ImmGen::ImmGen(sc_module_name moduleName) : sc_module(moduleName)
{

	SC_METHOD(operation);
	sensitive << clk.neg();
	dont_initialize();
}

void ImmGen::operation()
{
	ID_EXOut.write(IF_IDIn.read());
}