# This test script create ILA from Python model,
# and then it generates the Verilog.
# By using the built-in wrapper within this script,
# it performs an exhaust test on the generated Verilog.

# Python Model -->> ILA -->> Verilog
#   |                            |
#   -----------------------------
#           compare


import ila
import subprocess

VerilogFile = 'tmp/test_verilog_export.v'

def foo(d):
    # print 'initial value: %s' % str(d)
    return { "sum": d['r0'] + d['r1'] }

def bar(d):
    # print 'initial value: %s' % str(d)
    return { "diff": d['r0'] - d['r1'] }

def baz(d):
    # print d
    a = d['a']
    b = d['b']
    return  { "baz": a ^ b }
    
def shaz(d):
    # print d
    a = d['a']
    b = d['b']
    return { "shaz": not(a ^ b) }

def daz(d):
    r0 = d['r0']
    r1 = d['r1']
    return { "daz": r0 + r1 + 0x44 }

def razmatazz(d):
    r0 = d['r0']
    r1 = d['r1']
    r0lo = r0 & 0xf
    r1hi = (r1 & 0xf0) >> 4
    res = r0lo + r1hi
    return { "razmatazz": res }

def jazz(d):
    r0 = d['r0']
    r1 = d['r1']
    r0lo = r0 & 0xf
    return { "jazz": (r0 & 0xf) | (r0lo << 4) }

#    temp1 = ?? How to concat
#    return
    
def main():
    
    
    # ila.enablelog("Synthesizer")
    ila.enablelog("VerilogExport")
    ila.setloglevel(3,"")
    
    
    sys = ila.Abstraction("test")
    r0 = sys.reg('r0', 8)
    r1 = sys.reg('r1', 8)

    a = sys.bit('a')
    b = sys.bit('b')
    
    out1 = sys.reg('Rsum',8)
    out2 = sys.reg('Rdiff',8)
    out3 = sys.bit('Rbaz')
    out4 = sys.bit('Rshaz')
    out5 = sys.reg('Rdaz',8)
    
    out6 = sys.reg('Rrazmatazz',4)
    out7 = sys.reg('Rjazz',8)
    
    mem  = sys.mem('mem1',2,4)
    
    action1 = ila.store(mem,r0[1:0],r1[3:0])
    action2 = ila.store(mem,r1[1:0],r0[3:0])
    action3 = ila.store( ila.store(mem,r0[7:6],r1[7:4]) ,r1[7:6],r0[7:4] )
    
    final_action = ila.ite(a,action1,  ila.ite(b,action2,action3))
    sys.set_next('mem1',final_action)

    ex = ila.choice("function", r0+r1, r0-r1, r0+r1+1)
    resfoo = sys.syn_elem("sum", ex, foo)
    assert sys.areEqual(resfoo, r0+r1)

    resbar = sys.syn_elem("diff", ex, bar)
    assert sys.areEqual(resbar, r0-r1)

    a1 = ila.choice("a1", a, ~a, a&b, a|b)
    b1 = ila.choice("b1", [b, ~b, a&b, a|b, a^b])

    a2 = ila.choice("a2", a, ~a)
    b2 = ila.choice("b2", b, ~b)

    t1 = a1 & b1
    t2 = a2 & b2
    y  = t1 | t2
    resbaz = sys.syn_elem("baz", y, baz)
    assert sys.areEqual(resbaz, a^b)

    resshaz= sys.syn_elem("shaz", y, shaz)
    assert sys.areEqual(resshaz, ~(a^b))
    
    c = ila.inrange("cnst", sys.const(0x00,8), sys.const(0xff,8))
    z = ila.choice("func_z", r0+r1+c, r0+r1-c)
    resdaz = sys.syn_elem("daz", z, daz)
    assert sys.areEqual(resdaz, r0 + r1 + 0x44)

    slc0 = ila.readslice("r0slice", r0, 4)
    slc1 = ila.readchunk("r1chunk", r1, 4)
    res = ila.choice('slice', slc0 + slc1, slc0 - slc1)
    resrmz = sys.syn_elem("razmatazz", res, razmatazz)
    assert sys.areEqual(resrmz, r0[3:0]+r1[7:4])

    nr0 = ila.writeslice("wr0slice", r0, slc0)
    resjazz = sys.syn_elem("jazz", nr0, jazz)
    assert sys.areEqual(resjazz, ila.concat(r0[3:0], r0[3:0]))
    
    sys.set_next('Rsum',resfoo)
    sys.set_next('Rdiff',resbar)
    sys.set_next('Rbaz',resbaz)
    sys.set_next('Rshaz',resshaz)
    sys.set_next('Rdaz',resdaz)
    sys.set_next('Rrazmatazz',resrmz)
    sys.set_next('Rjazz',resjazz)
    
    sys.generateVerilog(VerilogFile)
    
    testVerilog(VerilogFile)




