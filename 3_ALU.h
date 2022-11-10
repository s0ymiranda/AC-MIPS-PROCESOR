#ifndef ALU_H
#define ALU_H

#include <systemc.h>

class ALU : public sc_module
{

public:

	sc_in_clk clk;
	sc_in<sc_uint<5>> instructIn;
	sc_in<sc_int<32>> value_1In, value_2In;
	sc_out<sc_int<32>> resultOut;

	SC_CTOR(ALU);

private:
	void process();
};

#endif