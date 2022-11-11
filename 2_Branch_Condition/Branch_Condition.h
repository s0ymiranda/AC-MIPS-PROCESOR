#ifndef IF_ID_H
#define IF_ID_H

#include <systemc.h>

class Branch_Condition : public sc_module
{

public:
	
	// como la condicion para branch se evalua en este modelo es en la etapa id, se crea este modulo para enviar la senial a la unidad de control y esta envie las respectivas seniales de Fflush y al mux de la etapa if
    sc_in<sc_int<32>> s1In;     
    sc_in<sc_int<32>> s2In; 
    sc_in<sc_uint<5>> instrucIn;   
   
    sc_out<bool> resultOut;

	SC_CTOR(Branch_Condition);

private:
	void operation();
};

#endif