built_in_rtl_wrapper = """
module wrapper();

reg clk;
reg rst;

integer infile;
integer ofile;

`define MAX_LINE_LENGTH 1000
reg [8*`MAX_LINE_LENGTH:0] line; /* Line of text read from file */

reg             Rbaz_OG ;
reg             Rbaz_WAIT ;
reg[7:0]        Rdaz_OG ;
reg             Rdaz_WAIT ;
reg[7:0]        Rdiff_OG ;
reg             Rdiff_WAIT ;
reg[7:0]        Rjazz_OG ;
reg             Rjazz_WAIT ;
reg[3:0]        Rrazmatazz_OG ;
reg             Rrazmatazz_WAIT ;
reg             Rshaz_OG ;
reg             Rshaz_WAIT ;
reg[7:0]        Rsum_OG ;
reg             Rsum_WAIT ;
reg             a_OG ;
reg             a_WAIT ;
reg             b_OG ;
reg             b_WAIT ;
reg[7:0]        r0_OG ;
reg             r0_WAIT ;
reg[7:0]        r1_OG ;
reg             r1_WAIT ;

wire[7:0]   r1 ;
wire[7:0]   Rjazz ;
wire[7:0]   Rdaz ;
wire[3:0]   Rrazmatazz ;
wire[7:0]   Rdiff ;
wire        Rbaz ;
wire        Rshaz ;
wire[7:0]   r0 ;
wire[7:0]   Rsum ;
wire        a ;
wire        b ;

reg[31:0]   counterMax;

reg dummy;

// other controls

// finish logic
reg[31:0]   CycCount;
reg[31:0]   startCycle;
wire[31:0]  curCycle = CycCount;
reg         endSimulation;

always @(posedge clk) begin
    if(rst)
        CycCount <= 0;
    else begin
        CycCount <= CycCount + 1;
        #1 if(CycCount == counterMax) begin
            $display("Time out. Simulation terminated.\\n");
            endSimulation = 1;
        end
    end
end


initial begin
    //$dumpfile("tmp/wrapper.vcd");
    //$dumpvars(0,wrapper);

    endSimulation = 0;
    infile = $fopen("tmp/assign.in","r");
    
    
    dummy = $fscanf(infile, "%d", counterMax  );

    clk = 0;
    #1 rst = 1;
    #4 clk = 1;
    #5 clk = 0;
    #1 rst = 0;

    dummy = $fscanf(infile, "%s %h %b",line, Rbaz_OG , Rbaz_WAIT  );    // RegDirect
    dummy = $fscanf(infile, "%s %h %b",line, Rdaz_OG , Rdaz_WAIT  );    // RegDirect
    dummy = $fscanf(infile, "%s %h %b",line, Rdiff_OG , Rdiff_WAIT  );  // RegDirect
    dummy = $fscanf(infile, "%s %h %b",line, Rjazz_OG , Rjazz_WAIT  );  // RegDirect
    dummy = $fscanf(infile, "%s %h %b",line, Rrazmatazz_OG , Rrazmatazz_WAIT  );    // RegDirect
    dummy = $fscanf(infile, "%s %h %b",line, Rshaz_OG , Rshaz_WAIT  );  // RegDirect
    dummy = $fscanf(infile, "%s %h %b",line, Rsum_OG , Rsum_WAIT  );    // RegDirect
    dummy = $fscanf(infile, "%s %h %b",line, a_OG , a_WAIT  );  // RegDirect
    dummy = $fscanf(infile, "%s %h %b",line, b_OG , b_WAIT  );  // RegDirect
    dummy = $fscanf(infile, "%s %h %b",line, r0_OG , r0_WAIT  );    // RegDirect
    dummy = $fscanf(infile, "%s %h %b",line, r1_OG , r1_WAIT  );    // RegDirect

    // set the current state
    
    test.Rbaz = Rbaz_OG;
    test.Rdaz = Rdaz_OG;
    test.Rdiff = Rdiff_OG;
    test.Rjazz = Rjazz_OG;
    test.Rrazmatazz = Rrazmatazz_OG;
    test.Rshaz = Rshaz_OG;
    test.Rsum = Rsum_OG;
    test.a = a_OG;
    test.b = b_OG;
    test.r0 = r0_OG;
    test.r1 = r1_OG;
    

    startCycle = curCycle; // should be zero @ this point

    //  and execute 
    #4 clk = 1;
    forever #5 clk = ~clk;
end



always @(*) begin
    if(endSimulation) begin
        $fclose(infile);
        // dump the signals
        ofile = $fopen("tmp/result.out","w");

        $fwrite(ofile,".RTL_OP_START\\n"); 

        $fwrite(ofile,"%s %h\\n"        ,"Rbaz",test.Rbaz); 
        $fwrite(ofile,"%s %h\\n"        ,"Rdaz",test.Rdaz); 
        $fwrite(ofile,"%s %h\\n"        ,"Rdiff",test.Rdiff); 
        $fwrite(ofile,"%s %h\\n"        ,"Rjazz",test.Rjazz); 
        $fwrite(ofile,"%s %h\\n"        ,"Rrazmatazz",test.Rrazmatazz); 
        $fwrite(ofile,"%s %h\\n"        ,"Rshaz",test.Rshaz); 
        $fwrite(ofile,"%s %h\\n"        ,"Rsum",test.Rsum); 
        $fwrite(ofile,"%s %h\\n"        ,"a",test.a); 
        $fwrite(ofile,"%s %h\\n"        ,"b",test.b); 
        $fwrite(ofile,"%s %h\\n"        ,"r0",test.r0); 
        $fwrite(ofile,"%s %h\\n"        ,"r1",test.r1); 

        $fwrite(ofile,".RTL_OP_END\\n");

        $fclose(ofile);
        $finish;
    end
end

test    test (
        .r1         (r1) ,
        .Rjazz          (Rjazz) ,
        .Rdaz           (Rdaz) ,
        .Rrazmatazz         (Rrazmatazz) ,
        .Rdiff          (Rdiff) ,
        .Rbaz           (Rbaz) ,
        .Rshaz          (Rshaz) ,
        .r0         (r0) ,
        .Rsum           (Rsum) ,
        .a          (a) ,
        .b          (b) ,
        .clk            (clk) ,
        .step           (1'b1) ,
        .rst            (rst) 
);


always @(negedge clk) begin
    if(rst) begin
    end
    else begin
        #2;
        if( ( curCycle == startCycle + 1 ) ) begin
            endSimulation = 1;
        end
    end
end

endmodule
"""


