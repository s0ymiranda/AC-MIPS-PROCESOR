#ifndef UNIDAD_CONTROL
#define UNIDAD_CONTROL

#include <systemc.h>

class Control_Unit: public sc_module
{
public:
	sc_out<sc_uint<5>> Ex_ALUOut;
	sc_out<bool> Mem_MemWriteOut, Mem_MemReadOut;
	sc_out<bool> Wb_MemtoRegOut, Wb_RegWriteOut;
    sc_out<bool> IDIFflushOut;
	sc_out<bool> muxPcsrOut;

	sc_in<sc_uint<5>> InstrucIn;
	sc_in<bool> BranchConditionIn;
	SC_CTOR(Control_Unit);

private:
	void operation();
};

#endif