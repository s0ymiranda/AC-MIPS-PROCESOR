#include "Divider.h"

using namespace std;

divider::divider(sc_module_name moduleName) : sc_module(moduleName) {
	SC_METHOD(process);
	sensitive << InstrucIn;

}
divider::~divider(){

}

void divider::process(){
	InstrucIn_0.write(InstrucIn.read()[0]);
	InstrucIn_1.write(InstrucIn.read()[1]);
	InstrucIn_2.write(InstrucIn.read()[2]);
	InstrucIn_3.write(InstrucIn.read()[3]);
	InstrucIn_4.write(InstrucIn.read()[4]);
}
