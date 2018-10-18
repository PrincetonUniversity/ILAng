#include "hw.h"

struct HW_REG_t reg_HW;

void wr_STS (uint32_t val) {
    reg_HW.STS.val = val;
}

void wr_STS_busy (uint32_t val) {
    reg_HW.STS.field.busy = val;
}

void wr_DATA (uint32_t val) {
    reg_HW.DATA.val = val;
}

uint32_t rd_STS () {
    return reg_HW.STS.val;
}

uint32_t rd_STS_busy () {
    return reg_HW.STS.field.busy;
}

uint32_t rd_DATA () {
    return reg_HW.DATA.val;
}

