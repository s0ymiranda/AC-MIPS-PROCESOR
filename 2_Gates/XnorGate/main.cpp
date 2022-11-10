#include <systemc.h>

#include "XnorGate.h"
#include "TestBench.h"

int sc_main(int argc, char *argv[]) {
  sc_signal<bool> a, b, c;

  const sc_time period(10, SC_NS);

  sc_clock clock("clock", period);

  XnorGate xnorGate("xorGate");
  TestBench testBench("testBench");

  xnorGate.aIn(a);
  testBench.aOut(a);

  xnorGate.bIn(b);
  testBench.bOut(b);

  xnorGate.cOut(c);
  testBench.cIn(c);

  testBench.clk(clock);

  sc_start();
  return 0;
}