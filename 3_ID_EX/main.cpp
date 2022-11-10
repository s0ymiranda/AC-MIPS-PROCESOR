#include "ID_EX.h"
#include "TestBench.h"


int sc_main(int argv, char* argc[]) {

    sc_time period(10,SC_NS);
    sc_time delay(0,SC_NS);

    sc_clock clock("clock", period, 0.5, delay, true);

    id_ex id_ex("id_ex");
    TestBench TestBench("TestBench");

    sc_signal<sc_int<32>> rs1OutSg, rs2OutSg, imm_genOutSg;
    sc_signal<sc_uint<5>> rs1_registerOutSg, rs2_registerOutSg, target_registerOutSg, AluIns1Sg;

    sc_signal<sc_int<32>> rs1InSg, rs2InSg;
    sc_signal<sc_uint<5>> rs1_registerInSg, rs2_registerInSg, target_registerInSg, AluIns2Sg;

    sc_signal<bool> HazardSg, MemWrite1Sg, MemRead1Sg, MuxWb1Sg, RegWrite1WbSg;
    sc_signal<bool> MemWrite2Sg, MemRead2Sg, MuxWb2Sg, RegWrite2WbSg;
    
    id_ex.rs1In(rs1OutSg);
    id_ex.rs2In(rs2OutSg);
    id_ex.imm_genIn(imm_genOutSg);
    id_ex.rs1_registerIn(rs1_registerOutSg);
    id_ex.rs2_registerIn(rs2_registerOutSg);
    id_ex.target_registerIn(target_registerOutSg);
    id_ex.HazardIn(HazardSg);
    id_ex.Mem_MemWriteIn(MemWrite1Sg);
    id_ex.Mem_MemReadIn(MemRead1Sg);
    id_ex.Wb_MemtoRegIn(MuxWb1Sg);
    id_ex.Wb_RegWriteIn(RegWrite1WbSg);
    id_ex.Ex_ALUIn(AluIns1Sg);

    id_ex.rs1Out(rs1InSg);
    id_ex.rs2Out(rs2InSg);
    id_ex.rs1_registerOut(rs1_registerInSg);
    id_ex.rs2_registerOut(rs2_registerInSg);
    id_ex.target_registerOut(target_registerInSg);
    id_ex.Mem_MemWriteOut(MemWrite2Sg);
    id_ex.Mem_MemReadOut(MemRead2Sg);
    id_ex.Wb_MemtoRegOut(MuxWb2Sg);
    id_ex.Wb_RegWriteOut(RegWrite2WbSg);
    id_ex.Ex_ALUOut(AluIns2Sg);


    TestBench.rs1In(rs1InSg);
    TestBench.rs2In(rs2InSg);
    TestBench.rs1_registerIn(rs1_registerInSg);
    TestBench.rs2_registerIn(rs2_registerInSg);
    TestBench.target_registerIn(target_registerInSg);
    TestBench.Mem_MemWriteIn(MemWrite2Sg);
    TestBench.Mem_MemReadIn(MemRead2Sg);
    TestBench.Wb_MemtoRegIn(MuxWb2Sg);
    TestBench.Wb_RegWriteIn(RegWrite2WbSg);
    TestBench.Ex_ALUIn(AluIns2Sg);

    TestBench.rs1Out(rs1OutSg);
    TestBench.rs2Out(rs2OutSg);
    TestBench.imm_genOut(imm_genOutSg);
    TestBench.rs1_registerOut(rs1_registerOutSg);
    TestBench.rs2_registerOut(rs2_registerOutSg);
    TestBench.target_registerOut(target_registerOutSg);
    TestBench.HazardOut(HazardSg);
    TestBench.Mem_MemWriteOut(MemWrite1Sg);
    TestBench.Mem_MemReadOut(MemRead1Sg);
    TestBench.Wb_MemtoRegOut(MuxWb1Sg);
    TestBench.Wb_RegWriteOut(RegWrite1WbSg);
    TestBench.Ex_ALUOut(AluIns1Sg);


       
    
    id_ex.clkIn(clock);

    TestBench.clkIn(clock);

    sc_start();

  return 0;
}