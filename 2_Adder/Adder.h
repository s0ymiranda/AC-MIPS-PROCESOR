#ifndef ADDER_H
#define ADDER_H

#include <systemc.h>

class Adder : public sc_module{

    public:
    // Sumador de la etapa id, destinado a sumar el pc actual, con el valor de imm en caso de existir una branch
	    sc_in<sc_int<32>> aIn, bIn;
	    sc_out<sc_int<32>> resultOut;

	    SC_CTOR(Adder);

    private:
	    void operation();
};

#endif
