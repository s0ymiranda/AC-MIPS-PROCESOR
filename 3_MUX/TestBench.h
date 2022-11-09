#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>

class TestBench : public sc_module {
  public:
    
    
	sc_in<bool> clkIn;
    sc_in<sc_int<32>> valueIn;
    sc_out<sc_int<32>> value_1Out, value_2Out, value_3Out;
	sc_out<bool> aOut, bOut;

  	SC_CTOR(TestBench);

  private:
	  void print();
	  void test();
};

#endif // TESTBENCH_H