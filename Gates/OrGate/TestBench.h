#ifndef TEST_BENCH_H
#define TEST_BENCH_H

#include <systemc.h>

class TestBench : public sc_module {
  public:
    sc_out<bool> aOut, bOut;
    sc_in<bool> cIn;
    sc_in_clk clk;

    SC_CTOR(TestBench);

  private:
    void test();

    void printValues();
};

#endif // TEST_BENCH_H