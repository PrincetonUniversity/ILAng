#include <stdlib.h>
#include <stdint.h>

struct HW_ITF_t {
    union STS_t {
        struct field_t {
            uint32_t rsvd : 31;
            uint32_t busy : 1;
        } field;
        uint32_t val;
    } STS;

    union DATA_t {
        uint32_t val;
    } DATA;
};

struct HW_ITF_t* mmio_HW;
struct HW_ITF_t  reg_HW;

void foo () {
    int counter = 0;
    while (mmio_HW->STS.field.busy) {
        counter++;
        if (counter >= 5) {
            mmio_HW->STS.val = 0;
        }
    }

    if (mmio_HW->DATA.val == 1)
        mmio_HW->DATA.val = 0;
    else
        mmio_HW->DATA.val = 1;

    return;
}

int main () {
    foo ();
    
    return 0;
}
