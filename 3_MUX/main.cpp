#include "MUX_3.h"
#include "TestBench.h"

int sc_main(int argv, char* argc[]) {


  sc_time period(10, SC_NS);
  sc_time delay(0, SC_NS);


  sc_clock clock("clock", period, 0.5, delay, true);

 
  Mux Mux("Mux");
  TestBench TestBench("TestBench");

 
  sc_signal<sc_int<32>> value_1Sg, value_2Sg, value_3Sg, valueSg;
  sc_signal<bool> aSg, bSg;

 
  Mux.value_1In(value_1Sg);
  Mux.value_2In(value_2Sg);
  Mux.value_3In(value_3Sg);
  Mux.aIn(aSg);
  Mux.bIn(bSg);
  Mux.valueOut(valueSg);

  TestBench.valueIn(valueSg);
  TestBench.value_1Out(value_1Sg);
  TestBench.value_2Out(value_2Sg);
  TestBench.value_3Out(value_3Sg);
  TestBench.aOut(aSg);
  TestBench.bOut(bSg);

  
  TestBench.clkIn(clock);

  
  sc_start();

  return 0;
}