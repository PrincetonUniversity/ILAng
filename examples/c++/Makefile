# Makefile for c++ examples
CXX_FLAGS=-std=c++11 -Wall -fPIC
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
SRC_FILES := $(wildcard $(SRC_DIR)/*.cc)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SRC_FILES))

$(shell mkdir -p $(OBJ_DIR))

cpp_example: $(OBJ_FILES)
	   $(CXX) -o $@ $^ $(LD_FLAGS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	   $(CXX) $(CXX_FLAGS) -c -o $@ $<

all: cpp_example

clean:
	rm -rf $(OBJ_DIR)/*
