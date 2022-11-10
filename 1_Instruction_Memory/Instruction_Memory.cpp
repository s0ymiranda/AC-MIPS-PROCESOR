#include "Instruction_Memory.h"

InstructionMemory::InstructionMemory(sc_module_name moduleName) : sc_module(moduleName), instructionNumberIn("instructonNumberIn"), operationOut("operationOut"){

  ifstream instructionFile("program.txt", ios::in);
   //instructionFile.fail
	 	if (instructionFile.fail())
		exit(EXIT_FAILURE);

  numOfInstructions = 0;
  std::string line; //line

  while (!instructionFile.eof()) { //!instructionFile.eof() instructionFile.eof() != true
    getline(instructionFile, line);
    //if(instruction != '\n') 
		numOfInstructions++;
  }

  instructionFile.close();

  instructionFile.open("program.txt", ios::in);
  if (instructionFile.fail()) 
		exit(EXIT_FAILURE);

  instructionsList = new std::string[numOfInstructions];
  for (sc_int<32> i = 0; !instructionFile.eof();){
    getline(instructionFile, instructionsList[i]);
    if(instructionsList[i] == "") {
        continue;
      }
    i++;
  }
  instructionFile.close();

	SC_METHOD(operation);
	sensitive << clk.neg();
	dont_initialize();
}

