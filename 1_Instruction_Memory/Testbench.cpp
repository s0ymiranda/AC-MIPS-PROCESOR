#include "Testbench.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>

Testbench::Testbench(sc_module_name TB_InstructionMemory) : sc_module(TB_InstructionMemory), clk("clk"), instructionNumberOut("instructionNumberOut"), operationIn("operationIn"){
	SC_THREAD(test);
	sensitive << clk;
	dont_initialize();
}

void Testbench::test(){
	wait();
	std::cout << " Time    operand1    operand2    operand3    instruction\n";
	std::cout << "--------------------------------------------------------\n";

	// Si Instruction Memory es sensible a la entrada, la lectura de la linea 0 no la detecta, si no que es la lectura por defecto al principio del programa. Por esto, basta con colocar un wait ac� y ya tendremos la lectura de la primera l�nea. En este caso, el for empezar�a a partir de 1 (0 ya lo ley�)

	for (int i = 1; i < 10; i++){
	// for (int i = 0; i < 10; i++)
		instructionNumberOut.write(i);
		// Al estar sincronizado con reloj, el testbench debe esperar un ciclo completo para obtener respuesta de Instruction Memory, debido a la lectura y escritura sobre los puertos
		// wait();
		wait();
		wait();

		for (sc_uint<3> i = 0; i < 4; i++)
			instruction[i] = operationIn.read()[i];

		if (instruction == 3 or instruction == 6 or instruction == 7 or instruction == 12 or instruction == 13 or instruction == 8 or instruction == 9 or instruction == 14 or instruction == 15){
			for (sc_uint<4> i = 4, j = 0; i < 9; i++, j++)
				operand1[j] = operationIn.read()[i];

			for (sc_uint<4> i = 9, j = 0; i < 14; i++, j++)
				operand2[j] = operationIn.read()[i];

			for (sc_uint<6> i = 14, j = 0; i < 32; i++, j++)
				operand3[j] = operationIn.read()[i];
		}
		else
		{
			for (sc_uint<4> i = 4, j = 0; i < 9; i++, j++)
				operand1[j] = operationIn.read()[i];

			for (sc_uint<4> i = 9, j = 0; i < 14; i++, j++)
				operand2[j] = operationIn.read()[i];

			for (sc_uint<5> i = 14, j = 0; i < 19; i++, j++)
				operand3[j] = operationIn.read()[i];
		}
		print();
	}

	std::cout << "--------------------------------------------------------\n";

	sc_stop();
}

void Testbench::print()
{
	std::cout << std::setw(5) << sc_time_stamp();
	std::cout << std::setw(12) << operand1.to_string();
	std::cout << std::setw(12) << operand2.to_string();
	std::cout << std::setw(12) << operand3.to_string();
	std::cout << std::setw(15) << instruction.to_string() << '\n';
}