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
 * HW regs:
 * - master:
 *      reg_msg_slv2mst_ctr
 *      reg_msg_slv2mst_dat
 *      reg_msg_mst2slv_mir
 *      mst_sram
 * - slave:
 *      reg_msg_mst2slv_ctr
 *      reg_msg_mst2slv_dat
 *      reg_msg_slv2mst_mir
 *      reg_slv_int
 */

uint32_t reg_msg_mst2slv_db;
uint32_t reg_msg_mst2slv_dat0;
uint32_t reg_msg_mst2slv_dat1;
uint32_t reg_msg_mst2slv_dbm;
uint32_t reg_msg_slv2mst_db;
uint32_t reg_msg_slv2mst_dat0;
uint32_t reg_msg_slv2mst_dat1;
uint32_t reg_msg_slv2mst_dbm;
uint32_t reg_slv_int;
char mst_sram[MAX_SRAM_SIZE];

uint8_t mstCpl = 0;
uint8_t slvCpl = 0;
#ifdef INT_LOCK
pthread_mutex_t int_lock;
#endif

/* Firmware entries
   master firmware, slave firmware, and slave interrupt handler
*/
void* entryMst (void* in) {
    mainMst ();
    mstCpl = 1;
    return in;
}

void* entrySlv (void* in) {
    mainSlv ();
    slvCpl = 1;
    return in;
}

void* entryHdl (void* in) {
    while (!mstCpl || !slvCpl) {
#ifdef INT_LOCK
        pthread_mutex_lock (&int_lock);
        intHdl ();
        pthread_mutex_unlock (&int_lock);
#else
        intHdl ();
#endif
    }
    return in;
}

/* Main function
*/

int main () {
    mstCpl = slvCpl = 0;

#ifdef INT_LOCK
    pthread_mutex_init (&int_lock, NULL);
#endif

    pthread_t tidMst, tidSlv, tidHdl;
    pthread_create (&tidMst, NULL, entryMst, NULL);
    pthread_create (&tidSlv, NULL, entrySlv, NULL);
    pthread_create (&tidHdl, NULL, entryHdl, NULL);

#ifdef MEM_CHECK
    while (!mstCpl || !slvCpl);
#else
    pthread_join (tidMst, NULL);
    pthread_join (tidSlv, NULL);
    pthread_join (tidHdl, NULL);
#endif

#ifdef INT_LOCK
    pthread_mutex_destroy (&int_lock);
#endif

    return 0;
}
