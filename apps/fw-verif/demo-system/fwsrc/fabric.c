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

void HW_REG_WRITE (uint32_t addr, uint32_t val) {
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
}

uint32_t HW_REG_READ (uint32_t addr) {
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
    return res;
}

void write_reg_msg_mst2slv_db (uint32_t val) {
#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_unlock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_end ();
#endif // MUtEX
#endif // CTX_LOCK

    if (val != 0)
        while (reg_slv_int);
#ifdef FAB_LOCK
    __VERIFIER_atomic_begin ();
#endif // FAB_LOCK

    if (val != 0)
        assert (reg_slv_int == 0);

    reg_msg_mst2slv_db = val;
    reg_msg_mst2slv_dbm = val;

    reg_slv_int = 1;
#ifdef FAB_LOCK
    __VERIFIER_atomic_end ();
#endif // FAB_LOCK

#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_lock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_begin ();
#endif // MUtEX
#endif // CTX_LOCK
}

void write_reg_msg_mst2slv_dbm (uint32_t val) {
#ifndef POR_OPT
#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_unlock (&ctx_lock);
    pthread_mutex_lock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_end ();
    __VERIFIER_atomic_begin ();
#endif // MUtEX
#endif // CTX_LOCK
#endif // POR_OPT
    return;
}

void write_reg_msg_mst2slv_dat0 (uint32_t val) {
#ifndef POR_OPT
#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_unlock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_end ();
#endif // MUtEX
#endif // CTX_LOCK

#ifdef FAB_LOCK
    __VERIFIER_atomic_begin ();
#endif // FAB_LOCK
#endif // POR_OPT

    reg_msg_mst2slv_dat0 = val;

#ifndef POR_OPT
#ifdef FAB_LOCK
    __VERIFIER_atomic_end ();
#endif // FAB_LOCK

#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_lock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_begin ();
#endif // MUtEX
#endif // CTX_LOCK
#endif // POR_OPT
}

void write_reg_msg_mst2slv_dat1 (uint32_t val) {
#ifndef POR_OPT
#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_unlock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_end ();
#endif // MUtEX
#endif // CTX_LOCK

#ifdef FAB_LOCK
    __VERIFIER_atomic_begin ();
#endif // FAB_LOCK
#endif // POR_OPT

    reg_msg_mst2slv_dat1 = val;

#ifndef POR_OPT
#ifdef FAB_LOCK
    __VERIFIER_atomic_end ();
#endif // FAB_LOCK

#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_lock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_begin ();
#endif // MUtEX
#endif // CTX_LOCK
#endif // POR_OPT
}

void write_reg_msg_slv2mst_db (uint32_t val) {
#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_unlock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_end ();
#endif // MUtEX
#endif // CTX_LOCK

#ifdef FAB_LOCK
    __VERIFIER_atomic_begin ();
#endif // FAB_LOCK

    reg_msg_slv2mst_db = val;
    reg_msg_slv2mst_dbm = val;

#ifdef FAB_LOCK
    __VERIFIER_atomic_end ();
#endif // FAB_LOCK

#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_lock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_begin ();
#endif // MUtEX
#endif // CTX_LOCK
}

void write_reg_msg_slv2mst_dbm (uint32_t val) {
#ifndef POR_OPT
#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_unlock (&ctx_lock);
    pthread_mutex_lock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_end ();
    __VERIFIER_atomic_begin ();
#endif // MUtEX
#endif // CTX_LOCK
#endif // POR_OPT
    return;
}

void write_reg_msg_slv2mst_dat0 (uint32_t val) {
#ifndef POR_OPT
#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_unlock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_end ();
#endif // MUtEX
#endif // CTX_LOCK

#ifdef FAB_LOCK
    __VERIFIER_atomic_begin ();
#endif // FAB_LOCK
#endif // POR_OPT

    reg_msg_slv2mst_dat0 = val;

#ifndef POR_OPT
#ifdef FAB_LOCK
    __VERIFIER_atomic_end ();
#endif // FAB_LOCK

#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_lock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_begin ();
#endif // MUtEX
#endif // CTX_LOCK
#endif // POR_OPT
}

void write_reg_msg_slv2mst_dat1 (uint32_t val) {
#ifndef POR_OPT
#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_unlock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_end ();
#endif // MUtEX
#endif // CTX_LOCK

#ifdef FAB_LOCK
    __VERIFIER_atomic_begin ();
#endif // FAB_LOCK
#endif // POR_OPT

    reg_msg_slv2mst_dat1 = val;

#ifndef POR_OPT
#ifdef FAB_LOCK
    __VERIFIER_atomic_end ();
#endif // FAB_LOCK

#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_lock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_begin ();
#endif // MUtEX
#endif // CTX_LOCK
#endif // POR_OPT
}

uint32_t read_reg_msg_mst2slv_db () {
#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_unlock (&ctx_lock);
    pthread_mutex_lock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_end ();
    __VERIFIER_atomic_begin ();
#endif // MUtEX
#endif // CTX_LOCK
    return reg_msg_mst2slv_db;
}

uint32_t read_reg_msg_mst2slv_dbm () {
#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_unlock (&ctx_lock);
    pthread_mutex_lock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_end ();
    __VERIFIER_atomic_begin ();
#endif // MUtEX
#endif // CTX_LOCK
    return reg_msg_mst2slv_dbm;
}

uint32_t read_reg_msg_mst2slv_dat0 () {
#ifndef POR_OPT
#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_unlock (&ctx_lock);
    pthread_mutex_lock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_end ();
    __VERIFIER_atomic_begin ();
#endif // MUtEX
#endif // CTX_LOCK
#endif // POR_OPT
    return reg_msg_mst2slv_dat0;
}

uint32_t read_reg_msg_mst2slv_dat1 () {
#ifndef POR_OPT
#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_unlock (&ctx_lock);
    pthread_mutex_lock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_end ();
    __VERIFIER_atomic_begin ();
#endif // MUtEX
#endif // CTX_LOCK
#endif // POR_OPT
    return reg_msg_mst2slv_dat1;
}

uint32_t read_reg_msg_slv2mst_db () {
#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_unlock (&ctx_lock);
    pthread_mutex_lock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_end ();
    __VERIFIER_atomic_begin ();
#endif // MUtEX
#endif // CTX_LOCK
    return reg_msg_slv2mst_db;
}

uint32_t read_reg_msg_slv2mst_dbm () { 
#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_unlock (&ctx_lock);
    pthread_mutex_lock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_end ();
    __VERIFIER_atomic_begin ();
#endif // MUtEX
#endif // CTX_LOCK
    return reg_msg_slv2mst_dbm;
}

uint32_t read_reg_msg_slv2mst_dat0 () { 
#ifndef POR_OPT
#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_unlock (&ctx_lock);
    pthread_mutex_lock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_end ();
    __VERIFIER_atomic_begin ();
#endif // MUtEX
#endif // CTX_LOCK
#endif // POR_OPT
    return reg_msg_slv2mst_dat0;
}

uint32_t read_reg_msg_slv2mst_dat1 () { 
#ifndef POR_OPT
#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_unlock (&ctx_lock);
    pthread_mutex_lock (&ctx_lock);
#else //MUTEX
    __VERIFIER_atomic_end ();
    __VERIFIER_atomic_begin ();
#endif // MUtEX
#endif // CTX_LOCK
#endif // POR_OPT
    return reg_msg_slv2mst_dat1;
}


