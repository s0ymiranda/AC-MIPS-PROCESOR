#include "RegisterFile.h"
#include "TestBench.h"


int sc_main(int argc, char* argv[])
{
	sc_time period(10, SC_NS);
	sc_time delay(0, SC_NS);
	sc_clock clock("clock", period, 0.5, delay, true);

	TestBench tb("tb");
	RegisterFile rf("rf");

	tb.clk(clock);
	rf.clk(clock);

	sc_signal<sc_int<32>> s1Sg, s2Sg,rSg;
	sc_signal<sc_uint<5>> rdSg, rs1Sg, rs2Sg;
	sc_signal<bool> weSg;

	tb.rOut(rSg);
	rf.rIn(rSg);

	tb.weOut(weSg);
	rf.weIn(weSg);

	tb.s1In(s1Sg);
	rf.s1Out(s1Sg);

	tb.s2In(s2Sg);
	rf.s2Out(s2Sg);

	tb.rdOut(rdSg);
	rf.rdIn(rdSg);

	tb.rs1Out(rs1Sg);
	rf.rs1In(rs1Sg);

	tb.rs2Out(rs2Sg);
	rf.rs2In(rs2Sg);

	sc_start();

	return 0;
}