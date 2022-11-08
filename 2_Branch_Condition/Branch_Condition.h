#ifndef IF_ID_H
#define IF_ID_H

#include <systemc.h>

class Branch_Condition : public sc_module
{

public:
	

    sc_in<sc_int<32>> s1In;     
    sc_in<sc_int<32>> s2In;    
   
    sc_out<sc_uint<2>> resultOut;

	SC_CTOR(Branch_Condition);

private:
	void operation();
};

#endif