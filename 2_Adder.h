#ifndef ADDER2_H
#define ADDER2_H

#include <systemc.h>

class Adder : public sc_module{

    public:
	    sc_in<sc_int<32>> aIn, bIn;
	    sc_out<sc_int<32>> resultOut;

	    SC_CTOR(Adder);

    private:
	    void operation();
};

#endif
