// riscvIla.cc

#include <string>

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/ilang++.h>

#include "helpers.hpp"

using namespace ilang;

#include "riscvIla.hpp"

#define CBYTE 0x0
#define CHALF 0x1
#define CWORD 0x2

void riscvILA_user::UpdateGPR(InstrRef& inst, const ExprRef& idxBits,
                              const ExprRef& val) {
  inst.SetUpdate(GPR[0], bv(0));
  for (int idx = 1; idx < 32; idx++) {
    inst.SetUpdate(GPR[idx], Ite(idxBits == BvConst(idx, 5), val, GPR[idx]));
  }
}

ExprRef riscvILA_user::indexIntoGPR(const ExprRef& idxBits) {
  auto expr = bv(0); // GPR[0];
  for (int idx = 1; idx < 32; idx++) {
    expr = Ite(idxBits == BvConst(idx, 5), GPR[idx], expr);
  }
  return expr;
}

riscvILA_user::riscvILA_user(int pc_init_val)
    : model(InstrLvlAbs::New("riscv")), // define ila
      pc(model.NewBvState("pc", XLEN)),
      mem(model.NewMemState("mem", MEM_WORD_ADDR_LEN, MEM_WORD)),
      inst(FetchFromMem(mem, pc(31, 2))),

      opcode(inst(6, 0)), rd(inst(11, 7)), rs1(inst(19, 15)), rs2(inst(24, 20)),
      funct3(inst(14, 12)), funct7(inst(31, 25)), funct12(inst(31, 20)),
      immI(sext(inst(31, 20))),
      immS(sext(lConcat({inst(31, 25), inst(11, 7)}))),
      immB(sext(lConcat(
          {inst(31), inst(7), inst(30, 25), inst(11, 8), BvConst(0, 1)}))),
      immU(lConcat({inst(31, 12), BvConst(0, 12)})),
      immJ(sext(lConcat(
          {inst(31), inst(19, 12), inst(20), inst(30, 21), BvConst(0, 1)}))),
      csr_index(inst(31, 20))

{
  for (int idx = 0; idx < 32; idx++)
    GPR.push_back(model.NewBvState("x" + std::to_string(idx), XLEN));
  if ((pc_init_val & 0x3) != 0)
    std::cerr << "Warning: the initial pc is not valid: not aligned."
              << std::endl;

  model.AddInit(pc == BvConst(pc_init_val, XLEN));
}

ExprRef riscvILA_user::getSlice(const ExprRef& word, const ExprRef& lowBits,
                                int width, bool unSigned) {
  auto nonDet = BvConst(0, 32); // FIXME: currently we don't support nondet
#define ext(x) ((unSigned) ? zext(x) : sext(x))
  if (width == CBYTE) {
    return Ite(lowBits == BvConst(0, 2), ext(word(7, 0)),
               Ite(lowBits == BvConst(1, 2), ext(word(15, 8)),
                   Ite(lowBits == BvConst(2, 2), ext(word(23, 16)),
                       ext(word(31, 24)))));
  } else if (width == CHALF) {
    return Ite(lowBits == BvConst(0, 2), ext(word(15, 0)),
               Ite(lowBits == BvConst(2, 2), ext(word(31, 16)), nonDet));
  } else if (width == CWORD) {
    return Ite(lowBits == BvConst(0, 2), word, nonDet);
  } else {
    std::cerr
        << "Error : RV 32 does not support width other than Byte/Half/Word. "
        << std::endl;
    return nonDet;
  }
}

ExprRef riscvILA_user::CombineSlices(const ExprRef& word,
                                     const ExprRef& lowBits, int width,
                                     const ExprRef& old) {
  auto misalignVal = old;
#define zero(w) BvConst(0, w)
  if (width == CBYTE) {
    return Ite(
        lowBits == BvConst(0, 2), zext(word(7, 0)) | ((~bv(0xff)) & old),
        Ite(lowBits == BvConst(1, 2),
            zext(Concat(word(7, 0), zero(8))) | ((~bv(0xff00)) & old),
            Ite(lowBits == BvConst(2, 2),
                zext(Concat(word(7, 0), zero(16))) | ((~bv(0xff0000)) & old),
                /*     Ite( lowBits == BvConst(3,2)*/
                (Concat(word(7, 0), zero(24))) | ((~bv(0xff000000)) & old))));
  } else if (width == CHALF) {
    return Ite(lowBits == BvConst(0, 2),
               zext(word(15, 0)) | ((~bv(0xffff)) & old),
               Ite(lowBits == BvConst(2, 2),
                   Concat(word(15, 0), zero(16)) | ((~bv(0xffff0000)) & old),
                   misalignVal));
  } else if (width == CWORD) {
    return Ite(lowBits == BvConst(0, 2), word, misalignVal);
  } else {
    std::cerr
        << "Error : RV 32 does not support width other than Byte/Half/Word. "
        << std::endl;
    return bv(0);
  }
}

