#ifndef NOT_GATE_H
#define NOT_GATE_H

#include <systemc.h>

class NotGate : public sc_module {
  public:
    sc_in<bool> aIn;
    sc_out<bool> bOut;

    SC_CTOR(NotGate);
    
  private:
    void process();

};

#endif // AND_GATE_H