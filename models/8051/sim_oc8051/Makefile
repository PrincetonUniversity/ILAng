CC = g++
CFLAGS = -std=c++11 -O0 -g -Wall
CFLAGS = -std=c++11 -O3 

SRCS = subfun_cppUpdateFun_ACC.cpp subfun_cppUpdateFun_B.cpp subfun_cppUpdateFun_DPH.cpp subfun_cppUpdateFun_DPL.cpp subfun_cppUpdateFun_IE.cpp subfun_cppUpdateFun_IP.cpp subfun_cppUpdateFun_IRAM.cpp subfun_cppUpdateFun_P0.cpp subfun_cppUpdateFun_P1.cpp subfun_cppUpdateFun_P2.cpp subfun_cppUpdateFun_P3.cpp subfun_cppUpdateFun_PC.cpp subfun_cppUpdateFun_PCON.cpp subfun_cppUpdateFun_PSW.cpp subfun_cppUpdateFun_SBUF.cpp subfun_cppUpdateFun_SCON.cpp subfun_cppUpdateFun_SP.cpp subfun_cppUpdateFun_TCON.cpp subfun_cppUpdateFun_TH0.cpp subfun_cppUpdateFun_TH1.cpp subfun_cppUpdateFun_TL0.cpp subfun_cppUpdateFun_TL1.cpp subfun_cppUpdateFun_TMOD.cpp subfun_cppUpdateFun_XRAM_ADDR.cpp subfun_cppUpdateFun_XRAM_DATA_OUT.cpp subfun_update.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)
EXE = oc8051_sim

all: $(SRCS) $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm *.o 
