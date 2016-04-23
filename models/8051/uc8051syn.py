#! /usr/bin/python2.7

import sys
import argparse

import ila
from uc8051ast import uc8051
from sim51 import eval8051
import time

def synthesize(state, enable_ps):
    uc = uc8051()
    # create nicknames
    pc, iram, sp = uc.pc, uc.iram, uc.sp
    op0, op1, op2 = uc.op0, uc.op1, uc.op2
    acc, b, dptr = uc.acc, uc.b, uc.dptr
    rx = uc.rx
    rom = uc.rom
    model = uc.model
    model.enable_parameterized_synthesis = enable_ps

    # fetch and decode.
    model.fetch_expr = uc.op0 # s/hand for uc.rom[uc.pc]
    model.decode_exprs = [uc.op0 == i for i in xrange(0x0, 0x20)]

    ########################### PC ##############################################
    def cjmp(name, cond):
        pc_taken = ila.choice(name+'_taken', pc_rel1, pc_rel2)
        pc_seq   = ila.choice(name+'_seq', pc+2, pc+3)
        return ila.ite(cond, pc_taken, pc_seq)

    def jmppolarity(name):
        return ila.inrange(name, model.const(0, 1), model.const(1, 1))

    # ajmp/acall
    pc_ajmp_pg1 = (pc+2)[15:11]
    pc_ajmp_pg2 = ila.inrange('ajmp_page', model.const(0x0, 3), model.const(0x7, 3))
    pc_ajmp_pg = ila.concat(pc_ajmp_pg1, pc_ajmp_pg2)
    pc_ajmp = ila.concat(pc_ajmp_pg, op1)
    # lcall/ljmp
    pc_ljmp = ila.choice('ljmp', 
        [ila.concat(op2, op1), ila.concat(op1, op2)])
    # ret.
    pc_ret = ila.choice('pc_ret', [
        ila.concat(iram[sp-1], iram[sp]),
        ila.concat(iram[sp], iram[sp-1]),
        ila.concat(iram[sp], iram[sp+1]),
        ila.concat(iram[sp+1], iram[sp])])
    # relative to pc
    pc_rel1 = ila.choice('pc_rel1_base', [pc,pc+1,pc+2,pc+3]) + ila.sign_extend(op1, 16)
    pc_rel2 = ila.choice('pc_rel2_base', [pc,pc+1,pc+2,pc+3]) + ila.sign_extend(op2, 16)
    # sjmp
    pc_sjmp = ila.choice('sjmp', pc_rel1, pc_rel2)
    # jb
    jb_bitaddr  = ila.choice('jb_bitaddr', [op1, op2])
    jb_bit      = uc.readBit(jb_bitaddr)
    jx_polarity = jmppolarity('jx_polarity')
    pc_jb       = cjmp('pc_jb', jb_bit == jx_polarity)
    # jc
    pc_jc       = cjmp('pc_jc', uc.cy == jx_polarity)
    # jz
    acc_zero    = acc == 0
    acc_nonzero = acc != 0
    jz_test     = ila.choice('jz_test_polarity', acc_zero, acc_nonzero)
    pc_jz       = cjmp('pc_jz', jz_test)
    # jmp
    pc_jmp      = dptr+ila.zero_extend(acc, 16)
    # cjne
    cjne_src1 = ila.choice('cjne_src1', [acc, iram[rx[0]], iram[rx[1]]] + rx)
    cjne_src2 = ila.choice('cjne_src2', [
        op1, op2, uc.readDirect(ila.choice('cjne_iram_addr', [op1, op2]))])
    cjne_taken = cjne_src1 != cjne_src2
    pc_cjne = cjmp('pc_cjne', cjne_taken)
    # djnz
    djnz_src = ila.choice('djnz_src', 
        [uc.readDirect(ila.choice('djnz_iram_src', [op1, op2]))] + uc.rx)
    djnz_taken = djnz_src != 1
    pc_djnz = cjmp('pc_djnz', djnz_taken)

    pc_choices = [
        pc+1, pc+2, pc+3, pc_ajmp, pc_ljmp, pc_ret, pc_sjmp, 
        pc_jb, pc_jc, pc_jz, pc_jmp, pc_cjne, pc_djnz
    ]
    model.set_next('PC', ila.choice('pc', pc_choices))

    ########################### SP ##############################################
    sp_next = ila.choice('sp_next', [sp+2, sp+1, sp-1, sp-2, sp])
    model.set_next('SP', sp_next)

    ########################### ACC ##############################################
    # various sources for ALU ops.
    acc_src2_dir_addr = ila.choice('acc_src2_dir_addr', [op1, op2] + uc.rxaddr)
    acc_src2_dir = uc.readDirect(acc_src2_dir_addr)
    acc_src2_indir_addr = ila.choice('acc_src2_indir_addr', [rx[0], rx[1]])
    acc_src2_indir = iram[acc_src2_indir_addr]
    src2_imm = ila.choice('src2_imm', [op1, op2])
    acc_src2 = ila.choice('acc_src2', [acc_src2_dir, acc_src2_indir, src2_imm])
    acc_rom_offset = ila.choice('acc_rom_offset', [dptr, pc+1, pc+2, pc+3])
    # the decimal adjust instruction. this is a bit of mess.
    # first, deal with the lower nibble
    acc_add_6  = (uc.ac == 1) | (acc[3:0] > 9)
    acc_ext9 = ila.zero_extend(acc,9)
    acc_da_stage1 = ila.ite(acc_add_6, acc_ext9 + 6, acc_ext9)
    acc_da_cy1 = acc_da_stage1[8:8]
    # and then the upper nibble
    acc_add_60 = ((acc_da_cy1 | uc.cy) == 1) | (acc_da_stage1[7:4] > 9) 
    acc_da_stage2 = ila.ite(acc_add_60, acc_da_stage1 + 0x60, acc_da_stage1)
    acc_da = acc_da_stage2[7:0]
    # instructions which modify the accumulator.
    acc_rr  = ila.rrotate(acc, 1)
    acc_rrc = ila.rrotate(ila.concat(acc, uc.cy), 1)[8:1]
    acc_rl  = ila.lrotate(acc, 1)
    acc_rlc = ila.lrotate(ila.concat(uc.cy, acc), 1)[7:0]
    acc_inc = acc + 1
    acc_dec = acc - 1
    acc_add = acc + acc_src2
    acc_addc = acc + acc_src2 + ila.zero_extend(uc.cy, 8)
    acc_orl = acc | acc_src2 
    acc_anl = acc & acc_src2
    acc_xrl = acc ^ acc_src2
    acc_subb = acc - acc_src2 + ila.sign_extend(uc.cy, 8)
    acc_mov = acc_src2
    acc_cpl = ~acc
    acc_clr = model.const(0, 8)
    acc_rom = rom[ila.zero_extend(acc, 16) + acc_rom_offset]
    acc_swap = ila.concat(acc[3:0], acc[7:4])
    # mul and div.
    acc_div = ila.ite(b == 0, model.const(0xff, 8), acc / b)
    mul_result = ila.zero_extend(acc, 16) * ila.zero_extend(b, 16)
    acc_mul = mul_result[7:0]
    # xchg - dir
    xchg_src2_dir_addr = ila.choice('xchg_src2_dir_addr', [op1, op2] + uc.rxaddr)
    xchg_src2_dir = uc.readDirect(xchg_src2_dir_addr)
    acc_xchg_dir = xchg_src2_dir
    # xchg - indir
    xchg_src2_indir_addr = ila.choice('xchg_src2_indir_addr', [rx[0], rx[1]])
    xchg_src2_full_indir = iram[xchg_src2_indir_addr]
    xchg_src2_half_indir = ila.concat(acc[7:4], xchg_src2_full_indir[3:0])
    xchg_src2_indir = ila.choice('xchg_src2_indir', [xchg_src2_full_indir, xchg_src2_half_indir])
    acc_xchg_indir = xchg_src2_indir
    # final acc value.
    acc_next = ila.choice('acc_r_next', [
        acc_rr, acc_rl, acc_rrc, acc_rlc, acc_inc, acc_dec, acc_add, 
        acc_addc, acc_orl, acc_anl, acc_xrl, acc_mov, acc_rom, acc_clr,
        acc_subb, acc_swap, acc_cpl, acc, acc_div, acc_mul, acc_da,
        acc_xchg_dir, acc_xchg_indir])
    model.set_next('ACC', acc_next)

    ########################### IRAM ##############################################
    # instructions where the result is a direct iram address
    dir_src1_addr = ila.choice('dir_src1_addr', [op1, op2] + uc.rxaddr)
    dir_src1 = uc.readDirect(dir_src1_addr)
    dir_src2_iram_addr = ila.choice('dir_src2_iram_addr', [op1, op2] + uc.rxaddr)
    dir_src2_iram = uc.readDirect(dir_src2_iram_addr)
    dir_src2_indir_addr = ila.choice('dir_src2_indir_addr', [rx[0], rx[1]])
    dir_src2_indir = iram[dir_src2_indir_addr]
    dir_src2 = ila.choice('dir_src2', 
                          [op1, op2, acc, dir_src2_iram, dir_src2_indir])
    dir_inc = dir_src1 + 1 
    dir_dec = dir_src1 - 1
    dir_orl = dir_src1 | dir_src2
    dir_anl = dir_src1 & dir_src2
    dir_xrl = dir_src1 ^ dir_src2
    dir_mov = dir_src2
    dir_result = ila.choice('dir_result', 
                            [dir_inc, dir_dec, dir_orl, dir_anl, dir_xrl, dir_mov])
    r_dir = uc.writeDirect(dir_src1_addr, dir_result)

    # instructions where the result is an indirect iram address.
    src1_indir_addr = ila.choice('src1_indir_addr', [rx[0], rx[1]])
    src1_indir = iram[src1_indir_addr]
    src2_indir_dir_addr = ila.choice('src2_indir_dir_addr', [op1, op2])
    src2_indir_dir = uc.readDirect(src2_indir_dir_addr)
    src2_indir = ila.choice('src2_indir', [op1, op2, acc, src2_indir_dir])
    src1_indir_inc = src1_indir + 1
    src1_indir_dec = src1_indir - 1
    src1_indir_mov = src2_indir
    src1_indir_result = ila.choice('src1_indir_result', 
            [src1_indir_inc, src1_indir_dec, src1_indir_mov])
    iram_indir = ila.store(iram, src1_indir_addr, src1_indir_result)
    # calls
    pc_topush = ila.choice('pc_topush', [pc+1, pc+2, pc+3])
    pc_topush_lo = pc_topush[7:0]
    pc_topush_hi = pc_topush[15:8]
    pc_topush_0 = ila.choice('pc_topush_endianess', [pc_topush_lo, pc_topush_hi])
    pc_topush_1 = ila.choice('pc_topush_endianess', [pc_topush_hi, pc_topush_lo])
    pc_push_addr = ila.choice('pc_push_addr', [sp, sp+1])
    iram_call = ila.store(
                    ila.store(iram, 
                        pc_push_addr, pc_topush_0), 
                            pc_push_addr+1, pc_topush_1)

    # set the next iram.
    iram_next = ila.choice('iram_result', 
                    [iram, r_dir.iram, iram_indir, iram_call])
    model.set_next('IRAM', iram_next)

    ########################### DPTR ##############################################
    mov_dptr = ila.choice('mov_dptr', [ila.concat(op1, op2), ila.concat(op2, op1)])
    inc_dptr = dptr + 1
    dptr = ila.choice('next_dptr', [mov_dptr, inc_dptr, dptr])
    dpl = dptr[7:0]
    dph = dptr[15:8]

    ########################### PSW ##############################################
