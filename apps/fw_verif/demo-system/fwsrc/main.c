// Demo modeling multi-firmware communication
// File: main.c
// Synopsis: wrap the firmware and interrupt handler as threads

#include <pthread.h>
#include <stdlib.h>
#include "smack.h"

#include "common.h"
#include "mst.h"
#include "slv.h"

/* Global Variables 
 */

uint32_t reg_slv_int;
char mst_sram[MAX_SRAM_SIZE];

uint8_t mstCpl = 0;
uint8_t slvCpl = 0;
uint8_t intCpl = 0;

#ifdef INT_LOCK
pthread_mutex_t int_lock;
#endif // INT_LOCK

#ifdef FAB_LOCK
#ifdef MUTEX
pthread_mutex_t fab_lock;
#endif // MUTEX
#endif // FAB_LOCK

#ifdef CTX_LOCK
#ifdef MUTEX
pthread_mutex_t ctx_lock;
#endif // MUTEX
#endif // CTX_LOCK

/* Firmware entries
   master firmware, slave firmware, and slave interrupt handler
*/
void* entryMst (void* in) {
#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_lock (&ctx_lock);
#else // MUTEX
    __VERIFIER_atomic_begin ();
#endif // MUTEX
#endif // CTX_LOCK

    mainMst ();
    mstCpl = 1;

#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_unlock (&ctx_lock);
#else // MUTEX
    __VERIFIER_atomic_end ();
#endif // MUTEX
#endif // CTX_LOCK

    return in;
}

void* entrySlv (void* in) {
#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_lock (&ctx_lock);
#else // MUTEX
    __VERIFIER_atomic_begin ();
#endif // MUTEX
#endif // CTX_LOCK

    mainSlv ();
    slvCpl = 1;

#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_unlock (&ctx_lock);
#else // MUTEX
    __VERIFIER_atomic_end ();
#endif // MUTEX
#endif // CTX_LOCK

    return in;
}

void* entryHdl (void* in) {
    while (reg_slv_int == 0);
    intHdl ();
    while (reg_slv_int == 0);
    intHdl ();

    /*
    while (!mstCpl || !slvCpl) {
#ifdef INT_LOCK
        pthread_mutex_lock (&int_lock);
        intHdl ();
        pthread_mutex_unlock (&int_lock);
#else
        intHdl ();
#endif
    }
    */
    intCpl = 1;
    return in;
}

void initHW ();

/* Main function
*/

int main () {
    initHW ();

    mstCpl = slvCpl = intCpl = 0;

#ifdef INT_LOCK
    pthread_mutex_init (&int_lock, NULL);
#endif // INT_LOCK

#ifdef FAB_LOCK
#ifdef MUTEX
    pthread_mutex_init (&fab_lock, NULL);
#endif // MUTEX
#endif // FAB_LOCK

#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_init (&ctx_lock, NULL);
#endif // MUTEX
#endif // CTX_LOCK

    pthread_t tidMst, tidSlv, tidHdl;
    pthread_create (&tidHdl, NULL, entryHdl, NULL);
    pthread_create (&tidMst, NULL, entryMst, NULL);
    pthread_create (&tidSlv, NULL, entrySlv, NULL);

    //while (!mstCpl || !slvCpl || !intCpl);
    pthread_join (tidMst, NULL);
    pthread_join (tidSlv, NULL);
    pthread_join (tidHdl, NULL);

#ifdef INT_LOCK
    pthread_mutex_destroy (&int_lock);
#endif // INT_LOCK

#ifdef FAB_LOCK
#ifdef MUTEX
    pthread_mutex_destroy (&fab_lock);
#endif // MUTEX
#endif // FAB_LOCK

#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_destroy (&ctx_lock);
#endif // MUTEX
#endif // CTX_LOCK

    return 0;
}

void initHW () {
    reg_msg_mst2slv_db = 0;
    reg_msg_mst2slv_dbm = 0;
    reg_msg_slv2mst_db = 0;
    reg_msg_slv2mst_dbm = 0;

    hw_reg_MB.STS.val = 0;
    hw_reg_MB.R_CMD.val = 0;
    hw_reg_MB.S_CMD.val = 0;

    reg_slv_int = 0;
    gSlvFlag[SLV_FLAG_IMG_RDY] = 0;
    gMbCtx[MB_SPACE_OFF_S_CMD] = 0;
    gMbCtx[MB_SPACE_OFF_R_CMD] = 0;
}
