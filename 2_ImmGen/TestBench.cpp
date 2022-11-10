#include "TestBench.h"
#include <iostream>

TestBench::TestBench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clk;
  
  dont_initialize();
}

void TestBench::print(){
  std::cout << "\n\n IF/ID OUT: ";
  for(int i = 11 ; i >= 0 ; i-- )
    std::cout << IF_IDOut.read()[i];

  std::cout << "\n ID/EX  IN: ";
  for(int i = 31 ; i >= 0 ; i--)
    std::cout << ID_EXIn.read()[i];

  std::cout << "\n Adder  IN: ";
  for(int i = 31 ; i >= 0 ; i--)
    std::cout << AdderIn.read()[i];

}
void TestBench::test() {
    
    print();
    IF_IDOut.write(5); //escribiendo un valor de prueba 

    wait();
    wait();
    wait();
    wait();

    print();

  sc_stop();
}