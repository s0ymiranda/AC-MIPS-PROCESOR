#include "ID_EX.h"
#include "TestBench.h"


int sc_main(int argv, char* argc[]) {

    sc_time period(10,SC_NS);
    sc_time delay(10,SC_NS);

    sc_clock clock("clock", period, 0.5, delay, true);

    id_ex id_ex("id_ex");
    TestBench TestBench("TestBench");

    sc_signal<sc_int<32>> rs1OutSg, rs2OutSg, imm_genOutSg;
    sc_signal<sc_uint<5>> rs1_registerOutSg, rs2_registerOutSg, target_registerOutSg;

    sc_signal<sc_int<32>> rs1InSg, rs2InSg;
    sc_signal<sc_uint<5>> rs1_registerInSg, rs2_registerInSg, target_registerInSg;

    id_ex.rs1In(rs1OutSg);
    id_ex.rs2In(rs2OutSg);
    id_ex.imm_genIn(imm_genOutSg);
    id_ex.rs1_registerIn(rs1_registerOutSg);
    id_ex.rs2_registerIn(rs2_registerOutSg);
    id_ex.target_registerIn(target_registerOutSg);

    id_ex.rs1Out(rs1InSg);
    id_ex.rs2Out(rs2InSg);
    id_ex.rs1_registerOut(rs1_registerInSg);
    id_ex.rs2_registerOut(rs2_registerInSg);
    id_ex.target_registerOut(target_registerInSg);

    TestBench.rs1In(rs1InSg);
    TestBench.rs2In(rs2InSg);
    TestBench.rs1_registerIn(rs1_registerInSg);
    TestBench.rs2_registerIn(rs2_registerInSg);
    TestBench.target_registerIn(target_registerInSg);

    TestBench.rs1Out(rs1OutSg);
    TestBench.rs2Out(rs2OutSg);
    TestBench.imm_genOut(imm_genOutSg);
    TestBench.rs1_registerOut(rs1_registerOutSg);
    TestBench.rs2_registerOut(rs2_registerOutSg);
    TestBench.target_registerOut(target_registerOutSg);
       
    
    id_ex.clkIn(clock);

    TestBench.clkIn(clock);

    sc_start();

  return 0;
}