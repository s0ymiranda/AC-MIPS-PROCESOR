#ifndef EX_MEM_H
#define EX_MEM_H
#include <systemc.h>

class EX_MEM : public sc_module{
    public:
        sc_in_clk clkIn; //Reloj
    
    sc_in<sc_uint<5>> direccion_In;//Direccion de entrada ALU
    sc_out<sc_uint<5>> direccion_Out;//Salida

    //Señales de control entrada
    sc_in<bool> Mem_MemWriteIn, Mem_MemReadIn;
	sc_in<bool> Wb_MemtoRegIn, Wb_RegWriteIn;

    //Señales de control salida
    sc_out<bool> Mem_MemWriteOut, Mem_MemReadOut;
	sc_out<bool> Wb_MemtoRegOut, Wb_RegWriteOut; 

    sc_in<sc_int<32>> memo_In[2];
	sc_out<sc_int<32>> memo_Out[2];

    SC_CTOR(EX_MEM);
    private:
	void operation();
};

#endif