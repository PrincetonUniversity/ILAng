#! /usr/bin/python2.7

import ila
from riscvast import riscv
from riscvsim import *

def synthesize():
  rv = riscv()

  xregs = rv.xregs
  fregs = rv.fregs
  pc = rv.pc
  ram = rv.ram
  bv = rv.model.const

  rv.model.fetch_expr = rv.op
  rv.model.decode_exprs = [rv.op == i for i in xrange(2)]

  X1_next = ila.choice('x1', [bv(0x1, 64), xregs[0], xregs[2]])
  rv.model.set_next('X1', X1_next)
  rv.model.set_init('X0', bv(0x2, 64))
  rv.model.set_next('X0', bv(0x2, 64))

  rv.model.set_init('X2', bv(0x0, 64))
  rv.model.set_next('X2', bv(0x0, 64))

  rv.model.synthesize('X1', sim)
  synthesized = rv.model.get_next('X1')
  # expected: (if (or (eq (readmem RAM PC) 0x1) (eq (readmem RAM PC) 0x0)) X2 X1)
  expected = ila.ite((ram[pc] == 1) | (ram[pc] == 0), xregs[2], xregs[1])
  assert rv.model.areEqual(synthesized, expected)

#############################################################
if __name__ == '__main__':
  ila.setloglevel(0, '')
  synthesize()
