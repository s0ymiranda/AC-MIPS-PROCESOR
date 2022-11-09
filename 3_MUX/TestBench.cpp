#include "TestBench.h"
#include <iostream>
using namespace std;

TestBench :: TestBench(sc_module_name moduleName) : sc_module(moduleName) {
  SC_THREAD(test);
  sensitive << clkIn.pos();
  dont_initialize();
}

void TestBench :: print() {
 cout << sc_time_stamp() << "       ";
 cout << value_1Out.read() << "          ";
 cout << value_2Out.read() << "           ";
 cout << value_3Out.read() << "       ";
 cout << aOut.read() << "       ";
 cout << bOut.read() << "       ";
 cout << valueIn.read() << "\n";
}


void TestBench :: test() {
  cout << "Time   value_1In   value_2In   value_3In   aIn   bIn   valueOut\n";
  cout << "---------------------------------------------------------------\n";

    value_1Out.write(1);
    value_2Out.write(2);
    value_3Out.write(3);

    aOut.write(false);
    bOut.write(false);
    wait();
    print();

    aOut.write(true);
    bOut.write(false);
    wait();
    print();

    aOut.write(false);
    bOut.write(true);
    wait();
    print();

  sc_stop();
}