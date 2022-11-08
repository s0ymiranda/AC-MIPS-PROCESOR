#include "TestBench.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

TestBench::TestBench(sc_module_name moduleName) : sc_module(moduleName){

	SC_THREAD(test);
	sensitive << clk;

}

void TestBench::test(){
	srand(time(NULL));
	

	std::cout << " Time    aOut    bOut    resultIn\n";
	std::cout << "---------------------------------\n";

		aOut.write(7);
		bOut.write(10);         //valores de prueba 
		wait();
		print();
        aOut.write(42);
		bOut.write(-6);
		wait();
		print();
	std::cout << "---------------------------------\n";

	sc_stop();
}

void TestBench::print()
{
	std::cout << sc_time_stamp();
	std::cout <<"     " << aOut.read().to_string();
	std::cout <<"      " << bOut.read().to_string();
	std::cout <<"     " << resultIn.read().to_string() << '\n';
}