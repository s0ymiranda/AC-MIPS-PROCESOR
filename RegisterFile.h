#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H

#include <systemc.h>

class RegisterFile : public sc_module {

    public: 
            sc_in<sc_uint<5>> rdIn;      //register destination
            sc_in<sc_uint<5>> rs1In;     //register source 1
            sc_in<sc_uint<5>> rs2In;     //register source 2
            sc_in_clk clk;
            sc_in<sc_int<32>> rIn;      //result
            sc_in<bool> weIn;            //Write enable
            sc_out<sc_int<32>> s1Out;     // Variable dentro del rs1
            sc_out<sc_int<32>> s2Out;     // Variable dentro del rs2
           
            SC_CTOR(RegisterFile);

    private:

        //int registers[32];
        sc_vector<sc_signal<sc_int<32>>> SC_NAMED(registers, 32);
        void read();
        void write();


};

#endif