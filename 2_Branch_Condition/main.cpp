#include "Branch_Condition.h"
#include "TestBench.h"

int sc_main(int argc, char* argv[]){

	sc_time period(10, SC_NS);
	sc_time delay(10, SC_NS);
	sc_clock clock("clock", period, 5, delay, false);

	Branch_Condition bc("bc");
	TestBench tb("tb");

	tb.clk(clock);

	sc_signal<sc_int<32>> s1Sg, s2Sg;
	sc_signal<sc_uint<5>> instrucSg;
    sc_signal<bool> resultSg;

	bc.s1In(s1Sg);
	tb.s1Out(s1Sg);

	bc.s2In(s2Sg);
	tb.s2Out(s2Sg);

	bc.instrucIn(instrucSg);
	tb.instrucOut(instrucSg);

	bc.resultOut(resultSg);
	tb.resultIn(resultSg);

	sc_start();

	return 0;
}