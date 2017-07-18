// Demo modeling multi-firmware communication

#include <pthread.h>
#include <stdlib.h>
#include "smack.h"

#include "common.h"

/* Global Variables 
   master/slave interface (HW regs)
   -- master:
        reg_msg_slv2mst_ctr
        reg_msg_slv2mst_dat
        reg_msg_mst2slv_mir
   -- slave:
        reg_msg_mst2slv_ctr
        reg_msg_mst2slv_dat
        reg_msg_slv2mst_mir
        reg_slv_int
*/
uint32_t reg_msg_mst2slv_ctr;
uint32_t reg_msg_mst2slv_dat;
uint32_t reg_msg_mst2slv_mir;
uint32_t reg_msg_slv2mst_ctr;
uint32_t reg_msg_slv2mst_dat;
uint32_t reg_msg_slv2mst_mir;
uint32_t reg_slv_int;

bool mstCpl = false;
bool slvCpl = false;
#ifdef INT_LOCK
pthread_mutex_t int_lock;
#endif

/* Firmware entries
   master firmware, slave firmware, and slave interrupt handler
*/
void* entryMst (void* in) {
    mainMst ();
    mstCpl = true;
    return in;
}

void* entrySlv (void* in) {
    mainSlv ();
    slvCpl = true;
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
    mstCpl = slvCpl = false;

#ifdef INT_LOCK
    pthread_mutex_init (&int_lock);
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
