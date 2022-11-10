#ifndef TESTBENCH_H
#define TESTBENCH_H
#include <iostream>
#include <systemc.h>

class Testbench : public sc_module{
    public:

    sc_in<bool> clkIn;

    //Entradas señales de control
    sc_in<bool> Mem_MemWriteOut, Mem_MemReadOut;
    sc_in<bool> Wb_MemtoRegOut, Wb_RegWriteOut;

    //Salidas señales de control
    sc_out<bool> Mem_MemWriteIn, Mem_MemReadIn;
    sc_out<bool> Wb_MemtoRegIn, Wb_RegWriteIn;

    sc_out<sc_int<32>> memo_In[2];
    sc_in<sc_int<32>> memo_Out[3];

    sc_out<sc_uint<5>> dir_In_;
    sc_in<sc_uint<5>> dir_Out;

    SC_CTOR(Testbench);
    private:
        void print();
        void test();
};

#endif