###    ctxCJNE = ctxNOP.clone()
###    CJNE_CY = If(ULT(cjne_src1, cjne_src2), BitVecVal(1, 1), BitVecVal(0, 1))
###    ctxCJNE.PSW = Concat(CJNE_CY, Extract(6, 0, ctx.PSW))

    for s in state:
        print s
        st = time.clock()
        model.synthesize(s, eval8051)
        t_elapsed = time.clock() - st
        print model.get_next(s)


###    ctxNOP = ctx.clone()
###    ctxNOP.PC = nextPC
###    # SP can be incremented, decrement or stay the same
###    ctxNOP.SP = Choice('SP_CALL', op0, [
###        ctx.SP, 
###        Add(ctx.SP, BitVecVal(2, 8)), 
###        Sub(ctx.SP, BitVecVal(2, 8))])
###
###    # CJNE sets the carry flag
###    ctxCJNE = ctxNOP.clone()
###    CJNE_CY = If(ULT(cjne_src1, cjne_src2), BitVecVal(1, 1), BitVecVal(0, 1))
###    ctxCJNE.PSW = Concat(CJNE_CY, Extract(6, 0, ctx.PSW))
###
###    # SRC2 for instructions which modify accumulator.
###    ACC_SRC2_DIR_ADDR = Choice('ACC_SRC2_DIR_ADDR', [op1, op2] + rxaddr)
###    ACC_SRC2_DIR = ctx.readDirect(ACC_SRC2_DIR_ADDR)
###    ACC_SRC2_INDIR_ADDR = Choice('ACC_SRC2_INDIR_ADDR', [ctx.Rx[ 0 ], ctx.Rx[ 1 ]])
###    ACC_SRC2_INDIR = ReadMem(ctx.IRAM, ACC_SRC2_INDIR_ADDR)
###    SRC2_IMM = Choice('SRC2_IMM', [op1, op2])
###    ACC_SRC2 = Choice('ACC_SRC2', [ACC_SRC2_DIR, ACC_SRC2_INDIR, SRC2_IMM])
###    ACC_ROM_OFFSET = Choice('ACC_ROM_OFFSET', [DPTR, ctx.PC, PC_plus1, PC_plus2, PC_plus3])
###
###    # The decimal adjust instruction. This is a bit of mess.
###    # First, deal with the lower nibble
###    ACC_DA_LO = Extract(3, 0, ctx.ACC)
###    ACC_ADD_6  = Or(Equal(ctx.AC, BitVecVal(1,1)), 
###                    UGT(ACC_DA_LO, BitVecVal(9, 4)))
###    ACC_DA_stage1 = If(ACC_ADD_6, 
###                        Add(ZeroExt(ctx.ACC,1), BitVecVal(0x6, 9)), 
###                        ZeroExt(ctx.ACC,1))
###    ACC_DA_CY1 = Extract(8, 8, ACC_DA_stage1)
###
###    # and then the upper nibble
###    ACC_DA_HI = Extract(7, 4, ACC_DA_stage1)
###    ACC_ADD_60 = Or(Equal(BVOr(ACC_DA_CY1, ctx.CY), BitVecVal(1,1)), 
###                    UGT(ACC_DA_HI, BitVecVal(9, 4)))
###    ACC_DA_stage2 = If(ACC_ADD_60, 
###                        Add(ACC_DA_stage1, BitVecVal(0x60, 9)), 
###                        ACC_DA_stage1)
###    ACC_DA = Extract(7, 0, ACC_DA_stage2)
###    ACC_DA_CY2 = Extract(8, 8, ACC_DA_stage2)
###
###    ACC_DA_CY = BVOr(ACC_DA_CY2, BVOr(ACC_DA_CY1, ctx.CY))
###    ctxDA = ctxNOP.clone()
###    ctxDA.ACC = ACC_DA
###    ctxDA.PSW = Concat(ACC_DA_CY, Extract(6, 0, ctx.PSW))
###
###    # Instructions which modify the accumulator.
###    ACC_RR  = RotateRight(ctx.ACC)
###    ACC_RRC = Extract(8, 1, RotateRight(Concat(ctx.ACC, ctx.CY)))
###    ACC_RL  = RotateLeft(ctx.ACC)
###    ACC_RLC = Extract(7, 0, RotateLeft(Concat(ctx.CY, ctx.ACC)))
###    ACC_INC = Add(ctx.ACC, BitVecVal(1, 8))
###    ACC_DEC = Sub(ctx.ACC, BitVecVal(1, 8))
###    ACC_ADD = Add(ctx.ACC, ACC_SRC2)
###    ACC_ADDC = Add(ctx.ACC, Add(ACC_SRC2, ZeroExt(ctx.CY, 7)))
###    ACC_ORL = BVOr(ctx.ACC, ACC_SRC2)
###    ACC_ANL = BVAnd(ctx.ACC, ACC_SRC2)
###    ACC_XRL = BVXor(ctx.ACC, ACC_SRC2)
###    ACC_SUBB = Add(Sub(ctx.ACC, ACC_SRC2), SignExt(ctx.CY, 7))
###    ACC_MOV = ACC_SRC2
###    ACC_CPL = Complement(ctx.ACC)
###    ACC_CLR = BitVecVal(0, 8)
###    ACC_ROM = ReadMem(ctx.ROM, Add(ZeroExt(ctx.ACC, 8), ACC_ROM_OFFSET))
###    ACC_SWAP = Concat(Extract(3, 0, ctx.ACC), Extract(7, 4, ctx.ACC))
###
###    # final acc value.
###    ctxACC = ctxNOP.clone()
###    ctxACC.ACC = Choice('ACC_RES', [
###        ACC_RR, ACC_RL, ACC_RRC, ACC_RLC, ACC_INC, ACC_DEC, ACC_ADD, 
###        ACC_ADDC, ACC_ORL, ACC_ANL, ACC_XRL, ACC_MOV, ACC_ROM, ACC_CLR,
###        ACC_SUBB, ACC_SWAP, ACC_CPL])
###    
###    # compute the CY/AC/OV flags
###    ALU_CY_IN = Choice('ALU_CY_IN', [ctx.CY, BitVecVal(0, 1)])
###
###    ALU_SRC1 = ctx.ACC
###    ALU_SRC1_LO = Extract(3, 0, ALU_SRC1)
###    ALU_SRC1_HI = Extract(7, 4, ALU_SRC1)
###
###    ALU_SRC2 = ACC_SRC2
###    ALU_SRC2_LO = Extract(3, 0, ALU_SRC2)
###    ALU_SRC2_HI = Extract(7, 4, ALU_SRC2)
###    ALU_CY_5B = Choice('ALU_CY_5B', [ZeroExt(ALU_CY_IN, 4), SignExt(ALU_CY_IN, 4)])
###
###    ALU_SRC1_LO_5B = ZeroExt(ALU_SRC1_LO, 1)
###    ALU_SRC2_LO_5B = ZeroExt(ALU_SRC2_LO, 1)
###    ALU_AC_ADD = Extract(4, 4, Add(ALU_SRC1_LO_5B, Add(ALU_SRC2_LO_5B, ALU_CY_5B)))
###    ALU_AC_SUB = If(ULT(ALU_SRC1_LO_5B, Add(ALU_SRC2_LO_5B, ALU_CY_5B)), BitVecVal(1, 1), BitVecVal(0, 1))
###    ALU_AC = Choice('ALU_AC', [ALU_AC_ADD, ALU_AC_SUB])
###
###    ALU_SRC1_SEXT = SignExt(ALU_SRC1, 1)
###    ALU_SRC2_SEXT = SignExt(ALU_SRC2, 1)
###    ALU_SRC1_ZEXT = ZeroExt(ALU_SRC1, 1)
###    ALU_SRC2_ZEXT = ZeroExt(ALU_SRC2, 1)
###    ALU_CY_9B_SEXT = SignExt(ALU_CY_IN, 8)
###    ALU_CY_9B_ZEXT = ZeroExt(ALU_CY_IN, 8)
###    ALU_CY_9B = Choice('ALU_CY_9B', [ALU_CY_9B_ZEXT, ALU_CY_9B_SEXT])
###
###    ALU_ZEXT_9B_SUM = Add(ALU_SRC1_ZEXT, Add(ALU_SRC2_ZEXT, ALU_CY_9B))
###    ALU_CY_ADD = Extract(8, 8, ALU_ZEXT_9B_SUM)
###    ALU_CY_SUB = If(ULT(ALU_SRC1_ZEXT, Add(ALU_SRC2_ZEXT, ALU_CY_9B)), BitVecVal(1, 1), BitVecVal(0, 1))
###    ALU_CY = Choice('ALU_CY', [ALU_CY_ADD, ALU_CY_SUB])
###
###    ALU_OV_9B_SRC1 = Choice('ALU_OV_9B_SRC1', [ALU_SRC1_SEXT, ALU_SRC1_ZEXT])
###    ALU_OV_9B_SRC2 = Choice('ALU_OV_9B_SRC2', [ALU_SRC2_SEXT, ALU_SRC2_ZEXT])
###
###    ALU_9B_ADD = Add(ALU_OV_9B_SRC1, Add(ALU_OV_9B_SRC2, ALU_CY_9B))
###    ALU_9B_SUB = Sub(ALU_OV_9B_SRC1, Add(ALU_OV_9B_SRC2, ALU_CY_9B))
###    ALU_9B_RES = Choice('ALU_9B_RES', [ALU_9B_ADD, ALU_9B_SUB])
###    ALU_OV = If(Not(Equal(Extract(8, 8, ALU_9B_RES), Extract(7, 7, ALU_9B_RES))),
###                BitVecVal(1, 1),
###                BitVecVal(0, 1))
###
###    ACC_CY = Choice('ACC_CY', [ctx.CY, Extract(0, 0, ctx.ACC), Extract(7, 7, ctx.ACC), ALU_CY])
###    ACC_AC = Choice('ACC_AC', [ctx.AC, ALU_AC])
###    ACC_OV = Choice('ACC_OV', [ctx.OV, ALU_OV])
###
###    ctxACC.PSW = Concat(ACC_CY, ACC_AC, Extract(5, 3, ctx.PSW), ACC_OV, Extract(1, 0, ctx.PSW))
###
###    # multiply and divide.
###    ctxDIV = ctxNOP.clone()
###    ctxDIV.ACC = If(Equal(ctx.B, BitVecVal(0, 8)), BitVecVal(0xFF,8), BVDiv(ctx.ACC, ctx.B))
###    ctxDIV.B = If(Equal(ctx.B, BitVecVal(0, 8)), ctx.ACC, BVRem(ctx.ACC, ctx.B))
###    DIV_OV = If(Equal(ctx.B, BitVecVal(0, 8)), BitVecVal(1, 1), BitVecVal(0, 1))
###    ctxDIV.PSW = Concat(BitVecVal(0, 1), Extract(6, 3, ctx.PSW), DIV_OV, Extract(1, 0, ctx.PSW))
###
###    ctxMUL = ctxNOP.clone()
###    MUL_RESULT = BVMul(ZeroExt(ctx.ACC, 8), ZeroExt(ctx.B, 8))
###    ctxMUL.ACC = Extract(7, 0, MUL_RESULT)
###    ctxMUL.B = Extract(15, 8, MUL_RESULT)
###    MUL_OV = If(Not(Equal(ctxMUL.B, BitVecVal(0, 8))), BitVecVal(1, 1), BitVecVal(0, 1))
###    ctxMUL.PSW = Concat(BitVecVal(0, 1), Extract(6, 3, ctx.PSW), MUL_OV, Extract(1, 0, ctx.PSW))
###
###    # call type instructions push the PC onto the stack.
###    ctxCALL = ctxNOP.clone()
###    PC_topush = Choice('PC_topush', [ctx.PC, PC_plus1, PC_plus2, PC_plus3])
###    PC_topush_lo = Extract(7, 0, PC_topush)
###    PC_topush_hi = Extract(15, 8, PC_topush)
###    PC_topush_0 = Choice('PC_topush_endianess', [PC_topush_lo, PC_topush_hi])
###    PC_topush_1 = Choice('PC_topush_endianess', [PC_topush_hi, PC_topush_lo])
###    PC_push_addr = Choice('PC_push_addr', [ctx.SP, Add(ctx.SP, BitVecVal(1, 8))])
###    ctxCALL.IRAM = WriteMem(WriteMem(ctx.IRAM, PC_push_addr, PC_topush_0), Add(PC_push_addr, BitVecVal(1, 8)), PC_topush_1)
###
###    # instructions where the result is a direct iram address
###    DIR_SRC1_ADDR = Choice('DIR_SRC1_ADDR', [op1, op2] + rxaddr)
###    DIR_SRC1 = ctx.readDirect(DIR_SRC1_ADDR)
###    DIR_SRC2_IRAM_ADDR = Choice('DIR_SRC2_IRAM_ADDR', [op1, op2] + rxaddr)
###    DIR_SRC2_IRAM = ctx.readDirect(DIR_SRC2_IRAM_ADDR)
###    DIR_SRC2_INDIR_ADDR = Choice('DIR_SRC2_INDIR_ADDR', [ctx.Rx[ 0 ], ctx.Rx[ 1 ]])
###    DIR_SRC2_INDIR = ReadMem(ctx.IRAM, DIR_SRC2_INDIR_ADDR)
###
###    DIR_SRC2 = Choice('DIR_SRC2', 
###            [op1, op2, ctx.ACC, DIR_SRC2_IRAM, DIR_SRC2_INDIR])
###    DIR_INC = Add(DIR_SRC1, BitVecVal(1, 8))
###    DIR_DEC = Sub(DIR_SRC1, BitVecVal(1, 8))
###    DIR_ORL = BVOr(DIR_SRC1, DIR_SRC2)
###    DIR_ANL = BVAnd(DIR_SRC1, DIR_SRC2)
###    DIR_XRL = BVXor(DIR_SRC1, DIR_SRC2)
###    DIR_MOV = DIR_SRC2
###
###    DIR_RESULT = Choice('DIR_RESULT', [DIR_INC, DIR_DEC, DIR_ORL, DIR_ANL, DIR_XRL, DIR_MOV])
###    ctxDIR = ctxNOP.writeDirect(DIR_SRC1_ADDR, DIR_RESULT)
###
###    # instructions where the result is an indirect iram address
###    SRC1_INDIR_ADDR = Choice('SRC1_INDIR_ADDR', [ctx.Rx[ 0 ], ctx.Rx[ 1 ]])
###    SRC1_INDIR = ReadMem(ctx.IRAM, SRC1_INDIR_ADDR)
###    SRC2_INDIR_DIR_ADDR = Choice('SRC2_INDIR_DIR_ADDR', [op1, op2])
###    SRC2_INDIR_DIR = ctx.readDirect(SRC2_INDIR_DIR_ADDR)
###    SRC2_INDIR = Choice('SRC2_INDIR', [op1, op2, ctx.ACC, SRC2_INDIR_DIR])
###    SRC1_INDIR_INC = Add(SRC1_INDIR, BitVecVal(1, 8))
###    SRC1_INDIR_DEC = Sub(SRC1_INDIR, BitVecVal(1, 8))
###    SRC1_INDIR_MOV = SRC2_INDIR
###    SRC1_INDIR_RESULT = Choice('SRC1_INDIR_RESULT', [SRC1_INDIR_INC, SRC1_INDIR_DEC, SRC1_INDIR_MOV])
###    ctxINDIR = ctxNOP.clone()
###    ctxINDIR.IRAM = WriteMem(ctx.IRAM, SRC1_INDIR_ADDR, SRC1_INDIR_RESULT)
###
###    # push/pop instructions
###    STK_SP = Choice('STK_SP', [Add(ctx.SP, BitVecVal(1, 8)),
###        Sub(ctx.SP, BitVecVal(1, 8))])
###    STK_IRAM_ADDR = Choice('STK_IRAM_ADDR', [
###                        ctx.SP, 
###                        Add(ctx.SP, BitVecVal(1, 8)),
###                        Sub(ctx.SP, BitVecVal(1, 8))])
###    STK_SRC_DIR_ADDR = Choice('STK_SRC_DIR_ADDR', [op1, op2])
###    STK_SRC_DIR = ctx.readDirect(STK_SRC_DIR_ADDR)
###    STK_SRC = Choice('STK_SRC', [STK_SRC_DIR, ctx.ACC])
###    ctxPUSH = ctxNOP.clone()
###    ctxPUSH.SP = STK_SP
###    ctxPUSH.IRAM = WriteMem(ctx.IRAM, STK_IRAM_ADDR, STK_SRC)
###
###    STK_DATA = Choice('STK_DATA', [mem_SP, mem_SP_plus1, mem_SP_minus1])
###    ctxPOP = ctxNOP.writeDirect(STK_SRC_DIR_ADDR, STK_DATA)
###    ctxPOP.SP = If(Equal(STK_SRC_DIR_ADDR, BitVecVal(0x81, 8)), ctxPOP.SP, STK_SP)
###
###    # instructions which write to specific bit addressable registers.
###    ctxBIT = ctxNOP.clone()
###    BIT_SRC1_ADDR = Choice('BIT_SRC1_ADDR', [op1, op2])
###    BIT_SRC1 = ctx.readBit(BIT_SRC1_ADDR)
###
###    # some instructions write their result to the carry flag; which is also the first operand.
###    CY_ORL = BVOr(ctx.CY, BIT_SRC1)
###    CY_ORLC = BVOr(ctx.CY, Complement(BIT_SRC1))
###    CY_ANL = BVAnd(ctx.CY, BIT_SRC1)
###    CY_ANLC = BVAnd(ctx.CY, Complement(BIT_SRC1))
###    CY_MOV = BIT_SRC1
###    CY_CPL_BIT = Complement(BIT_SRC1)
###    CY_CPL_C = Complement(ctx.CY)
###    BIT_CNST1 = BitVecVal(1,1)
###    BIT_CNST0 = BitVecVal(0,1)
###    BIT_CY = Choice('BIT_CY', 
###            [CY_ORL, CY_ANL, CY_ORLC, CY_ANLC, CY_CPL_C,
###            CY_MOV, CY_CPL_BIT, BIT_CNST1, BIT_CNST0])
###
###    ctxBIT.PSW = Concat(BIT_CY, Extract(6, 0, ctx.PSW))
###
###    WRBIT_CY = ctx.CY
###    WRBIT_CPL = Complement(BIT_SRC1)
###    WRBIT_DATA = Choice('WRBIT_DATA', [WRBIT_CY, WRBIT_CPL, BIT_CNST0, BIT_CNST1])
###    ctxWRBIT = ctxNOP.writeBit(BIT_SRC1_ADDR, WRBIT_DATA)
###
###    # DPTR
###    ctxDPTR = ctxNOP.clone()
###    MOV_DPTR = Choice('MOV_DPTR', [Concat(op1, op2), Concat(op2, op1)])
###    INC_DPTR = Add(DPTR, BitVecVal(1, 16))
###    ctxDPTR.DPTR = Choice('NEXT_DPTR', [MOV_DPTR, INC_DPTR])
###    ctxDPTR.DPL = Extract(7, 0, ctxDPTR.DPTR)
###    ctxDPTR.DPH = Extract(15, 8, ctxDPTR.DPTR)
###
###    # exchange instructions.
###    # first we deal with the direct addressed exchanges.
###    XCHG_SRC2_DIR_ADDR = Choice('XCHG_SRC2_DIR_ADDR', 
###        [op1, op2] + rxaddr)
###    XCHG_SRC2_DIR = ctx.readDirect(XCHG_SRC2_DIR_ADDR)
###    ctxXCHG_DIR = ctx.writeDirect(XCHG_SRC2_DIR_ADDR, ctx.ACC)
###    ctxXCHG_DIR.ACC = XCHG_SRC2_DIR
###
###    # and now with the indirect addressed exchanges.
###    # note we can have both a 'full' write and a 'half' write which only
###    # modifes the lower nibble
###    XCHG_SRC2_INDIR_ADDR = Choice('XCHG_SRC2_INDIR_ADDR', [ctx.Rx[ 0 ], ctx.Rx[ 1 ]])
###    XCHG_SRC2_FULL_INDIR = ReadMem(ctx.IRAM, XCHG_SRC2_INDIR_ADDR)
###    XCHG_SRC2_HALF_INDIR = Concat(Extract(7, 4, ctx.ACC), Extract(3, 0, XCHG_SRC2_FULL_INDIR))
###    XCHG_SRC2_INDIR = Choice('XCHG_SRC2_INDIR', [XCHG_SRC2_FULL_INDIR, XCHG_SRC2_HALF_INDIR])
###    XCHG_SRC1_HALF_INDIR = Concat(Extract(7, 4, XCHG_SRC2_FULL_INDIR), Extract(3, 0, ctx.ACC))
###    XCHG_SRC1_INDIR = Choice('XCHG_SRC1', [XCHG_SRC1_HALF_INDIR, ctx.ACC])
###    ctxXCHG_INDIR = ctxNOP.clone()
###    ctxXCHG_INDIR.IRAM = WriteMem(ctx.IRAM, XCHG_SRC2_INDIR_ADDR, XCHG_SRC1_INDIR)
###    ctxXCHG_INDIR.ACC = XCHG_SRC2_INDIR
###
###    # XRAM reads and writes
###    XRAM_ADDR_Rx = Concat(BitVecVal(0, 8),
###                          Choice('LSB_XRAM_ADDR', [ctx.Rx[ 0 ], ctx.Rx[ 1 ]]))
###    XRAM_ADDR = Choice('XRAM_ADDR', [XRAM_ADDR_Rx, DPTR])
###    XRAM_DATA_OUT = Choice('XRAM_DATA_OUT', [BitVecVal(0, 8), ctx.ACC])
###    ctxWRX = ctxNOP.clone()
###    ctxWRX.XRAM_DATA_OUT = XRAM_DATA_OUT
###    ctxWRX.XRAM_ADDR = XRAM_ADDR
###
###    ctxRDX = ctxNOP.clone()
###    ctxRDX.XRAM_ADDR = XRAM_ADDR
###    ctxRDX.ACC = ctx.XRAM_DATA_IN
###    
###    # final result.
###    ctxFINAL = CtxChoice('CTX3', [ctxNOP, ctxACC, ctxDIR, ctxDPTR, 
###                ctxPOP, ctxINDIR, ctxCALL, ctxBIT, ctxMUL, ctxDIV, ctxWRBIT, 
###                ctxPUSH, ctxDA, ctxXCHG_DIR, ctxXCHG_INDIR, ctxWRX, ctxRDX,
###                ctxCJNE])
###
###    syn.addOutput('PC', ctxFINAL.PC, Synthesizer.BITVEC)
###    syn.addOutput('ACC', ctxFINAL.ACC, Synthesizer.BITVEC)
###    syn.addOutput('IRAM', ctxFINAL.IRAM, Synthesizer.MEM)
###    syn.addOutput('XRAM', ctxFINAL.XRAM, Synthesizer.MEM)
###    syn.addOutput('PSW', ctxFINAL.PSW, Synthesizer.BITVEC)
###    syn.addOutput('SP', ctxFINAL.SP, Synthesizer.BITVEC)
###    syn.addOutput('B', ctxFINAL.B, Synthesizer.BITVEC)
###    syn.addOutput('DPL', ctxFINAL.DPL, Synthesizer.BITVEC)
###    syn.addOutput('DPH', ctxFINAL.DPH, Synthesizer.BITVEC)
###    # ports
###    syn.addOutput('P0', ctxFINAL.P0, Synthesizer.BITVEC)
###    syn.addOutput('P1', ctxFINAL.P1, Synthesizer.BITVEC)
###    syn.addOutput('P2', ctxFINAL.P2, Synthesizer.BITVEC)
###    syn.addOutput('P3', ctxFINAL.P3, Synthesizer.BITVEC)
###    # misc SFRs.
###    syn.addOutput('PCON', ctxFINAL.PCON, Synthesizer.BITVEC)
###    syn.addOutput('TCON', ctxFINAL.TCON, Synthesizer.BITVEC)
###    syn.addOutput('TMOD', ctxFINAL.TMOD, Synthesizer.BITVEC)
###    syn.addOutput('TL0', ctxFINAL.TL0, Synthesizer.BITVEC)
###    syn.addOutput('TH0', ctxFINAL.TH0, Synthesizer.BITVEC)
###    syn.addOutput('TL1', ctxFINAL.TL1, Synthesizer.BITVEC)
###    syn.addOutput('TH1', ctxFINAL.TH1, Synthesizer.BITVEC)
###    syn.addOutput('SCON', ctxFINAL.SCON, Synthesizer.BITVEC)
###    syn.addOutput('SBUF', ctxFINAL.SBUF, Synthesizer.BITVEC)
###    syn.addOutput('IE', ctxFINAL.IE, Synthesizer.BITVEC)
###    syn.addOutput('IP', ctxFINAL.IP, Synthesizer.BITVEC)
###    syn.addOutput('XRAM_ADDR', ctxFINAL.XRAM_ADDR, Synthesizer.BITVEC)
###    syn.addOutput('XRAM_DATA_OUT', ctxFINAL.XRAM_DATA_OUT, Synthesizer.BITVEC)
###
###    if logfilename:
###        if logfilename == 'STDOUT':
###            lf = sys.stdout
###        else:
###            lf = open(logfilename, 'wt')
###        syn.debug(vb=verbosity, lf=lf, uc=unsat_core)
###    else:
###        lf = None
###
###    cnst = Equal(ctx.op0, BitVecVal(opc, 8))
###    # log
###    if lf: 
###        print >> lf, 'opcode: %02x' % opc
###
###    # synthesize
###    r = syn.synthesize(regs, [cnst], eval8051)
###    if len(outputfilename):
###        with open(outputfilename, 'wb') as f:
###            pk = Pickler(f, -1)
###            pk.dump(opc)
###            for name, ast in itertools.izip(regs, r):
###                pk.dump(name)
###                pk.dump(ast)
###    else:
###        # print
###        fmt = '%02x\n' + ('\n'.join(['%s'] * len(r))) + '\n'
###        print fmt % tuple([opc] + r)
###        # log again
###        if lf: 
###            print >> lf, fmt % tuple([opc] + r)
###
###    if lf:
###        lf.close()

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--en", type=int, default=1, 
                        help="enable parameterized synthesis.")
    parser.add_argument("state", type=str, nargs='+', 
                        help='the state to synthesize.')
    args = parser.parse_args()
    synthesize(args.state, args.en)

if __name__ == '__main__':
    st = time.clock()
    main()
    t_elapsed = time.clock() - st
    print 'time taken: %.2f' % t_elapsed

