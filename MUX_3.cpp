#include "MUX_3.h"

Mux :: Mux(sc_module_name moduleName) : sc_module(moduleName), aIn("aIn"), bIn("bIn"), value_1In("value_1In"), value_2In("value_2In"), value_3In("value_3In"), valueOut("valueOut")
{
	SC_METHOD(process);
	sensitive << value_1In << value_2In << value_3In << aIn << bIn;
}

void Mux :: process()
{
    const bool a = aIn.read();
    const bool b = bIn.read();

    if (a == false && b == false) {
        valueOut.write(value_1In.read());
    } 
    else if (a == true && b == false) {
        valueOut.write(value_2In.read());
    }
    else if (a == false && b == true) {
        valueOut.write(value_3In.read());
  }
}
