#include "Hazard_Detection_Unit.h"

Hazard_Detection_Unit::Hazard_Detection_Unit(sc_module_name moduleName) : sc_module(moduleName){


    and2[0].aIn(aSg[0]);
    aAuxOut[0](aSg[0]);
    and2[0].bIn(bSg[0]);
    bAuxOut[0](bSg[0]);
    and2[0].cOut(cSg[0]);

    and2[1].aIn(aSg[1]);
    aAuxOut[1](aSg[1]);
    and2[1].bIn(bSg[1]);
    bAuxOut[1](bSg[1]);
    and2[1].cOut(cSg[1]);

    and2[2].aIn(aSg[2]);
    aAuxOut[2](aSg[2]);
    and2[2].bIn(bSg[2]);
    bAuxOut[2](bSg[2]);
    and2[2].cOut(cSg[2]);

    and2[3].aIn(aSg[3]);
    aAuxOut[3](aSg[3]);
    and2[3].bIn(bSg[3]);
    bAuxOut[3](bSg[3]);
    and2[3].cOut(cSg[3]);

    and2[4].aIn(aSg[4]);
    aAuxOut[4](aSg[4]);
    and2[4].bIn(bSg[4]);
    bAuxOut[4](bSg[4]);
    and2[4].cOut(cSg[4]);

    and5[0].aIn(cSg[0]);
    and5[0].bIn(cSg[1]);
    and5[0].cIn(cSg[2]);
    and5[0].dIn(cSg[3]);
    and5[0].eIn(cSg[4]);

    and2[5].aIn(aSg[5]);
    aAuxOut[5](aSg[5]);
    and2[5].bIn(bSg[5]);
    bAuxOut[5](bSg[5]);
    and2[5].cOut(cSg[5]);

    and2[6].aIn(aSg[6]);
    aAuxOut[6](aSg[6]);
    and2[6].bIn(bSg[6]);
    bAuxOut[6](bSg[6]);
    and2[6].cOut(cSg[6]);

    and2[7].aIn(aSg[7]);
    aAuxOut[7](aSg[7]);
    and2[7].bIn(bSg[7]);
    bAuxOut[7](bSg[7]);
    and2[7].cOut(cSg[7]);

    and2[8].aIn(aSg[8]);
    aAuxOut[8](aSg[8]);
    and2[8].bIn(bSg[8]);
    bAuxOut[8](bSg[8]);
    and2[8].cOut(cSg[8]);

    and2[9].aIn(aSg[9]);
    aAuxOut[9](aSg[9]);
    and2[9].bIn(bSg[9]);
    bAuxOut[9](bSg[9]);
    and2[9].cOut(cSg[9]);

    and5[1].aIn(cSg[5]);
    and5[1].bIn(cSg[6]);
    and5[1].cIn(cSg[7]);
    and5[1].dIn(cSg[8]);
    and5[1].eIn(cSg[9]);

    and2[10].aIn(aSg[10]);
    aAuxOut[10](aSg[10]);
    and2[10].bIn(bSg[10]);
    bAuxOut[10](bSg[10]);
    and2[10].cOut(cSg[10]);

    and2[11].aIn(aSg[11]);
    aAuxOut[11](aSg[11]);
    and2[11].bIn(bSg[11]);
    bAuxOut[11](bSg[11]);
    and2[11].cOut(cSg[11]);

    and2[12].aIn(aSg[12]);
    aAuxOut[12](aSg[12]);
    and2[12].bIn(bSg[12]);
    bAuxOut[12](bSg[12]);
    and2[12].cOut(cSg[12]);

    and2[13].aIn(aSg[13]);
    aAuxOut[13](aSg[13]);
    and2[13].bIn(bSg[13]);
    bAuxOut[13](bSg[13]);
    and2[13].cOut(cSg[13]);

    and2[14].aIn(aSg[14]);
    aAuxOut[14](aSg[14]);
    and2[14].bIn(bSg[14]);
    bAuxOut[14](bSg[14]);
    and2[14].cOut(cSg[14]);

    and5[2].aIn(cSg[10]);
    and5[2].bIn(cSg[11]);
    and5[2].cIn(cSg[12]);
    and5[2].dIn(cSg[13]);
    and5[2].eIn(cSg[14]);

    //fase 2
    and5[1].fOut(orSg[0]);
    or2[0].aIn(orSg[0]);

    and5[2].fOut(orSg[1]);
    or2[0].bIn(orSg[1]);

    //fase 3
    and5[0].fOut(andSg[0]);  
    and2[15].aIn(andSg[0]);

    or2[0].cOut(andSg[1]);
    and2[15].bIn(andSg[1]);

    //fase 4
    and2[15].cOut(andSg[2]);


	SC_METHOD(operation);
    sensitive << clk.neg() << and2[15].cOut;//IDEXInstrucIn << aAuxOut[0] << bAuxOut[0]<< aAuxOut[1] << bAuxOut[1] << aAuxOut[2] << bAuxOut[2] << aAuxOut[3] << bAuxOut[3] << aAuxOut[4] << bAuxOut[4];//clk.neg()  << and2[0].cOut << and2[1].cOut << and2[2].cOut << and2[3].cOut << and2[4].cOut ;
    dont_initialize();




}
//Como necesitamos verificar es que la instruccion proveniente de ID/EX es load word, y sabemos que la codificacion para esta instruccion es 8 
void Hazard_Detection_Unit::operation()
{
	


/*    if (IDEXInstrucIn.read() == 8 and (IDEXrdIn.read() == rs1In.read() or IDEXrdIn.read() == rs2In.read() )){
        pcwriteOut.write(0);
        IFIDwriteOut.write(0);
        muxControlOut.write(0);

    }else{
        pcwriteOut.write(1);
        IFIDwriteOut.write(1);
        muxControlOut.write(1);

    }
*/
    LwInstruc = 8;

    //valores fase 1
    aAuxOut[0].write(LwInstruc[0]);
    aAuxOut[1].write(LwInstruc[1]);
    aAuxOut[2].write(LwInstruc[2]);
    aAuxOut[3].write(LwInstruc[3]);
    aAuxOut[4].write(LwInstruc[4]);

    bAuxOut[0].write(IDEXInstrucIn.read()[0]);
    bAuxOut[1].write(IDEXInstrucIn.read()[1]);
    bAuxOut[2].write(IDEXInstrucIn.read()[2]);
    bAuxOut[3].write(IDEXInstrucIn.read()[3]);
    bAuxOut[4].write(IDEXInstrucIn.read()[4]);

    aAuxOut[0].write(LwInstruc[0]);
    aAuxOut[1].write(LwInstruc[1]);
    aAuxOut[2].write(LwInstruc[2]);
    aAuxOut[3].write(LwInstruc[3]);
    aAuxOut[4].write(LwInstruc[4]);

    bAuxOut[0].write(IDEXInstrucIn.read()[0]);
    bAuxOut[1].write(IDEXInstrucIn.read()[1]);
    bAuxOut[2].write(IDEXInstrucIn.read()[2]);
    bAuxOut[3].write(IDEXInstrucIn.read()[3]);
    bAuxOut[4].write(IDEXInstrucIn.read()[4]);

    for( int i =0 ; i<5;i++){
        std::cout << LwInstruc[i] << aAuxOut[i].read() << " - " << IDEXInstrucIn.read()[i] << bAuxOut[i].read() << "\n";
    }
    std::cout << "   result  "<<and5[1].fOut.read();
    std::cout << and5[0].fOut.read();

    aAuxOut[5].write(IDEXrdIn.read()[0]);
    aAuxOut[6].write(IDEXrdIn.read()[1]);
    aAuxOut[7].write(IDEXrdIn.read()[2]);
    aAuxOut[8].write(IDEXrdIn.read()[3]);
    aAuxOut[9].write(IDEXrdIn.read()[4]);

    bAuxOut[5].write(rs1In.read()[0]);
    bAuxOut[6].write(rs1In.read()[1]);
    bAuxOut[7].write(rs1In.read()[2]);
    bAuxOut[8].write(rs1In.read()[3]);
    bAuxOut[9].write(rs1In.read()[4]);  


    aAuxOut[10].write(IDEXrdIn.read()[0]);
    aAuxOut[11].write(IDEXrdIn.read()[1]);
    aAuxOut[12].write(IDEXrdIn.read()[2]);
    aAuxOut[13].write(IDEXrdIn.read()[3]);
    aAuxOut[14].write(IDEXrdIn.read()[4]);

    bAuxOut[10].write(rs2In.read()[0]);
    bAuxOut[11].write(rs2In.read()[1]);
    bAuxOut[12].write(rs2In.read()[2]);
    bAuxOut[13].write(rs2In.read()[3]);
    bAuxOut[14].write(rs2In.read()[4]);

    std::cout << and5[2].fOut.read();  

    pcwriteOut.write(!and2[15].cOut.read());
    IFIDwriteOut.write(!and2[15].cOut.read());
    muxControlOut.write(!and2[15].cOut.read());




    
}