void InstructionMemory::list (std::string instruction){
  /*
  0 add
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
  (12+1) slti
  15 jal
  16 jalr
  */

  /*
  Bits 0 - 4, tipo de instruccion OpCode
	Bits 5 - 9, primer registro rs1
	Bits 10 - 14, segundo registro rs2
	Bits 15 - 19, tercer registro rd
  Bits 20 - 31, Valor inmediato u offset
  */

 	std::string aux = instruction.substr(0, instruction.find_first_of(' '));
	if (aux.back() == ':'){
		instruction = instruction.substr(instruction.find_first_of(' ') + 1);
		aux = instruction.substr(0, instruction.find_first_of(' '));
	}

	sc_uint<5> opCode = 0;
	operand = 0;

  if(aux == "add" or aux == "sub" or aux == "sll" or aux == "slt" or aux == "or" or aux == "and"){
  /*
  Bits 0 - 4, tipo de instruccion 
	Bits 5 - 9, primer registro rs1
	Bits 10 - 14, segundo registro rs2
	Bits 15 - 19, tercer registro rd
  Bits 20 - 31, 0
  */

  std::string aux2(instruction.substr(instruction.find_first_of('x') + 1));
		sc_int<32> rd = stoi(aux2); //rd 
		//registerValidation(dir01);
		std::string aux3(aux2.substr(aux2.find_first_of(',') + 3));
		//cout<<aux3<<endl;
		sc_int<32> rs1 = stoi(aux3); //rs1
		//registerValidation(dir02);
		std::string aux4(aux3.substr(aux3.find_first_of(',') + 3));
		sc_int<32> rs2 = stoi(aux4); //rs2
		//registerValidation(dir03);

/*
	for(int i = 0; i < 32; i++){
		std::cout << operand[i];
	}
	cout<<endl<<"dir1: "<<"="<<dir01<<endl;
	
	for(int i = 0; i < 5; i++){
		std::cout << dir01[i];
	}
cout<<endl<<"dir2: "<<"="<<dir02<<endl;
		for(int i = 0; i < 32; i++){
		std::cout << dir02[i];
	}
cout<<endl<<"dir3: "<<"="<<dir03<<endl;
		for(int i = 0; i < 5; i++){
		std::cout << dir03[i];
	}
	cout<<endl;
 
		operand <<= 5;
		
	for(int i = 0; i < 32; i++){
		std::cout << operand[i];
	}
	cout<<endl;

		for(int i = 0; i < 32; i++){
		std::cout << operand[i];
	}
	cout<<endl;
	*/
		operand += rd;
		operand <<= 5;
		operand += rs2;
		operand <<= 5;
		operand +=rs1;
		operand <<= 5;

		if (aux == "add")
			opCode = 0;
		else if (aux == "sub")
			opCode = 2;
		else if (aux == "sll")
			opCode = 3;
		else if (aux == "or")
			opCode = 5;
		else if (aux == "and")
			opCode = 7;
		else if (aux == "slt")
			opCode = (12+1);
		operand += opCode;
		operationOut.write(operand);
  }

	else if (aux == "addi" or aux == "slli" or aux == "ori" or aux == "slti"){ //slti
  /*
  Bits 0 - 4, tipo de instruccion 
	Bits 5 - 9, primer registro rs1
	Bits 10 - 14, 0
	Bits 15 - 19, registro rd
  Bits 20 - 31, Valor inmediato o shamt
  */

	std::string aux2(instruction.substr(instruction.find_first_of('x') + 1));
	sc_int<32> rd = stoi(aux2);
	registerValidation(rd);
	std::string aux3(aux2.substr(aux2.find_first_of(',') + 3));
	sc_int<32> rs1 = stoi(aux3);
	registerValidation(rs1);
	std::string aux4(aux3.substr(aux3.find_first_of(',') + 2));
	sc_int<32> imm = stoi(aux4);
	immValidation(imm);

	operand += imm;
	operand <<= 5;
	operand += rd;
	operand <<= 10; //porque rs2 es 0
	operand += rs1;
	operand <<= 5;

	if (aux == "addi")
		opCode = 1;
	else if (aux == "slli")
		opCode = 4;
	else if (aux == "ori")
		opCode = 6;
	else if (aux == "slti")
		opCode = 14;

	operand += opCode;
	operationOut.write(operand);
}

	else if (aux == "lw" or aux == "sw"){
		std::string aux2(instruction.substr(instruction.find_first_of('x') + 1));
		sc_int<32> rd = stoi(aux2);
		registerValidation(rd);
		std::string aux3(aux2.substr(aux2.find_first_of(',') + 2));
		sc_int<32> offset = stoi(aux3);
		std::string aux4(aux3.substr(aux3.find_first_of('x') + 1));
		immValidation(offset);
		sc_int<32> rs1 = stoi(aux4);
		registerValidation (rs1);

		operand += offset;
		operand <<= 5;
		operand += rd;
		operand <<= 10;
		operand += rs1;
		operand <<= 5;
		if (aux == "lw")
			opCode = 8;
		else if (aux == "sw")
			opCode = 9;
		operand += opCode;
		operationOut.write(operand);
	}

	else if (aux == "beq" or aux == "bne" or aux == "blt"){ //blt
		std::string aux2(instruction.substr(instruction.find_first_of('x') + 1));
		sc_int<32> rs1 = stoi(aux2);
		registerValidation(rs1);
		std::string aux3(aux2.substr(aux2.find_first_of('x') + 1));
		sc_int<32> rs2 = stoi(aux3);
		registerValidation(rs2);
		std::string aux4(aux3.substr(aux3.find_first_of(',') + 2));
		aux4.pop_back();

		bool found = false;
		sc_int<17> linea = 0;
		for (sc_int<17> i = 0; i < numOfInstructions; i++){
			sc_int<18> pos = instructionsList[i].find_first_of(':');
			if (pos != -1){
					std::string temp = instructionsList[i].substr(0, pos);
					if (aux4 == temp){
						linea = i - instructionNumberIn.read();
						found = true;
						break;
				}
			}
		}

		try{
			if (!found){
				throw aux4.c_str();
			}
		}
		catch (const char* err){
			std::cout << "\n\nNo existe la etiqueta de salto " << err << " en el código especificado.\n\n";
			sc_stop();
		}
		/*
		for (sc_uint<5> i = 0; i < 18; i++){
			operand[i] = linea[i];
		}
		*/
		
    operand += linea;
		operand <<= 10;
		operand += rs2;
		operand <<= 5;
		operand += rs1;
		operand <<= 5;

			if (aux == "beq")
			opCode = 10;
		else if (aux == "bne")
			opCode = 11;
		else if (aux == "blt")
			opCode = 12;

		operand += opCode;
		operationOut.write(operand);
	}

	else if(aux == "jal"){

		
	}

	else if(aux == "jalr"){
	

	}
}

void InstructionMemory::operation(){
  if (instructionNumberIn.read() >= 0 and instructionNumberIn.read() < numOfInstructions)
		list(instructionsList[instructionNumberIn.read()]);
  else
	sc_stop();
}

inline void InstructionMemory::registerValidation(sc_int<32> dir){
	try{
		if (dir < 0 || dir > 31)
			throw dir;
	}
	catch (sc_int<32> &dir){
		std::cout << "\n\nEl registro ingresado " << dir << " no existe en el archivo de registros.\n\n";
		sc_stop();
	}
}

inline void InstructionMemory::immValidation(sc_int<32> dir){
	try{
		// El valor inmediato solo puede ser desde -2^17 hasta 2^17 - 1
		if (dir < -131072 || dir > 131071)
			throw dir;
	}
	catch (sc_int<32> &dir){
		std::cout << "\n\nEl valor inmediato ingresado " << dir << " no es válido en la operación.\n\n";
		sc_stop();
	}
}