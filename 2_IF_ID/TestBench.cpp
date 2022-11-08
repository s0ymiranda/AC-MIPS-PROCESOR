#include "TestBench.h"
#include <iostream>

TestBench::TestBench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clk;
  //testbench sensible a reloj
  dont_initialize();
}

void TestBench::print() {

    std::cout <<"\n\n\nPc: " << pcOut.read();
    std::cout << "\nID_EX0: " << ID_EX0In.read();
    std::cout << "\nHazzardOut " << hazzardOut.read();
    std::cout << "\nRs1: " << fileRegister1In.read();
    std::cout << "\nRs2: " << fileRegister2In.read();
    std::cout << "\nimmGen: " << immGenIn.read();
    std::cout << "\nID_EX1: " << ID_EX1In.read();
    std::cout << "\nID_EX2: " << ID_EX2In.read();
    std::cout << "\nID_EX3(Rd): " << ID_EX3In.read();
    std::cout << "\nID_unidadControl: " << ID_unidadControlIn.read();
    std::cout << "\nID_unidadHazzard: " << ID_unidadHazzardIn.read() << "\n";
    for( int i = 31; i>=0 ; i--)
    std::cout << insMemOut.read()[i];
}

void TestBench::test() {
 

    pcOut.write(0);
    hazzardOut.write(0);
    insMemOut.write(54546166);
    wait();
    wait();
    print();

    pcOut.write(1);
    
    insMemOut.write(548452);    
    hazzardOut.write(1);
    wait();
    wait();
    print();
    
    pcOut.write(1);
    
    insMemOut.write(15485620);
    hazzardOut.write(0);
    wait();
    wait();
    print();

    pcOut.write(2);
    hazzardOut.write(0);

    insMemOut.write(2);
    wait();
    wait();
    print();

    pcOut.write(3);
    hazzardOut.write(0);

    insMemOut.write(48454465);
    wait();
    wait();
    print();

    sc_stop();

}