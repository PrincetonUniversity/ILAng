//-----------------------------------------------------------------------------
//
// Pramod Subramanyan
// 
//
// Based on 8051sim written by: Roman Lysecky, Tony Givargis, Greg Stitt, Ann
// Gordon-Ross, and Kris Miller 
//
//-----------------------------------------------------------------------------
//
// 8051 Instruction Set Simulator usable for Synthesis
// Version 1.4
//
//-----------------------------------------------------------------------------

#include <iostream>
#include <stdlib.h>
#include "i8051.h"


static I8051 i8051;

int main(int argc, char* argv[])
{
    if(argc != 2) {
        std::cerr << "Syntax error. " << std::endl
                  << "  Usage: " << argv[0] << " [input-state-file]" << std::endl;
    } else {
        i8051.SynSim(argv[1]);
    }
    return 0;
}
