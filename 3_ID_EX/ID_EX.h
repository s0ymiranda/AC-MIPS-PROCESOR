#ifndef ID_EX_H
#define ID_EX_H

#include <systemc.h>

class id_ex : public sc_module
{
public:
	sc_in_clk clkIn;

    sc_in<sc_int<32>> rs1In, rs2In, imm_genIn;
    sc_in<sc_uint<5>> rs1_registerIn, rs2_registerIn, target_registerIn;

    sc_out<sc_int<32>> rs1Out, rs2Out;
    sc_out<sc_uint<5>> rs1_registerOut, rs2_registerOut, target_registerOut;
    

	SC_CTOR(id_ex);

private:
	void process();
};

#endif