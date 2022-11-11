#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H
#include <systemc.h>

const int tamanioMemoria = 256;

class Data_Memory: public sc_module {
public:
    sc_in<sc_int<32>> addressIn;//Entrada de la direccion
    sc_out<sc_int<32>> read_dataOut; //Lectura de dato 
    sc_in<sc_int<32>> write_dataIn; //Escritura de dato
    
    sc_in<bool> clkIn;
    sc_in<bool> writeIn, readIn;//Valores de los puertos de entrada Bien sea para habilitar o no

    sc_vector<sc_signal<sc_int<32>>> SC_NAMED(memory, tamanioMemoria);

    SC_CTOR(Data_Memory);

private:
    //Funciones para leer o escribir en el data memory
    void read();
    void write();
};

#endif