#include "Testbench.h"
#include <iomanip>
using namespace std;

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn;
  dont_initialize();
}
void Testbench::print() {
  cout<<"Modulo : MEM_WB (IN)------------------------\n";
  cout<<"  Wb_MRegIn :"<<  Wb_MRegIn.read()<<"\n";
  cout<<"  Wb_RegWIn :"<<  Wb_RegWIn.read()<<"\n";
  cout<<"  mem_In[0] :"<<  mem_In[0].read().to_string()<<"\n";
  cout<<"  mem_In[1] :"<<  mem_In[1].read().to_string()<<"\n";
  cout<<"  dir_In :"<<  dir_In.read().to_string()<<"\n";
  cout<<endl;  
  cout << "Modulo: EX MEM (OUT)------------------------\n";
  cout << "  aIWb_MRegOutn :" << Wb_MRegOut.read() << "\n"; 
  cout << "  Wb_RegWOut :" << Wb_RegWOut.read() << "\n";    
  cout << "  mem_Out[0] (MemWb_muxWb1):" << mem_Out[0].read().to_string() << "\n";
  cout << "  mem_Out[1] (MemWb_muxWb2):" << mem_Out[1].read().to_string() << "\n";
  cout << "  dir_Out :" << dir_Out.read().to_string() << "\n";
  cout << endl;

  cout << "\n";
}


void Testbench::test() {


  int b[] = {27,326,53,754,10, 122,16};
  int a[] = { 64, 234, 140, 455,103,12,176};
  for(int i = 0; i < 4; i++){
   cout << "##############################################################################\n";
   
   mem_In[(i % 2)].write(a[i]);
    dir_In.write(b[i] % 32);
    Wb_MRegIn.write((i + 1) % 2);
    Wb_RegWIn.write((i + 1) % 2); 
    wait();
    print();    
  }



  
  sc_stop();
}
