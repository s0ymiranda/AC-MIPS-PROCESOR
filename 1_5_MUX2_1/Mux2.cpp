#include "Mux2.h"

Mux2::Mux2(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(operation);
  sensitive << s0In << d0In << d1In;
  dont_initialize();
}

void Mux2::operation() {
  const bool s0 = s0In.read();
  const bool d0 = d0In.read();
  const bool d1 = d1In.read();
  if (s0 == false) {
    fOut.write(d0);
  } else {
    fOut.write(d1);
  }
}

Mux2::~Mux2() {}