#include "TestBench.h"
#include "ImmGen.h"

int sc_main(int argc, char* argv[])
{
	sc_time period(10, SC_NS);
	sc_time delay(0, SC_NS);
	sc_clock clock("clock", period, 0.5, delay, true);

	TestBench tb("tb");
	ImmGen immGen("immGen");

	tb.clk(clock);
	immGen.clk(clock);

	sc_signal<sc_int<12>> Sg1;
	sc_signal<sc_int<32>> Sg2;

	tb.IF_IDOut(Sg1);
	immGen.IF_IDIn(Sg1);

	tb.ID_EXIn(Sg2);
	immGen.ID_EXOut(Sg2);

	sc_start();

	return 0;
}