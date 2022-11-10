#include "IF_ID.h"

IF_ID::IF_ID(sc_module_name moduleName) : sc_module(moduleName){

	SC_METHOD(operation);
	sensitive << clk.pos();
	dont_initialize();

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

// 32 bits, 5 para la instruccion, 5 para rs1, 5 para rs2, 5 para rd, 12 para los valores inmediatos
void IF_ID::operation()
{
	sc_uint<5> instruction;
	sc_uint<5> rs1, rs2, rd;
	sc_int<12> imm;
    
if(hazardIn.read() == 0){
    for (sc_uint<3> i = 0; i < 5; i++)
		instruction[i] = insMemIn.read()[i];

	if (instruction == 0 or instruction == 2 or instruction == 3 or instruction == 5 or instruction == 7 or instruction == 13 )
	{
		for (sc_uint<5> i = 5, j = 0; i < 10; i++, j++)
			rs1[j] = insMemIn.read()[i];

        for(sc_uint<5> i = 10, j = 0; i < 15; i++, j++ )
            rs2[j] = insMemIn.read()[i];

		for (sc_uint<5> i = 15, j = 0; i < 20; i++, j++)
			rd[j] = insMemIn.read()[i];
		for (sc_uint<6> i = 20, j = 0; i < 32; i++, j++)
			imm[j] = insMemIn.read()[i];

	} else if (instruction == 1 or instruction == 4 or instruction == 6 or instruction == 8 or instruction == 9 or instruction == 14 or instruction == 16)
	{
		for (sc_uint<5> i = 5, j = 0; i < 10; i++, j++)
			rs1[j] = insMemIn.read()[i];

		for (sc_uint<5> i = 10, j = 0; i < 15; i++, j++)
			rs2[j] = 0;

		for (sc_uint<5> i = 15, j = 0; i < 20; i++, j++) 
			rd[j] = insMemIn.read()[i];
        
        for(sc_uint<6> i = 20, j = 0; i < 32; i++, j++ )
            imm[j] = insMemIn.read()[i];

		

	}else if ( instruction == 10 or instruction == 11 or instruction == 12)
    {
		for (sc_uint<5> i = 5, j = 0; i < 10; i++, j++)
			rs1[j] = insMemIn.read()[i];

		for (sc_uint<5> i = 10, j = 0; i < 15; i++, j++)
			rs2[j] = insMemIn.read()[i];

		for (sc_uint<5> i = 15, j = 0; i < 20; i++, j++) 
			rd[j] = 0;
        
        for(sc_uint<6> i = 20, j = 0; i < 32; i++, j++ )
            imm[j] = insMemIn.read()[i];

        
    }else if (instruction == 15)
    {
		for (sc_uint<5> i = 5, j = 0; i < 10; i++, j++)
			rs1[j] = 0;

		for (sc_uint<5> i = 10, j = 0; i < 15; i++, j++)
			rs2[j] = 0;

		for (sc_uint<5> i = 15, j = 0; i < 20; i++, j++) 
			rd[j] = insMemIn.read()[i];
        
        for(sc_uint<6> i = 20, j = 0; i < 32; i++, j++ )
            imm[j] = insMemIn.read()[i];

    }else {
		for (sc_uint<5> i = 5, j = 0; i < 10; i++, j++)
			rs1[j] = 0;

		for (sc_uint<5> i = 10, j = 0; i < 15; i++, j++)
			rs2[j] = 0;

		for (sc_uint<5> i = 15, j = 0; i < 20; i++, j++) 
			rd[j] =0;
        
        for(sc_uint<6> i = 20, j = 0; i < 32; i++, j++ )
            imm[j] = 0;
        
    }



	fileRegister1Out.write(rs1);
	fileRegister2Out.write(rs2);
    ID_EX0Out.write(pcIn.read());
    ID_unidadControlOut.write(instruction);
    ID_EX1Out.write(rs1);
    ID_EX2Out.write(rs2);
    ID_EX3Out.write(rd);
    immGenOut.write(imm);
    ID_HDUrs1Out.write(rs1);
    ID_HDUrs2Out.write(rs2);
    
}

}