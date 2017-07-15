// Demo modeling multi-firmware communication

#include <pthread.h>
#include <stdlib.h>
#include "smack.h"

#include "fwA.h"
#include "fwB.h"

// global variables
int32_t msg_reg_A2B_CTR;
int32_t msg_reg_A2B_DATA;
int32_t msg_reg_A2B_CTRM;

int32_t msg_reg_B2A_CTR;
int32_t msg_reg_B2A_DATA;
int32_t msg_reg_B2A_CTRM;

// two firmware entries
void* entryA (void* input) {
}

void* entryB (void* input) {
}

int main () {

    return 0;
}
