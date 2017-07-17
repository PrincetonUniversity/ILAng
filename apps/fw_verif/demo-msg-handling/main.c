// Demo modeling multi-firmware communication

#include <pthread.h>
#include <stdlib.h>
#include "smack.h"

#include "fwA.h"
#include "fwB.h"
#include "fwC.h"

// global variables
int32_t msg_reg_A_CTR;  // ctrl reg for sending msg from A
int32_t msg_reg_A_DATA; // data reg for sending msg from A
int32_t msg_reg_A_CTRM; // mirrored ctrl reg for sending msg from A

int32_t msg_reg_B_CTR;  // ctrl reg for sending msg from B
int32_t msg_reg_B_DATA; // data reg for sending msg from B
int32_t msg_reg_B_CTRM; // mirrored ctrl reg for sending msg from B

int32_t msg_reg_C_CTR;  // ctrl reg for sending msg from C
int32_t msg_reg_C_DATA; // data reg for sending msg from C
int32_t msg_reg_C_CTRM; // mirrored ctrl reg for sending msg from C

// firmware entries
void* entryA (void* input) {
    main_A ();
}

void* entryB (void* input) {
    main_B ();
}

void* entryC (void* input) {
    main_C ();
}

int main () {
    pthread_t tidA, tidB, tidC;

    pthread_create (&tidA, NULL, entryA, NULL);
    pthread_create (&tidA, NULL, entryB, NULL);
#ifdef OVRD
    pthread_create (&tidC, NULL, entryC, NULL);
#endif

    pthread_join (tidA, NULL);
    pthread_join (tidB, NULL);
#ifdef OVRD
    pthread_join (tidC, NULL);
#endif

    return 0;
}
