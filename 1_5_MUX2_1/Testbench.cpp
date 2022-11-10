#include "Testbench.h"
#include <iostream>

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn.pos();
  dont_initialize();
}

void Testbench::print() {
  std::cout << sc_time_stamp() << "    ";
  std::cout << d0Out.read() << "    ";
  std::cout << d1Out.read() << "    ";
  std::cout << s0Out.read() << "    ";
  std::cout << fIn.read() << "\n";
}

void Testbench::test() {
  std::cout << "Tiempo   d0   d1   s0   f\n";
  std::cout << "-------------------------\n";

  for (int i = 0; i < 2; ++i) {
    d0Out.write(i);
    for (int j = 0; j < 2; ++j) {
      d1Out.write(j);
      for (int k = 0; k < 2; ++k) {
        s0Out.write(k);
        wait();
        print();
      }
      std::cout << "-------------------------\n";
    }
  }
  sc_stop();
}