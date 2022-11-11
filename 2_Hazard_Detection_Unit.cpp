#include "2_Hazard_Detection_Unit.h"

Hazard_Detection_Unit::Hazard_Detection_Unit(sc_module_name moduleName) : sc_module(moduleName){

	SC_METHOD(operation);
    sensitive << IDEXInstrucIn << IDEXrdIn << rs1In << rs2In ;

}
//Como necesitamos verificar es que la instruccion proveniente de ID/EX es load word, y sabemos que la codificacion para esta instruccion es 8 
void Hazard_Detection_Unit::operation()
{
	
    if (IDEXInstrucIn.read() == 9 and (IDEXrdIn.read() == rs1In.read() or IDEXrdIn.read() == rs2In.read() )){
        pcwriteOut.write(0);
        IFIDwriteOut.write(0);
        muxControlOut.write(0);

    }else{
        pcwriteOut.write(1);
        IFIDwriteOut.write(1);
        muxControlOut.write(1);

    }
}
