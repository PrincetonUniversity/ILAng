// File: slv.c
// Synopsis: source file for slave firmware

#include "slv.h"

uint32_t gSlvFlag[SLV_FLAG_SIZE] = {0};
uint32_t gMbCtx[MB_SPACE_SIZE]   = {0};

/* mainSlv: slave firmware main function
 * 1. wait for image ready flag and image size
 * 2. copy from master sram to local buffer
 * 3. send message to master indicating copy done
 */
void mainSlv () {
    // 1. wait for image ready flag and image size
    while (!gSlvFlag[SLV_FLAG_IMG_RDY]);
    
#ifdef INT_LOCK
    pthread_mutex_lock (&int_lock);
#endif // INT_LOCK

    // 2. copy from master sram to local buffer
#ifdef MEM_OP
    char* slvBuff = (char*) malloc (gSlvFlag[SLV_FLAG_IMG_SIZE]);
    memcpy (slvBuff, mst_sram, gSlvFlag[SLV_FLAG_IMG_SIZE]);
#endif // MEM_OP
    
    //assert (gSlvFlag[SLV_FLAG_IMG_SIZE] <= MAX_SRAM_SIZE);

    // 3. send message to master indicating copy done
    gMbCtx[MB_SPACE_OFF_S_CMD] = CMD_IMAGE_DONE;
    gMbCtx[MB_SPACE_OFF_S_SIZE] = 0;
    sendMsgSlv2Mst ();
#ifdef MEM_OP
    free (slvBuff);
#endif // MEM_OP

#ifdef INT_LOCK
    pthread_mutex_unlock (&int_lock);
#endif // INT_LOCK

    return;
}

/* sendMsgSlv2Mst: send message to master
 * arg 1: (IN) command
 * arg 2: (IN) data pointer
 * arg 3: (IN) data size (DW)
 * Note: should not exceed max data size MAX_DATA_LENGTH
 */
void sendMsgSlv2Mst () {
    while (reg_MB->STS.field.busy);

    reg_MB->S_DAT0.val = gMbCtx[MB_SPACE_OFF_S_DAT0];
    reg_MB->S_DAT1.val = gMbCtx[MB_SPACE_OFF_S_DAT1];
    reg_MB->S_SIZE.val = gMbCtx[MB_SPACE_OFF_S_SIZE];
    reg_MB->S_CMD.val  = gMbCtx[MB_SPACE_OFF_S_CMD];

    return;
}

/* intHdl: interrupt handling
 * 1. get register data to local copy
 * 2. handle based on the corresponding opcode
 */
void intHdl () {
    // Only when interrupted
    if (reg_slv_int == 0) return;

#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_lock (&ctx_lock);
#else // MUTEX
    __VERIFIER_atomic_begin ();
#endif // MUTEX
#endif // CTX_LOCK

    // 1. get register data to local copy
    getMbCtx ();

    // 2. handle based on the corresponding opcode
    handleCmd ();

    // reset interrupt signal (enable)
    reg_slv_int = 0;

#ifdef CTX_LOCK
#ifdef MUTEX
    pthread_mutex_unlock (&ctx_lock);
#else // MUTEX
    __VERIFIER_atomic_end ();
#endif // MUTEX
#endif // CTX_LOCK

    return;
}

/* getMbCtx: access MB registers to get local copy to gMbCtx
 */
void getMbCtx () {
    // ack message and trigger MB to get data
    reg_MB->ACK.val = 1;

    // copy MB received message to local copy
    gMbCtx[MB_SPACE_OFF_R_CMD]  = reg_MB->R_CMD.val;
    gMbCtx[MB_SPACE_OFF_R_DAT0] = reg_MB->R_DAT0.val;
    gMbCtx[MB_SPACE_OFF_R_DAT1] = reg_MB->R_DAT1.val;
    gMbCtx[MB_SPACE_OFF_R_SIZE] = reg_MB->R_SIZE.val;
    
    return;
}

/* handleCmd: handle interrupt based on MB local copy
 */
void handleCmd () {
    switch (gMbCtx[MB_SPACE_OFF_R_CMD]) {
        case CMD_STATUS_REQUEST: 
            gMbCtx[MB_SPACE_OFF_S_CMD]  = CMD_STATUS_REPLY;
            gMbCtx[MB_SPACE_OFF_S_DAT0] = 4;
            gMbCtx[MB_SPACE_OFF_S_SIZE] = 1;
            sendMsgSlv2Mst ();
            break; 
        case CMD_IMAGE_READY:
            //assert (gMbCtx[MB_SPACE_OFF_R_SIZE] == 1);
            // XXX potential false positive in interrupt handling
            gSlvFlag[SLV_FLAG_IMG_SIZE] = gMbCtx[MB_SPACE_OFF_R_DAT0];
            gSlvFlag[SLV_FLAG_IMG_RDY] = 1;
            break;
        default:
            assert (0);
            break;
    };

    return;
}


