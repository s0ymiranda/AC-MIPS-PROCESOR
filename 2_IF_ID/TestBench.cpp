#include "TestBench.h"
#include <iostream>

TestBench::TestBench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clk;
  //testbench sensible a reloj
  dont_initialize();
}

void TestBench::print() {
    std::cout << "\n\n\n FFLUSH: " << controlFlushOut.read();
    std::cout <<"\nPc: " << pcOut.read();
    std::cout << "\nID_EX0: " << ID_EX0In.read();
    std::cout << "\nHazardOut " << hazardOut.read();
    std::cout << "\nRs1: " << fileRegister1In.read();
    std::cout << "\nRs2: " << fileRegister2In.read();
    std::cout << "\nimmGen: " << immGenIn.read();
    std::cout << "\nID_EX1: " << ID_EX1In.read();
    std::cout << "\nID_EX2: " << ID_EX2In.read();
    std::cout << "\nID_EX3(Rd): " << ID_EX3In.read();
    std::cout << "\nID_unidadControl: " << ID_unidadControlIn.read();
    std::cout << "\nID_HDUrs1: " << ID_HDUrs1In.read();
    std::cout << "\nID_HDUrs2: " << ID_HDUrs2In.read() << "\n";

}

void TestBench::test() {
 

    pcOut.write(0);
    hazardOut.write(0);
    controlFlushOut.write(1);
    insMemOut.write(54546166);
    wait();
    wait();
    print();

    pcOut.write(0);
    controlFlushOut.write(0);
    insMemOut.write(548452);    
    hazardOut.write(0);
    wait();
    wait();
    print();
    
    pcOut.write(1);
    controlFlushOut.write(0);
    insMemOut.write(15620);
    hazardOut.write(0);
    wait();
    wait();
    print();

    pcOut.write(1);
    hazardOut.write(1);
    controlFlushOut.write(0);
    insMemOut.write(2);
    wait();
    wait();
    print();

    pcOut.write(2);
    hazardOut.write(0);
    controlFlushOut.write(0);
    insMemOut.write(48454465);
    wait();
    wait();
    print();

    sc_stop();

}