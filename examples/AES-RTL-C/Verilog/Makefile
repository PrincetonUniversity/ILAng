CC = g++
VCC = verilator
VERILOG_SRC = simXramAes_top.v
VERILOG_TOP = simXramAes_top.v
CXX_SRC = simulateAES.cpp
EXEC = AESsim

IDIR = /usr/share/verilator/include
LOCAL_IDIR = obj_dir

VERILATOR_SRC = $(IDIR)/verilated.cpp
CFLAGS = -I $(IDIR) -I $(LOCAL_IDIR) -Wall -O3

CXX_OBJ = $(CXX_SRC:.cpp=.o)
VXX_OBJ = verilated.o
VERILOG_MK = $(VERILOG_TOP:.v=.mk)
VERILOG_LIB = $(VERILOG_TOP:.v=__ALL.a)

$(EXEC):verilogcxx $(CXX_OBJ) $(VXX_OBJ)
	$(CC) $(CXX_OBJ) $(VXX_OBJ) $(LOCAL_IDIR)/V$(VERILOG_LIB) -o $@
	cp $@ ..

clean:
	-rm -r -f $(LOCAL_IDIR)
	-rm -f $(EXEC)
	-rm	-f $(CXX_OBJ) $(VXX_OBJ)
	-rm -f sim
	-rm -f ../$(EXEC)
	-rm -f *~

$(VXX_OBJ):
	$(CC) $(CFLAGS) -c $(VERILATOR_SRC)

.cpp.o:
	$(CC) $(CFLAGS) -c $<


verilogcxx: $(VERILOG_SRC) 
	$(VCC) -Wall --cc $^
	make -C $(LOCAL_IDIR) -j -f V$(VERILOG_MK) V$(VERILOG_LIB)

vsim:
	iverilog -o sim oc8051_timescale.v T.v S.v xS.v S4.v table_lookup.v expand_key_128.v one_round.v final_round.v oc8051_xram.v aes_128.v reg16byte.v reg32byte.v reg256byte.v reg2byte.v aes_top.v simXramAes_top.v top.t.v 
