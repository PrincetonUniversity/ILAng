// File: mb.h
// Synopsis: header file for message buffer (MB) hardware model

/* TODO:
 * need to handle interrupt triggering 
 */

struct MB_ITF_t {
    union STS_t {
        struct field_t {
            uint32_t rsvd : 31;
            uint32_t busy : 1;
        } field;
        uint32_t val;
    } STS;

    union R_CMD_t {
        uint32_t val;
    } R_CMD;

    union R_DAT0_t {
        uint32_t val;
    } R_DAT0;

    union R_DAT1_t {
        uint32_t val;
    } R_DAT1;

    union R_SIZE_t {
        uint32_t val;
    } R_SIZE;

    union S_CMD_t {
        uint32_t val;
    } S_CMD;

    union S_DAT0_t {
        uint32_t val;
    } S_DAT0;

    union S_DAT1_t {
        uint32_t val;
    } S_DAT1;

    union S_SIZE_t {
        uint32_t val;
    } S_SIZE;
};

volatile extern struct MB_ITF_t* reg_MB;
