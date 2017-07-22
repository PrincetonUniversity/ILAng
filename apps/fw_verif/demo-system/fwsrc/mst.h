// File: mst.h
// Synopsis: header file for master firmware

#ifndef __MST_H__
#define __MST_H__

#include "common.h"
#include "fabric.h"

#define MST_HW_BASE             FAB_HW_BASE

#define MST_HW_OFF_SLV2MST_DBM  FAB_HW_OFF_SLV2MST_DBM
#define MST_HW_OFF_MST2SLV_DB   FAB_HW_OFF_MST2SLV_DB
#define MST_HW_OFF_MST2SLV_DAT0 FAB_HW_OFF_MST2SLV_DAT0   
#define MST_HW_OFF_MST2SLV_DAT1 FAB_HW_OFF_MST2SLV_DAT1

#define MST_HW_OFF_MST2SLV_DBM  FAB_HW_OFF_MST2SLV_DBM
#define MST_HW_OFF_SLV2MST_DB   FAB_HW_OFF_SLV2MST_DB
#define MST_HW_OFF_SLV2MST_DAT0 FAB_HW_OFF_SLV2MST_DAT0
#define MST_HW_OFF_SLV2MST_DAT1 FAB_HW_OFF_SLV2MST_DAT1

void mainMst ();

void sendMsgMst2Slv (uint32_t cmd, uint32_t* data, uint8_t dataSize);

void receiveMsgSlv2Mst (uint32_t* cmd, uint32_t* data, uint8_t* dataSize);

#endif // __MST_H__
