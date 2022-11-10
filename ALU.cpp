#include "ALU.h"

ALU :: ALU(sc_module_name nm) : sc_module(nm), value_1In("value_1In"), value_2In("value_2In"), resultOut("resultOut")
{
	SC_METHOD(process);
	sensitive << instructIn << value_1In << value_2In;
	dont_initialize();
}

//Instructions List:
// add, addi, sub, sll, slli, or, ori, and, lw, sw, beq, bne, blt, slt, slti, jal, jalr

void ALU :: process(){

    switch (instructIn.read())
    {
    case 0: //Add

        resultOut.write(value_1In.read() + value_2In.read());
        break;

    case 1: //Addi

        resultOut.write(value_1In.read() + value_2In.read());
        break;

    case 2: //Sub

        resultOut.write(value_1In.read() - value_2In.read());
        break;

    case 3: //Sll
        {
        sc_int<32> aux1 = value_1In.read();
	    sc_int<32> aux2 = value_2In.read();
		resultOut.write(aux1 <<= aux2);
        break;
        }

    case 4: //Slli
        {
        sc_int<32> aux1 = value_1In.read();
	    sc_int<32> aux2 = value_2In.read();
		resultOut.write(aux1 <<= aux2);
        break;
        }

    case 5: //Or

        resultOut.write(value_1In.read() or value_2In.read());
        break;

    case 6: //Ori

        resultOut.write(value_1In.read() or value_2In.read());
        break;

    case 7: //And

        resultOut.write(value_1In.read() and value_2In.read());
        break;
    
    case 8: //Lw

        resultOut.write(value_1In.read() + value_2In.read());
        break;

    case 9: //Sw

        resultOut.write(value_1In.read() + value_2In.read());
        break;

    case 10: //Beq

        resultOut.write(value_1In.read() == value_2In.read());
        break;

    case 11: //Bne

        resultOut.write(value_1In.read() != value_2In.read());
        break;

    case 12: //Blt

        resultOut.write(value_1In.read() < value_2In.read());
        break;

    case 13: //Slt

        if (value_1In.read() < value_2In.read()){
            
            resultOut.write(value_1In.read());

        }

        break;


    case 14: //Slti

        if (value_1In.read() < value_2In.read()){
            
            resultOut.write(value_1In.read());

        }
        
        break;
    
    case 15: //Jal

        resultOut.write(value_1In.read() + value_2In.read());
        break;

    case 16: //Jalr

        resultOut.write(value_1In.read() + value_2In.read());
        break;

    }

}