//Including Instruction Fetch libraries
#include "1_Adder.h"
#include "1_Mux.h"
#include "1_PC.h"
#include "1_Instruction_Memory.h"

//Including Instruction Decode libraries

#include "2_Adder.h"
#include "2_Branch_Condition.h"
#include "2_Hazard_Detection_Unit.h"
#include "2_Control_Unit.h"
#include "2_IF_ID.h"
#include "2_ImmGen.h"
#include "2_RegisterFile.h"

//Including Execution libraries

#include "3_ALU.h"
#include "3_FORWARDING_UNIT.h"
#include "3_ID_EX.h"
#include "3_MUX_3.h"

//Including Mem libraries
#include "4_EX_MEM.h"
#include "4_Data_Memory.h"

//Including WriteBack libraries

#include "5_Mux.h"
#include "5_MEM_WB.h"


int sc_main(int argc, char *argv[])
{
	
    //Clock settings

	sc_time period(10, SC_NS);
	sc_time delay(0, SC_NS);
	sc_clock clock("clock", period, 0.5, delay, true);

//==============================================================================================

    //Instruction Fetch modules:

    Mux1 mux1("mux1");
    Adder1 adder_1("adder_1");
    PC pc("pc");
    InstructionMemory instruction_memory("instruction_memory");


    //Instruction Fetch signals:

    sc_signal<sc_int<32>> PCAddressOutSg, PCAddressIF_IDOutSg, PCAddressInsMemOutSg, PCAddressAdderOutSg, Adder_1MuxOutSg;
    sc_signal<sc_uint<32>> InsMemOperationOutSg;

    //Connecting the signals to the ports:

    mux1.aIn(Adder_2MuxOutSg);
    mux1.bIn(Adder_1MuxOutSg);
    mux1.sIn(muxPcSg);
    mux1.cOut(PCAddressOutSg);

    pc.adressIn(PCAddressOutSg);
    pc.HazardIn(pcwriteSg);
    pc.adressAdderOut(PCAddressAdderOutSg);
    pc.adressPC_IF_IDOut(PCAddressIF_IDOutSg);
    pc.adressInstructionMemoryOut(PCAddressInsMemOutSg);

    instruction_memory.instructionNumberIn(PCAddressInsMemOutSg);
    instruction_memory.operationOut(InsMemOperationOutSg);
    
    adder_1.aIn(PCAddressAdderOutSg);
    adder_1.resultOut(Adder_1MuxOutSg);

//==============================================================================================

    //Instruction Decode modules:

	IF_ID if_id("if_id");
    Adder adder_2("adder_2");
    Branch_Condition branch_condition("branch condition");
    Control_Unit control_unit("control unit");
    Hazard_Detection_Unit hdu("hazard detection unit");
    ImmGen imm_gen("ImmGen");
    RegisterFile register_file("register file");

    //Instruction Decode signals:

    sc_signal<bool> hazzardSg, resultbranchOutSg, FlushSg, muxPcSg, MemWriteSg, MemReadSg, WbtoRegSg, WbWriteSg, muxControlSg, IFIDwriteSg, pcwriteSg ;
    sc_signal<sc_int<32>> ID_EXAdderOutSg, RegisterFileID_EXrs1OutSg, RegisterFileID_EXrs2OutSg, ImmGenID_EXOutSg, ImmGenAdderOutSg, Adder_2MuxOutSg;
    sc_signal<sc_uint<5>> RegisterFile1OutSg, RegisterFile2OutSg, RegisterRs1OutSg, RegisterRs2OutSg, TargetRegisterOutSg, ALUInsOutSg;
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
    if_id.controlFlushIn(FlushSg);
    if_id.hazardIn(IFIDwriteSg);
    

    adder_2.aIn(ID_EXAdderOutSg);
    adder_2.bIn(ImmGenAdderOutSg);
    adder_2.resultOut(Adder_2MuxOutSg);

    register_file.rs1In(RegisterFile1OutSg);
    register_file.rs2In(RegisterFile2OutSg);
    register_file.rIn(MuxRegisterFileOutSg);
    register_file.weIn(RegWrite4WbSg);
    register_file.rdIn(MEM_WBTargetRegisterOutSg);
    register_file.s1Out(RegisterFileID_EXrs1OutSg);
    register_file.s2Out(RegisterFileID_EXrs2OutSg);

    branch_condition.s1In(RegisterFileID_EXrs1OutSg);
    branch_condition.s2In(RegisterFileID_EXrs2OutSg);
    branch_condition.instrucIn(ControlOutSg);
    branch_condition.resultOut(resultbranchOutSg);

    control_unit.InstrucIn(ControlOutSg);
    control_unit.BranchConditionIn(resultbranchOutSg);
    control_unit.Ex_ALUOut(ALUInsOutSg);
    control_unit.IDIFflushOut(FlushSg);
    control_unit.muxPcsrOut(muxPcSg);
    control_unit.Mem_MemWriteOut(MemWriteSg);
    control_unit.Mem_MemReadOut(MemReadSg);
    control_unit.Wb_MemtoRegOut(WbtoRegSg);
    control_unit.Wb_RegWriteOut(WbWriteSg);

    hdu.IDEXInstrucIn(ALUInsOutSg);
    hdu.rs1In(HDUrs1OutSg);
    hdu.rs2In(HDUrs2OutSg);
    hdu.IDEXrdIn(EX_MEMTargetRegisterOutSg);
    hdu.muxControlOut(muxControlSg);
    hdu.IFIDwriteOut(IFIDwriteSg);
    hdu.pcwriteOut(pcwriteSg);

    imm_gen.IF_IDIn(immGenOutSg);
    imm_gen.ID_EXOut(ImmGenID_EXOutSg);
    immGen.AdderOut(ImmGenAdderOutSg);


//==============================================================================================

    //Execution modules:

    id_ex id_ex("id_ex");
    ALU alu("alu");
    F_Unit f_unit("forwarding unit");
    Mux mux_1("mux_1"), mux_2("mux_2");

    //Execution signals:

    sc_signal<sc_int<32>> ID_EXMux1OutSg, ID_EXMux2OutSg, Mux1ALUrs1OutSg, Mux2ALUrs2OutSg, ALUResultOutSg;
    sc_signal<sc_uint<5>> ID_EXF_Unitrs1OutSg, ID_EXF_Unitrs2OutSg, EX_MEMTargetRegisterOutSg, AluIns2Sg;
    sc_signal<bool> Mux1_aOutSg, Mux1_bOutSg, Mux2_aOutSg, Mux2_bOutSg, MemWrite2Sg, MemRead2Sg, MuxWb2Sg, RegWrite2WbSg; 


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
    id_ex.Ex_ALUIn(ALUInsOutSg);
    id_ex.Mem_MemWriteIn(MemWriteSg);
    id_ex.Mem_MemReadIn(MemReadSg);
    d_ex.Wb_MemtoRegIn(WbtoRegSg);
    id_ex.Wb_RegWriteIn(WbWriteSg);
    id_ex.HazardIn(muxControlSg);
    id_ex.Mem_MemWriteOut(MemWrite2Sg);
    id_ex.Mem_MemReadOut(MemRead2Sg);
    id_ex.Wb_MemtoRegOut(MuxWb2Sg);
    id_ex.Wb_RegWriteOut(RegWrite2WbSg);
    id_ex.Ex_ALUOut(AluIns2Sg);

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
    alu.instructIn(AluIns2Sg);
    alu.resultOut(ALUResultOutSg);

    f_unit.rs1_registerIn(ID_EXF_Unitrs1OutSg);
    f_unit.rs2_registerIn(ID_EXF_Unitrs2OutSg);
    f_unit.ex_mem_registerIn(TargetRegisterMEM_WBOutSg);
    f_unit.mem_wb_registerIn(MEM_WBTargetRegisterOutSg);
    f_unit.mux1In(MemWrite3Sg);
    f_unit.mux2In(RegWrite4WbSg);
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
    sc_signal<bool> MemWrite3Sg, MemRead3Sg, MuxWb3Sg, RegWrite3WbSg;
    

    //Connecting the signals to the ports:

    ex.mem.memo_In0(ALUResultOutSg);
    ex.mem.memo_In1(Mux2ALUrs2OutSg);
    ex_mem.direccion_In(EX_MEMTargetRegisterOutSg);
    ex.mem.memo_Out0(ALUResultDataMemoryOutSg);
    ex.mem.memo_Out1(rs2DataMemoryOutSg);
    ex.mem.memo_Out1(TargetRegisterMEM_WBOutSg);
    ex_mem.Mem_MemWriteIn(MemWrite2Sg);
    ex_mem.Mem_MemReadIn(MemRead2Sg);
    ex_mem.Wb_MemtoRegIn(MuxWb2Sg);
    ex_mem.Wb_RegWriteIn(RegWrite2WbSg);
    ex_mem.Mem_MemWriteOut(MemWrite3Sg);
    ex_mem.Mem_MemReadOut(MemRead3Sg);
    ex_mem.Wb_MemtoRegOut(MuxWb3Sg);
    ex_mem.Wb_RegWriteOut(RegWrite3WbSg);

    data_memory.addressIn(ALUResultDataMemoryOutSg);
    data_memory.write_dataIn(rs2DataMemoryOutSg);
    data_memory.writeIn(MemWrite3Sg); 
    data_memory.readIn(MemRead3Sg);
    data_memory.read_dataOut(ResultMEM_WBOutSg);
    data_memory.read_dataOut(rs2DataMemoryOutSg);

//==============================================================================================


    //WriteBack modules:

    MEM_WB mem_wb("mem_wb");
    Mux5 mux5_b("mux5");

    //WriteBack signals:

    sc_signal<sc_int<32>> ResultALUMuxOutSg, rs2MEM_WBMuxOutSg, MEM_WBTargetRegisterOutSg, MuxRegisterFileOutSg;
    sc_signal<bool> MuxWb4Sg, RegWrite4WbSg;

    //Connecting the signals to the ports:


    mem_wb.mem_In0(ResultMEM_WBOutSg);
    mem_wb.mem_In1(rs2DataMemoryOutSg);
    mem_wb.Wb_MRegIn(MuxWb3Sg);
    mem_wb.Wb_RegWIn(RegWrite3WbSg);
    mem_wb.dir_In(TargetRegisterMEM_WBOutSg);
    mem_wb.mem_Out0(ResultALUMuxOutSg);
    mem_wb.mem_Out1(rs2MEM_WBMuxOutSg);
    mem_wb.Wb_MRegOut(MuxWb4Sg);
    mem_wb.Wb_RegWOut(RegWrite4WbSg);
    mem_wb.dir_Out(MEM_WBTargetRegisterOutSg);

    mux5_b.aIn(ResultALUMuxOutSg);
    mux5_b.bIn(rs2MEM_WBMuxOutSg);
    mux5_b.sIn(MuxWb4Sg);
    mux5_b.cOut(MuxRegisterFileOutSg);


//==============================================================================================

    //Conecting all the modules to the clock signal:

    pc.clk(clock);
    instruction_memory.clk(clock);
    if_id.clk(clock);
    hdu.clk(clock);
    control_unit.clk(clock);
    register_file.clk(clock);
    imm_gen.clk(clock);
    id_ex.clk(clock);
    alu.clk(clock);
    f_unit.clk(clock);
    ex_mem.clk(clock);
    data_memory.clk(clock);
    mem_wb.clk(clock);

	sc_start();

	return 0;
}


