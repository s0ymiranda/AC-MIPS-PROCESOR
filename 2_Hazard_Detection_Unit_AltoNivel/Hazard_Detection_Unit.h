#ifndef ADDER_H
#define ADDER_H

#include <systemc.h>

class Hazard_Detection_Unit : public sc_module{

    public:
        //sc_in_clk clk;
	    sc_in<sc_uint<5>> IDEXInstrucIn;
	    sc_in<sc_uint<5>> rs1In;
        sc_in<sc_uint<5>> rs2In;
        sc_in<sc_uint<5>> IDEXrdIn;

        sc_out<bool> pcwriteOut;
        sc_out<bool> IFIDwriteOut;
        sc_out<bool> muxControlOut;

	    SC_CTOR(Hazard_Detection_Unit);

    private:
	    void operation();
};

#endif