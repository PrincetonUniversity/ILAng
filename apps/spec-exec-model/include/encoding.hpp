/********************

 RISC-V Encoding 

********************/

#ifndef __RISCV_ENCODING_HPP__
#define __RISCV_ENCODING_HPP__

#define XLEN                32
#define INSTR_SIZE          XLEN
#define MEM_WORD_ADDR_LEN   (XLEN-2)
#define MEM_WORD            XLEN


#define OP_LEN  7
#define OPIMM 	BvConst(0x13, OP_LEN)
#define LUI		BvConst(0x37, OP_LEN)
#define AUIPC	BvConst(0x17, OP_LEN)
#define OP		BvConst(0x33, OP_LEN)
#define BRANCH	BvConst(0x63, OP_LEN)
#define JAL		BvConst(0x6f, OP_LEN)
#define JALR	BvConst(0x67, OP_LEN)
#define LOAD	BvConst(0x03, OP_LEN)
#define STORE	BvConst(0x23, OP_LEN)

// funct3 for OPIMM

#define FUNCT3_LEN 3
#define ADDI    BvConst(0x0, FUNCT3_LEN)
#define SLTI    BvConst(0x2, FUNCT3_LEN)
#define SLTIU   BvConst(0x3, FUNCT3_LEN)
#define ANDI    BvConst(0x7, FUNCT3_LEN)
#define ORI     BvConst(0x6, FUNCT3_LEN)
#define XORI    BvConst(0x4, FUNCT3_LEN)
#define SLLI    BvConst(0x1, FUNCT3_LEN)
#define SRLI    BvConst(0x5, FUNCT3_LEN)
#define SRAI    BvConst(0x5, FUNCT3_LEN)

#define FUNCT7_LEN 7
#define SLLIfunct7 BvConst(0x00, FUNCT7_LEN)
#define SRLIfunct7 BvConst(0x00, FUNCT7_LEN)
#define SRAIfunct7 BvConst(0x20, FUNCT7_LEN)
#define funct7_NM  BvConst(0x00, FUNCT7_LEN)
#define funct7_PM  BvConst(0x20, FUNCT7_LEN)

// funct3 for OP
#define ADD     BvConst(0x0 ,  FUNCT3_LEN)
#define SLL     BvConst(0x1 ,  FUNCT3_LEN)
#define SLT     BvConst(0x2 ,  FUNCT3_LEN)
#define SLTU    BvConst(0x3 ,  FUNCT3_LEN)
#define XOR     BvConst(0x4 ,  FUNCT3_LEN)
#define SRL     BvConst(0x5 ,  FUNCT3_LEN)
#define OR      BvConst(0x6 ,  FUNCT3_LEN)
#define AND     BvConst(0x7 ,  FUNCT3_LEN)
#define SUB     BvConst(0x0 ,  FUNCT3_LEN)
#define SRA     BvConst(0x5 ,  FUNCT3_LEN)

// funct 3 for BRANCH
#define BEQ     BvConst(0x0, FUNCT3_LEN)
#define BNE     BvConst(0x1, FUNCT3_LEN)
#define BLT     BvConst(0x4, FUNCT3_LEN)
#define BGE     BvConst(0x5, FUNCT3_LEN)
#define BLTU    BvConst(0x6, FUNCT3_LEN)
#define BGEU    BvConst(0x7, FUNCT3_LEN)

// funct 3 for L/S
#define BYTE    BvConst(0x0 , FUNCT3_LEN)
#define HALF    BvConst(0x1 , FUNCT3_LEN)
#define WORD    BvConst(0x2 , FUNCT3_LEN)
#define DOUBLE  BvConst(0x3 , FUNCT3_LEN)
#define BU      BvConst(0x4 , FUNCT3_LEN)
#define HU      BvConst(0x5 , FUNCT3_LEN)
#define WU      BvConst(0x6 , FUNCT3_LEN)




#endif
