#ifndef MUX_H
#define MUX_H

#include <systemc.h>

class Mux5 : public sc_module
{
public:
	sc_in<bool> sIn;
	sc_in<sc_int<32>> aIn, bIn;
	sc_out<sc_int<32>> cOut;

	SC_CTOR(Mux5);
private:
	void operation();
};

#endif