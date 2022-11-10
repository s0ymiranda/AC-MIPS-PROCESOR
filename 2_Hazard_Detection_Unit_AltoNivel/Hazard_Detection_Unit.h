#ifndef ADDER_H
#define ADDER_H

#include <systemc.h>
#include "AndGate.h"
#include "AndGate5.h"
#include "OrGate.h"

class Hazard_Detection_Unit : public sc_module{

    public:
        sc_in_clk clk;
	    sc_in<sc_uint<5>> IDEXInstrucIn;
	    sc_in<sc_uint<5>> rs1In;
        sc_in<sc_uint<5>> rs2In;
        sc_in<sc_uint<5>> IDEXrdIn;

        

        sc_out<bool> pcwriteOut;
        sc_out<bool> IFIDwriteOut;
        sc_out<bool> muxControlOut;

	    SC_CTOR(Hazard_Detection_Unit);

    private:

        sc_vector<AndGate> SC_NAMED(and2,16);
        sc_vector<sc_signal<bool>> SC_NAMED(aSg,15);
        sc_vector<sc_signal<bool>> SC_NAMED(bSg,15);
        sc_vector<sc_signal<bool>> SC_NAMED(cSg,15);
        sc_vector<sc_out<bool>> SC_NAMED(aAuxOut,15);
        sc_vector<sc_out<bool>> SC_NAMED(bAuxOut,15);

        sc_vector<AndGate5> SC_NAMED(and5,3);
        sc_vector<sc_signal<bool>> SC_NAMED(andSg, 3);
        
        sc_vector<OrGate> SC_NAMED(or2,1);
        sc_vector<sc_signal<bool>> SC_NAMED(orSg,2);

       

        sc_uint<5> LwInstruc;

	    void operation();
};

#endif