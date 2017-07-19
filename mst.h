// File: mst.h
// Synopsis: header file for master firmware

#ifndef __MST_H__
#define __MST_H__

#include "common.h"

void mainMst ();

void sendMsgMst2Slv (uint32_t cmd, uint32_t* data, uint8_t dataSize);

void receiveMsgSlv2Mst (uint32_t* cmd, uint32_t* data, uint8_t* dataSize);

#endif // __MST_H__
