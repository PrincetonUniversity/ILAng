// File: slv.h
// Synopsis: header file for slave firmware

#ifndef __SLV_H__
#define __SLV_H__

#include "common.h"
#include "mb.h"

/* slave system flags
 */
extern uint32_t gSlvFlag[];
#define SLV_FLAG_IMG_RDY    0
#define SLV_FLAG_IMG_SIZE   1
#define SLV_FLAG_SIZE       2

/* hardware context for message buffer (MB)
 */
extern uint32_t gMbCtx[];
#define MB_SPACE_OFF_S_CMD  0
#define MB_SPACE_OFF_S_DAT0 1
#define MB_SPACE_OFF_S_DAT1 2
#define MB_SPACE_OFF_S_SIZE 3
#define MB_SPACE_OFF_R_CMD  4
#define MB_SPACE_OFF_R_DAT0 5
#define MB_SPACE_OFF_R_DAT1 6
#define MB_SPACE_OFF_R_SIZE 7
#define MB_SPACE_SIZE       8

/* mainstream firmware 
 */
void mainSlv ();

void sendMsgSlv2Mst ();

/* interrupt handler
 */
void intHdl ();

void getMbCtx ();

void handleCmd ();

#endif // __SLV_H__
