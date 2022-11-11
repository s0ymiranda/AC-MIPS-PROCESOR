#include "TestBench.h"

TestBench::TestBench(sc_module_name moduleName) : sc_module(moduleName) {
  SC_THREAD(test);
  dont_initialize();
  sensitive << clk.pos();
}

void TestBench::test() {
  cout << "Starting TestBench::test() Compuerta Not" << endl;
  
  cout << "a\tb\t" << endl;

  aOut.write(true);
  

  wait();
  printValues();


  aOut.write(false);
  
  wait();
  printValues();

  sc_stop();
}

void TestBench::printValues() {
  cout << aOut.read() << "\t" << bIn.read()  << endl;
}