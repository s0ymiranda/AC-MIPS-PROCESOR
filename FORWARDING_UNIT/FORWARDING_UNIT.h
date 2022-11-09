#ifndef FORWARDING_UNIT_H
#define FORWARDING_UNIT_H

#include <systemc.h>

class F_Unit : public sc_module
{
public:

	sc_in<sc_uint<5>> rs1_registerIn, rs2_registerIn, mem_wb_registerIn, ex_mem_registerIn;
	sc_in<bool> mux1In, mux2In;
    sc_out<bool> mux1_aOut, mux1_bOut, mux2_aOut, mux2_bOut;
	

	SC_CTOR(F_Unit);

private:
	void process();
};

#endif