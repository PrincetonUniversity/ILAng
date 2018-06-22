// riscvIla.cc

//

#include <iostream>
#include <string>
#include <cassert>


#include "ila++.h"

#include "helpers.hpp"

using namespace ila;

#include "riscvIla.hpp"


#define CBYTE    0x0
#define CHALF    0x1
#define CWORD    0x2

// you need to provide Which one (ARF/PRF) explicitly
void riscvILA_user::UpdateGPR(std::vector<ExprRef> &GPR, InstrRef & inst, const ExprRef & idxBits, const ExprRef & val  )
{
    inst.SetUpdate( GPR[0], bv(0)  );
    for(int idx = 1; idx < 32; idx ++) {
        inst.SetUpdate(GPR[idx], Ite( idxBits == BvConst(idx, 5) , val, GPR[idx] ) );
    }
}

ExprRef riscvILA_user::indexIntoGPR(std::vector<ExprRef> &GPR, const ExprRef & idxBits)
{
    auto expr = bv(0); //GPR[0];
    for(int idx = 1; idx < 32; idx ++) {
        expr = Ite( idxBits == BvConst(idx, 5) , GPR[idx], expr );
    }
    return expr;
}

riscvILA_user::riscvILA_user ( int pc_init_val ):
    model ( "riscv" ), // define ila
    pc    ( model.NewBvState("pc", XLEN ) ),
    mem   ( model.NewMemState("mem" , MEM_WORD_ADDR_LEN, MEM_WORD) ),
    inst  ( FetchFromMem(mem, pc( 31 , 2 ) ) ) ,

    opcode ( inst(  6 , 0) ),
    rd     ( inst( 11 , 7) ),
    rs1    ( inst( 19 ,15) ),
    rs2    ( inst( 24 ,20) ),
    funct3 ( inst( 14 ,12) ),
    funct7 ( inst( 31 ,25) ),
    funct12( inst( 31 ,20) ),
    immI   ( sext( inst(31 ,20) ) ),
    immS   ( sext( lConcat( {inst(31, 25) , inst( 11, 7)} ) ) ),
    immB   ( sext( lConcat( {inst(31) , inst(7), inst(30,25), inst(11,8), BvConst(0,1)} ) ) ),
    immU   ( lConcat( {inst(31,12), BvConst(0,12)} ) ),
    immJ   ( sext( lConcat( {inst(31) , inst(19,12), inst(20), inst(30,21), BvConst(0,1)} ) ) ),
    csr_index ( inst(31,20) ),

    // --------------------------------------
    //    speculative execution model
    // --------------------------------------
    spc     ( model.NewBvState("spc", XLEN ) ),    
    seflag  ( model.NewBoolState("seflag") ), 
    sc      ( model.NewBvState("sc", XLEN ) ), // should us sc counter length
    spec_mem( model.NewMemState("spec_mem" , MEM_WORD_ADDR_LEN, MEM_WORD) ), // used to register spec_mem write? and also read

    S_inst   ( FetchFromMem(mem, spc( 31 , 2 ) ) ),  // it is fine to use the non-spec pc, because for RISC-V fence instruction is needed for self-modification code
    S_opcode ( S_inst(  6 , 0) ),
    S_rd     ( S_inst( 11 , 7) ),
    S_rs1    ( S_inst( 19 ,15) ),
    S_rs2    ( S_inst( 24 ,20) ),
    S_funct3 ( S_inst( 14 ,12) ),
    S_funct7 ( S_inst( 31 ,25) ),
    S_funct12( S_inst( 31 ,20) ),
    S_immI   ( sext( S_inst(31 ,20) ) ),
    S_immS   ( sext( lConcat( {S_inst(31, 25) , S_inst( 11, 7)} ) ) ),
    S_immB   ( sext( lConcat( {S_inst(31) , S_inst(7), S_inst(30,25), S_inst(11,8), BvConst(0,1)} ) ) ),
    S_immU   ( lConcat( {S_inst(31,12), BvConst(0,12)} ) ),
    S_immJ   ( sext( lConcat( {S_inst(31) , S_inst(19,12), S_inst(20), S_inst(30,21), BvConst(0,1)} ) ) ),
    S_csr_index ( S_inst(31,20) ),

    nondet_PC           ( "nondet_PC",  SortRef::BV(32) ), // FuncRef
    nondet_spec_exec    ( "nondet_spec_exec", SortRef::BOOL() )

