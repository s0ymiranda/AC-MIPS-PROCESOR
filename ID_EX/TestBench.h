#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>

#include <systemc.h>


class TestBench : public sc_module {

public:

    sc_in_clk clkIn;

    sc_out<sc_int<32>> rs1Out, rs2Out, imm_genOut;
    sc_out<sc_uint<5>> rs1_registerOut, rs2_registerOut, target_registerOut;

    sc_in<sc_int<32>> rs1In, rs2In;
    sc_in<sc_uint<5>> rs1_registerIn, rs2_registerIn, target_registerIn;

    SC_CTOR(TestBench);

private:

  void print();
  void test();
};

#endif