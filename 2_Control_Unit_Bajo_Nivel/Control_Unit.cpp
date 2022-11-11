#include "Control_Unit.h"

Control_Unit::Control_Unit(sc_module_name nm) : sc_module(nm)
{
/*
	and5[0].aIn(aInSg[0]);
	and5[0].bIn(bInSg[0]);
	and5[0].cIn(cInSg[0]);
	and5[0].dIn(dInSg[0]);
	and5[0].eIn(eInSg[0]);
	and5[0].fOut(fOutSg[0]);
*/

	for(int i = 0;  i < 17; i++){
		and5[i].aIn(aInSg[i]);
		and5[i].bIn(bInSg[i]);
		and5[i].cIn(cInSg[i]);
		and5[i].dIn(dInSg[i]);
		and5[i].eIn(eInSg[i]);
		and5[i].fOut(fOutSg[i]);
	}

	for(int i = 0, j=0 ; i < 85; i=i+5,j++){
		aux[i](aInSg[j]);
		aux[i+1](bInSg[j]);
		aux[i+2](cInSg[j]);
		aux[i+3](dInSg[j]);
		aux[i+4](eInSg[j]);
	}

	//Wb_MemtoRegOut [0-7], 9, 13-14

	or_gate[0].aIn(fOutSg[0]);
	or_gate[0].bIn(fOutSg[1]);
	or_gate[0].cOut(orCOut[0]);

	or_gate[1].aIn(fOutSg[2]);
	or_gate[1].bIn(fOutSg[3]);
	or_gate[1].cOut(orCOut[1]);

	or_gate[2].aIn(fOutSg[4]);
	or_gate[2].bIn(fOutSg[5]);
	or_gate[2].cOut(orCOut[2]);

	or_gate[3].aIn(fOutSg[6]);
	or_gate[3].bIn(fOutSg[7]);
	or_gate[3].cOut(orCOut[3]);

	or_gate[4].aIn(fOutSg[13]);
	or_gate[4].bIn(fOutSg[14]);
	or_gate[4].cOut(orCOut[4]);

	or_gate[5].aIn(orCOut[0]);
	or_gate[5].bIn(orCOut[1]);
	or_gate[5].cOut(orCOut[5]);

	or_gate[6].aIn(orCOut[2]);
	or_gate[6].bIn(orCOut[3]);
	or_gate[6].cOut(orCOut[6]);

	or_gate[7].aIn(orCOut[4]);
	or_gate[7].bIn(orCOut[5]);
	or_gate[7].cOut(orCOut[7]);

	or_gate[8].aIn(orCOut[6]);
	or_gate[8].bIn(orCOut[7]);
	or_gate[8].cOut(orCOut[8]);

	or_gate[9].aIn(orCOut[8]);
	or_gate[9].bIn(fOutSg[9]);
	or_gate[9].cOut(orCOut[9]);

	//Wb_RegWriteOut

	or_gate[10].aIn(orCOut[8]);
	or_gate[10].bIn(fOutSg[8]);
	or_gate[10].cOut(orCOut[10]);

	and2 = new AndGate("and2");
	and2->aIn(aSg);
	and2->bIn(bSg);
	and2->cOut(cSg);
	BranchC(aSg);
	Uno(bSg);

	SC_METHOD(operation);
	sensitive << clk << BranchConditionIn << InstrucIn;
}

/*  0 add   - rd, rs1, rs2
    1 addi  - rd, rs1, imm
    2 sub   - rd, rs1, rs2
    3 sll   - rd, rs1, rs2
    4 slli  - rd, rs1, imm
    5 or    - rd, rs1, rs2
    6 ori   - rd, rs1, imm
    7 and   - rd, rs1, rs2
    8 lw    - rd, rs1, imm
    9 sw    - rd, rs1, imm 
    10 beq  - rs1, rs2, imm
    11 bne  - rs1, rs2, imm
    12 blt  - rs1, rs2, imm
    13 slt  - rd, rs1, rs2
    14 slti - rd, rs1, imm
    15 jal  - rd, imm
    16 jalr - rd, rs1, imm
*/

