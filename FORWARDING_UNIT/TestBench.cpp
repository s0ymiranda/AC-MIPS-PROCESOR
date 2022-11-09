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
 cout << rs1_registerOut.read() << "                 ";
 cout << rs2_registerOut.read() << "                  ";
 cout << mem_wb_registerOut.read() << "                   ";
 cout << ex_mem_registerOut.read() << "             ";
 cout << mux1Out.read() << "        ";
 cout << mux2Out.read() << "         ";
 cout << mux1_aIn.read() << "         ";
 cout << mux1_bIn.read() << "         ";
 cout << mux2_aIn.read() << "        ";
 cout << mux2_bIn.read() << "\n";
}


void TestBench :: test() {
  cout << "Time  rs1_registerOut  rs2_registerOut  mem_wb_registerOut  ex_mem_registerOut  mux1Out  mux2Out  mux1_aIn  mux1_bIn  mux2_aIn  mux2_bIn\n";
  cout << "----------------------------------------------------------------------------------------------------------------------------------------\n";

    rs1_registerOut.write(0);
    rs2_registerOut.write(0);
    mem_wb_registerOut.write(0);
    ex_mem_registerOut.write(1);
    mux1Out.write(0);
    mux2Out.write(0);
    wait();
    print();

    rs1_registerOut.write(0);
    rs2_registerOut.write(0);
    mem_wb_registerOut.write(0);
    ex_mem_registerOut.write(1);
    mux1Out.write(1);
    mux2Out.write(1);
    wait();
    print();

    rs1_registerOut.write(1);
    rs2_registerOut.write(1);
    mem_wb_registerOut.write(0);
    ex_mem_registerOut.write(1);
    mux1Out.write(0);
    mux2Out.write(0);
    wait();
    print();

    rs1_registerOut.write(1);
    rs2_registerOut.write(1);
    mem_wb_registerOut.write(0);
    ex_mem_registerOut.write(1);
    mux1Out.write(1);
    mux2Out.write(1);
    wait();
    print();

  sc_stop();
}