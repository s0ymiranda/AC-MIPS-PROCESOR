#include "RegisterFile.h"
RegisterFile::RegisterFile(sc_module_name moduleName) : sc_module(moduleName){

	SC_METHOD(write);
	sensitive << clk.pos();
	SC_METHOD(read);
	sensitive << clk.neg();
}

void RegisterFile::write()
{
	if (weIn.read() and rdIn.read()){
		registers[rdIn.read()] = rIn.read();
  }
}

void RegisterFile::read()
{
	if (rs1In.read() >= 0 and rs1In.read() < 32)
		s1Out.write(registers[rs1In.read()]);
	if (rs2In.read() >= 0 and rs2In.read() < 32)
		s2Out.write(registers[rs2In.read()]);
}