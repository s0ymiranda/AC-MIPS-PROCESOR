#include "TestBench.h"
#include <iostream>


TestBench::TestBench(sc_module_name moduleName) : sc_module(moduleName){

	SC_THREAD(test);
	sensitive << clk;

}

void TestBench::test(){
	srand(time(NULL));
	


	std::cout << " Time    ID/EXInstruc    IF/IDrs1   IF/IDrs2   ID/EXrd   PcWrite IF/IDWrite MuxControl\n";
	std::cout << "--------------------------------------------------------------------------------------\n";
        IDEXInstrucOut.write(4);
		rs1Out.write(10);         //valores de prueba 
		rs2Out.write(2);
        IDEXrdOut.write(7);
		wait();
        wait();
		print();

		IDEXInstrucOut.write(8);
		rs1Out.write(10);         //valores de prueba 
		rs2Out.write(2);
        IDEXrdOut.write(10);
		wait();
		wait();
		print();

        IDEXInstrucOut.write(4);
		rs1Out.write(10);         //valores de prueba 
		rs2Out.write(2);
        IDEXrdOut.write(7);
		wait();
        wait();
		print();

    	IDEXInstrucOut.write(8);
		rs1Out.write(10);         //valores de prueba 
		rs2Out.write(2);
        IDEXrdOut.write(2);
        wait();
		wait();
		print();


	std::cout << "--------------------------------------------------------------------------------------\n";

	sc_stop();
}

void TestBench::print()
{
	std::cout << sc_time_stamp();
	std::cout <<"           " << IDEXInstrucOut.read().to_string();
	std::cout <<"            " << rs1Out.read().to_string();
	std::cout <<"          " << rs2Out.read().to_string();
    std::cout <<"        " << IDEXrdOut.read().to_string();
	std::cout <<"         " << pcwriteIn.read();
	std::cout <<"          " << IFIDwriteIn.read();
	std::cout <<"         " << muxControlIn.read()<< "\n";    
    
}