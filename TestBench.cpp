#include "TestBench.h"
#include <systemc.h>

TestBench :: TestBench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(process);
  sensitive << clk;
  dont_initialize();
}

#include "Testbench.h"
#include <iomanip>



Testbench::Testbench(sc_module_name moduleName) : sc_module(moduleName)
{
	SC_THREAD(operation);
	sensitive << clk.pos();
	dont_initialize();
}

void Testbench::operation()
{
	for (int i = 0; true; i++)
	{
		wait();
		print();
	}
}
void Testbench::print()
{
	std::cout << "====================CAMINO DE DATOS===================\n";
	std::cout << "Modulo: INSTRUCTION MEMORY-----------\n";

	sc_uint<5> opCode, rs1, rs2, rd;
	sc_int<17> imm;

	std::cout << "Time     OpCode      rs1       rs2       rd        imm\n";
	std::cout << "--------------------------------------------------------\n";

	for (int i = 1; i < 10; i++){
		instructionNumberIn.write(i);
		wait();
		wait();

	for (sc_uint<5> i = 0; i < 5; i++){
		opCode[i] = operationIn.read()[i];
		}

	for (sc_uint<5> i = 5, j = 0; i < 10; i++, j++){
		rs1[j] = operationIn.read()[i];
	}

	for (sc_uint<6> i = 10, j = 0; i < 15; i++, j++){
		rs2[j] = operationIn.read()[i];
	}

	for (sc_uint<6> i = 15, j = 0; i < 20; i++, j++){
		rd[j] = operationIn.read()[i];
		}

		for (sc_uint<6> i = 20, j = 0; i < 32; i++, j++){
			imm[j] = operationIn.read()[i];
		}
	}


	
	std::cout << " Time    operand1    operand2    operand3    instruction\n";
	std::cout << "--------------------------------------------------------\n";
	
	std::cout << std::setw(5) << sc_time_stamp();
	std::cout << std::setw(12) << operand1.to_string();
	std::cout << std::setw(12) << operand2.to_string();
	std::cout << std::setw(12) << operand3.to_string();
	std::cout << std::setw(15) << instruction.to_string() << '\n';
	std::cout << "--------------------------------------------------------\n";
	std::cout << endl;

	std::cout << "Modulo: Unidad control---------------------------\n";
	std::cout << " Ex_ALUOpOut  :" << Ex_ALUOpOut.read().to_string() << "\n";
	std::cout << " Ex_ALUSrcOut  :" << Ex_ALUSrcOut.read() << "\n";
	std::cout << " Mem_MemWriteOut  :" << Mem_MemWriteOut.read() << "\n";
	std::cout << " Mem_MemReadOut  :" << Mem_MemReadOut.read() << "\n";
	std::cout << " Mem_BranchOut  :" << Mem_BranchOut.read() << "\n";
	std::cout << " Wb_MemtoRegOut  :" << Wb_MemtoRegOut.read() << "\n";
	std::cout << " Wb_RegWriteOut  :" << Wb_RegWriteOut.read() << "\n";
	std::cout << endl;

	std::cout << "Modulo:  REGISTER-----------\n";
	std::cout << " aOut  :" << aOut.read().to_string() << "\n";
	std::cout << " bOut  :" << bOut.read().to_string() << "\n";
	std::cout << endl;

	std::cout << "Modulo: ALU ------------------------\n";
	std::cout << "  resultOut :" << resultOut_alu.read().to_string() << "\n";
	std::cout << endl;

	std::cout << "Modulo: DATA_MEMORY ------------------------\n";
	std::cout << "  read_dataOut :" << read_dataOut.read().to_string() << "\n";
	std::cout << "Modulo: MUX------------------------\n";
	std::cout << "  cOut :" << cOut.read().to_string() << "\n";
	std::cout << endl;
}