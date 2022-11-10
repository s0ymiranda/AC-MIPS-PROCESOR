#ifndef XNOR_GATE_H
#define XNOR_GATE_H

#include <systemc.h>

class XnorGate : public sc_module {
  public:
    sc_in<bool> aIn, bIn;
    sc_out<bool> cOut;

    SC_CTOR(XnorGate);
  
  private:
    void process();

};

#endif // AND_GATE_H