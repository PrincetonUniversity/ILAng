// main function for c++ api tutorial
#include <fstream>
#include "ila++.h"
#include "z3++.h"

using namespace ila;

#include "ila_fifo.h"
#include "util.h"


void parseArg(int argc, char ** argv, int & bnd) {
	if (argc != 2) {
		std::cout << "   BMC for two FIFO designs (w./w.o. overflow & underflow protection)." << std::endl;
		std::cout << "   Checking if overflow/underflow is possible.                        " << std::endl;
		std::cout << "   Usage:  " << argv[0] << " bound (a positive integer)"  << std::endl; 
		exit(1);
	}
	try {
		bnd = std::stoi(argv[1]);
	} catch (...) {
		std::cerr << "The bound has to be a positive number. " << std::endl;
		exit(1);
	}
	if (bnd <= 0) {
		std::cerr << "The bound has to be a positive number. " << std::endl;
		exit(1);		
	}
}


int main(int argc, char **argv) {

  int bnd;
  parseArg(argc,argv,bnd);

  try {

    auto fifo1 = fifo_no_protect("FIFO (w.o protection)");
    std::cout << "ILA Constructed for "<< fifo1.name() << std::endl;
    auto fifo2 = fifo_w_protect ("FIFO (w. protection)");
    std::cout << "ILA Constructed for "<< fifo2.name() << std::endl;

    std::cout << "BMC bound:" << bnd << std::endl;

    std::cout << "Checking:"<< fifo1.name() << std::endl;
    if( CheckOverUnderFlow(fifo1, bnd + 1) )
    	std::cout <<  fifo1.name() << " will not under/overflow" << std::endl;

    
    std::cout << "Checking:"<< fifo2.name() << std::endl;
    if ( CheckOverUnderFlow(fifo2, bnd + 1) )
    	std::cout <<  fifo2.name() << " will not under/overflow" << std::endl;

  } catch (...) {
    std::cout << "unexpected error.\n";
  }
  std::cout << "Check completed!\n";
  return 0;
}

