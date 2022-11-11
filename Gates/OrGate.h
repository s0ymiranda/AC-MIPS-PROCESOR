#ifndef ORGATE_H
#define ORGATE_H

#include <systemc.h>


class OrGate : public sc_module {
public:
  sc_in<bool> aIn, bIn;
  sc_out<bool> cOut;

  SC_CTOR(OrGate);

private:
  void operation();
};

#endif