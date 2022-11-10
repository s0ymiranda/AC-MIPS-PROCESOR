//Including Instruction Fetch libraries

#include "Mux2.h"
#include "PC.h"
#include "Instruction_Memory.h"

//Including Instruction Decode libraries

#include "Adder.h"
#include "Branch_Condition.h"
#include "Hazard_Detection_Unit.h"
#include "IF_ID.h"
#include "ImmGen.h"
#include "RegisterFile.h"

//Including Execution libraries

#include "ALU.h"
#include "FORWARDING_UNIT.h"
#include "ID_EX.h"
#include "MUX_3.h"

//Including WriteBack libraries

#include "5_Mux.h"
#include "MEM_WB.h"


int sc_main(int argc, char *argv[])
{
	
    //Clock settings

	sc_time period(10, SC_NS);
	sc_time delay(0, SC_NS);
	sc_clock clock("clock", period, 0.5, delay, true);

//==============================================================================================

    //Instruction Fetch modules:

    //Mux2 mux2("mux2");
    Adder adder_1("adder_1");
    PC pc("pc");
    InstructionMemory instruction_memory("instruction memory");


    //Instruction Fetch signals:

    sc_signal<sc_int<32>> PCAddressInSg, PCAddressIF_IDOutSg, PCAddressInsMemOutSg, PCAddressAdderOutSg;
    sc_signal<sc_uint<32>> InsMemOperationOutSg;

    //Connecting the signals to the ports:

    pc.adressIn(PCAddressInSg);
    pc.adressAdderOut(PCAddressAdderOutSg);
    pc.adressPC_IF_IDOut(PCAddressIF_IDOutSg);
    pc.adressInstructionMemoryOut(PCAddressInsMemOutSg);

    instruction_memory.instructionNumberIn(PCAddressInsMemOutSg);
    instruction_memory.operationOut(InsMemOperationOutSg);
    
    adder_1.aIn(PCAddressAdderOutSg);
    //adder_1.bIn(); This is always a number (4)
    //adder.resultOut();

//==============================================================================================

    //Instruction Decode modules:

	IF_ID if_id("if_id");
    Adder adder_2("adder_2");
    Branch_Condition branch_condition("branch condition");
    Hazard_Detection_Unit hdu("hazard detection unit");
    ImmGen imm_gen("ImmGen");
    RegisterFile register_file("register file");

    //Instruction Decode signals:

    sc_signal<bool> hazzardSg;
    sc_signal<sc_int<32>> ID_EXAdderOutSg, RegisterFileID_EXrs1OutSg, RegisterFileID_EXrs2OutSg, ImmGenID_EXOutSg;
    sc_signal<sc_uint<5>> RegisterFile1OutSg, RegisterFile2OutSg, RegisterRs1OutSg, RegisterRs2OutSg, TargetRegisterOutSg;
    sc_signal<sc_int<12>> immGenOutSg;
    sc_signal<sc_uint<5>> HDUrs1OutSg, HDUrs2OutSg, ControlOutSg;

    //Connecting the signals to the ports:

    if_id.pcIn(PCAddressIF_IDOutSg);
    if_id.insMemIn(PCAddressInsMemOutSg);
    if_id.hazardIn(hazzardSg);
    if_id.fileRegister1Out(RegisterFile1OutSg);
    if_id.fileRegister2Out(RegisterFile2OutSg);
    if_id.immGenOut(immGenOutSg);
    if_id.ID_EX0Out(ID_EXAdderOutSg);
    if_id.ID_EX1Out(RegisterRs1OutSg);
    if_id.ID_EX2Out(RegisterRs2OutSg);
    if_id.ID_EX3Out(TargetRegisterOutSg);
    if_id.ID_unidadControlOut(ControlOutSg);
    if_id.ID_HDUrs1Out(HDUrs1OutSg);
    if_id.ID_HDUrs2Out(HDUrs2OutSg);

    adder_2.aIn(ID_EXAdderOutSg);
    //adder_2.resultOut();

    register_file.rs1In(RegisterFile1OutSg);
    register_file.rs2In(RegisterFile2OutSg);
    register_file.rIn(MuxRegisterFileOutSg);
    //register_file.weIn();
    register_file.rdIn(MEM_WBTargetRegisterOutSg);
    register_file.s1Out(RegisterFileID_EXrs1OutSg);
    register_file.s2Out(RegisterFileID_EXrs2OutSg);

    imm_gen.IF_IDIn(immGenOutSg);
    imm_gen.ID_EXOut(ImmGenID_EXOutSg);

    hdu.rs1In(HDUrs1OutSg);
    hdu.rs2In(HDUrs2OutSg);
    //hdu.IDEXrdIn(IDEXrdSg);
    //hdu.IDEXInstrucIn(IDEXInstrucSg);

    //Control Unit left


//==============================================================================================

    //Execution modules:

    id_ex id_ex("id_ex");
    ALU alu("alu");
    F_Unit f_unit("forwarding unit");
    Mux mux_1("mux_1"), mux_2("mux_2");

    //Execution signals:

    sc_signal<sc_int<32>> ID_EXMux1OutSg, ID_EXMux2OutSg, Mux1ALUrs1OutSg, Mux2ALUrs2OutSg, ALUResultOutSg;
    sc_signal<sc_uint<5>> ID_EXF_Unitrs1OutSg, ID_EXF_Unitrs2OutSg, EX_MEMTargetRegisterOutSg;
    sc_signal<bool> Mux1_aOutSg, Mux1_bOutSg, Mux2_aOutSg, Mux2_bOutSg; 
    //Waiting for the next stages (MEM, WB)


    //Connecting the signals to the ports:

    id_ex.rs1In(RegisterFileID_EXrs1OutSg);
    id_ex.rs2In(RegisterFileID_EXrs2OutSg);
    id_ex.imm_genIn(ImmGenID_EXOutSg);
    id_ex.rs1_registerIn(RegisterRs1OutSg);
    id_ex.rs2_registerIn(RegisterRs2OutSg);
    id_ex.target_registerIn(TargetRegisterOutSg);
    id_ex.rs1Out(ID_EXMux1OutSg);
    id_ex.rs2Out(ID_EXMux2OutSg);
    id_ex.rs1_registerOut(ID_EXF_Unitrs1OutSg);
    id_ex.rs2_registerOut(ID_EXF_Unitrs2OutSg);
    id_ex.target_registerOut(EX_MEMTargetRegisterOutSg);

    mux_1.value_1In(ID_EXMux1OutSg);
    mux_1.value_2In(MuxRegisterFileOutSg);
    mux_1.value_3In(ALUResultDataMemoryOutSg);
    mux_1.aIn(Mux1_aOutSg);
    mux_1.bIn(Mux1_bOutSg);
    mux_1.valueOut(Mux1ALUrs1OutSg);

    mux_2.value_1In(ID_EXMux2OutSg);
    mux_2.value_2In(MuxRegisterFileOutSg);
    mux_2.value_3In(ALUResultDataMemoryOutSg);
    mux_2.aIn(Mux2_aOutSg);
    mux_2.bIn(Mux2_aOutSg);
    mux_2.valueOut(Mux2ALUrs2OutSg);

    alu.value_1In(Mux1ALUrs1OutSg);
    alu.value_2In(Mux2ALUrs2OutSg);
    //alu.instructIn();
    alu.resultOut(ALUResultOutSg);

    f_unit.rs1_registerIn(ID_EXF_Unitrs1OutSg);
    f_unit.rs2_registerIn(ID_EXF_Unitrs2OutSg);
    f_unit.ex_mem_registerIn(TargetRegisterMEM_WBOutSg);
    f_unit.mem_wb_registerIn(MEM_WBTargetRegisterOutSg);
    //f_unit.mux1In();
    //f_unit.mux2In();
    f_unit.mux1_aOut(Mux1_aOutSg);
    f_unit.mux1_bOut(Mux1_bOutSg);
    f_unit.mux2_aOut(Mux2_aOutSg);
    f_unit.mux2_bOut(Mux2_aOutSg);

//==============================================================================================

    //MemoryAccess modules:

    EX_MEM ex_mem("ex_mem");
    Data_Memory data_memory("data memory");

    //MemoryAcces signals:

    sc_signal<sc_int<32>> ALUResultDataMemoryOutSg, rs2DataMemoryOutSg, TargetRegisterMEM_WBOutSg, ResultMEM_WBOutSg;

    

    //Connecting the signals to the ports:

    ex.mem.memo_In0(ALUResultOutSg);
    ex.mem.memo_In1(Mux2ALUrs2OutSg);
    ex_mem.direccion_In(EX_MEMTargetRegisterOutSg);
    ex.mem.memo_Out0(ALUResultDataMemoryOutSg);
    ex.mem.memo_Out1(rs2DataMemoryOutSg);
    ex.mem.memo_Out1(TargetRegisterMEM_WBOutSg);
    //ex_mem.Mem_MemWriteIn();
    //ex_mem.Mem_MemReadIn();
    //ex_mem.Wb_MemtoRegIn();
    //ex_mem.Wb_RegWriteIn();

    data_memory.addressIn(ALUResultDataMemoryOutSg);
    data_memory.write_dataIn(rs2DataMemoryOutSg);
    //data_memory.writeIn(); 
    //data_memory.readIn();
    data_memory.read_dataOut(ResultMEM_WBOutSg);
    data_memory.read_dataOut(rs2DataMemoryOutSg);

//==============================================================================================


    //WriteBack modules:

    MEM_WB mem_wb("mem_wb");
    Mux5 mux5("mux5");

    //WriteBack signals:

    sc_signal<sc_int<32>> ResultALUMuxOutSg, rs2MEM_WBMuxOutSg, MEM_WBTargetRegisterOutSg, MuxRegisterFileOutSg;


    //Connecting the signals to the ports:

    mem_wb.Wb_MRegIn(ResultMEM_WBOutSg);
    mem_wb.Wb_RegWIn(rs2DataMemoryOutSg);
    mem_wb.dir_In(TargetRegisterMEM_WBOutSg);
    memm_wb.Wb_MRegOut(ResultALUMuxOutSg);
    mem_wb.Wb_RegWOut(rs2MEM_WBMuxOutSg);
    mem_wb.dir_Out(MEM_WBTargetRegisterOutSg);

    mux5.aIn(ResultALUMuxOutSg);
    mux5.bIn(rs2MEM_WBMuxOutSg);
    //mux5.sIn();
    mux5.cOut(MuxRegisterFileOutSg);
    

//==============================================================================================






	

	sc_start();

	return 0;
}


