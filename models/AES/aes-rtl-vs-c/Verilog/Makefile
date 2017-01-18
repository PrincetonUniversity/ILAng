CC = g++
VCC = verilator
VERILOG_SRC = simXramAes_top.v
VERILOG_TOP = simXramAes_top.v
CXX_SRC = simulateAES.cpp
EXEC = AESsim


IDIR = /usr/local/share/verilator/include/
LOCAL_IDIR = obj_dir
CFLAGS = -I $(IDIR) -I $(LOCAL_IDIR) -Wall -O3

CXX_OBJ = $(CXX_SRC:.cpp=.o)
VERILOG_MK = $(VERILOG_TOP:.v=.mk)
VERILOG_LIB = $(VERILOG_TOP:.v=__ALL.a)

$(EXEC):verilogcxx $(CXX_OBJ) 
	$(CC) $(CXX_OBJ) verilated.o $(LOCAL_IDIR)/V$(VERILOG_LIB) -o $@
	cp $@ ../

verilated.o:$(CXX_OBJ)

clean:
	-rm -r -f $(LOCAL_IDIR)
	-rm -f $(EXE)
	-rm	-f $(CXX_OBJ)
	-rm -f sim
	-rm -f AESsim
	-rm -f ../AESsim
	-rm -f *~
	
.cpp.o:
	$(CC) $(CFLAGS) -c $<
	make -C $(LOCAL_IDIR) -j -f V$(VERILOG_MK) ../$@ verilated.o


verilogcxx: $(VERILOG_SRC)
	$(VCC) -Wall --cc $^
	make -C $(LOCAL_IDIR) -j -f V$(VERILOG_MK) V$(VERILOG_LIB)

vsim:
	iverilog -o sim oc8051_timescale.v T.v S.v xS.v S4.v table_lookup.v expand_key_128.v one_round.v final_round.v oc8051_xram.v aes_128.v reg16byte.v reg32byte.v reg256byte.v reg2byte.v aes_top.v simXramAes_top.v top.t.v 