{
    for(int idx = 0; idx < 32; idx ++  )
        GPR_ARF.push_back( model.NewBvState( "x" + std::to_string(idx) , XLEN ) );
    if( (pc_init_val & 0x3) != 0)
        std::cerr<<"Warning: the initial pc is not valid: not aligned."<<std::endl;

    model.AddInit( pc == BvConst(pc_init_val, XLEN )  );

    // --------------------------------------
    //    speculative execution model
    // --------------------------------------
    for(int idx = 0; idx < 32; idx ++  )
        GPR_PRF.push_back( model.NewBvState( "p" + std::to_string(idx) , XLEN ) );

}


ExprRef riscvILA_user::getSlice(const ExprRef & word, const ExprRef & lowBits, int width, bool unSigned)
{
    auto nonDet = BvConst(0, 32); // FIXME: currently we don't support nondet
    #define ext(x) ((unSigned) ? zext(x) : sext(x))
    if(width == CBYTE) {
        return Ite( lowBits == BvConst(0,2) , ext( word( 7, 0) ) , 
               Ite( lowBits == BvConst(1,2) , ext( word(15, 8) ) ,
               Ite( lowBits == BvConst(2,2) , ext( word(23,16) ) ,
                                              ext( word(31,24) ) ) ) );
    }
    else if(width == CHALF) {
        return Ite( lowBits == BvConst(0,2) , ext( word( 15, 0) ),
               Ite( lowBits == BvConst(2,2) , ext( word( 31,16) ),
               nonDet ) );
    }
    else if(width == CWORD) {
        return Ite( lowBits == BvConst(0,2) , word ,
               nonDet ) ;        
    }
    else{
        std::cerr<<"Error : RV 32 does not support width other than Byte/Half/Word. " << std::endl;
        return nonDet;
    }
}

ExprRef riscvILA_user::CombineSlices(const ExprRef & word, const ExprRef & lowBits, int width, const ExprRef & old)
{
    auto misalignVal = old; 
    #define zero(w) BvConst(0,w)
    if(width == CBYTE) {
        return Ite( lowBits == BvConst(0,2) , zext(          word(7,0)               ) | ( ( ~ bv(      0xff) ) & old ) ,
               Ite( lowBits == BvConst(1,2) , zext( Concat(  word(7,0)  , zero( 8) ) ) | ( ( ~ bv(    0xff00) ) & old ) ,
               Ite( lowBits == BvConst(2,2) , zext( Concat(  word(7,0)  , zero(16) ) ) | ( ( ~ bv(  0xff0000) ) & old ) ,
        /*     Ite( lowBits == BvConst(3,2)*/     ( Concat(  word(7,0)  , zero(24) ) ) | ( ( ~ bv(0xff000000) ) & old ) 
                ) ) );
    }
    else if(width == CHALF) {
        return Ite( lowBits == BvConst(0,2) ,   zext(  word(15,0)             ) | ( ( ~ bv(    0xffff) ) & old ) ,
               Ite( lowBits == BvConst(2,2) , Concat(  word(15,0)  , zero(16) ) | ( ( ~ bv(0xffff0000) ) & old ) ,
                    misalignVal 
                ) );
    }
    else if(width == CWORD) {
        return Ite( lowBits == BvConst(0,2) , word ,
               misalignVal ) ;        
    }
    else{
        std::cerr<<"Error : RV 32 does not support width other than Byte/Half/Word. " << std::endl;
        return bv(0);
    }
}


#define RECORD_INST(name) do { \
    assert( Instrs.find(name) == Instrs.end() ); \
    Instrs.insert(name); \
    InstrMap.insert(std::make_pair(name,instr)); \
    } while(0)

#define START_SPECULATION do { \
        instr.SetUpdate( spc, nondet_PC() ); \
        instr.SetUpdate( seflag, BoolConst(true) ); \
        instr.SetUpdate( sc, BvConst(0, XLEN) ); \
        instr.SetUpdate( GPR_PRF[0], BvConst(0,XLEN) ); \
        for(int idx = 1; idx < 32; idx ++ ) { instr.SetUpdate(GPR_PRF[idx], GPR_ARF[idx] ); } \
    } while(0)

#define UPDATE_R(r,exp)     UpdateGPR( GPR_ARF, instr, (r), (exp) )
#define UPDATE_PC(v)        ( instr.SetUpdate(pc, (v) ) )
#define UPDATE_MEM(wa, v)   ( instr.SetUpdate(mem, StoreToMem(mem,  (wa), (v) ) ) )
#define EXEC_COND           (!seflag)
#define NAME_SUFFIX         ""
#define EXECUTE_IF_SPEC     
    
