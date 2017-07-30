import ila
import NyILA
SCALAR_REG_BITS = 32
SCALAR_REGS_PER_MACHINE = 32
PC_BITS = 32
VECTOR_LANE_BITS = 32
VECTOR_LANES_PER_REG = 16
VECTOR_REGS_PER_MACHINE = 32
VECTOR_MASK_REG_BITS = 32
MEM_ADDRESS_BITS = 32

def AddInst(rm):
	rm.model.set_next('pc', rm.pc_nxt())
	print 1
	rm.model.set_next('mem', rm.mem_nxt())
	for regNo in xrange(1, SCALAR_REGS_PER_MACHINE):
		rm.model.set_next('SREG_' + str(regNo), rm.sreg_nxt(regNo))
        print 2
	mask = rm.indexToSGPR(rm.rrMask)
	print 3
	for regNo in xrange(VECTOR_REGS_PER_MACHINE):
		for laneNo in xrange(VECTOR_LANES_PER_REG):
			rm.model.set_next('VREG_' + str(regNo) + '_' + str(laneNo), ila.ite(rm.isMask, ila.ite(mask[laneNo] == rm.model.const(0b1, 1), rm.vector_registers[regNo][laneNo], rm.vreg_nxt(regNo, laneNo, rm.rrType)), rm.vreg_nxt(regNo, laneNo, rm.rrType)))
			print regNo
			print laneNo
	print 4
rm = NyILA.nyGPUModel()
AddInst(rm)
