CC = g++
CFLAGS = -g -Wall -O0
CFLAGS = -std=c++11 -O3

SRCS = subfun_cppUpdateFun_XRAM.cpp subfun_cppUpdateFun_aes_addr.cpp subfun_cppUpdateFun_aes_ctr.cpp subfun_cppUpdateFun_aes_key0.cpp subfun_cppUpdateFun_aes_key1.cpp subfun_cppUpdateFun_aes_keysel.cpp subfun_cppUpdateFun_aes_len.cpp subfun_cppUpdateFun_aes_state.cpp subfun_cppUpdateFun_blk_cnt.cpp subfun_cppUpdateFun_byte_cnt.cpp subfun_cppUpdateFun_dataout.cpp subfun_cppUpdateFun_enc_data.cpp subfun_cppUpdateFun_oped_byte_cnt.cpp subfun_cppUpdateFun_rd_data.cpp subfun_update.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)
EXE = aes_sim

all: $(SRCS) $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm *.o
