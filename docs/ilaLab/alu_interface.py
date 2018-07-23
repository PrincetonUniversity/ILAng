# File: simultor interface
from alu_sim import ALU

def sim(s_in):
  regs = []
  for i in xrange(0, 8):
    regName = 'reg{}'.format(i)
    regs.append(s_in[regName])

  alu = ALU()
  alu.setStates(regs)

  out = alu.simulate(s_in['input'])

  s_out = s_in
  s_out['output'] = out

  return s_out

if __name__ == '__main__':
  s_in = { 'reg0'  : 1,
           'reg1'  : 2,
           'reg2'  : 3,
           'reg3'  : 4,
           'reg4'  : 5,
           'reg5'  : 6,
           'reg6'  : 7,
           'reg7'  : 8,
           'input' : 0x02000001,
           'output': 0
  }
  s_out = sim(s_in)
