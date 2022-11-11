#ifndef TESTBENCH_H_
#define TESTBENCH_H_

#include <systemc.h>

class TestBench : public sc_module {
  public:
    sc_in_clk clk;
	sc_in<sc_uint<5>> Ex_ALUIn;
	sc_in<bool> Mem_MemWriteIn, Mem_MemReadIn;
	sc_in<bool> Wb_MemtoRegIn, Wb_RegWriteIn;
  sc_in<bool> IDIFflushIn;
	sc_in<bool> muxPcsrIn;


	sc_out<sc_uint<5>> InstrucOut;
  sc_out<bool> BranchConditionOut;


    SC_CTOR(TestBench);

  private:
    void print();
    void test();
};

#endif // TESTBENCH_H_