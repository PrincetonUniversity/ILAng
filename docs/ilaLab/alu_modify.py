# File: Modify the synthesized ALU into a Moore machine.
import ila

def modify():
  # Create the ILA container.
  m = ila.Abstraction('alu')

  # Import the whole ILA from file.
  m.importAll('ALU.ila')

  # Completely define transition relations for unspecified states.
  for i in xrange(0, 8):
    regName = 'reg{}'.format(i)
    m.set_next(regName, m.getreg(regName))

  out_nxt = m.get_next('output')
  inp_nxt = ila.concat(out_nxt, out_nxt)
  m.set_next('input', inp_nxt)

  # Export the result
  m.exportAll('ALU_moore.ila')

if __name__ == '__main__':
  modify()
