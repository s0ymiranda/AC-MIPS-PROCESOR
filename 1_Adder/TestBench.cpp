#include "TestBench.h"
#include <iostream>


TestBench::TestBench(sc_module_name moduleName) : sc_module(moduleName){

	SC_THREAD(test);
	sensitive << clk;

}

void TestBench::test(){
	srand(time(NULL));
	

	std::cout << " Time    aOut    resultIn\n";
	std::cout << "---------------------------------\n";

		aOut.write(7);
		                       //valores de prueba 
		wait();
		print();
               aOut.write(42);
		
		wait();
		print();
	std::cout << "---------------------------------\n";

	sc_stop();
}

void TestBench::print()
{
	std::cout << sc_time_stamp();
	std::cout <<"     " << aOut.read().to_string();
	std::cout <<"     " << resultIn.read().to_string() << '\n';
}