#define RECORD_INST(name)                                                      \
  do {                                                                         \
    assert(Instrs.find(name) == Instrs.end());                                 \
    Instrs.insert(name);                                                       \
    InstrMap.insert(std::make_pair(name, instr));                              \
  } while (0)

#define UPDATE_R(r, exp) UpdateGPR(instr, (r), (exp))

void riscvILA_user::addInstructions() {

  // ------------------------- Instruction: BRANCH
  // ------------------------------ //
  {
    auto rs1_val = indexIntoGPR(rs1);
    auto rs2_val = indexIntoGPR(rs2);
    auto BTarget = pc + immB;
    auto NC = pc + bv(4);
    // ------------------------- Instruction: BEQ ------------------------------
    // //
    {
      auto instr = model.NewInstr("BEQ");
      auto decode = (opcode == BRANCH) & (funct3 == BEQ);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, Ite(rs1_val == rs2_val, BTarget, NC));
      RECORD_INST("BEQ");
    }
    // ------------------------- Instruction: BNE ------------------------------
    // //
    {
      auto instr = model.NewInstr("BNE");
      auto decode = (opcode == BRANCH) & (funct3 == BNE);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, Ite(rs1_val != rs2_val, BTarget, NC));
      RECORD_INST("BNE");
    }
    // ------------------------- Instruction: BLT ------------------------------
    // //
    {
      auto instr = model.NewInstr("BLT");
      auto decode = (opcode == BRANCH) & (funct3 == BLT);
      instr.SetDecode(decode);

      // this is the signed comparison
      instr.SetUpdate(pc, Ite(rs1_val < rs2_val, BTarget, NC));
      RECORD_INST("BLT");
    }
    // ------------------------- Instruction: BLTU
    // ------------------------------ //
    {
      auto instr = model.NewInstr("BLTU");
      auto decode = (opcode == BRANCH) & (funct3 == BLTU);
      instr.SetDecode(decode);

      // this is the unsigned comparison
      instr.SetUpdate(pc, Ite(Ult(rs1_val, rs2_val), BTarget, NC));
      RECORD_INST("BLTU");
    }
    // ------------------------- Instruction: BGE ------------------------------
    // //
    {
      auto instr = model.NewInstr("BGE");
      auto decode = (opcode == BRANCH) & (funct3 == BGE);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, Ite(rs1_val >= rs2_val, BTarget, NC));
      RECORD_INST("BGE");
    }
    // ------------------------- Instruction: BGEU
    // ------------------------------ //
    {
      auto instr = model.NewInstr("BGEU");
      auto decode = (opcode == BRANCH) & (funct3 == BGEU);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, Ite(Uge(rs1_val, rs2_val), BTarget, NC));
      RECORD_INST("BGEU");
    }
    // ------------------------- Instruction: JAL ------------------------------
    // //
    {
      auto instr = model.NewInstr("JAL");
      auto decode = (opcode == JAL);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, pc + immJ);
      UPDATE_R(rd, NC);
      RECORD_INST("JAL");
    }
    // ------------------------- Instruction: JALR
    // ------------------------------ //
    {
      auto instr = model.NewInstr("JALR");
      auto decode = (opcode == JALR);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, (rs1_val + immI) & bv(0xFFFFFFFE));
      UPDATE_R(rd, NC);
      RECORD_INST("JALR");
    }
  }

  // ------------------------- Instruction: LOAD ------------------------------
  // //
  {
    auto rs1_val = indexIntoGPR(rs1);
    auto addr = rs1_val + immI;
    auto lw_val = LoadFromMem(mem, addr(31, 2));
    auto nxt_pc = pc + bv(4);

    // we assume a hardware-level misalign resolution

    // ------------------------- Instruction: LW ------------------------------
    // //
    {
      auto instr = model.NewInstr("LW");
      auto decode = (opcode == LOAD) & (funct3 == WORD);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, getSlice(lw_val, addr(1, 0), CWORD, 0));
      RECORD_INST("LW");
    }

    // ------------------------- Instruction: LH ------------------------------
    // //
    {
      auto instr = model.NewInstr("LH");
      auto decode = (opcode == LOAD) & (funct3 == HALF);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, getSlice(lw_val, addr(1, 0), CHALF, 0));
      RECORD_INST("LH");
    }

    // ------------------------- Instruction: LB ------------------------------
    // //
    {
      auto instr = model.NewInstr("LB");
      auto decode = (opcode == LOAD) & (funct3 == BYTE);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, getSlice(lw_val, addr(1, 0), CBYTE, 0));
      RECORD_INST("LB");
    }
    // ------------------------- Instruction: LHU ------------------------------
    // //
    {
      auto instr = model.NewInstr("LHU");
      auto decode = (opcode == LOAD) & (funct3 == HALF);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, getSlice(lw_val, addr(1, 0), CHALF, 1));
      RECORD_INST("LHU");
    }

    // ------------------------- Instruction: LBU ------------------------------
    // //
    {
      auto instr = model.NewInstr("LBU");
      auto decode = (opcode == LOAD) & (funct3 == BYTE);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, getSlice(lw_val, addr(1, 0), CBYTE, 1));
      RECORD_INST("LBU");
    }
  }

  // ------------------------- Instruction: STORE ------------------------------
  // //
  {
    auto rs1_val = indexIntoGPR(rs1);
    auto rs2_val = indexIntoGPR(rs2);
    auto addr = rs1_val + immS;
    auto word_addr = addr(31, 2);
    auto old_val = LoadFromMem(mem, word_addr);
    auto nxt_pc = pc + bv(4);

    // ------------------------- Instruction: SW ------------------------------
    // //
    {
      auto instr = model.NewInstr("SW");
      auto decode = (opcode == STORE) & (funct3 == WORD);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);

      auto store_value = CombineSlices(rs2_val, addr(1, 0), CWORD, old_val);
      instr.SetUpdate(mem, StoreToMem(mem, word_addr, store_value));

      RECORD_INST("SW");
    }

    // ------------------------- Instruction: SH ------------------------------
    // //
    {
      auto instr = model.NewInstr("SH");
      auto decode = (opcode == STORE) & (funct3 == WORD);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);

      auto store_value = CombineSlices(rs2_val, addr(1, 0), CHALF, old_val);
      instr.SetUpdate(mem, StoreToMem(mem, word_addr, store_value));

      RECORD_INST("SH");
    }

    // ------------------------- Instruction: SB ------------------------------
    // //
    {
      auto instr = model.NewInstr("SB");
      auto decode = (opcode == STORE) & (funct3 == WORD);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);

      auto store_value = CombineSlices(rs2_val, addr(1, 0), CBYTE, old_val);
      instr.SetUpdate(mem, StoreToMem(mem, word_addr, store_value));

      RECORD_INST("SB");
    }
  }

  // ------------------------- Instruction: ALU ------------------------------
  // //
  {
    auto rs1_val = indexIntoGPR(rs1);
    auto rs2_val = indexIntoGPR(rs2);
    auto shamt = zext(rs2_val(4, 0));
    auto nxt_pc = pc + bv(4);
    // ------------------------- Instruction: ADD ------------------------------
    // //
    {
      auto instr = model.NewInstr("ADD");
      auto decode = (opcode == OP) & (funct3 == ADD) & (funct7 == funct7_NM);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, rs1_val + rs2_val);

      RECORD_INST("ADD");
    }
    // ------------------------- Instruction: AND ------------------------------
    // //
    {
      auto instr = model.NewInstr("AND");
      auto decode = (opcode == OP) & (funct3 == AND) & (funct7 == funct7_NM);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, rs1_val & rs2_val);

      RECORD_INST("AND");
    }
    // ------------------------- Instruction: OR ------------------------------
    // //
    {
      auto instr = model.NewInstr("OR");
      auto decode = (opcode == OP) & (funct3 == OR) & (funct7 == funct7_NM);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, rs1_val | rs2_val);

      RECORD_INST("OR");
    }

    // ------------------------- Instruction: XOR ------------------------------
    // //
    {
      auto instr = model.NewInstr("XOR");
      auto decode = (opcode == OP) & (funct3 == XOR) & (funct7 == funct7_NM);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, rs1_val ^ rs2_val);

      RECORD_INST("XOR");
    }

    // ------------------------- Instruction: SLL ------------------------------
    // //
    {
      auto instr = model.NewInstr("SLL");
      auto decode = (opcode == OP) & (funct3 == SLL) & (funct7 == funct7_NM);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, rs1_val << shamt); // shift left

      RECORD_INST("SLL");
    }
    // ------------------------- Instruction: SRL ------------------------------
    // //
    {
      auto instr = model.NewInstr("SRL");
      auto decode = (opcode == OP) & (funct3 == SRL) & (funct7 == funct7_NM);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, Lshr(rs1_val, shamt)); // logical shift right

      RECORD_INST("SRL");
    }

    // ------------------------- Instruction: SUB ------------------------------
    // //
    {
      auto instr = model.NewInstr("SUB");
      auto decode = (opcode == OP) & (funct3 == SUB) & (funct7 == funct7_PM);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, rs1_val - rs2_val);

      RECORD_INST("SUB");
    }

    // ------------------------- Instruction: SRA ------------------------------
    // //
    {
      auto instr = model.NewInstr("SRA");
      auto decode = (opcode == OP) & (funct3 == SRA) & (funct7 == funct7_PM);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, rs1_val >> shamt); // arithmetic shift right

      RECORD_INST("SRA");
    }

    // ------------------------- Instruction: SLT ------------------------------
    // //
    {
      auto instr = model.NewInstr("SLT");
      auto decode = (opcode == OP) & (funct3 == SLT) & (funct7 == funct7_NM);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, Ite(rs1_val < rs2_val, bv(1), bv(0)));

      RECORD_INST("SLT");
    }
    // ------------------------- Instruction: SLTU
    // ------------------------------ //
    {
      auto instr = model.NewInstr("SLTU");
      auto decode = (opcode == OP) & (funct3 == SLTU) & (funct7 == funct7_NM);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, Ite(Ult(rs1_val, rs2_val), bv(1), bv(0)));

      RECORD_INST("SLTU");
    }
  }
  // ------------------------- Instruction: ALUimm
  // ------------------------------ //
  {
    auto rs1_val = indexIntoGPR(rs1);
    auto shamt = zext(inst(24, 20));
    auto nxt_pc = pc + bv(4);

    // ------------------------- Instruction: ADDI
    // ------------------------------ //
    {
      auto instr = model.NewInstr("ADDI");
      auto decode = (opcode == OPIMM) & (funct3 == ADDI);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, rs1_val + immI);

      RECORD_INST("ADDI");
    }
    // ------------------------- Instruction: SLTI
    // ------------------------------ //
    {
      auto instr = model.NewInstr("SLTI");
      auto decode = (opcode == OPIMM) & (funct3 == SLTI);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd,
               Ite(rs1_val < immI, bv(1), bv(0))); // This is signed comparison

      RECORD_INST("SLTI");
    }
    // ------------------------- Instruction: SLTIU
    // ------------------------------ //
    {
      auto instr = model.NewInstr("SLTIU");
      auto decode = (opcode == OPIMM) & (funct3 == SLTIU);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, Ite(Ult(rs1_val, immI), bv(1), bv(0)));

      RECORD_INST("SLTIU");
    }
    // ------------------------- Instruction: ANDI
    // ------------------------------ //
    {
      auto instr = model.NewInstr("ANDI");
      auto decode = (opcode == OPIMM) & (funct3 == ANDI);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, rs1_val & immI);

      RECORD_INST("ANDI");
    }
    // ------------------------- Instruction: ORI ------------------------------
    // //
    {
      auto instr = model.NewInstr("ORI");
      auto decode = (opcode == OPIMM) & (funct3 == ORI);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, rs1_val | immI);

      RECORD_INST("ORI");
    }
    // ------------------------- Instruction: XORI
    // ------------------------------ //
    {
      auto instr = model.NewInstr("XORI");
      auto decode = (opcode == OPIMM) & (funct3 == XORI);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, rs1_val ^ immI);

      RECORD_INST("XORI");
    }
    // ------------------------- Instruction: SLLI
    // ------------------------------ //
    {
      auto instr = model.NewInstr("SLLI");
      auto decode =
          (opcode == OPIMM) & (funct3 == SLLI) & (funct7 == SLLIfunct7);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, rs1_val << shamt); // shift left

      RECORD_INST("SLLI");
    }
    // ------------------------- Instruction: SRLI
    // ------------------------------ //
    {
      auto instr = model.NewInstr("SRLI");
      auto decode =
          (opcode == OPIMM) & (funct3 == SRLI) & (funct7 == SRLIfunct7);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, Lshr(rs1_val, shamt)); // logic shift right

      RECORD_INST("SRLI");
    }
    // ------------------------- Instruction: SRAI
    // ------------------------------ //
    {
      auto instr = model.NewInstr("SRAI");
      auto decode =
          (opcode == OPIMM) & (funct3 == SRAI) & (funct7 == SRAIfunct7);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, rs1_val >> shamt); // arithmetic shift right

      RECORD_INST("SRAI");
    }
  }

  // ------------------------- Instruction: imm ------------------------------
  // //
  {
    auto nxt_pc = pc + bv(4);
    // ------------------------- Instruction: LUI ------------------------------
    // //
    {
      auto instr = model.NewInstr("LUI");
      auto decode = (opcode == LUI);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, immU);

      RECORD_INST("LUI");
    }
    // ------------------------- Instruction: AUIPC
    // ------------------------------ //
    {
      auto instr = model.NewInstr("AUIPC");
      auto decode = (opcode == AUIPC);
      instr.SetDecode(decode);

      instr.SetUpdate(pc, nxt_pc);
      UPDATE_R(rd, pc + immU);

      RECORD_INST("AUIPC");
    }
  }
}

//------------------------------------------------------------
//          Build ILA function
//------------------------------------------------------------
