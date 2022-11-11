#ifndef UNIDAD_CONTROL
#define UNIDAD_CONTROL

#include <systemc.h>
#include "AndGate5.h"
#include "AndGate.h"
#include "OrGate.h"

class Control_Unit: public sc_module
{
public:
	sc_out<sc_uint<5>> Ex_ALUOut;
	sc_in_clk clk;
	sc_out<bool> Mem_MemWriteOut, Mem_MemReadOut;
	sc_out<bool> Wb_MemtoRegOut, Wb_RegWriteOut;
    sc_out<bool> IDIFflushOut;
	sc_out<bool> muxPcsrOut;

	sc_in<sc_uint<5>> InstrucIn;
	sc_in<bool> BranchConditionIn;
	SC_CTOR(Control_Unit);

private:

	sc_vector<AndGate5> SC_NAMED(and5,17);
	sc_vector<sc_signal<bool>> SC_NAMED(aInSg, 17);
	sc_vector<sc_signal<bool>> SC_NAMED(bInSg, 17);
	sc_vector<sc_signal<bool>> SC_NAMED(cInSg, 17);
	sc_vector<sc_signal<bool>> SC_NAMED(dInSg, 17);
	sc_vector<sc_signal<bool>> SC_NAMED(eInSg, 17);
	sc_vector<sc_signal<bool>> SC_NAMED(fOutSg, 17);
	sc_vector<sc_out<bool>> SC_NAMED(aux, 85);

	sc_vector<OrGate> SC_NAMED(or_gate, 11);
	sc_vector<sc_signal<bool>> SC_NAMED(orCOut, 11);

	//sc_vector<sc_signal<bool>> SC_NAMED(notBOut, 52);

	AndGate *and2;
	sc_signal<bool> aSg, bSg, cSg;
	sc_out<bool> BranchC, Uno;

	void operation();
};

#endif