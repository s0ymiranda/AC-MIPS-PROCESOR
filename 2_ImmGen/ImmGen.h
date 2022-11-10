#ifndef IMM_GEN_H
#define IMM_GEN_H

#include <systemc.h>

class ImmGen : public sc_module{

    public:
        sc_in_clk clk;
	    sc_in<sc_int<12>> IF_IDIn;
	    sc_out<sc_int<32>> ID_EXOut, AdderOut;

	    SC_CTOR(ImmGen);

    private:
	    void operation();

};

#endif
