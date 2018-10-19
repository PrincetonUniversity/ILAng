# Makefile for the reference model
CXX_FLAGS=-std=c11 -Wall -fPIC
LD_FLAGS=-lz3

# OS dependant lib name
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	LD_FLAGS+=-lila++d
else ifeq ($(UNAME), Linux)
	LD_FLAGS+=-lila++
endif

SRC_DIR=src
OBJ_DIR=obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

$(shell mkdir -p $(OBJ_DIR))

pdpref: $(OBJ_FILES)
	   $(CC) -o $@ $^ $(LD_FLAGS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	   $(CC) $(CXX_FLAGS) -c -o $@ $<

all: pdpref

clean:
	rm -rf $(OBJ_DIR)/*
