#ifndef IF_ID_H
#define IF_ID_H

#include <systemc.h>

class Branch_Condition : public sc_module
{

public:
	

    sc_in<sc_int<32>> s1In;     
    sc_in<sc_int<32>> s2In; 
    sc_in<sc_uint<5>> instrucIn;   
   
    sc_out<bool> resultOut;

	SC_CTOR(Branch_Condition);

private:
	void operation();
};

#endif