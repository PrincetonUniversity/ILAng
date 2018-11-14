#!/usr/bin/python

import os
import subprocess
import json

no_step = 20

YosysPath = os.getenv("HOME") + "/yosys/yosys"
YosysSMTPath = os.getenv("HOME") + "/yosys/yosys-smtbmc"

YosysScript = """
read_verilog -formal {foutname}.v;
prep -top wrapper; 
flatten;

memory -nordff
write_smt2 -mem -bv -wires {foutname}.smt2
"""

VTemplate = """
module wrapper(input clk, input rst, input [7:0] inst, input nondet_start,input [1:0] dummy_read_rf, output [7:0] dummy_rf_data , output allassert, input dummy_reset);

wire [7:0] impl_rf;
wire [7:0] spec_rf0;
wire [7:0] spec_rf1;
wire [7:0] spec_rf2;
wire [7:0] spec_rf3;
reg start;
reg started;
reg _1;
reg _2;
reg _3;
wire commit = _3;

/*def_list*/

assign dummy_rf_data = impl_rf & spec_rf0 & spec_rf1 & spec_rf2 & spec_rf3 ;

simpleALU    m0(.clk(clk), .rst(rst), .inst(inst), .__ILA_simpleALU_grant__(4'b1111) , .r0(spec_rf0), .r1(spec_rf1), .r2(spec_rf2), .r3(spec_rf3) );
pipeline_alu m1(.clk(clk), .rst(rst), .inst(inst), .dummy_read_rf(dummy_read_rf), .dummy_rf_data( impl_rf ) , /*port_list_top*/);


always @(posedge clk) begin
	if(rst)
		started <= 1'b0;
    else if(start) 
        started <= 1'b1;
end

// monitors
always @(posedge clk) begin
    if(rst) // || ( nondet_start && ~started) 
        start <= 1'b1;
    else if(start || started)
        start <= 1'b0;
end

always @(posedge clk) begin
    if(rst == 1) 
        _1 <= 1'b0;
    else
        _1 <= start;
end
always @(posedge clk) begin
    if(rst == 1) 
        _2 <= 1'b0;
    else
        _2 <= _1;
end
always @(posedge clk) begin
    if(rst == 1) 
        _3 <= 1'b0;
    else
        _3 <= _2;
end

{Assumes}

{Asserts}

{newWires}
assign allassert = {AndOfAssrtWires} ;

endmodule

"""

port_list_out = [] # output
def_list = [] # wire ...
port_list_top =  [] # instantiation
inner_assign_list   = [] # assign 
replaceDict = {}

def InstrumentLoad(fname):
	def wtos(w): 
		if w==1 : return ''
		return '[%d:0]' % (w-1)
	instMap = json.loads(open(fname).read())

	for n,w in instMap['m1'].items():
		ni = n.split('.')[1]
		no = ni.replace('[','_').replace(']','_')
		w = wtos(int(w))
		print ni,no,w
		port_list_out.append('output {w} {no}'.format(w=w,no=no))
		inner_assign_list.append('assign {no} = {ni} ;'.format(no=no,ni=ni))
		port_list_top.append('.{no}({no})'.format(no=no))
		def_list.append('wire {w} {no} ;'.format(w=w,no=no))
		replaceDict[n] = no;

	for n,n2 in instMap['m0'].items():
		replaceDict[n] = n2;

def InstrAssumptAssume(sin):
	print 
	retval = sin[:]
	for k,v in replaceDict.items():
		retval = retval.replace(k,v)
	return retval 

def InstrFile(ctx):
	ctx = ctx.replace('/*port_list_out*/',','.join(port_list_out))
	ctx = ctx.replace('/*def_list*/',     '\n'.join(def_list))
	ctx = ctx.replace('/*port_list_top*/',','.join(port_list_top))
	ctx = ctx.replace('/*inner_assign_list*/', '\n'.join(inner_assign_list))
	return ctx



