// File: fabric.c
// Synopsis: source file for fabric end point hardware model (MMIO registers)

#include "fabric.h"

uint32_t reg_msg_mst2slv_db;
uint32_t reg_msg_mst2slv_dat0;
uint32_t reg_msg_mst2slv_dat1;
uint32_t reg_msg_mst2slv_dbm;
uint32_t reg_msg_slv2mst_db;
uint32_t reg_msg_slv2mst_dat0;
uint32_t reg_msg_slv2mst_dat1;
uint32_t reg_msg_slv2mst_dbm;

void FAB_REG_LOCK () {
#ifdef FAB_LOCK
    pthread_mutex_lock (&fab_lock);
#endif
}

void FAB_REG_UNLOCK () {
#ifdef FAB_LOCK
    pthread_mutex_unlock (&fab_lock);
#endif
}

void HW_REG_WRITE (uint32_t addr, uint32_t val) {
#ifdef CTX_OPT
    pthread_mutex_unlock (&ctx_lock);
#endif
    FAB_REG_LOCK ();
    switch (addr) {
        case FAB_HW_BASE+FAB_HW_OFF_SLV2MST_DBM:
            write_reg_msg_slv2mst_dbm (val);
            break;
        case FAB_HW_BASE+FAB_HW_OFF_MST2SLV_DB:
            write_reg_msg_mst2slv_db (val);
            break;
        case FAB_HW_BASE+FAB_HW_OFF_MST2SLV_DAT0:
            write_reg_msg_mst2slv_dat0 (val);
            break;
        case FAB_HW_BASE+FAB_HW_OFF_MST2SLV_DAT1:
            write_reg_msg_mst2slv_dat1 (val);
            break;
        case FAB_HW_BASE+FAB_HW_OFF_MST2SLV_DBM:
            write_reg_msg_mst2slv_dbm (val);
            break;
        case FAB_HW_BASE+FAB_HW_OFF_SLV2MST_DB:
            write_reg_msg_slv2mst_db (val);
            break;
        case FAB_HW_BASE+FAB_HW_OFF_SLV2MST_DAT0:
            write_reg_msg_slv2mst_dat0 (val);
            break;
        case FAB_HW_BASE+FAB_HW_OFF_SLV2MST_DAT1:
            write_reg_msg_slv2mst_dat1 (val);
            break;
        default:
            assert (0);
            break;
    }
    FAB_REG_UNLOCK ();
#ifdef CTX_OPT
    pthread_mutex_lock (&ctx_lock);
#endif // CTX_OPT
}

uint32_t HW_REG_READ (uint32_t addr) {
#ifdef CTX_OPT
    pthread_mutex_unlock (&ctx_lock);
#endif // CTX_OPT
    FAB_REG_LOCK ();
    uint32_t res = 0;
    switch (addr) {
        case FAB_HW_BASE+FAB_HW_OFF_SLV2MST_DBM:
            res = read_reg_msg_slv2mst_dbm ();
            break;
        case FAB_HW_BASE+FAB_HW_OFF_MST2SLV_DB:
            res = read_reg_msg_mst2slv_db ();
            break;
        case FAB_HW_BASE+FAB_HW_OFF_MST2SLV_DAT0:
            res = read_reg_msg_mst2slv_dat0 ();
            break;
        case FAB_HW_BASE+FAB_HW_OFF_MST2SLV_DAT1:
            res = read_reg_msg_mst2slv_dat1 ();
            break;
        case FAB_HW_BASE+FAB_HW_OFF_MST2SLV_DBM:
            res = read_reg_msg_mst2slv_dbm ();
            break;
        case FAB_HW_BASE+FAB_HW_OFF_SLV2MST_DB:
            res = read_reg_msg_slv2mst_db ();
            break;
        case FAB_HW_BASE+FAB_HW_OFF_SLV2MST_DAT0:
            res = read_reg_msg_slv2mst_dat0 ();
            break;
        case FAB_HW_BASE+FAB_HW_OFF_SLV2MST_DAT1:
            res = read_reg_msg_slv2mst_dat1 ();
            break;
        default:
            assert (0);
            break;
    }
    FAB_REG_UNLOCK ();
#ifdef CTX_OPT
    pthread_mutex_lock (&ctx_lock);
#endif // CTX_OPT
    return res;
}

void write_reg_msg_mst2slv_db (uint32_t val) {
    if (val != 0)
        while (reg_slv_int);

    reg_msg_mst2slv_db = val;
    reg_msg_mst2slv_dbm = val;

    reg_slv_int = 1;
}

void write_reg_msg_mst2slv_dbm (uint32_t val) {
    return;
}

void write_reg_msg_mst2slv_dat0 (uint32_t val) {
    reg_msg_mst2slv_dat0 = val;
}

void write_reg_msg_mst2slv_dat1 (uint32_t val) {
    reg_msg_mst2slv_dat1 = val;
}

void write_reg_msg_slv2mst_db (uint32_t val) {
    reg_msg_slv2mst_db = val;
    reg_msg_slv2mst_dbm = val;
}

void write_reg_msg_slv2mst_dbm (uint32_t val) {
    return;
}

void write_reg_msg_slv2mst_dat0 (uint32_t val) {
    reg_msg_slv2mst_dat0 = val;
}

void write_reg_msg_slv2mst_dat1 (uint32_t val) {
    reg_msg_slv2mst_dat1 = val;
}

uint32_t read_reg_msg_mst2slv_db () {
    return reg_msg_mst2slv_db;
}

uint32_t read_reg_msg_mst2slv_dbm () {
    return reg_msg_mst2slv_dbm;
}

uint32_t read_reg_msg_mst2slv_dat0 () {
    return reg_msg_mst2slv_dat0;
}

uint32_t read_reg_msg_mst2slv_dat1 () {
    return reg_msg_mst2slv_dat1;
}

uint32_t read_reg_msg_slv2mst_db () {
    return reg_msg_slv2mst_db;
}

uint32_t read_reg_msg_slv2mst_dbm () { 
    return reg_msg_slv2mst_dbm;
}

uint32_t read_reg_msg_slv2mst_dat0 () { 
    return reg_msg_slv2mst_dat0;
}

uint32_t read_reg_msg_slv2mst_dat1 () { 
    return reg_msg_slv2mst_dat1;
}


