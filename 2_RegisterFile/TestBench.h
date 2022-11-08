#ifndef TESTBENCH_H_
#define TESTBENCH_H_

#include <systemc.h>

class TestBench : public sc_module {
  public:
    sc_out<sc_uint<5>> rdOut;      //register destination
    sc_out<sc_uint<5>> rs1Out;     //register source 1
    sc_out<sc_uint<5>> rs2Out;     //register source 2
    sc_in_clk clk;
    sc_out<sc_int<32>> rOut;      //result
    sc_out<bool> weOut;            //Write enable
    sc_in<sc_int<32>> s1In;     // Variable dentro del rs1
    sc_in<sc_int<32>> s2In;     // Variable dentro del rs2

    SC_CTOR(TestBench);

  private:
    void print();
    void test();
};

#endif // TESTBENCH_H_