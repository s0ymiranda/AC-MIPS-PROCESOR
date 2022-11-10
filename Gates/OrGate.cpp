#include "OrGate.h"

OrGate::OrGate(sc_module_name moduleName) : sc_module(moduleName), aIn("aIn"), bIn("bIn"), cOut("cOut") {
  SC_METHOD(process);
  dont_initialize();
  sensitive << aIn << bIn;
}

void OrGate::process() {
  cOut.write(aIn.read() or bIn.read());
}