#include "NotGate.h"
NotGate::NotGate(sc_module_name moduleName) : sc_module(moduleName) {
	SC_METHOD(process);
	sensitive << aIn;

}
NotGate::~NotGate(){}
void NotGate::process(){
	bOut.write(!aIn.read());
}