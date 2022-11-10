#include "5_Mux.h"

Mux5::Mux5(sc_module_name moduleName) : sc_module(moduleName), sIn("sIn"), aIn("aIn"), bIn("bIn"), cOut("cOut")
{
	SC_METHOD(operation);
	sensitive << aIn << bIn << sIn;
}

void Mux5::operation()
{
	if (sIn.read())
		cOut.write(bIn.read());
	else
		cOut.write(aIn.read());
}