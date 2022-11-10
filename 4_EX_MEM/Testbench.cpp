#include "Testbench.h"
#include <iostream>
using namespace std;

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn;
  dont_initialize();
}

void Testbench::print() {

  cout << "Modulo:  EX MEN (Entradas)->\n";
  cout << "  Escritura In :" << Mem_MemWriteIn.read() << "\n";
  cout << "  Lectrua In :" << Mem_MemReadIn.read() << "\n";
  cout << "  Wb_MemtoRegIn :" << Wb_MemtoRegIn.read() << "\n";
  cout << "  Wb_RegWriteIn :" << Wb_RegWriteIn.read() << "\n";
  cout << "  memo_In[0] (alu_exMem_32bit):" << memo_In[0].read().to_string() << "\n";
  cout << "  memo_In[1] (muxEx_exMem):" << memo_In[1].read().to_string() << "\n";
  cout << "  dir_In_ :" << dir_In_.read().to_string() << "\n";

   cout<<"Modulo: EX MEM (Salidas)->\n";
   cout<<"  Escritura Out :"<<  Mem_MemWriteOut.read()<<"\n";
   cout<<"  Lectura Out :"<<  Mem_MemReadOut.read()<<"\n";
   cout<<"  Wb_MemtoRegOut :"<< Wb_MemtoRegOut.read()<<"\n";
   cout<<"  Wb_RegWriteOut :"<<  Wb_RegWriteOut.read()<<"\n";
   cout<<"  memo_Out[0] (exMem_dataMemoryAddress):"<< memo_Out[0].read().to_string()<<"\n";
   cout<<"  memo_Out[1] (exMem_dataMemoryData):"<< memo_Out[1].read().to_string()<<"\n";
   cout<<"  memo_Out[2] (exMem_MemWb32bits):"<< memo_Out[2].read().to_string()<<"\n";
    cout << "  dir_Out :" << dir_Out.read().to_string() << "\n";

  cout << "\n";
}

void Testbench::test() {


  int b[] = { 42, 32, 53, 74,10,1,16};
  int a[] = { 4, 2, 3, 4,10,12,176};
  int help = 0;
  for(int i = 0; i < 3; i++){
   if(i >= 2){
      help = 1;
   }
    memo_In[i- help].write(a[i]);
    dir_In_.write(b[i]);

    Mem_MemWriteIn.write((i + 1) % 2); 
    Mem_MemReadIn.write((i + 1) % 2);
    Wb_MemtoRegIn.write((i + 1) % 2);
    Wb_RegWriteIn.write((i + 1) % 2); 
    wait();
    print();    
  }

  sc_stop();
}