
#ifndef __HW_H__
#define __HW_H__

#include "stdlib.h"
#include "stdint.h"

struct HW_ITF_t {
    struct STS {
        uint32_t val;
        struct field {
            uint32_t rsvd;
            uint32_t busy;
            uint32_t dum;
        } field;
    } STS;

    struct DATA {
        uint32_t val;
    } DATA;
};

struct HW_REG_t {
    union STS_t {
        uint32_t val;
        struct field_t {
            uint32_t rsvd : 30;
            uint32_t busy : 1;
            uint32_t dum : 1;
        } field;
    } STS;

    union DATA_t {
        uint32_t val;
    } DATA;
};


extern void wr_STS (uint32_t val);
extern void wr_STS_busy (uint32_t val);
extern void wr_DATA (uint32_t val);
extern uint32_t rd_STS ();
extern uint32_t rd_STS_busy ();
extern uint32_t rd_DATA ();

extern struct HW_REG_t reg_HW;
extern struct HW_ITF_t* mmio_HW;

#endif
