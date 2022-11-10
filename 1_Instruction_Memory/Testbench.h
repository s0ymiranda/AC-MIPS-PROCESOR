#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>
#include <systemc.h>

class Testbench : public sc_module{
public:
	sc_in_clk clk;

	sc_out<sc_int<32>> instructionNumberOut;
	sc_in<sc_uint<32>> operationIn;

	SC_CTOR(Testbench);

private:
	sc_uint<5> operand1, operand2, instruction;
	sc_int<17> operand3;

	void
	print();
	void test();
};

#endif