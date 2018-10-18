# File: simulator for the alu.

class ALU(object):
  def __init__(self):
    self.REGS  = []
    self.INPUT = 0

    for i in xrange(0, 8):
      self.REGS.append(0)

  def setStates(self, regList):
    if len(regList) != 8:
      print 'State size not match, need 9 registers'
      return 0

    for i in xrange(0, len(regList)):
      self.REGS[i] = regList[i]

  def simulate(self, ip):
    imm = ip & 0xff
    op  = (ip >> 8) & 0xff

    if op % 9 == 0:
      src1 = imm
    else:
      src1 = self.REGS[(op % 9) - 1]

    src2 = self.REGS[(op + 1) % 8]

    if op % 3 == 0:
      out = src1 * src2
    elif op % 3 == 1:
      out = src1 + src2
    else:
      out = src1 + src2

    out = out & 0xff

    print hex(ip), hex(op), hex(out)

    return out

def test():
  alu = ALU()
  init = [i + 1 for i in xrange(0, 8)]
  alu.setStates(init)
  print alu.simulate(0)
  print alu.simulate(1)
  print alu.simulate(0x0201)

if __name__ == '__main__':
  test()

