
export ROOT_PATH  = $(shell pwd)
export ILA_LIB    = $(ROOT_PATH)/../../build/lib
export ILA_HEADER = $(ROOT_PATH)/../../include

CXX=g++
CXX_FLAGS=-std=c++11 -Wall -fPIC
CXX_FLAGS+=-I$(ILA_HEADER)
LD_FLAGS=-L$(ILA_LIB) -lutild -lilad -lilatoolsd

SRC_DIR=src
OBJ_DIR=obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cc)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SRC_FILES))

$(shell mkdir -p $(OBJ_DIR))

main: $(OBJ_FILES)
	   @$(CXX) -o $@ $^ $(LD_FLAGS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	   @$(CXX) $(CXX_FLAGS) -c -o $@ $<

all: main.exe

clean:
	rm -rf $(OBJ_DIR)/*
