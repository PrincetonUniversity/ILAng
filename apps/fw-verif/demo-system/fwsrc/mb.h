// File: mb.h
// Synopsis: header file for message buffer (MB) hardware model

#ifndef __MB_H__
#define __MB_H__

#include "common.h"
#include "fabric.h"

struct MB_REG_t {
    union STS_t {
        uint32_t val;
        struct field_t {
            uint32_t rsvd : 31;
            uint32_t busy : 1;
        } field;
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

    union ACK_t {
        uint32_t val;
    } ACK;
};

struct MB_ITF_t {
    struct STS {
        uint32_t val;
        struct field {
            uint32_t rsvd;
            uint32_t busy;
        } field;
    } STS;

    struct R_CMD {
        uint32_t val;
    } R_CMD;

    struct R_DAT0 {
        uint32_t val;
    } R_DAT0;

    struct R_DAT1 {
        uint32_t val;
    } R_DAT1;

    struct R_SIZE {
        uint32_t val;
    } R_SIZE;

    struct S_CMD {
        uint32_t val;
    } S_CMD;

    struct S_DAT0 {
        uint32_t val;
    } S_DAT0;

    struct S_DAT1 {
        uint32_t val;
    } S_DAT1;

    struct S_SIZE {
        uint32_t val;
    } S_SIZE;

    struct ACK {
        uint32_t val;
    } ACK;
};

extern struct MB_ITF_t* reg_MB;
extern struct MB_REG_t hw_reg_MB;

/* HW model (read/write centric)
 */
void write_reg_MB_STS (uint32_t val);
void write_reg_MB_R_CMD (uint32_t val);
void write_reg_MB_R_DAT0 (uint32_t val);
void write_reg_MB_R_DAT1 (uint32_t val);
void write_reg_MB_R_SIZE (uint32_t val);
void write_reg_MB_S_CMD (uint32_t val);
void write_reg_MB_S_DAT0 (uint32_t val);
void write_reg_MB_S_DAT1 (uint32_t val);
void write_reg_MB_S_SIZE (uint32_t val);
void write_reg_MB_ACK (uint32_t val);
void write_reg_MB_STS_busy (uint32_t val);
uint32_t read_reg_MB_STS ();
uint32_t read_reg_MB_R_CMD ();
uint32_t read_reg_MB_R_DAT0 ();
uint32_t read_reg_MB_R_DAT1 ();
uint32_t read_reg_MB_R_SIZE ();
uint32_t read_reg_MB_S_CMD ();
uint32_t read_reg_MB_S_DAT0 ();
uint32_t read_reg_MB_S_DAT1 ();
uint32_t read_reg_MB_S_SIZE ();
uint32_t read_reg_MB_ACK ();
uint32_t read_reg_MB_STS_busy ();

#endif // __MB_H__