void Control_Unit::operation()
{
	/*
	Ex_ALUOut.write(InstrucIn.read());

	if(BranchConditionIn.read() == 1){
		muxPcsrOut.write(1);
		IDIFflushOut.write(1);
	}else {
		muxPcsrOut.write(0);
		IDIFflushOut.write(0);		
	}
	//reducido:
	if(InstrucIn.read() == 16 or InstrucIn.read() == 15 or InstrucIn.read() == 12 or InstrucIn.read() == 11 or InstrucIn.read() == 10){
		Mem_MemWriteOut.write(0); 
        Mem_MemReadOut.write(0);
	    Wb_MemtoRegOut.write(0);
        Wb_RegWriteOut.write(0);
	}else if(InstrucIn.read() == 14 or InstrucIn.read() == 13 or InstrucIn.read() == 7 or InstrucIn.read() == 6 or InstrucIn.read() == 5 or InstrucIn.read() == 4 or InstrucIn.read() == 3 or InstrucIn.read() == 2 or InstrucIn.read() == 1 or InstrucIn.read() == 0){
	    Mem_MemWriteOut.write(0); 
        Mem_MemReadOut.write(0);
	    Wb_MemtoRegOut.write(1);
        Wb_RegWriteOut.write(1);
	}else if(InstrucIn.read() == 8){
	    Mem_MemWriteOut.write(0); 
        Mem_MemReadOut.write(1);
	    Wb_MemtoRegOut.write(0);
        Wb_RegWriteOut.write(1);
	}else if(InstrucIn.read() == 9){
	    Mem_MemWriteOut.write(1); 
        Mem_MemReadOut.write(0);
	    Wb_MemtoRegOut.write(1);
        Wb_RegWriteOut.write(0);
	}

	//mega agrupado:
*/

	aux[0].write(!InstrucIn.read()[0]);
	aux[1].write(!InstrucIn.read()[1]);
	aux[2].write(!InstrucIn.read()[2]);
	aux[3].write(!InstrucIn.read()[3]);
	aux[4].write(!InstrucIn.read()[4]);

	aux[5].write(InstrucIn.read()[0]);
	aux[6].write(!InstrucIn.read()[1]);
	aux[7].write(!InstrucIn.read()[2]);
	aux[8].write(!InstrucIn.read()[3]);
	aux[9].write(!InstrucIn.read()[4]);

	aux[10].write(!InstrucIn.read()[0]);
	aux[11].write(InstrucIn.read()[1]);
	aux[12].write(!InstrucIn.read()[2]);
	aux[13].write(!InstrucIn.read()[3]);
	aux[14].write(!InstrucIn.read()[4]);

	aux[15].write(InstrucIn.read()[0]);
	aux[16].write(InstrucIn.read()[1]);
	aux[17].write(!InstrucIn.read()[2]);
	aux[18].write(!InstrucIn.read()[3]);
	aux[19].write(!InstrucIn.read()[4]);

	aux[20].write(!InstrucIn.read()[0]);
	aux[21].write(!InstrucIn.read()[1]);
	aux[22].write(InstrucIn.read()[2]);
	aux[23].write(!InstrucIn.read()[3]);
	aux[24].write(!InstrucIn.read()[4]);

	aux[25].write(InstrucIn.read()[0]);
	aux[26].write(!InstrucIn.read()[1]);
	aux[27].write(InstrucIn.read()[2]);
	aux[28].write(!InstrucIn.read()[3]);
	aux[29].write(!InstrucIn.read()[4]);

	aux[30].write(!InstrucIn.read()[0]);
	aux[31].write(InstrucIn.read()[1]);
	aux[32].write(InstrucIn.read()[2]);
	aux[33].write(!InstrucIn.read()[3]);
	aux[34].write(!InstrucIn.read()[4]);

	aux[35].write(InstrucIn.read()[0]);
	aux[36].write(InstrucIn.read()[1]);
	aux[37].write(InstrucIn.read()[2]);
	aux[38].write(!InstrucIn.read()[3]);
	aux[39].write(!InstrucIn.read()[4]);

	aux[40].write(!InstrucIn.read()[0]);
	aux[41].write(!InstrucIn.read()[1]);
	aux[42].write(!InstrucIn.read()[2]);
	aux[43].write(InstrucIn.read()[3]);
	aux[44].write(!InstrucIn.read()[4]);

	aux[45].write(InstrucIn.read()[0]);
	aux[46].write(!InstrucIn.read()[1]);
	aux[47].write(!InstrucIn.read()[2]);
	aux[48].write(InstrucIn.read()[3]);
	aux[49].write(!InstrucIn.read()[4]);

	aux[50].write(!InstrucIn.read()[0]);
	aux[51].write(InstrucIn.read()[1]);
	aux[52].write(!InstrucIn.read()[2]);
	aux[53].write(InstrucIn.read()[3]);
	aux[54].write(!InstrucIn.read()[4]);

	aux[55].write(InstrucIn.read()[0]);
	aux[56].write(InstrucIn.read()[1]);
	aux[57].write(!InstrucIn.read()[2]);
	aux[58].write(InstrucIn.read()[3]);
	aux[59].write(!InstrucIn.read()[4]);

	aux[60].write(!InstrucIn.read()[0]);
	aux[61].write(!InstrucIn.read()[1]);
	aux[62].write(InstrucIn.read()[2]);
	aux[63].write(InstrucIn.read()[3]);
	aux[64].write(!InstrucIn.read()[4]);

	aux[65].write(InstrucIn.read()[0]);
	aux[66].write(!InstrucIn.read()[1]);
	aux[67].write(InstrucIn.read()[2]);
	aux[68].write(InstrucIn.read()[3]);
	aux[69].write(!InstrucIn.read()[4]);

	aux[70].write(!InstrucIn.read()[0]);
	aux[71].write(InstrucIn.read()[1]);
	aux[72].write(InstrucIn.read()[2]);
	aux[73].write(InstrucIn.read()[3]);
	aux[74].write(!InstrucIn.read()[4]);

	aux[75].write(InstrucIn.read()[0]);
	aux[76].write(InstrucIn.read()[1]);
	aux[77].write(InstrucIn.read()[2]);
	aux[78].write(InstrucIn.read()[3]);
	aux[79].write(!InstrucIn.read()[4]);

	aux[80].write(!InstrucIn.read()[0]);
	aux[81].write(!InstrucIn.read()[1]);
	aux[82].write(!InstrucIn.read()[2]);
	aux[83].write(!InstrucIn.read()[3]);
	aux[84].write(InstrucIn.read()[4]);

	BranchC.write(BranchConditionIn.read());
	Uno.write(1);

	Mem_MemWriteOut.write(and5[9].fOut.read()); 
    Mem_MemReadOut.write(and5[8].fOut.read());
	Wb_MemtoRegOut.write(or_gate[9].cOut.read());
    Wb_RegWriteOut.write(or_gate[10].cOut.read());
	
	muxPcsrOut.write(and2->cOut.read());
	IDIFflushOut.write(and2->cOut.read());	

	Ex_ALUOut.write(InstrucIn.read());

//	bool b0 = InstrucIn.read()[0];
//	bool b1 = InstrucIn.read()[1];
//	bool b2 = InstrucIn.read()[2];
//	bool b3 = InstrucIn.read()[3];
//	bool b4 = InstrucIn.read()[4];
//	Ex_ALUOut[0]->write(b0);
//	Ex_ALUOut[1]->write(b1);
//	Ex_ALUOut[2]->write(b2);
//	Ex_ALUOut[3]->write(b3);
//	Ex_ALUOut[4]->write(b4);


}
