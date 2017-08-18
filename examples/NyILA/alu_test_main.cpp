#include<iostream>
#include<stdlib.h>
#include "Valu_test.h"
#include "verilated.h"
#include <verilated_vcd_c.h>
using namespace std;

namespace
{
    vluint64_t currentTime = 0;
}

double sc_time_stamp(){
    return currentTime;
}

int main(int argc, char** argv, char** env)
{
    Verilated::commandArgs(argc, argv);
    Verilated::debug(0);

    Verilated::randReset(0);

    Valu_test* testbench = new Valu_test;
    testbench->reset = 1;
    testbench->clk = 0;
    testbench->enable = 1;
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    testbench->trace(tfp, 99);
    tfp->open("trace.vcd");
    while(currentTime < 100) {
        if (currentTime > 10)
	    testbench->reset = 0;
	testbench->clk = !testbench->clk;
	testbench->eval();
	tfp->dump(currentTime);
	currentTime++;
    }
    tfp->close();
    testbench->final();
    delete testbench;
    return 0;
}
