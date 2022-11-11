#ifndef IF_ID_H
#define IF_ID_H

#include <systemc.h>

class IF_ID : public sc_module
{

public:
	sc_in_clk clk;

	sc_in<sc_int<32>> pcIn;
	sc_in<sc_uint<32>> insMemIn;
    sc_in<bool> hazardIn;
   	sc_in<bool> controlFlushIn;  

	sc_out<sc_uint<5>> fileRegister1Out;
	sc_out<sc_uint<5>> fileRegister2Out;
	sc_out<sc_int<12>> immGenOut;
	sc_out<sc_int<32>> ID_EX0Out;
	sc_out<sc_uint<5>> ID_EX1Out;
	sc_out<sc_uint<5>> ID_EX2Out;
	sc_out<sc_uint<5>> ID_EX3Out;
	sc_out<sc_uint<5>> ID_unidadControlOut;
	sc_out<sc_uint<5>> ID_HDUrs1Out;
  	sc_out<sc_uint<5>> ID_HDUrs2Out;

	SC_CTOR(IF_ID);

private:
	void operation();
};

#endif
