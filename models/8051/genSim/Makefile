CC = g++
CFLAGS = -std=c++11 -O3 -g -Wall
CFLAGS = -std=c++11 -O0 -g -Wall

SRCS = sim_8051.cpp main.cpp
SRCS = sim_8051_decode.cpp sim_8051_ACC.cpp sim_8051_B.cpp sim_8051_update.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)
EXE = oc8051_sim

all: $(SRCS) $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm *.o $(IDIR)/*.o
