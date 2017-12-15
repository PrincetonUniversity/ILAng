import ila

def sim(state_in):
  rom = state_in['rom']
  pc = state_in['pc']

  state_out = state_in
  opcode = rom[pc]
  r0 = state_in['r0']
  r1 = state_in['r1']
  print 'ROM:', rom
  print 'pc:%08x r0:%08x r1:%08x' % (pc, r0, r1)
  if opcode == 0:
    state_out['r0'] = (r0 + r1)
  elif opcode == 1:
    state_out['r0'] = (r0 - r1)
  elif opcode == 2:
    state_out['r0'] = (r0 + 1)
  else:
    state_out['r0'] = (r0 - 1)

  print 'r0_out:%08x' % state_out['r0']
  return state_out


ila.setloglevel(0,"")
#ila.enablelog("Synthesizer")
m = ila.Abstraction('test')
regs = [m.reg('r%d' % i, 32) for i in xrange(4)]
pc = m.reg('pc', 32)
rom = m.mem('rom', 32, 32)

m.fetch_expr = rom[pc]
m.decode_exprs = [rom[pc] == 0, rom[pc] == 1, rom[pc] == 2, rom[pc] == 3]

r0_next = ila.choice('t1', [regs[0] + regs[1], regs[0] - regs[1], regs[0] + 1, regs[0] - 1])
m.set_next('r0', r0_next)
m.synthesize('r0', sim)
print m.get_next('r0')
