#include "TestBench.h"

TestBench::TestBench(sc_module_name moduleName) : sc_module(moduleName) {
  SC_THREAD(test);
  dont_initialize();
  sensitive << clk.pos();
}

void TestBench::test() {
  cout << "Starting TestBench::test()" << endl;

  cout << "a\tb\tc\td\te\tf" << endl;

  aOut.write(true);
  bOut.write(true);
  cOut.write(true);
  dOut.write(true);
  eOut.write(true);

  wait();
  printValues();

  aOut.write(true);
  bOut.write(false);
  cOut.write(true);
  dOut.write(true);
  eOut.write(true);

  wait();
  printValues();


  aOut.write(true);
  bOut.write(true);
  cOut.write(false);
  dOut.write(false);
  eOut.write(true);

  wait();
  printValues();
  
  aOut.write(false);
  bOut.write(false);
  cOut.write(false);
  dOut.write(false);
  eOut.write(false);

  wait();
  printValues();
  sc_stop();
}

void TestBench::printValues() {
  cout << aOut.read() << "\t" << bOut.read() << "\t" << cOut.read() << "\t" << dOut.read() << "\t" << eOut.read() <<"\t" <<fIn.read() << endl;
}
