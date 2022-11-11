#include "NotGate.h"

NotGate::NotGate(sc_module_name moduleName) : sc_module(moduleName), aIn("aIn"), bOut("bOut"){
  SC_METHOD(process);
  dont_initialize();
  sensitive << aIn;
}

void NotGate::process() {
  bOut.write(not(aIn.read()));
}