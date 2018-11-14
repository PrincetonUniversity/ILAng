#include <iostream>
#include <fstream>
#include <ila++.h>

using namespace std;
using namespace ila;

#define SET_UPDATE(INST, RD, RES) do { \
            (INST).SetUpdate(r0, Ite( (RD) == 0, (RES), r0 ));  \
            (INST).SetUpdate(r1, Ite( (RD) == 1, (RES), r1 ));  \
            (INST).SetUpdate(r2, Ite( (RD) == 2, (RES), r2 ));  \
            (INST).SetUpdate(r3, Ite( (RD) == 3, (RES), r3 ));  \
            } while(0);

Ila BuildModel() {
    // build the ila
    auto alu_ila = Ila("simpleALU");
    auto inst = alu_ila.NewBvInput("inst", 8);
    auto r0 = alu_ila.NewBvState("r0", 8);
    auto r1 = alu_ila.NewBvState("r1", 8);
    auto r2 = alu_ila.NewBvState("r2", 8);
    auto r3 = alu_ila.NewBvState("r3", 8);

    auto op  = inst(7,6);
    auto rs1 = inst(5,4);
    auto rs2 = inst(3,2);
    auto rd  = inst(1,0);

    auto rs1_val =  Ite(rs1 == 0 , r0 ,
                    Ite(rs1 == 1 , r1 ,
                    Ite(rs1 == 2 , r2 ,
                                   r3
                        )));

    auto rs2_val =  Ite(rs2 == 0 , r0 ,
                    Ite(rs2 == 1 , r1 ,
                    Ite(rs2 == 2 , r2 ,
                                   r3
                        )));

    auto NOP = alu_ila.NewInstr("NOP");
    {
        NOP.SetDecode(op == BvConst(0,2) );
    }

    auto ADD = alu_ila.NewInstr("ADD");
    {
        ADD.SetDecode(op == BvConst(1,2) );
        auto res = rs1_val + rs2_val;
        SET_UPDATE(ADD, rd, res);
    }

    auto SUB = alu_ila.NewInstr("SUB");
    {
        SUB.SetDecode(op == BvConst(2,2) );
        auto res = rs1_val - rs2_val;
        SET_UPDATE(SUB, rd, res);
    }

    auto AND = alu_ila.NewInstr("AND");
    {
        AND.SetDecode(op == BvConst(3,2) );
        auto res = rs1_val & rs2_val;
        SET_UPDATE(AND, rd, res);
    }

    return alu_ila;
}

void GenerateVerilogModel(const Ila & a) {
	ofstream fout("vlg-gen/alu.v");
    a.ExportToVerilog(fout);
}


int main() {
	GenerateVerilogModel(BuildModel());
	return 0;
}