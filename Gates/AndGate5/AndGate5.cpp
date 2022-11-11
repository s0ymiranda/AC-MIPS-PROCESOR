#include "AndGate5.h"


AndGate5::AndGate5(sc_module_name mn) : sc_module(mn) {
  SC_METHOD(operation);
  sensitive << aIn << bIn << cIn << dIn << eIn;
}

void AndGate5::operation() {
  fOut.write(aIn.read() and bIn.read() and cIn.read() and dIn.read() and eIn.read() );
}