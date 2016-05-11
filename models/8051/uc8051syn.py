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
    psw = uc.psw
    rx = uc.rx
    rom = uc.rom
    model = uc.model
    model.enable_parameterized_synthesis = enable_ps
    bv = model.const

    # fetch and decode.
    model.fetch_expr = uc.op0 # s/hand for uc.rom[uc.pc]
    model.decode_exprs = [uc.op0 == i for i in xrange(0x0, 0x100)]

    ########################### PC ##############################################
    def cjmp(name, cond):
        pc_taken = ila.choice(name+'_taken', pc_rel1, pc_rel2)
        pc_seq   = ila.choice(name+'_seq', pc+2, pc+3)
        return ila.ite(cond, pc_taken, pc_seq)

    def jmppolarity(name):
        return ila.inrange(name, bv(0, 1), bv(1, 1))

    # ajmp/acall
    pc_ajmp_pg1 = (pc+2)[15:11]
    pc_ajmp_pg2 = ila.inrange('ajmp_page', bv(0x0, 3), bv(0x7, 3))
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
        [uc.readDirect(ila.choice('djnz_iram_src', [op1, op2]))] + rx)
    djnz_taken = djnz_src != 1
    pc_djnz = cjmp('pc_djnz', djnz_taken)

    pc_choices = [
        pc+1, pc+2, pc+3, pc_ajmp, pc_ljmp, pc_ret, pc_sjmp, 
        pc_jb, pc_jc, pc_jz, pc_jmp, pc_cjne, pc_djnz
    ]
    model.set_next('PC', ila.choice('pc', pc_choices))


    ########################### ACC ##############################################
    # various sources for ALU ops.
    acc_src2_dir_addr = ila.choice('acc_src2_dir_addr', [op1, op2])
    acc_src2_dir = ila.choice('acc_src2_dir', 
                                [uc.readDirect(acc_src2_dir_addr)] + rx)
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
    acc_clr = bv(0, 8)
    acc_rom = rom[ila.zero_extend(acc, 16) + acc_rom_offset]
    acc_swap = ila.concat(acc[3:0], acc[7:4])
    # div.
    acc_div = ila.ite(b == 0, bv(0xff, 8), acc / b)
    b_div = ila.ite(b == 0, acc, acc % b)
    # mul
    mul_result = ila.zero_extend(acc, 16) * ila.zero_extend(b, 16)
    acc_mul = mul_result[7:0]
    b_mul = mul_result[15:8]
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
        acc_xchg_dir, acc_xchg_indir, uc.xram_data_in])
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
    dir_addrs = [dir_src1_addr]
    dir_datas = [dir_result]

    # write a bit.
    bit_src1_addr = ila.choice('bit_src1_addr', [op1, op2])
    bit_src1 = uc.readBit(bit_src1_addr)
    wrbit_data = ila.choice('wrbit_data', 
                    [uc.cy, ~uc.cy, bit_src1, ~bit_src1, bv(0,1), bv(1,1)])
    r_bit = uc.writeBit(bit_src1_addr, wrbit_data)
    # some instructions write their result to the carry flag; which is also the first operand.
    cy_orl = uc.cy | bit_src1
    cy_orlc = uc.cy | ~bit_src1
    cy_anl = uc.cy & bit_src1
    cy_anlc = uc.cy & ~bit_src1
    cy_mov = bit_src1
    cy_cpl_bit = ~bit_src1
    cy_cpl_c = ~uc.cy
    bit_cnst1 = bv(1,1)
    bit_cnst0 = bv(0,1)
    bit_cy = ila.choice('bit_cy', 
                        [cy_orl, cy_anl, cy_orlc, cy_anlc, cy_cpl_c,
                         cy_mov, cy_cpl_bit, bit_cnst1, bit_cnst0])

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
    indir_addrs = [src1_indir_addr]      # indirect write addr
    indir_datas = [src1_indir_result]   # and data.
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

    # push or pop instructions.
    stk_iram_addr = ila.choice('stk_iram_addr', [sp, sp+1, sp-1])
    stk_src_dir_addr = ila.choice('stk_src_dir_addr', [op1, op2])
    stk_src_dir = uc.readDirect(stk_src_dir_addr)
    stk_src = ila.choice('stk_src', [stk_src_dir, acc])
    sp_pushpop = ila.choice('sp_pushpop', sp+1, sp-1)
    indir_addrs.append(stk_iram_addr)
    indir_datas.append(stk_src)

    stk_data = ila.choice('stk_data', [iram[sp], iram[sp+1], iram[sp-1]])
    dir_addrs.append(stk_src_dir_addr)
    dir_datas.append(stk_data)
    r_pop = uc.writeDirect(stk_src_dir_addr, stk_data)
    sp_pop = ila.ite(stk_src_dir_addr == bv(0x81, 8), r_pop.sp, sp_pushpop)

    # exchanges;  part of this implemented above in acc section.
    dir_addrs.append(xchg_src2_dir_addr)
    dir_datas.append(acc)
    xchg_src1_half_indir = ila.concat(xchg_src2_full_indir[7:4], acc[3:0])
    xchg_src1_indir = ila.choice('xchg_src1', [xchg_src1_half_indir, acc])
    indir_addrs.append(xchg_src2_indir_addr)
    indir_datas.append(xchg_src1_indir)

    # final indirect writes.
    iram_indir = ila.store(iram, 
        ila.choice('iram_indir', indir_addrs),
        ila.choice('iram_indir', indir_datas))
    # final direct writes.
    assert len(dir_addrs) == len(dir_datas)
    r_dir = uc.writeDirect(
        ila.choice('iram_dir', dir_addrs),
        ila.choice('iram_dir', dir_datas))

    # set the next iram.
    iram_next = ila.choice('iram_result', 
                    [iram, iram_indir, iram_call, r_dir.iram, r_bit.iram])
    model.set_next('IRAM', iram_next)

    ########################### PSW ##############################################
    cjne_cy = ila.ite(cjne_src1 < cjne_src2, bv(1, 1), bv(0, 1))
    # muldiv
    div_ov = ila.ite(b == 0, bv(1, 1), bv(0, 1))
    mul_ov = ila.ite(b_mul != 0, bv(1, 1), bv(0, 1))
    # da
    acc_da_cy2 = acc_da_stage2[8:8]
    acc_da_cy = acc_da_cy2 | acc_da_cy1 | uc.cy
    # alu
    alu_cy_in = ila.choice('alu_cy_in', [uc.cy, bv(0, 1)])
    alu_cy_5b = ila.choice('alu_cy_5b', 
                           [ila.zero_extend(alu_cy_in, 5), 
                            ila.sign_extend(alu_cy_in, 5)])
    alu_src1_lo_5b = ila.zero_extend(acc[3:0], 5)
    alu_src2_lo_5b = ila.zero_extend(acc_src2[3:0], 5)
    alu_ac_add = (alu_src1_lo_5b + alu_src2_lo_5b + alu_cy_5b)[4:4]
    alu_ac_sub = ila.ite(alu_src1_lo_5b < (alu_src2_lo_5b + alu_cy_5b), 
                         bv(1, 1), bv(0, 1))
    alu_ac = ila.choice('alu_ac', [alu_ac_add, alu_ac_sub])
    alu_src1_sext = ila.sign_extend(acc, 9)
    alu_src2_sext = ila.sign_extend(acc_src2, 9)
    alu_src1_zext = ila.zero_extend(acc, 9)
    alu_src2_zext = ila.zero_extend(acc_src2, 9)
    alu_cy_9b_sext = ila.sign_extend(alu_cy_in, 9)
    alu_cy_9b_zext = ila.zero_extend(alu_cy_in, 9)
    alu_cy_9b = ila.choice('alu_cy_9b', [alu_cy_9b_zext, alu_cy_9b_sext])
    alu_zext_9b_sum = alu_src1_zext + alu_src2_zext + alu_cy_9b
    alu_cy_add = alu_zext_9b_sum[8:8]
    alu_cy_sub1 = ila.ite(alu_src1_zext < (alu_src2_zext + alu_cy_9b), 
                         bv(1, 1), bv(0, 1))
    alu_cy_sub2 = ila.ite(acc < (acc_src2 + ila.zero_extend(uc.cy, 8)), bv(1, 1), bv(0, 1))
    alu_cy = ila.choice('alu_cy', [alu_cy_add, alu_cy_sub1, alu_cy_sub2])
    alu_ov_9b_src1 = ila.choice('alu_ov_9b_src1', [alu_src1_sext, alu_src1_zext])
    alu_ov_9b_src2 = ila.choice('alu_ov_9b_src2', [alu_src2_sext, alu_src2_zext])
    alu_9b_add = alu_ov_9b_src1 + alu_ov_9b_src2 + alu_cy_9b
    alu_9b_sub = alu_ov_9b_src1 - alu_ov_9b_src2 + alu_cy_9b
    alu_9b_res = ila.choice('alu_9b_res', [alu_9b_add, alu_9b_sub])
    alu_ov = ila.ite(alu_9b_res[8:8] != alu_9b_res[7:7], bv(1, 1), bv(0, 1))
    acc_cy = ila.choice('acc_cy', [uc.cy, acc[0:0], acc[7:7], alu_cy])
    acc_ac = ila.choice('acc_ac', [uc.ac, alu_ac])
    acc_ov = ila.choice('acc_ov', [uc.ov, alu_ov])

    psw_bit = ila.concat(bit_cy, psw[6:0])
    psw_cjne = ila.concat(cjne_cy, psw[6:0])
    psw_div = ila.concat(bv(0, 1), ila.concat(psw[6:3], ila.concat(div_ov, psw[1:0])))
    psw_mul = ila.concat(bv(0, 1), ila.concat(psw[6:3], ila.concat(mul_ov, psw[1:0])))
    psw_da = ila.concat(acc_da_cy, psw[6:0])
    psw_acc = ila.concat(acc_cy, 
                ila.concat(acc_ac, 
                    ila.concat(psw[5:3], 
                        ila.concat(acc_ov, psw[1:0]))))
    psw_next = ila.choice('psw_next', [r_dir.psw, r_bit.psw, psw_cjne, psw_bit,
                                       psw_div, psw_mul, psw_da, psw_acc, psw])
    model.set_next('PSW', psw_next)

    ########################### SP ##############################################
    sp_next = ila.choice('sp_next', 
                         [sp+2, sp+1, sp-1, sp-2, sp, sp_pop, 
                          r_pop.sp, r_dir.sp, r_bit.sp])
    model.set_next('SP', sp_next)

    ########################### DPTR ##############################################
    mov_dptr = ila.choice('mov_dptr', [ila.concat(op1, op2), ila.concat(op2, op1)])
    inc_dptr = dptr + 1
    dptr_n1 = ila.choice('next_dptr', [mov_dptr, inc_dptr, dptr])
    dpl_n1 = dptr[7:0]
    dph_n1 = dptr[15:8]
    dpl_next = ila.choice('dpl_next', [dpl_n1, r_dir.dpl, r_bit.dpl, uc.dpl])
    dph_next = ila.choice('dph_next', [dph_n1, r_dir.dph, r_bit.dph, uc.dph])
    model.set_next('DPL', dpl_next)
    model.set_next('DPH', dph_next)

    ########################### B #################################################
    b_next = ila.choice('b_next', [b_mul, b_div, r_bit.b, r_dir.b, uc.b])
    model.set_next('B', b_next)

    ########################## XRAM ###############################################
    xram_addr_rx = ila.concat(bv(0, 8),ila.choice('lsb_xram_addr', [rx[0], rx[1]]))
    xram_addr_next = ila.choice('xram_addr', [xram_addr_rx, dptr, uc.xram_addr, bv(0, 16)])
    model.set_next('XRAM_ADDR', xram_addr_next)
    xram_data_out_next = ila.choice('xram_data_out', [bv(0, 8), acc])
    model.set_next('XRAM_DATA_OUT', xram_data_out_next)
    
    ########################## SFRS ###############################################
    sfrs = ['p0', 'p1', 'p2', 'p3', 'pcon', 'tcon', 'tmod', 'tl0',
            'th0', 'tl1', 'th1', 'scon', 'sbuf', 'ie', 'ip' ]
    for s in sfrs:
        sfr_next = ila.choice(s+'_next', [
                    getattr(r_bit, s), getattr(r_dir, s), getattr(uc, s)])
        model.set_next(s.upper(), sfr_next)

    for s in state:
        print s
        st = time.clock()
        model.synthesize(s, eval8051)
        t_elapsed = time.clock() - st
        ast = model.get_next(s)
        print 'time: %.2f' % t_elapsed
        model.exportOne(ast, 'asts/%s_%s' % (s, 'en' if enable_ps else 'dis'))

def main():
    ila.setloglevel(0, "")
    parser = argparse.ArgumentParser()
    parser.add_argument("--en", type=int, default=1, 
                        help="enable parameterized synthesis.")
    parser.add_argument("state", type=str, nargs='+', 
                        help='the state to synthesize.')
    args = parser.parse_args()
    synthesize(args.state, args.en)

if __name__ == '__main__':
    main()

