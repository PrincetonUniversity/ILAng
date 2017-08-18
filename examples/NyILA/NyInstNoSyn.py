import ila
import NyILANoSyn
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
	for regNo in xrange(SCALAR_REGS_PER_MACHINE):
		rm.model.set_next('SREG_' + str(regNo), rm.sreg_nxt(regNo))
        print 2
	mask = rm.indexToSGPR(rm.rrMask)
	print 3
	for regNo in xrange(VECTOR_REGS_PER_MACHINE):
		for laneNo in xrange(VECTOR_LANES_PER_REG):
			#rm.model.set_next('VREG_' + str(regNo) + '_' + str(laneNo), ila.ite(rm.isMask, ila.ite(mask[laneNo] == rm.model.const(0b1, 1), rm.vector_registers[regNo][laneNo], rm.vreg_nxt(regNo, laneNo, rm.rrType)), rm.vreg_nxt(regNo, laneNo, rm.rrType)))
			rm.model.set_next('VREG_' + str(regNo) + '_' + str(laneNo), rm.vreg_nxt(regNo, laneNo))
			print regNo
			print laneNo
	print 4
rm = NyILANoSyn.nyGPUModel()
AddInst(rm)

state = ['pc'] + ['mem'] 
for i in xrange(SCALAR_REGS_PER_MACHINE):
	state.append('SREG_' + str(i))
for i in xrange(VECTOR_REGS_PER_MACHINE):
	for j in xrange(VECTOR_LANES_PER_REG):
		state.append('VREG_' + str(i) + '_' + str(j))
rm.model.generateVerilog('NyGPU.v')
#for s in state:
#	ast = rm.model.get_next(s)
#	file = open('asts/%s'%s, 'w+')
#	rm.model.exportOne(ast, 'asts/%s'%s)
