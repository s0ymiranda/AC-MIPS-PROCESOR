#ifndef TESTBENCH_H_
#define TESTBENCH_H_

#include <systemc.h>

class TestBench : public sc_module {

    public:
        sc_in_clk clk;
        sc_out<sc_int<12>> IF_IDOut;
	    sc_in<sc_int<32>> ID_EXIn;         
            

        SC_CTOR(TestBench);

    private:
        void print();
        void test();
};

#endif // TESTBENCH_H_