#include <systemc.h>

#include "AndGate.h"
#include "TestBench.h"

int sc_main(int argc, char *argv[]) {
  sc_signal<bool> a, b, c;

  const sc_time period(10, SC_NS);

  sc_clock clock("clock", period);

  AndGate andGate("andGate");
  TestBench testBench("testBench");

  andGate.aIn(a);
  testBench.aOut(a);

  andGate.bIn(b);
  testBench.bOut(b);

  andGate.cOut(c);
  testBench.cIn(c);

  testBench.clk(clock);

  sc_start();
  return 0;
}