#include "TestBench.h"

TestBench::TestBench(sc_module_name moduleName) : sc_module(moduleName) {
  SC_THREAD(test);
  dont_initialize();
  sensitive << clk.pos();
}

void TestBench::test() {
  cout << "Starting TestBench::test() Compuerta Or" << endl;

  cout << "a\tb\tc" << endl;

  aOut.write(true);
  bOut.write(true);

  wait();
  printValues();


  aOut.write(false);
  bOut.write(true);

  wait();
  printValues();


  aOut.write(true);
  bOut.write(false);

  wait();
  printValues();


  aOut.write(false);
  bOut.write(false);

  wait();
  printValues();

  sc_stop();
}

void TestBench::printValues() {
  cout << aOut.read() << "\t" << bOut.read() << "\t" << cIn.read() << endl;
}