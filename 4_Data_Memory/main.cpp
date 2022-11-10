#include "Data_Memory.h"
#include "Testbench.h"
#include <iostream>
#include <systemc.h>

int sc_main(int argv, char* argc[]){
    //Ciclos de reloj
    sc_time period(10,SC_NS);
    sc_time delay(10,SC_NS);

    sc_clock clock("clock", period, 0.5, delay, false);

    Data_Memory Data_Memory("Data_Memory");
    Testbench tb("tb");

    sc_signal<sc_int<32>> resulALU;//Direccion a la que se va acceder en Data Memory
    sc_signal<sc_int<32>> contenidoDM;//contenido de la dirección data memory
    sc_signal<sc_int<32>> dato;//Contenido de la direccion de memoria 
    sc_signal<bool> cable_1, cable_2;//Cables de entrada 

    Data_Memory.addressIn(resulALU);//Entrada de la direccion
    Data_Memory.read_dataOut(contenidoDM);//lectura del contenido data memory
    Data_Memory.write_dataIn(dato);//Escritura en la memoria de datos
    Data_Memory.writeIn(cable_1); 
    Data_Memory.readIn(cable_2);

    tb.addressOut(resulALU); //Dirección de la data momory
    tb.read_dataIn(contenidoDM);//Pasando resultado al testbench
    tb.write_dataOut(dato);
    tb.writeOut(cable_1); 
    tb.readOut(cable_2);

    Data_Memory.clkIn(clock);
    tb.clkIn(clock);

    sc_start();


    return 0;
}