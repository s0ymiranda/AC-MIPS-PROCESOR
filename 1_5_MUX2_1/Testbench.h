#ifndef TESTBENCH_H_
#define TESTBENCH_H_

#include <systemc.h>

class Testbench : public sc_module {
  public:
	  sc_in<bool> clkIn;
    sc_in<bool> fIn;
	  sc_out<bool> s0Out, d0Out, d1Out;

  	SC_CTOR(Testbench);

  private:
	  void print();
	  void test();
};

#endif 