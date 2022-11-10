#include "3_FORWARDING_UNIT.h"

F_Unit :: F_Unit(sc_module_name moduleName) : sc_module(moduleName)
{
	SC_METHOD(process);
	sensitive  << rs1_registerIn << rs2_registerIn << mem_wb_registerIn << ex_mem_registerIn << mux1In << mux2In;
}

void F_Unit :: process()
{
    
//Conditionals for the first mux pair of signals

    if (rs1_registerIn.read() == ex_mem_registerIn.read() && mux1In.read() == 1){
        mux1_aOut.write(1);
        mux1_bOut.write(0);
    }
    else if (rs1_registerIn.read() == mem_wb_registerIn.read() && mux1In.read() == 1 ){
        mux1_aOut.write(0);
        mux1_bOut.write(1);
    }
    else {
        mux1_aOut.write(0);
        mux1_bOut.write(0);
    }

//Conditionals for the second mux pair of signals

    if (rs2_registerIn.read() == ex_mem_registerIn.read() && mux1In.read() == 1){
        mux2_aOut.write(1);
        mux2_bOut.write(0);
    }
    else if (rs2_registerIn.read() == mem_wb_registerIn.read() && mux1In.read() == 1 ){
        mux2_aOut.write(0);
        mux2_bOut.write(1);
    }
    else {
        mux2_aOut.write(0);
        mux2_bOut.write(0);
    }

}
