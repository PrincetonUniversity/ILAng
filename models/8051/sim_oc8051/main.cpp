#include "model_oc8051_class.hpp"
#include "common.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    model_oc8051 model;

    // Initialize rom
    type_mem& mem = model.ROM;
//    #include "fib.cpp"
    #include "aes_test.cpp"

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

    // Start runing
    for (int i=0; i<10; i++) {
        std::cout << "Step: " << i << std::endl;
        model.update();
    }

    return 0;
}
