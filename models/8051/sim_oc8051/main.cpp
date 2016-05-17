#include "model_oc8051_class.hpp"
#include "common.hpp"

#include <boost/algorithm/string.hpp>
#include <iostream>
#include <time.h>

void dump(model_oc8051& mod, std::ostream& out) {
    boost::format fmt1("PC/ACC/P0/P1/P2/P3:         %1% %2% %3% %4% %5% %6%\n");
    boost::format fmt2("B/DPH/DPL/IE/IP:            %1% %2% %3% %4% %5%\n");
    boost::format fmt3("PCON/PSW/SBUF/SCON/SP/TCON: %1% %2% %3% %4% %5% %6%\n");
    boost::format fmt4("TH0/TH1/TL0/TL1/TMOD:       %1% %2% %3% %4% %5%\n");
    boost::format fmt5("XRAM_ADDR/XRAM_DATA_IN/XRAM_DATA_OUT: %1% %2% %3%\n");
    
    fmt1 % mod.PC % mod.ACC % mod.P0 % mod.P1 % mod.P2 % mod.P3;
    fmt2 % mod.B % mod.DPH % mod.DPL % mod.IE % mod.IP;
    fmt3 % mod.PCON % mod.PSW %mod.SBUF % mod.SCON % mod.SP % mod.TCON;
    fmt4 % mod.TH0 % mod.TH1 % mod.TL0 % mod.TL1 % mod.TMOD;
    fmt5 % mod.XRAM_ADDR % mod.XRAM_DATA_IN % mod.XRAM_DATA_OUT;

    out << "-----------------------------------------------------------------\n";
    out << fmt1.str();
    out << fmt2.str();
    out << fmt3.str();
    out << fmt4.str();
    out << fmt5.str();
}

int main(int argc, char* argv[])
{
    model_oc8051 model;

    // Initialize rom
    type_mem& mem = model.ROM;
    #include "fib.cpp"
//    #include "aes_test.cpp"
//    #include "instr.cpp"

    // Initialize states
    model.ACC = 0;
    model.B = 0;
    model.DPH = 0;
    model.IE = 0;
    model.IP = 0;
    model.P0 = 0;
    model.P1 = 0;
    model.P2 = 0;
    model.P3 = 0;
    model.PC = 0;
    model.PCON = 0;
    model.PSW = 0;
    model.SBUF = 0;
    model.SCON = 0;
    model.SP = 0;
    model.TCON = 0;
    model.TH0 = 0;
    model.TL0 = 0;
    model.TH1 = 0;
    model.TL1 = 0;
    model.TMOD = 0;
    model.XRAM_ADDR = 0;
    model.XRAM_DATA_IN = 0;
    model.XRAM_DATA_OUT = 0;

    BIT_VEC prevP0 = model.P0;

    clock_t t;
    t = clock();

    for (int i = 0; i < 10; i++) {
        model.update();
    }

    t = clock() - t;

    std::cout << "Time: " << t/CLOCKS_PER_SEC << std::endl;
    // Start runing
    /*
    bool startPrint = false;
    for (int i=0; i<2000; i++) {
        if (model.P0 != 0) {
            if (model.P0 != prevP0) {
                dump(model, std::cout);
                std::cout << "Step: " << i << std::endl;
                prevP0 = model.P0;
            }
            if (startPrint == false) startPrint = true;
        } 
        model.update();
    }
    */
    return 0;
}
