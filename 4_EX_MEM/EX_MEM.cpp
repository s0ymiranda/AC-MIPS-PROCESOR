#include "EX_MEM.h"
using namespace std;

EX_MEM::EX_MEM(sc_module_name nm) : sc_module(nm){
	SC_METHOD(operation);
	sensitive << clkIn.pos();
}

void EX_MEM::operation(){

    //Verificación para no sobrepasar los límites establecidos en el data memory
    if (Mem_MemWriteIn.read() or Mem_MemReadIn.read()){
		try{
			if (memo_In[0].read() < 0 || memo_In[0].read() >= 256)
				throw 0;
		}
		catch (...)
		{
			cout << "\n\nAcceso a Cache L1 de Datos fuera de límites\n\n";
			sc_stop();
		}
	}

    for (int i = 0; i < 2; i++){
		memo_Out[i].write(memo_In[i].read());
	}
    memo_Out[2].write(memo_In[0].read());

    direccion_Out.write(direccion_In.read());
    Mem_MemWriteOut.write(Mem_MemWriteIn.read());
	Mem_MemReadOut.write(Mem_MemReadIn.read());
	Wb_MemtoRegOut.write(Wb_MemtoRegIn.read());
	Wb_RegWriteOut.write(Wb_RegWriteIn.read());
}