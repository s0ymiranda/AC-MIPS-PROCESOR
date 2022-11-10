#ifndef OR_GATE_H
#define OR_GATE_H

#include <systemc.h>

class OrGate : public sc_module {
  public:
    sc_in<bool> aIn, bIn;
    sc_out<bool> cOut;

    SC_CTOR(OrGate);
  
  private:
    void process();

};

#endif // AND_GATE_H
