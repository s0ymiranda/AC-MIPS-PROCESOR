#include "FORWARDING_UNIT.h"
#include "TestBench.h"

int sc_main(int argv, char* argc[]) {


  sc_time period(10, SC_NS);
  sc_time delay(0, SC_NS);


  sc_clock clock("clock", period, 0.5, delay, true);

 
  F_Unit F_Unit("F_Unit");
  TestBench TestBench("TestBench");

 
  sc_signal<sc_uint<5>> rs1_registerSg, rs2_registerSg, mem_wb_registerSg, ex_mem_registerSg;
  sc_signal<bool> mux1Sg, mux2Sg, mux1_aSg, mux1_bSg, mux2_aSg, mux2_bSg;

 

  F_Unit.rs1_registerIn(rs1_registerSg);
  F_Unit.rs2_registerIn(rs2_registerSg);
  F_Unit.mem_wb_registerIn(mem_wb_registerSg);
  F_Unit.ex_mem_registerIn(ex_mem_registerSg);
  F_Unit.mux1In(mux1Sg);
  F_Unit.mux2In(mux2Sg);
  F_Unit.mux1_aOut(mux1_aSg);
  F_Unit.mux1_bOut(mux1_bSg);
  F_Unit.mux2_aOut(mux2_aSg);
  F_Unit.mux2_bOut(mux2_bSg);

  TestBench.rs1_registerOut(rs1_registerSg);
  TestBench.rs2_registerOut(rs2_registerSg);
  TestBench.mem_wb_registerOut(mem_wb_registerSg);
  TestBench.ex_mem_registerOut(ex_mem_registerSg);
  TestBench.mux1Out(mux1Sg);
  TestBench.mux2Out(mux2Sg);
  TestBench.mux1_aIn(mux1_aSg);
  TestBench.mux1_bIn(mux1_bSg);
  TestBench.mux2_aIn(mux2_aSg);
  TestBench.mux2_bIn(mux2_bSg);

  
  TestBench.clkIn(clock);

  
  sc_start();

  return 0;
}