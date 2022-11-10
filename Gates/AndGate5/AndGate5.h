#ifndef ANDGATE_H
#define ANDGATE_H

#include <systemc.h>


class AndGate5 : public sc_module {
public:
  sc_in<bool> aIn, bIn, cIn, dIn, eIn;
  sc_out<bool> fOut;

  SC_CTOR(AndGate5);

private:
  void operation();
};

#endif