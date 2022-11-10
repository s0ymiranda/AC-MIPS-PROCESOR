#include "Data_Memory.h"

Data_Memory::Data_Memory(sc_module_name nm) : sc_module(nm){
	SC_METHOD(write);
	sensitive << clkIn.pos();

	SC_METHOD(read);
	sensitive << clkIn.neg();
}

void Data_Memory::write(){
	//Escritura de dato
    if (writeIn.read()){
		memory[addressIn.read()] = write_dataIn.read();
	}
}

void Data_Memory::read(){
	//Lectura de dato
	if (readIn.read()){
		read_dataOut.write(memory[addressIn.read()]);
	}
}
