#include "IF_ID.h"

IF_ID::IF_ID(sc_module_name moduleName) : sc_module(moduleName){

	SC_METHOD(operation);
	sensitive << clk.pos();
	dont_initialize();

}
/*  0 add
    1 addi
    2 sub
    3 sll
    4 slli
    5 or
    6 ori
    7 and
    8 lw
    9 sw
    10 beq 
    11 bne
    12 blt
    13 slt
    14 slti
    15 jal
    16 jalr */

// 32 bits, 5 para la instruccion, 5 para rs1, 5 para rs2, 5 para rd, 12 para los valores inmediatos
void IF_ID::operation()
{
	sc_uint<5> instruction;
	sc_uint<5> rs1, rs2, rs3;
	sc_int<12> imm;
    
    if (hazzardIn.read()==1){
       	fileRegister1Out.write(0);
	    fileRegister2Out.write(0);
        ID_EX0Out.write(pcIn.read() - 4);
        ID_unidadControlOut.write(0);
        ID_EX1Out.write(0);
        ID_EX2Out.write(0);
        ID_EX3Out.write(0);
        immGenOut.write(0);
        ID_unidadHazzardOut.write(0);
     }




	for (sc_uint<3> i = 0; i < 5; i++)
		instruction[i] = insMemIn.read()[i];

	if (instruction == 1 || instruction == 4 or instruction == 6 or instruction == 8 or instruction == 9 or instruction == 10 or instruction == 11 or instruction == 14 )
	{
		for (sc_uint<5> i = 5, j = 0; i < 10; i++, j++)
			rs1[j] = insMemIn.read()[i];

        for(sc_uint<5> i = 10, j = 0; i < 15; i++, j++ )
            rs2[j] = 0;

		for (sc_uint<5> i = 15, j = 0; i < 20; i++, j++)
			rs3[j] = insMemIn.read()[i];



		for (sc_uint<6> i = 20, j = 0; i < 32; i++, j++)
			imm[j] = insMemIn.read()[i];
	}
	else
	{
		for (sc_uint<5> i = 5, j = 0; i < 10; i++, j++)
			rs1[j] = insMemIn.read()[i];

		for (sc_uint<5> i = 10, j = 0; i < 15; i++, j++)
			rs2[j] = insMemIn.read()[i];

		for (sc_uint<5> i = 15, j = 0; i < 20; i++, j++) 
			rs3[j] = insMemIn.read()[i];
        
        for(sc_uint<6> i = 20, j = 0; i < 32; i++, j++ )
            imm[j] = 0;

		

	}



	fileRegister1Out.write(rs1);
	fileRegister2Out.write(rs2);
    ID_EX0Out.write(pcIn.read());
    ID_unidadControlOut.write(instruction);
    ID_EX1Out.write(rs1);
    ID_EX2Out.write(rs2);
    ID_EX3Out.write(rs3);
    immGenOut.write(imm);
    ID_unidadHazzardOut.write(instruction);

    if (hazzardIn.read()==1){
       	fileRegister1Out.write(0);
	    fileRegister2Out.write(0);
        ID_EX0Out.write(0);
        ID_unidadControlOut.write(0);
        ID_EX1Out.write(0);
        ID_EX2Out.write(0);
        ID_EX3Out.write(0);
        immGenOut.write(0);
        ID_unidadHazzardOut.write(0);
     }


	
}