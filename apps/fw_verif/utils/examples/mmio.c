#include <stdlib.h>
#include <stdint.h>

struct UNIT_t {
    int32_t val;
};

struct REG_t {
    struct UNIT_t CMD;
    struct UNIT_t DAT;
    struct UNIT_t CTR;
};

volatile extern struct REG_t* reg;

int main () {

    int f = 0;

    reg->DAT.val = 1;
    reg->CMD.val = 0;

    if (reg->CTR.val) f = 1;

    return 0;
}
