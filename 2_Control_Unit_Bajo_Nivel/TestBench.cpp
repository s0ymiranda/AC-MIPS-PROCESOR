#include "TestBench.h"
#include <iostream>

TestBench::TestBench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clk;
  //testbench sensible a reloj
  dont_initialize();
}

void TestBench::print() {
    std::cout <<"\n\n\nInstrucOut: " << InstrucOut.read();
    std::cout <<"\nEx_ALUIn: " << Ex_ALUIn.read();
    std::cout << "\nMem_MemWriteOut: " << Mem_MemWriteIn.read();
    std::cout << "\nMem_MemReadOut: " << Mem_MemReadIn.read();
    std::cout << "\nWb_MemtoRegOut: " << Wb_MemtoRegIn.read();
    std::cout << "\nWb_RegWriteOut: " << Wb_RegWriteIn.read();
    std::cout << "\nBranchConditionOut: " << BranchConditionOut.read();    
    std::cout << "\nIDIFflushIn: " << IDIFflushIn.read();
    std::cout << "\nmuxPcsrIn: " << muxPcsrIn.read();

}

void TestBench::test() {
 
    BranchConditionOut.write(1);
    InstrucOut.write(10);
    wait();
    wait();
    print();

    BranchConditionOut.write(0);
    InstrucOut.write(0);
    wait();
    wait();
    print();

    BranchConditionOut.write(0);
    InstrucOut.write(14);
    wait();
    wait();
    print();
  
    BranchConditionOut.write(1);
    InstrucOut.write(2);
    wait();
    wait();
    print();

    BranchConditionOut.write(0);
    InstrucOut.write(9);
    wait();
    wait();
    print();


    sc_stop();

}