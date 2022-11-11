#ifndef TESTBENCH_H
#define TESTBENCH_H
#include <iostream>
#include <systemc.h>

class TestBench : public sc_module{
    //Senial de control 
    sc_in_clk clk;

    //Instruction memory
	sc_in<sc_int<32>> instructionNumberIn;
	sc_in<sc_uint<32>> operationIn;

    //RegisterFile
    sc_in<sc_int<32>> s1In;     // Variable dentro del rs1
    sc_in<sc_int<32>> s2In;     // Variable dentro del rs2
    sc_in<sc_uint<5>> rdOut;      //register destination
    sc_in<sc_uint<5>> rs1Out;     //register source 1
    sc_in<sc_uint<5>> rs2Out;     //register source 2
    sc_in<sc_int<32>> rOut;      //result

    //AlU
    sc_in<sc_int<32>> resultIn;
    sc_out<sc_int<32>> value_1Out, value_2Out;
    sc_out<sc_uint<5>>  instructOut;
    
    //Data Memory
    sc_out<sc_int<32>> addressOut; //Direccion de memoria de la data memory
    sc_in<sc_int<32>> read_dataIn; //Lectura del dato de entrada
    sc_out<sc_int<32>> write_dataOut; //Escritura del dato de salida
    sc_out<bool> writeOut, readOut; //Cables de salida

    //MUX
    sc_out<bool> sOut;
	sc_out<sc_int<32>> aOut, bOut;
	sc_in<sc_int<32>> cIn;

};

#endif