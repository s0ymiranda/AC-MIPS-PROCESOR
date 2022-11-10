#ifndef MUX_2_H_
#define MUX_2_H_

#include <systemc.h>

class Mux2: public sc_module {
  public:
    sc_in<bool> d0In, d1In, s0In;
    sc_out<bool> fOut;

    SC_CTOR(Mux2);
    ~Mux2();

  private:
    void operation();
};

#endif