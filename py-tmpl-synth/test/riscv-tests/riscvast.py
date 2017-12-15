import ila

class riscv(object):
  def __init__(self):
    self.model = ila.Abstraction('risc-v')

    self.createInputs()

    self.op = self.ram[self.pc]
    

  def createInputs(self):
    # Program Counter
    self.pc = self.model.reg('PC', 64)

    # Ram is both data and programs
    self.ram = self.model.mem('RAM', 64, 64)

    # General Purpose Integer Regers (X0 is hard wired to 0)
    self.xregs = [self.model.reg('X%d' %i, 64) for i in xrange(31)]

    # General Purpose FP registers
    self.fregs = [self.model.reg('F%d' %i, 64) for i in xrange(31)]
