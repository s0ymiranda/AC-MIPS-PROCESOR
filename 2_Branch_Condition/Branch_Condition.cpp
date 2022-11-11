#include "Branch_Condition.h"

Branch_Condition::Branch_Condition(sc_module_name moduleName) : sc_module(moduleName){

	SC_METHOD(operation);
	sensitive << s1In << s2In;

}

void Branch_Condition::operation()
{
    if(instrucIn.read() == 15 )
        resultOut.write(1);

    if(instrucIn.read() == 10 and (s1In.read() == s2In.read())){
	    resultOut.write(1);
    }else if(instrucIn.read() == 11 and(s1In.read() != s2In.read())){
        resultOut.write(1);
    }else if(instrucIn.read() == 12 and (s1In.read() < s2In.read() )){
        resultOut.write(1);
    }else {
        resultOut.write(0);
    }
}
