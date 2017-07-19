// File: slv.c
// Synopsis: source file for slave firmware

#include "slv.h"

uint32_t gMbCtx[MB_SPACE_SIZE] = {0};


/* mainSlv: slave firmware main function
 * 1. receive message from master for image chunk size
 * 2. copy from master sram to local buffer
 * 3. send message to master indicating copy done
 */
void mainSlv () {
    // TODO
    return;
}

/* sendMsgSlv2Mst: send message to master
 * arg 1: (IN) command
 * arg 2: (IN) data pointer
 * arg 3: (IN) data size (DW)
 * Note: should not exceed max data size MAX_MSG_LENGTH
 */
void sendMsgSlv2Mst (uint32_t cmd, uint32_t* data, uint8_t dataSize) {
    // TODO
    return;
}

/* intHdl: interrupt handling
 * 1. get register data to local copy
 * 2. handle based on the corresponding opcode
 */
void intHdl () {
    // TODO
    return;
}

/* getMbCtx: access MB registers to get local copy
 * arg 1: (OUT) MB context pointer
 */
void getMbCtx (uint32_t* mbCtx) {
    // TODO
    return;
}

/* handleCmd: handle interrupt based on MB local copy
 * arg 1: (IN) MB context pointer
 */
void handleCmd (uint32_t* mbCtx) {
    // TODO
    return;
}