def GenVerifWrapper(assumpts, asserts, finlist, foutname , newWires, AndOfAssrtWires , arbInit = False):
	fout = open(foutname+'.v', 'w')
	if arbInit:
		Vt = VTemplate.replace('(rst)','(dummy_reset)')
	else:
		Vt = VTemplate
	fout.write( Vt.format(Assumes = '\n'.join(assumpts) , Asserts = '\n'.join(asserts) ,
		AndOfAssrtWires = AndOfAssrtWires, newWires = newWires ) )
	for fn in finlist:
		with open(fn) as fin:
			fout.write('\n//File: %s\n' % fn)
			fout.write(fin.read())
	fout.close()

	fin = open(foutname+'.v')
	beforeInst = fin.read()
	fin.close()

	afterInst = InstrFile(beforeInst)
	with open(foutname+'.v', 'w') as fout:
		fout.write(afterInst)

def RunVlgChecker(foutname, arbInit = False):
	with open('YosysScript.ys','w') as fout:
		fout.write(YosysScript.format(foutname = foutname))
	# generate smt-lib2
	subprocess.call([YosysPath, "YosysScript.ys" ])
	# call verifer  
	subprocess.call([YosysSMTPath, "--dump-vcd","trace.vcd","-s","z3" , '-t', str(no_step if arbInit else 40) , "{foutname}.smt2".format(foutname = foutname) ])

def StepCount(rfmap):
    bnd = max([int(inst["ready bound"]) for inst in rfmap["instructions"] ]) 
    return (bnd if bnd > 0 else 1)
        

def Verify(rfJsonIn, vMapJsonIn, vlgOut):
	# Extract info from JSON
	rfmap = json.loads(open(rfJsonIn).read())
	vmap  = json.loads(open(vMapJsonIn).read())
	global no_step
	no_step = StepCount(rfmap)
	InstrumentLoad('ref-rel/instrument-map.json')

	finlist = [ rfmap["target ILA"].split(':')[0] , rfmap["target Verilog"].split(':')[0] ]
	foutname = vlgOut.split('.')[0]

	globalInv = rfmap["global invariants"]
	stateMap  = vmap["state mapping"]

	#now let's check the invariants first
	assumpts = []
	asserts = []
	newWires = ''
	idx = 0
	for inv in globalInv:
		result_inv = InstrAssumptAssume(inv)
		asserts.append("assert property ( %s ) ; " % result_inv )
		newWires += ("wire _p{idx}_; \n assign _p{idx}_ = {ctx} ; \n ".format(idx = idx, ctx = result_inv))
		idx += 1
	AndOfAssrtWires = ' && ' . join ( ['_p%d_' % i for i in range(idx)] )
	GenVerifWrapper(assumpts, asserts, finlist, foutname = foutname, newWires = newWires,  AndOfAssrtWires = AndOfAssrtWires)
	RunVlgChecker(foutname)

	#now let's check the instructions
	# dummy_reset

	assumpts = []
	asserts = []
	newWires = ''
	idx = 0
	for inv in globalInv:
		result_inv = InstrAssumptAssume(inv) # change the name to the newly added wire
		assumpts.append("assume property ( %s ) ; " % result_inv)
		idx += 1

	for sm in stateMap:
		result_sm = InstrAssumptAssume(sm)
		assumpts.append("assume property ( ( ~start ) || (%s) );" % result_sm)

	idx = 0
	for sm in stateMap:
		result_sm = InstrAssumptAssume(sm)
		asserts.append("assert property ( ( ~ _1 ) || (%s) ) ; " % result_sm )
		newWires += ("wire _p{idx}_; \n assign _p{idx}_ = {ctx} ; \n ".format(idx = idx, ctx = result_sm))
		idx += 1
	AndOfAssrtWires = ' && ' . join ( ['_p%d_' % i for i in range(idx)] )
	GenVerifWrapper(assumpts, asserts, finlist, foutname = foutname, newWires = newWires,  AndOfAssrtWires = AndOfAssrtWires, arbInit = True)
	RunVlgChecker(foutname, arbInit = True)



if __name__ == '__main__':
	Verify('ref-rel/ref-rel-verilog.json' ,  'ref-rel/ref-rel-var-map.json' , 'vlg-gen/all.v')

