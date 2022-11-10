#include <iostream>
#include <systemc.h>
#include "EX_MEM.h"
#include "Testbench.h"
using namespace std;

int sc_main(int argv, char* argc[]){
    sc_time period(10,SC_NS);
    sc_time delay(10,SC_NS);

    sc_clock clock("clock", period, 0.5, delay, true);
    
    EX_MEM EX_MEM("EX_MEM");
    Testbench tb("tb");
    
    sc_signal<bool> clkIn;

    //Señales de control
    sc_signal<bool> Wb_MemtoReg_1, Wb_no_idea_1 ;
    sc_signal<bool> Mem_MemWrite_1, Mem_MemRead_1;

    sc_signal<bool> Mem_MemWrite_2, Mem_MemRead_2;
    sc_signal<bool> Wb_MemtoReg_2, Wb_no_idea_2 ;

    //Memoria y direcciones
    sc_signal<sc_int<32>> memoIn[2];
    sc_signal<sc_uint<5>> dirIn;

    sc_signal<sc_int<32>> memoOut[3];
    sc_signal<sc_uint<5>> dirOut;

    EX_MEM.Mem_MemWriteIn(Mem_MemWrite_1), EX_MEM.Mem_MemReadIn(Mem_MemRead_1);
    EX_MEM.Mem_MemWriteOut(Mem_MemWrite_2), EX_MEM.Mem_MemReadOut(Mem_MemRead_2);
    EX_MEM.Wb_MemtoRegIn(Wb_MemtoReg_1), EX_MEM.Wb_RegWriteIn(Wb_no_idea_1) ;
    EX_MEM.Wb_MemtoRegOut(Wb_MemtoReg_2), EX_MEM.Wb_RegWriteOut(Wb_no_idea_2) ;

    for(int i = 0; i< 2; i++){
        EX_MEM.memo_In[i](memoIn[i]);
    } 

    EX_MEM.direccion_In(dirIn);
  
    for(int i = 0; i< 3; i++){
     EX_MEM.memo_Out[i](memoOut[i]);
    } 
  
    EX_MEM.direccion_Out(dirOut);
    tb.Mem_MemWriteIn(Mem_MemWrite_1), tb.Mem_MemReadIn(Mem_MemRead_1);
    tb.Mem_MemWriteOut(Mem_MemWrite_2), tb.Mem_MemReadOut(Mem_MemRead_2);
    tb.Wb_MemtoRegIn(Wb_MemtoReg_1), tb.Wb_RegWriteIn(Wb_no_idea_1) ;
    tb.Wb_MemtoRegOut(Wb_MemtoReg_2), tb.Wb_RegWriteOut(Wb_no_idea_2) ;

    for(int i = 0; i< 2; i++){
        tb.memo_In[i](memoIn[i]);
    } 

    tb.dir_In_(dirIn);
  

    for(int i = 0; i< 3; i++){
     tb.memo_Out[i](memoOut[i]);
    } 
  
    tb.dir_Out(dirOut);

    EX_MEM.clkIn(clock);
    tb.clkIn(clock);

  sc_start();

    return 0;
}