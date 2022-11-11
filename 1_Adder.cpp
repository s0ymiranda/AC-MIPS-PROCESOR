#include "1_Adder.h"

Adder1::Adder1(sc_module_name moduleName) : sc_module(moduleName){

	SC_METHOD(operation);
	sensitive << aIn ;

}

void Adder1::operation()
{
	resultOut.write(aIn.read() + 1);
}