void riscvILA_user::addInstructions()
{
    // ------------------------- Instruction: BRANCH ------------------------------ //
    {
        auto rs1_val = indexIntoGPR(GPR_ARF, rs1);   
        auto rs2_val = indexIntoGPR(GPR_ARF, rs2);  
        auto BTarget = pc + immB;
        auto NC      = pc + bv(4);

        // --------------------------
        // the branch speculation
        // -------------------------
        #undef  UPDATE_PC
        #define UPDATE_PC(v) (v) 
        // Update_R: -ARF- / Update_PC: -- / Update_MEM : -mem- / EXEC_COND : !seflag / NAME_SUFFIX "" / EXECUTE_IF_SPEC --
        #undef  UPDATE_PC
        #define UPDATE_PC(v) ( instr.SetUpdate(pc, (v) ) )

        // --------------------------
        // the branch resolve
        // -------------------------

        #undef  NAME_SUFFIX
        #undef  EXEC_COND
        #undef  START_SPECULATION
        #undef  EXECUTE_IF_SPEC 
        #define NAME_SUFFIX "_resolve"
        #define EXEC_COND ( seflag & ( sc == SPECULATIVE_WINDOW_SIZE ) )
        #define START_SPECULATION 
        #define EXECUTE_IF_SPEC ( instr.SetUpdate( seflag, BoolConst(false) ) )
        // Update_R: -ARF- / Update_PC: PC / Update_MEM : -mem- / EXEC_COND : seflag && inWindow / NAME_SUFFIX "_resolve" / EXECUTE_IF_SPEC seflag:=falses
        #include "insts/btype.hpp"

        #undef  START_SPECULATION
        #undef  NAME_SUFFIX
        #undef  EXECUTE_IF_SPEC 
        #undef  EXEC_COND
        #define NAME_SUFFIX ""
        #define EXECUTE_IF_SPEC 
        #define EXEC_COND (!seflag)
        // Update_R: ARF / Update_PC: PC / Update_MEM : -mem- / EXEC_COND : !seflag / NAME_SUFFIX "" / EXECUTE_IF_SPEC --
        #include "insts/jtype.hpp"

    }

    // ------------------------- Instructions: LOAD ------------------------------ //
    {
        auto rs1_val = indexIntoGPR(GPR_ARF, rs1);   
        auto addr    = rs1_val + immI;
        auto lw_val  = LoadFromMem(mem,  addr(31,2) );
        auto nxt_pc  = pc + bv(4);

        // we assume a hardware-level misalign resolution 
        #include "insts/load.hpp"
    }

    // ------------------------- Instructions: STORE ------------------------------ //
    {
        auto rs1_val   = indexIntoGPR(GPR_ARF, rs1);   
        auto rs2_val   = indexIntoGPR(GPR_ARF, rs2);  
        auto addr      = rs1_val + immS;
        auto word_addr = addr( 31, 2);
        auto old_val   = LoadFromMem(mem, word_addr);
        auto nxt_pc  = pc + bv(4);

        #include "insts/store.hpp"
    }

    // ------------------------- Instruction: ALU ------------------------------ //
    {
        auto rs1_val = indexIntoGPR(GPR_ARF, rs1);   
        auto rs2_val = indexIntoGPR(GPR_ARF, rs2);  
        auto shamt   = zext(rs2_val(4,0));
        auto nxt_pc  = pc + bv(4);
        #include "insts/ALU.hpp"
    }
    // ------------------------- Instructions: ALUimm ------------------------------ //
    {
        auto rs1_val   = indexIntoGPR(GPR_ARF, rs1);   
        auto shamt = zext( inst(24,20) );
        auto nxt_pc  = pc + bv(4);
        #include "insts/ALUimm.hpp"
    }

    // ------------------------- Instructions: imm ------------------------------ //
    {
        auto nxt_pc  = pc + bv(4);
        #include "insts/imm.hpp"
    }
}