def compareSignWithUnsigned(value1,value2,width):

    if value1 <0:
        value1 = 2**width + value1
    if value1 >= 2**width:
        value1 = value1 % (2**width)
    if value2 <0:
        value2 = 2**width + value2
    if value2 > 2**width:
        value2 = value2 % (2**width)
    if value1 != value2:
        print value1
        print value2
    return value1 == value2



def testVerilog(vlog_name):
    #extract wrapper
    with open ('tmp/VerilogWrapperGen.v','wt') as wrapper:
        wrapper.write(built_in_rtl_wrapper)

    #compile the two
    subprocess.call(['iverilog','tmp/VerilogWrapperGen.v',VerilogFile,'-o','tmp/RTLsim'])

    #exhaust test
    RTLSim = SimInterface()

    #subprocess.call(['mknod','tmp/assign.in','p'])
    #subprocess.call(['mknod','tmp/result.out','p'])

    s_input = {}
    for states in RTLSim.sortedStates:
        s_input[states] = 0

    for r0 in range(2**2,2**4):
        for r1 in range(2**2,2**4):
            for a in range(2):
                for b in range(2):
                    s_input['a'] = a
                    s_input['b'] = b
                    s_input['r0'] = r0
                    s_input['r1'] = r1
                    simResult = RTLSim.sim(s_input)


                    assert(compareSignWithUnsigned( foo(s_input)['sum'] , simResult['Rsum'] ,8) )
                    assert(compareSignWithUnsigned( bar(s_input)['diff'] , simResult['Rdiff'] ,8))
                    assert(compareSignWithUnsigned( daz(s_input)['daz']  , simResult['Rdaz'] ,8))
                    assert(compareSignWithUnsigned( razmatazz(s_input)['razmatazz']  , simResult['Rrazmatazz'] ,4))
                    assert(compareSignWithUnsigned( jazz(s_input)['jazz']  , simResult['Rjazz'] ,8))

                    assert(compareSignWithUnsigned( baz(s_input)['baz'] , simResult['Rbaz'] ,1))
                    assert(compareSignWithUnsigned( shaz(s_input)['shaz'] , simResult['Rshaz'] ,1))
    print 'All matched.'
                    


    

class SimInterface:
    def __init__(self):
        self.inFile = "tmp/assign.in"
        self.outFile = "tmp/result.out"
        self.sortedStates = ["Rbaz",
            "Rdaz",
            "Rdiff",
            "Rjazz",
            "Rrazmatazz",
            "Rshaz",
            "Rsum",
            "a",
            "b",
            "r0",
            "r1"]

    def sim(self,s_in):

        # write file
        with open(self.inFile,"wt") as AssignFile:
            print >> AssignFile, '10'
            for stateName in self.sortedStates:
                print >> AssignFile , stateName + ' ' + ('%x' % s_in[stateName] ) + ' 0'

        # invoke simulator
        subprocess.call(['./tmp/RTLsim'])

        with open(self.outFile) as ResultFile:
            line = ResultFile.readline()
            assert(line=='.RTL_OP_START\n')

            outState = {}
            line = ResultFile.readline()        
            while (line != ".RTL_OP_END\n"):
                wordList = line.split()
                SimVal = int( wordList[1], 16 )
                outState[ wordList[0] ] = SimVal
                line =  ResultFile.readline()    

        return outState


    


if __name__ == '__main__':
    main()
