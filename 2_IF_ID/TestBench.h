#ifndef TESTBENCH_H_
#define TESTBENCH_H_

#include <systemc.h>

class TestBench : public sc_module {
  public:
    sc_in_clk clk;
    sc_out<sc_int<32>> pcOut;      
    sc_out<sc_uint<32>> insMemOut;
    sc_out<bool> hazzardOut;

	sc_in<sc_uint<5>> fileRegister1In;
	sc_in<sc_uint<5>> fileRegister2In;
	sc_in<sc_int<12>> immGenIn;
	sc_in<sc_int<32>> ID_EX0In;
	sc_in<sc_uint<5>> ID_EX1In;
	sc_in<sc_uint<5>> ID_EX2In;
	sc_in<sc_uint<5>> ID_EX3In;
	sc_in<sc_uint<5>> ID_unidadControlIn;
	sc_in<sc_uint<5>> ID_unidadHazzardIn;

    SC_CTOR(TestBench);

  private:
    void print();
    void test();
};

#endif // TESTBENCH_H_