void riscvILA_user::addSpecInstructions()
{
    // ------------------------- Overwrite the instruction ------------------------ //

    ExprRef         inst(S_inst);

    ExprRef         opcode(S_opcode);
    ExprRef         rd(S_rd);
    ExprRef         rs1(S_rs1);
    ExprRef         rs2(S_rs2);
    ExprRef         funct3(S_funct3);
    ExprRef         funct7(S_funct7);
    ExprRef         funct12(S_funct12);
    ExprRef         immI(S_immI);
    ExprRef         immS(S_immS);
    ExprRef         immB(S_immB);
    ExprRef         immU(S_immU);
    ExprRef         immJ(S_immJ);
    ExprRef         csr_index(S_csr_index);

    #undef UPDATE_R
    #undef UPDATE_PC
    #undef UPDATE_MEM
    #undef EXEC_COND
    #undef NAME_SUFFIX
    #undef EXECUTE_IF_SPEC


    #define UPDATE_R(r,exp)     UpdateGPR( GPR_PRF, instr, (r), (exp) )
    #define UPDATE_MEM(wa, v)   ( instr.SetUpdate(spec_mem, StoreToMem(spec_mem,  (wa), (v) ) ) )
    #define EXEC_COND           ( seflag & (sc < SPECULATIVE_WINDOW_SIZE) )
    #define NAME_SUFFIX         "_speculative"
    #define EXECUTE_IF_SPEC     ( instr.SetUpdate(sc, sc + 1) )
    #define START_SPECULATION   
    //  & nondet_spec_exec()

    // ------------------------- Instruction: BRANCH ------------------------------ //
    {
        auto rs1_val = indexIntoGPR(GPR_PRF, rs1);   
        auto rs2_val = indexIntoGPR(GPR_PRF, rs2);  
        auto BTarget = pc + immB;
        auto NC      = pc + bv(4);

        // --------------------------
        // the nested branch
        // -------------------------
        #define UPDATE_PC(v) ( instr.SetUpdate(spc,  nondet_PC() ) )
        // Update_R: PRF / Update_PC: non_det / Update_MEM : -spec_mem- / EXEC_COND : seflag & inWindow / NAME_SUFFIX "_speculative" / EXECUTE_IF_SPEC sc++
        #include "insts/btype.hpp"
        #undef START_SPECULATION   

        // it will update spc
        #undef UPDATE_PC
        #define UPDATE_PC(v) ( instr.SetUpdate(spc, (v) ) )
        auto pc = spc; // overwrite pc for J-type instruction
        #include "insts/jtype.hpp"
    }

    #undef UPDATE_R
    #undef UPDATE_PC
    #undef UPDATE_MEM
    #undef EXEC_COND
    #undef NAME_SUFFIX
    #undef EXECUTE_IF_SPEC

    // update mem and update r won't both exist
    #define UPDATE_R(r,exp)     UpdateGPR( GPR_PRF, instr, (r), Ite( nondet_spec_exec() , (exp) , (r)  ) )
    #define UPDATE_PC(v)        ( instr.SetUpdate(spc, (v) ) )
    #define UPDATE_MEM(wa, v)   ( instr.SetUpdate(spec_mem, Ite( nondet_spec_exec() , StoreToMem(spec_mem,  (wa), (v) ), spec_mem ) ) )
    #define EXEC_COND           (seflag & (sc < SPECULATIVE_WINDOW_SIZE)  )
    #define NAME_SUFFIX         "_speculative"
    #define EXECUTE_IF_SPEC     ( instr.SetUpdate(sc, sc + 1) )

    // ------------------------- Instruction: LOAD ------------------------------ //
    {
        auto rs1_val = indexIntoGPR(GPR_PRF, rs1);   
        auto addr    = rs1_val + immI;
        auto lw_val  = LoadFromMem(spec_mem,  addr(31,2) );
        auto nxt_pc  = spc + bv(4);

        // we assume a hardware-level misalign resolution 
        #include "insts/load.hpp"
    }

    // ------------------------- Instruction: STORE ------------------------------ //
    {
        auto rs1_val   = indexIntoGPR(GPR_PRF, rs1);   
        auto rs2_val   = indexIntoGPR(GPR_PRF, rs2);  
        auto addr      = rs1_val + immS;
        auto word_addr = addr( 31, 2);
        auto old_val   = LoadFromMem(spec_mem, word_addr);
        auto nxt_pc  = spc + bv(4);

        #include "insts/store.hpp"
    }

    // ------------------------- Instruction: ALU ------------------------------ //
    {
        auto rs1_val = indexIntoGPR(GPR_PRF, rs1);   
        auto rs2_val = indexIntoGPR(GPR_PRF, rs2);  
        auto shamt   = zext(rs2_val(4,0));
        auto nxt_pc  = spc + bv(4);
        #include "insts/ALU.hpp"
    }
    // ------------------------- Instructions: ALUimm ------------------------------ //
    {
        auto rs1_val   = indexIntoGPR(GPR_PRF, rs1);   
        auto shamt = zext( inst(24,20) );
        auto nxt_pc  = spc + bv(4);
        #include "insts/ALUimm.hpp"
    }

    // ------------------------- Instructions: imm ------------------------------ //
    {
        auto nxt_pc  = spc + bv(4);
        auto pc(spc);
        #include "insts/imm.hpp"
    }
}
