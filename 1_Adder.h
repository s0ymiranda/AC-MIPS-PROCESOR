#ifndef ADDER_H
#define ADDER_H

#include <systemc.h>

class Adder1 : public sc_module{

    public:
    
	    sc_in<sc_int<32>> aIn;
	    sc_out<sc_int<32>> resultOut;

	    SC_CTOR(Adder1);

    private:
	    void operation();
};

#endif
