#include "AndGate.h"

AndGate::AndGate(sc_module_name moduleName) : sc_module(moduleName), aIn("aIn"), bIn("bIn"), cOut("cOut") {
  SC_METHOD(process);
  dont_initialize();
  sensitive << aIn << bIn;
}

void AndGate::process() {
  cOut.write(aIn.read() and bIn.read());
}