// File: slv.h
// Synopsis: header file for slave firmware

#ifndef __SLV_H__
#define __SLV_H__

#include "common.h"

/* hardware interface for message buffer (MB)
 *  MB_CMD
 *  MB_STS
 *  MB_DST
 *  MB_DATA0
 *  MB_DATA1
 */
#define MB_SPACE_SIZE       5
#define MB_SPACE_OFF_CMD    0
#define MB_SPACE_OFF_STS    1
#define MB_SPACE_OFF_DST    2
#define MB_SPACE_OFF_DATA0  3
#define MB_SPACE_OFF_DATA1  4

struct hwItfMb_t {
    // TODO
};


/* Shared variables
 * gMbCtx:      firmware local copy of message buffer context
 * reg_MB:      hardware interface
 */
extern uint32_t gMbCtx[];
extern struct hwItfMb_t* reg_MB;

/* mainstream firmware 
 */
void mainSlv ();

void sendMsgSlv2Mst (uint32_t cmd, uint32_t* data, uint8_t dataSize);

/* interrupt handler
 */
void intHdl ();

void getMbCtx (uint32_t* mbCtx);

void handleCmd (uint32_t* mbCtx);


#endif // __SLV_H__
