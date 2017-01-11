CC = g++
CFLAGS = -g -Wall -O0
CFLAGS = -std=c++11 -O3

SRCS = subfun_cppUpdateFun_XRAM.cpp subfun_cppUpdateFun_dataout.cpp subfun_cppUpdateFun_sha_bytes_read.cpp subfun_cppUpdateFun_sha_hs_data.cpp subfun_cppUpdateFun_sha_len.cpp subfun_cppUpdateFun_sha_rd_data.cpp subfun_cppUpdateFun_sha_rdaddr.cpp subfun_cppUpdateFun_sha_state.cpp subfun_cppUpdateFun_sha_wraddr.cpp subfun_update.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)
EXE = sha_sim

all: $(SRCS) $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm *.o
