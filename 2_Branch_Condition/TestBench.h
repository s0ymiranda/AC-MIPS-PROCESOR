#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>
#include <systemc.h>

class TestBench : public sc_module{
    
    public:

	    sc_in_clk clk;

	    sc_out<sc_int<32>> s1Out;
        sc_out<sc_int<32>> s2Out;
		sc_out<sc_uint<5>> instrucOut;  

	    sc_in<bool> resultIn;

	    SC_CTOR(TestBench);

    private:
	    void print();
	    void test();
};

#endif