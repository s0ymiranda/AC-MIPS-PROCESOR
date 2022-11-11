#include <systemc.h>

#include "OrGate.h"
#include "TestBench.h"

int sc_main(int argc, char *argv[]) {
  sc_signal<bool> a, b, c;

  const sc_time period(10, SC_NS);

  sc_clock clock("clock", period);

  OrGate orGate("orGate");
  TestBench testBench("testBench");

  orGate.aIn(a);
  testBench.aOut(a);

  orGate.bIn(b);
  testBench.bOut(b);

  orGate.cOut(c);
  testBench.cIn(c);

  testBench.clk(clock);

  sc_start();
  return 0;
}