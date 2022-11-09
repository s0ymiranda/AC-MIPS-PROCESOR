#include "TestBench.h"
#include <iostream>

TestBench::TestBench(sc_module_name moduleName) : sc_module(moduleName){

	SC_THREAD(test);
	sensitive << clk;

}

void TestBench::test(){
	std::cout << " Time  Instruction  s1Out    s2Out    ResultIn\n";
	std::cout << "----------------------------------------------\n";

		instrucOut.write(10);
		s1Out.write(7);
		s2Out.write(7);         //valores de prueba 
		wait();
		print();

		instrucOut.write(11);
        s1Out.write(7);
		s2Out.write(6);
		wait();
		print();

		instrucOut.write(12);
        s1Out.write(5);
		s2Out.write(8);
		wait();
		print();

		instrucOut.write(12);
        s1Out.write(8);
		s2Out.write(5);
		wait();
		print();

		instrucOut.write(14);
        s1Out.write(9);
		s2Out.write(8);
		wait();
		print();
	std::cout << "---------------------------------\n";

	sc_stop();
}

void TestBench::print()
{
	std::cout << sc_time_stamp();
	std::cout <<"      " << instrucOut.read().to_string();
	std::cout <<"         " << s1Out.read().to_string();
	std::cout <<"         " << s2Out.read().to_string();
	std::cout <<"         " << resultIn.read() << '\n';
}