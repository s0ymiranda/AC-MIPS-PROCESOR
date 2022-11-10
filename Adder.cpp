#include "Adder.h"

Adder::Adder(sc_module_name moduleName) : sc_module(moduleName){

	SC_METHOD(operation);
	sensitive << aIn << bIn;

}

void Adder::operation()
{
	resultOut.write(aIn.read() + bIn.read());
}