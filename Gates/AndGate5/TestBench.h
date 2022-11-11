#ifndef TEST_BENCH_H
#define TEST_BENCH_H

#include <systemc.h>

class TestBench : public sc_module {
  public:
    sc_out<bool> aOut, bOut , cOut, dOut,eOut;
    sc_in<bool> fIn;
    sc_in_clk clk;

    SC_CTOR(TestBench);

  private:
    void test();

    void printValues();
};

#endif // TEST_BENCH_H
