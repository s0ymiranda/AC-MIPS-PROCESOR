#include "Hazard_Detection_Unit.h"
#include "TestBench.h"

int sc_main(int argc, char* argv[]){

	sc_time period(10, SC_NS);
	sc_time delay(0, SC_NS);
	sc_clock clock("clock", period, 0.5, delay, true);

	Hazard_Detection_Unit hdu("hdu");
	TestBench tb("tb");

    hdu.clk(clock);
	tb.clk(clock);

	sc_signal<sc_uint<5>> IDEXInstrucSg, rs1Sg, rs2Sg, IDEXrdSg;
    sc_signal<bool> pcwriteSg, IFIDwriteSg, muxControlSg;

	hdu.IDEXInstrucIn(IDEXInstrucSg);
    tb.IDEXInstrucOut(IDEXInstrucSg);

    hdu.rs1In(rs1Sg);
    tb.rs1Out(rs1Sg);

    hdu.rs2In(rs2Sg);
    tb.rs2Out(rs2Sg);

    hdu.IDEXrdIn(IDEXrdSg);
    tb.IDEXrdOut(IDEXrdSg);

    hdu.pcwriteOut(pcwriteSg);
    tb.pcwriteIn(pcwriteSg);

    hdu.IFIDwriteOut(IFIDwriteSg);
    tb.IFIDwriteIn(IFIDwriteSg);

    hdu.muxControlOut(muxControlSg);
    tb.muxControlIn(muxControlSg);

	sc_start();

	return 0;
}