#ifndef ANDGATE_H
#define ANDGATE_H

#include <systemc.h>


class AndGate : public sc_module {
public:
  sc_in<bool> aIn, bIn;
  sc_out<bool> cOut;

  SC_CTOR(AndGate);

private:
  void operation();
};

#endif