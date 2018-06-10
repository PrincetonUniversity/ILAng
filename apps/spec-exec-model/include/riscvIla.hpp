/********************

 RISC-V ILA  

********************/

#ifndef __RISCV_ILA_HPP__
#define __RISCV_ILA_HPP__

#include <set>
#include <vector>

#include "encoding.hpp"

#define SPECULATIVE_WINDOW_SIZE 10

class riscvILA_user
{

protected:
    Ila  model;

    ExprRef         pc;
    ExprRef         mem;
    std::vector<ExprRef> GPR_ARF; // R0-R31

    std::set<std::string>           Instrs;
    std::map<std::string, InstrRef> InstrMap;
    ExprRef         inst;

    ExprRef         opcode;
    ExprRef         rd;
    ExprRef         rs1;
    ExprRef         rs2;
    ExprRef         funct3;
    ExprRef         funct7;
    ExprRef         funct12;
    ExprRef         immI;
    ExprRef         immS;
    ExprRef         immB;
    ExprRef         immU;
    ExprRef         immJ;
    ExprRef         csr_index;

    // Speculative Execution:
    std::vector<ExprRef> GPR_PRF; // R0-R31
    ExprRef         spc;          // speculative PC
    ExprRef         seflag;       // speculative execution flag
    ExprRef         sc;           // speculative counter
    ExprRef         spec_mem;     // speculative memory 

    ExprRef         S_inst;

    ExprRef         S_opcode;
    ExprRef         S_rd;
    ExprRef         S_rs1;
    ExprRef         S_rs2;
    ExprRef         S_funct3;
    ExprRef         S_funct7;
    ExprRef         S_funct12;
    ExprRef         S_immI;
    ExprRef         S_immS;
    ExprRef         S_immB;
    ExprRef         S_immU;
    ExprRef         S_immJ;
    ExprRef         S_csr_index;
    // HZ: let's try using the speculative memory as a local view?

    FuncRef         nondet_PC;
    FuncRef         nondet_spec_exec;
    // End Speculative Execution



    ExprRef indexIntoGPR(std::vector<ExprRef> &GPR, const ExprRef & idxBits);
    void UpdateGPR(std::vector<ExprRef> &GPR, InstrRef & inst, const ExprRef & idxBits, const ExprRef & val );
    
    ExprRef bv(int val) { return BvConst(val, XLEN); }
    ExprRef zext(const ExprRef & v) {return ZExt( v, XLEN ); }
    ExprRef sext(const ExprRef & v) {return SExt( v, XLEN ); }

private:
    ExprRef getSlice(const ExprRef & word,const ExprRef & lowBits, int width, bool unSigned);
    ExprRef CombineSlices(const ExprRef & word, const ExprRef & lowBits, int width, const ExprRef & old);

protected:
    // privileged model will overload these to insert their address translation
    virtual ExprRef FetchFromMem(const ExprRef &m, const ExprRef &addr) { return Load(m,addr); }
    virtual ExprRef LoadFromMem (const ExprRef &m, const ExprRef &addr) { return Load(m,addr); }
    virtual ExprRef StoreToMem  (const ExprRef &m, const ExprRef &addr , const ExprRef &data) { return Store(m,addr,data); }
    virtual ExprRef interruptCondition() { return  BoolConst(true); }

public:
    riscvILA_user( int pc_init_val );
    void addInstructions();
    void addSpecInstructions();
};




class riscvILA_machine : public riscvILA_user
{
    // FIXME: to be implemented.
};




#endif
