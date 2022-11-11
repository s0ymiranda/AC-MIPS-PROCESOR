#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>
#include <systemc.h>


class TestBench : public sc_module {

public:

  sc_in<sc_int<32>> resultIn;
  sc_out<sc_int<32>>  value_1Out, value_2Out;
  sc_out<sc_uint<5>>  instructOut;
  sc_in<bool> clk;

  SC_CTOR(TestBench);

private:

  void print();
  void process();
};

#endif