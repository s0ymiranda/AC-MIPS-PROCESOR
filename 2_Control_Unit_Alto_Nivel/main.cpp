#include "Control_Unit.h"
#include "TestBench.h"

int sc_main(int argc, char *argv[])
{
	sc_time period(10, SC_NS);
	sc_time delay(0, SC_NS);
	sc_clock clock("clock", period, 0.5, delay, true);

	Control_Unit cu("cu");
	TestBench tb("tb");


    sc_signal<bool> MemWriteSg, MemReadSg, WbtoRegSg, WbWriteSg,BranchConditionSg, muxPcSg, FlushSg ;
    sc_signal<sc_uint<5>> Instruc1Sg, Instruc2Sg;
    

    cu.Ex_ALUOut(Instruc1Sg);
    tb.Ex_ALUIn(Instruc1Sg);

    cu.BranchConditionIn(BranchConditionSg);
    tb.BranchConditionOut(BranchConditionSg);

    cu.IDIFflushOut(FlushSg);
    tb.IDIFflushIn(FlushSg);

    cu.muxPcsrOut(muxPcSg);
    tb.muxPcsrIn(muxPcSg);

    cu.Mem_MemWriteOut(MemWriteSg);
    tb.Mem_MemWriteIn(MemWriteSg);

    cu.Mem_MemReadOut(MemReadSg);
    tb.Mem_MemReadIn(MemReadSg);

    cu.Wb_MemtoRegOut(WbtoRegSg);
    tb.Wb_MemtoRegIn(WbtoRegSg);

    cu.Wb_RegWriteOut(WbWriteSg);
    tb.Wb_RegWriteIn(WbWriteSg);

    cu.InstrucIn(Instruc2Sg);
    tb.InstrucOut(Instruc2Sg);


	tb.clk(clock);
	//cu.clk(clock);

	sc_start();

	return 0;
}