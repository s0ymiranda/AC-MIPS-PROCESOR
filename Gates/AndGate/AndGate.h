#ifndef AND_GATE_H
#define AND_GATE_H

#include <systemc.h>

class AndGate : public sc_module {
  public:
    sc_in<bool> aIn, bIn;
    sc_out<bool> cOut;

    SC_CTOR(AndGate);
    
  private:
    void process();

};

#endif // AND_GATE_H