#include "TestBench.h"
#include <iomanip>
using namespace std;

TestBench :: TestBench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(process);
  sensitive << clk;
  dont_initialize();
}

void TestBench :: print() {

  cout << sc_time_stamp();
  cout << "        " << value_1Out.read();
  cout << "            " << value_2Out.read();
  cout << "             " << resultIn.read();
  cout << "\n";
}


void TestBench :: process() {
  cout << "Time    value_1Out    value_2Out    resultIn\n";
  cout << "--------------------------------------------\n";
  
  for (int i = 0; i < 17; i++) {

    instructOut.write(i);
    value_1Out.write(i);
    value_2Out.write(i+1);
    wait();
    wait();
    print();    

    cout << "-------------------------------------------\n";
  }
  sc_stop();
}