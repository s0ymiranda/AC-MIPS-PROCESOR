#include <systemc.h>

#include "AndGate5.h"
#include "TestBench.h"

int sc_main(int argc, char *argv[]) {
  sc_signal<bool> a, b, c, d, e, f;

  const sc_time period(10, SC_NS);

  sc_clock clock("clock", period);

  AndGate5 andGate5("andGate5");
  TestBench testBench("testBench");

  andGate5.aIn(a);
  testBench.aOut(a);

  andGate5.bIn(b);
  testBench.bOut(b);

  andGate5.cIn(c);
  testBench.cOut(c);
  
  andGate5.dIn(d);
  testBench.dOut(d);

  andGate5.eIn(e);
  testBench.eOut(e);

  andGate5.fOut(f);
  testBench.fIn(f);

  testBench.clk(clock);

  sc_start();
  return 0;
}
