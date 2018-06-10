
export ROOT_PATH  = $(shell pwd)
export ILA_LIB    = $(ROOT_PATH)/../../build/lib
export ILA_HEADER = $(ROOT_PATH)/../../include

CXX=clang++
CXX_FLAGS=-std=c++11 -Wall -fPIC
CXX_FLAGS+=-I$(ILA_HEADER)
LD_FLAGS=-L$(ILA_LIB) -lila++

HDR_DIR=include
SRC_DIR=src
OBJ_DIR=obj

HDR_FILES := $(wildcard $(HDR_DIR)/*.hpp)
SRC_FILES := $(wildcard $(SRC_DIR)/*.cc)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SRC_FILES))

main: $(OBJ_FILES)
	   $(CXX) $(LD_FLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc $(OBJ_DIR) $(HDR_FILES)
	   $(CXX) $(CXX_FLAGS) -I$(ROOT_PATH)/$(HDR_DIR) -c -o $@ $<

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

all: main.exe

clean:
	rm -rf $(OBJ_DIR)/*
