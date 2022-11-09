#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>
#include <systemc.h>

class TestBench : public sc_module{
    
    public:

	    sc_in_clk clk;

	    sc_out<sc_uint<5>> IDEXInstrucOut;
	    sc_out<sc_uint<5>> rs1Out;
        sc_out<sc_uint<5>> rs2Out;
        sc_out<sc_uint<5>> IDEXrdOut;

        sc_in<bool> pcwriteIn;
        sc_in<bool> IFIDwriteIn;
        sc_in<bool> muxControlIn;

	    SC_CTOR(TestBench);

    private:
	    void print();
	    void test();
};

#endif