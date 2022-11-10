#include "Control_Unit.h"

Control_Unit::Control_Unit(sc_module_name nm) : sc_module(nm)
{
	SC_METHOD(operation);
	sensitive << InstrucIn;
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
	Ex_ALUOut.write(InstrucIn.read());

	if(BranchConditionIn.read() == 1){
		muxPcsrOut.write(1);
		IDIFflushOut.write(1);
	}else {
		muxPcsrOut.write(0);
		IDIFflushOut.write(0);		
	}

	if (InstrucIn.read() == 0)
	{
	    Mem_MemWriteOut.write(1); 
        Mem_MemReadOut.write(1);
	    Wb_MemtoRegOut.write(0);
        Wb_RegWriteOut.write(0);
	}
	if (InstrucIn.read() == 1)
	{
	    Mem_MemWriteOut.write(1); 
        Mem_MemReadOut.write(1);
	    Wb_MemtoRegOut.write(0);
        Wb_RegWriteOut.write(0);
	}
	if (InstrucIn.read() == 2)
	{
	    Mem_MemWriteOut.write(1); 
        Mem_MemReadOut.write(1);
	    Wb_MemtoRegOut.write(0);
        Wb_RegWriteOut.write(0);
	}
	if (InstrucIn.read() == 3)
	{
	    Mem_MemWriteOut.write(1); 
        Mem_MemReadOut.write(1);
	    Wb_MemtoRegOut.write(0);
        Wb_RegWriteOut.write(0);
	}
	if (InstrucIn.read() == 4)
	{
	    Mem_MemWriteOut.write(1); 
        Mem_MemReadOut.write(1);
	    Wb_MemtoRegOut.write(0);
        Wb_RegWriteOut.write(0);
	}
	if (InstrucIn.read() == 5)
	{
	    Mem_MemWriteOut.write(1); 
        Mem_MemReadOut.write(1);
	    Wb_MemtoRegOut.write(0);
        Wb_RegWriteOut.write(0);
	}
	if (InstrucIn.read() == 7)
	{
	    Mem_MemWriteOut.write(1); 
        Mem_MemReadOut.write(1);
	    Wb_MemtoRegOut.write(0);
        Wb_RegWriteOut.write(0);
	}
	if (InstrucIn.read() == 8)
	{
	    Mem_MemWriteOut.write(1); 
        Mem_MemReadOut.write(0);
	    Wb_MemtoRegOut.write(1);
        Wb_RegWriteOut.write(0);
	}
	if (InstrucIn.read() == 9)
	{
	    Mem_MemWriteOut.write(0); 
        Mem_MemReadOut.write(1);
	    Wb_MemtoRegOut.write(1);
        Wb_RegWriteOut.write(1);
	}
	if (InstrucIn.read() == 10)
	{
	    Mem_MemWriteOut.write(1); 
        Mem_MemReadOut.write(1);
	    Wb_MemtoRegOut.write(1);
        Wb_RegWriteOut.write(1);
	}
	if (InstrucIn.read() == 11)
	{
	    Mem_MemWriteOut.write(1); 
        Mem_MemReadOut.write(1);
	    Wb_MemtoRegOut.write(1);
        Wb_RegWriteOut.write(1);
	}
	if (InstrucIn.read() == 12)
	{
	    Mem_MemWriteOut.write(1); 
        Mem_MemReadOut.write(1);
	    Wb_MemtoRegOut.write(1);
        Wb_RegWriteOut.write(1);
	}

	if (InstrucIn.read() == 13)
	{
	    Mem_MemWriteOut.write(1); 
        Mem_MemReadOut.write(1);
	    Wb_MemtoRegOut.write(0);
        Wb_RegWriteOut.write(0);
	}
	if (InstrucIn.read() == 14)
	{
	    Mem_MemWriteOut.write(1); 
        Mem_MemReadOut.write(1);
	    Wb_MemtoRegOut.write(0);
        Wb_RegWriteOut.write(0);
	}

	if (InstrucIn.read() == 15)
	{
	    Mem_MemWriteOut.write(1); 
        Mem_MemReadOut.write(1);
	    Wb_MemtoRegOut.write(1);
        Wb_RegWriteOut.write(1);
	}

	if (InstrucIn.read() == 16)
	{
	    Mem_MemWriteOut.write(1); 
        Mem_MemReadOut.write(1);
	    Wb_MemtoRegOut.write(1);
        Wb_RegWriteOut.write(1);
	}






}