#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>

class TestBench : public sc_module {
  public:

	sc_in<bool> clkIn;

	sc_out<sc_uint<5>> rs1_registerOut, rs2_registerOut, mem_wb_registerOut, ex_mem_registerOut;
    sc_out<bool> mux1Out, mux2Out;
	sc_in<bool> mux1_aIn, mux1_bIn, mux2_aIn, mux2_bIn;

  	SC_CTOR(TestBench);

  private:
	  void print();
	  void test();
};

#endif // TESTBENCH_H