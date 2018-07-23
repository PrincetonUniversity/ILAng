import ila

from alu_interface import sim
from alu_template import template

def synthesis():
  m = template()
  m.enable_parameterized_synthesis = 1

  m.synthesize('output', sim)

  m.exportOne(m.get_next('output'), 'out.ila')
  m.exportAll('ALU.ila')


if __name__ == '__main__':
  synthesis()
