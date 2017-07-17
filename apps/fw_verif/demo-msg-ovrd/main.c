// Demo modeling multi-firmware communication

#include "common.h"
#include "fwA.h"
#include "fwB.h"

#ifdef OVRD
#include "fwC.h"
#endif

/* Global Variables
   To keep it simple, IPs send msg by directly writing dst regs.
   CTR  -- ctrl reg which will be asserted when there is a msg, and vice versa.
   DATA -- data reg of the msg, valid when CTR is 1.
   lock -- HW reg protection.
*/
int32_t msg_reg_A_CTR;
int32_t msg_reg_A_DATA;
int32_t msg_reg_B_CTR;
int32_t msg_reg_B_DATA;
//int32_t* buffer_A;
//int32_t* buffer_B;
int32_t buffer_A[32];
int32_t buffer_B[32];

/* Firmware Entries
   Wrapper functions to pass firmware into threads.
*/
void* entryA (void* input) {
    mainA ();
    return input;
}

void* entryB (void* input) {
    mainB ();
    return input;
}
#ifdef OVRD
void* entryC (void* input) {
    mainC ();
}
#endif

int main () {
    msg_reg_A_CTR = 0;
    msg_reg_B_CTR = 0;
    //buffer_A = (int32_t*) malloc (32);
    //buffer_B = (int32_t*) malloc (32);

    pthread_t tid_A, tid_B, tid_C;

    pthread_create (&tid_A, NULL, entryA, NULL);
    pthread_create (&tid_B, NULL, entryB, NULL);

    pthread_join (tid_A, NULL);
    pthread_join (tid_B, NULL);

    //free (buffer_A);
    //free (buffer_B);

    return 0;
}
