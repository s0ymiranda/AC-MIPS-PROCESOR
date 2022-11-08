#include "Branch_Condition.h"

Branch_Condition::Branch_Condition(sc_module_name moduleName) : sc_module(moduleName){

	SC_METHOD(operation);
	sensitive << s1In << s2In;

}

void Branch_Condition::operation()
{
    if(s1In.read() == s2In.read()){
	    resultOut.write(0);
    } else if (s1In.read() < s2In.read()){
        resultOut.write(1);
    }else if (s1In.read() > s2In.read()){
        resultOut.write(2);
    } 
}