#include "Mux2.h"
#include "Testbench.h"

int sc_main(int argv, char* argc[]) {
  // Configuración del reloj
  sc_time period(10, SC_NS);
  sc_time delay(0, SC_NS);

  // Creando el reloj
  sc_clock clock("clock", period, 0.5, delay, true);

  // Creando instancias de los módulos
  Mux2 mux("mux2");
  Testbench tb("testBench");

  // Necesitaremos cables para conectar los módulos
  sc_signal<bool> s0Sg, fSg;
  sc_signal<bool> d0Sg, d1Sg;

  // Conectando los módulos a los cables
  mux.s0In(s0Sg);
  mux.d0In(d0Sg);
  mux.d1In(d1Sg);
  mux.fOut(fSg);

  tb.fIn(fSg);
  tb.s0Out(s0Sg);
  tb.d0Out(d0Sg);
  tb.d1Out(d1Sg);

  // Conectando el reloj al testbench
  tb.clkIn(clock);

  // Inicializando el simulador
  sc_start();

  return 0;
}