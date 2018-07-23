# File: specify property and bounded model check
import ila

def bmc():
  m = ila.Abstraction('alu')
  m.importAll('ALU_moore.ila')

  # Create state for property predicate
  prop = m.bit('prop')
  prop_nxt = prop & (m.getreg('input') == 0x0)
  m.set_next('prop', prop_nxt)

  # Set initial condition
  m.set_init('prop', m.bool(True))
  m.set_init('input', m.const(0x0, 16))

  # Create golden model
  golden = ila.Abstraction('golden')
  g_prop = golden.bit('prop')
  golden.set_next('prop', golden.bool(True))
  golden.set_init('prop', golden.bool(True))

  # Call bmc
  print ila.bmc(10, m, prop, 1, golden, g_prop)


if __name__ == '__main__':
  bmc()
