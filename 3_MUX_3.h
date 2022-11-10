#ifndef MUX_3_H
#define MUX_3_H

#include <systemc.h>

class Mux : public sc_module
{
public:

	sc_in<bool> aIn, bIn;
	sc_in<sc_int<32>> value_1In, value_2In, value_3In;
	sc_out<sc_int<32>> valueOut;

	SC_CTOR(Mux);

private:
	void process();
};

#endif