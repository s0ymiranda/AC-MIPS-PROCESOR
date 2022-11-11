#include <systemc.h>

#include "NotGate.h"
#include "TestBench.h"

int sc_main(int argc, char *argv[]) {
  sc_signal<bool> a, b, c;

  const sc_time period(10, SC_NS);

  sc_clock clock("clock", period);

  NotGate notGate("notGate");
  TestBench testBench("testBench");

  notGate.aIn(a);
  testBench.aOut(a);

  notGate.bOut(b);
  testBench.bIn(b);

  testBench.clk(clock);

  sc_start();
  return 0;
}