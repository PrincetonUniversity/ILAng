import ila

def template():
  # Create a model container.
  m = ila.Abstraction('tutorial')

  # Create/define states in the model.
  regs = []
  for i in xrange(0, 8):
    regName = 'reg{}'.format(i)
    regs.append(m.reg(regName, 8))

  instr = m.reg('input', 16)
  out   = m.reg('output', 8)

  # Define next state function.
  imm = instr[7:0]
  src1 = ila.choice('src1', regs + [imm])
  src2 = ila.choice('src2', regs + [imm])
  out_nxt  = ila.choice('out', [src1 + src2, 
                                src1 * src2])

  # Assign the next state function.
  m.set_next('output', out_nxt)


  # Define how to decode.
  m.decode_exprs = [instr[15:8] == i for i in xrange(0, 0x100)]

  return m


if __name__ == '__main__':
  m = template()

