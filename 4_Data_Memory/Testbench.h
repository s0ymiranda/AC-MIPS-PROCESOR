#ifndef TESTBENCH_H
#define TESTBENCH_H
#include <iostream>
#include <systemc.h>

class Testbench : public sc_module {
public:
    sc_out<sc_int<32>> addressOut; //Dirección de memoria de la data memory
    sc_in<sc_int<32>> read_dataIn; //Lectura del dato de entrada
    sc_out<sc_int<32>> write_dataOut; //Escritura del dato de salida
    sc_out<bool> writeOut, readOut; //Cables de salida

    sc_in<bool> clkIn;

    int* memory;//Valores de la memoria
    SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif