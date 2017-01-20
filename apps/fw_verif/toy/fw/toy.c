// Toy firmware code for testing FW/HW co-verification using ILA-CHC.

#include "seahorn/seahorn.h"
extern int nd();

// struct for accelerator 
struct acc_regs {
    unsigned char start;
    unsigned char state;
    unsigned char* rd_addr;
    unsigned char* wr_addr;
    int len;
    int bytes_read;
};

struct acc_regs acc_ptr;

__attribute__((optnone))
void HW_REG_WRITE (unsigned char* addr, unsigned data) {
    //*addr = data;
    acc_ptr.start = data + *addr;
}

void writecWrap (unsigned char* addr, unsigned char data) {
    // assertion on memory address check
    sassert (addr == &acc_ptr.start || addr == &acc_ptr.state);

    HW_REG_WRITE (addr, data);
    return;
}

void startAcc () {
    writecWrap (&acc_ptr.start, 1);

    sassert (acc_ptr.state == 0);
    // encode a legal fake bug.
    writecWrap (&acc_ptr.state, 1);

    while (acc_ptr.state != 0);
    return;
}

int main () {
    // assumptions on memory mapped address.
    assume (&acc_ptr == (struct acc_regs*)0xFE00);

    // initial condition.
    assume (acc_ptr.state == 0);

    // start the firmware.
    int pass = 0;
    sassert (pass == 0);

    acc_ptr.len = 3;

    startAcc();
    sassert (acc_ptr.state == 0);

    if (nd()) sassert (0);

    return 0;
}
