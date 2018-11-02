#include <stdlib.h>
#include <stdint.h>

#include "hw.h"

void foo () {
    int counter = 0;
    while (mmio_HW->STS.field.busy) {
        counter++;
        if (counter >= 5) {
            mmio_HW->STS.val = 0;
        } else {
            mmio_HW->STS.field.busy = 1;
        }
    }

    if (mmio_HW->DATA.val == 1)
        mmio_HW->DATA.val = 0;
    else
        mmio_HW->DATA.val = 1;

    return;
}

extern void HW_REG_WRITE (uint32_t);
extern uint32_t HW_REG_READ ();

int main () {
    foo ();

    uint32_t x = 0;
    x = HW_REG_READ ();
    HW_REG_WRITE (x);
    
    return 0;
}
