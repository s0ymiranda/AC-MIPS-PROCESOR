#include "ALU.h"
#include "TestBench.h"

int sc_main(int argv, char* argc[]) {

  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);

  ALU alu("alu");
  TestBench testbench("testbench");

  sc_signal<sc_int<32>> value_1, value_2, instruct, result;


  alu.value_1In(value_1);
  alu.value_2In(value_2);
  alu.instructIn(instruct);
  alu.resultOut(result);
  alu.clk(clock);


  testbench.resultIn(result);
  testbench.value_1Out(value_1);
  testbench.value_2Out(value_2);
  testbench.instructOut(instruct);


  testbench.clk(clock);

  sc_start();

  return 0;
}