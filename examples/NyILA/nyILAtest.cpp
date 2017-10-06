#include<iostream>
#include<stdlib.h>
#include "Vtest.h"
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

    Vtest* testbench = new Vtest;
    testbench->rst = 1;
    testbench->clk = 0;
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    testbench->trace(tfp, 99);
    tfp->open("trace.vcd");
    while(currentTime < 100) {
        if (currentTime > 10)
	    testbench->rst = 0;
	testbench->clk = !testbench->clk;
	testbench->step = 1;
	if (currentTime < 50)
		testbench->imem_rdata_ila = 0x05003c21;
	else
		testbench->imem_rdata_ila = 0x06007821;
	testbench->eval();
	tfp->dump(currentTime);
	currentTime++;
    }
    tfp->close();
    testbench->final();
    delete testbench;
    return 0;
}
