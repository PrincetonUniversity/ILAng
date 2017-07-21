// File: mb.c
// Synopsis: source file for message buffer (MB) hardware model

#include "mb.h"

struct MB_REG_t hw_reg_MB;

void write_reg_MB_STS (uint32_t val) {
    return;
}

void write_reg_MB_R_CMD (uint32_t val) {
    return;
}

void write_reg_MB_R_DAT0 (uint32_t val) {
    return;
}

void write_reg_MB_R_DAT1 (uint32_t val) {
    return;
}

void write_reg_MB_R_SIZE (uint32_t val) {
    return;
}

void write_reg_MB_S_CMD (uint32_t val) {
    hw_reg_MB.STS.field.busy = 1;

    hw_reg_MB.S_CMD.val = val;

    while (read_reg_msg_slv2mst_dbm ());
    write_reg_msg_slv2mst_dat0 (hw_reg_MB.S_DAT0.val);
    write_reg_msg_slv2mst_dat1 (hw_reg_MB.S_DAT1.val);
    uint32_t db = (hw_reg_MB.S_CMD.val << 9) | (hw_reg_MB.S_SIZE.val << 1) | 1;
    write_reg_msg_slv2mst_db (db);

    hw_reg_MB.STS.field.busy = 0;
}

void write_reg_MB_S_DAT0 (uint32_t val) {
    hw_reg_MB.S_DAT0.val = val;
}

void write_reg_MB_S_DAT1 (uint32_t val) {
    hw_reg_MB.S_DAT1.val = val;
}

void write_reg_MB_S_SIZE (uint32_t val) {
    hw_reg_MB.S_SIZE.val = val;
}

void write_reg_MB_ACK (uint32_t val) {
    uint32_t db = read_reg_msg_mst2slv_db ();

    hw_reg_MB.R_CMD.val = db >> 9;
    hw_reg_MB.R_SIZE.val = (db >> 1) & 0xff;
    hw_reg_MB.R_DAT0.val = read_reg_msg_mst2slv_dat0 ();
    hw_reg_MB.R_DAT1.val = read_reg_msg_mst2slv_dat1 ();

    write_reg_msg_mst2slv_db (0);
}

void write_reg_MB_STS_busy (uint32_t val) {
    return;
}

uint32_t read_reg_MB_STS () {
    return hw_reg_MB.STS.val;
}

uint32_t read_reg_MB_R_CMD () {
    return hw_reg_MB.R_CMD.val;
}

uint32_t read_reg_MB_R_DAT0 () {
    return hw_reg_MB.R_DAT0.val;
}

uint32_t read_reg_MB_R_DAT1 () {
    return hw_reg_MB.R_DAT1.val;
}

uint32_t read_reg_MB_R_SIZE () {
    return hw_reg_MB.R_SIZE.val;
}

uint32_t read_reg_MB_S_CMD () {
    return hw_reg_MB.S_CMD.val;
}

uint32_t read_reg_MB_S_DAT0 () {
    return hw_reg_MB.S_DAT0.val;
}

uint32_t read_reg_MB_S_DAT1 () {
    return hw_reg_MB.S_DAT1.val;
}

uint32_t read_reg_MB_S_SIZE () {
    return hw_reg_MB.S_SIZE.val;
}

uint32_t read_reg_MB_ACK () {
    return 0;
}

uint32_t read_reg_MB_STS_busy () {
    return hw_reg_MB.STS.field.busy;
}
