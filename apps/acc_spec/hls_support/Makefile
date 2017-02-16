#### HLS flags
include ../hls_support/Makefile.inc

all: test

run: run.cpp syn_target.cpp Stencil.h Linebuffer.h
	$(CXX) -std=c++11 $(HLS_CXXFLAGS) run.cpp syn_target.cpp -Wall -Wno-unused-label -Wno-unknown-pragmas  -o $@

test: run
	./run

clean:
	rm -f test_linebuffer
