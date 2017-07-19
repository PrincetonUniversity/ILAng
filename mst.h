// File: mst.h
// Synopsis: header file for master firmware

#ifndef __MST_H__
#define __MST_H__

#include "common.h"
#include "fabric.h"

#define MST_HW_BASE             0xffff0000

#define MST_HW_OFF_SLV2MST_DBM  0x0
#define MST_HW_OFF_MST2SLV_DB   0x1
#define MST_HW_OFF_MST2SLV_DAT0 0x2
#define MST_HW_OFF_MST2SLV_DAT1 0x3

#define MST_HW_OFF_MST2SLV_DBM  0x4
#define MST_HW_OFF_SLV2MST_DB   0x5
#define MST_HW_OFF_SLV2MST_DAT0 0x6
#define MST_HW_OFF_SLV2MST_DAT1 0x7

//#define HW_REG_WRITE(addr, val) *addr = val
//#define HW_REG_READ(addr) *addr
extern void HW_REG_WRITE (uint32_t addr, uint32_t val);
extern uint32_t HW_REG_READ (uint32_t addr);

void mainMst ();

void sendMsgMst2Slv (uint32_t cmd, uint32_t* data, uint8_t dataSize);

void receiveMsgSlv2Mst (uint32_t* cmd, uint32_t* data, uint8_t* dataSize);

#endif // __MST_H__
