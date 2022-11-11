#ifndef DIVIDER_H
#define DIVIDER_H

#include <systemc.h>

class divider : public sc_module{
public:
	sc_in<sc_uint<5>> InstrucIn;
	sc_out<bool> InstrucIn_3{"ins3"};
	sc_out<bool> InstrucIn_4{"ins4"};
	sc_out<bool> InstrucIn_0{"ins0"};
	sc_out<bool> InstrucIn_1{"ins1"};
	sc_out<bool> InstrucIn_2{"ins2"};

	SC_CTOR(divider);
	~divider();
private:
	void process();

};
#endif