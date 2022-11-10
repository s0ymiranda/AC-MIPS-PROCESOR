#include "Testbench.h"
#include <iostream>
using namespace std;

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);

  sensitive << clkIn;
  dont_initialize();
}

void Testbench::print() {

    cout<<"Modulo: DATA_MEMORY Entradas \n";
    
    cout<<"  Direccion de acceder :"<<  addressOut.read().to_string()<<"\n";//Salida de la direccion de memoria
    cout<<"  Escritura de dato :"<< write_dataOut.read().to_string()<<"\n";
    cout<<"  Escritura entrada :"<<  writeOut.read()<<"\n";
    cout<<"  Lectura entrada :"<<  readOut.read()<<"\n";

    cout<<"Dato de salida "<<read_dataIn.read().to_string()<<"\n";
}

void Testbench::test() {


    //Pruebas
    int dir[5] = {1, 1, 1, 1,1 };
    int datos[5] = {900, 22,93, 0, 89};
    

    for (int j = 0; j < 5;j++) {
      cout << "----------------------------------------------------------------------------\n";
      cout << "----------------------------------------------------------------------------\n";

      write_dataOut.write(datos[j]);
      addressOut.write(dir[j]); 
      readOut.write(true);            
      writeOut.write(true);            
      wait();
      print();
    }
  
  sc_stop();
}