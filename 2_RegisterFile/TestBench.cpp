#include "TestBench.h"
#include <iostream>

TestBench::TestBench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clk;
  //testbench sensible a reloj
  dont_initialize();
}

void TestBench::print() {
  std::cout << sc_time_stamp() ;
  std::cout << rdOut.read() << "    ";
  std::cout << rs1Out.read() << "    ";
  std::cout << rs2Out.read() << "     ";
  std::cout << s1In.read() << "    ";
  std::cout << s2In.read() << "     ";
  std::cout << rOut.read() << "\n";
}

void TestBench::test() {
  std::cout << "------------File Register TestBench-------------\n" ; 
  std::cout << "     rd   rs1  rs2   s1   s2    r     \n";
  print();

  //recorrido para llenar todos los valores posibles para las dos entradas
  rdOut.write(3);
  rs1Out.write(5);
  rs2Out.write(3);
  weOut.write(1);
  rOut.write(7);
  
  wait();
  wait();
  wait();
  wait();

  print();

  rs1Out.write(3);
  rs2Out.write(3);
  wait();
  wait();
  wait();
 
  print();


  sc_stop();
}