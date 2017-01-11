IDIR = verilatorInclude
CC = g++
CFLAGS = -I $(IDIR) -g -Wall -O3

SRCS = simulateAES.cpp VsimXramAes_top.cpp VsimXramAes_top_S.cpp VsimXramAes_top__Syms.cpp $(IDIR)/verilated.cpp

OBJS = $(SRCS:.cpp=.o)
EXE = AESsim

all: $(SRCS) $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm *.o $(IDIR)/*.o
