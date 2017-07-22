// File: fabric.h
// Synopsis: header file for fabric end point hardware model (MMIO registers)

#ifndef __FABRIC_H__
#define __FABRIC_H__

#include "common.h"

#define FAB_HW_BASE             0xffff0000

#define FAB_HW_OFF_SLV2MST_DBM  0x0
#define FAB_HW_OFF_MST2SLV_DB   0x1
#define FAB_HW_OFF_MST2SLV_DAT0 0x2
#define FAB_HW_OFF_MST2SLV_DAT1 0x3

#define FAB_HW_OFF_MST2SLV_DBM  0x4
#define FAB_HW_OFF_SLV2MST_DB   0x5
#define FAB_HW_OFF_SLV2MST_DAT0 0x6
#define FAB_HW_OFF_SLV2MST_DAT1 0x7

extern uint32_t reg_msg_mst2slv_db;
extern uint32_t reg_msg_mst2slv_dat0;
extern uint32_t reg_msg_mst2slv_dat1;
extern uint32_t reg_msg_mst2slv_dbm;
extern uint32_t reg_msg_slv2mst_db;
extern uint32_t reg_msg_slv2mst_dat0;
extern uint32_t reg_msg_slv2mst_dat1;
extern uint32_t reg_msg_slv2mst_dbm;

void FAB_REG_LOCK ();
void FAB_REG_UNLOCK ();

//#define HW_REG_WRITE(addr, val) *addr = val
//#define HW_REG_READ(addr) *addr
void HW_REG_WRITE (uint32_t addr, uint32_t val);
uint32_t HW_REG_READ (uint32_t addr);

/* HW model (read/write centric)
 */
void write_reg_msg_mst2slv_db (uint32_t val);
void write_reg_msg_mst2slv_dbm (uint32_t val);
void write_reg_msg_mst2slv_dat0 (uint32_t val);
void write_reg_msg_mst2slv_dat1 (uint32_t val);
void write_reg_msg_slv2mst_db (uint32_t val);
void write_reg_msg_slv2mst_dbm (uint32_t val);
void write_reg_msg_slv2mst_dat0 (uint32_t val);
void write_reg_msg_slv2mst_dat1 (uint32_t val);
uint32_t read_reg_msg_mst2slv_db ();
uint32_t read_reg_msg_mst2slv_dbm ();
uint32_t read_reg_msg_mst2slv_dat0 ();
uint32_t read_reg_msg_mst2slv_dat1 ();
uint32_t read_reg_msg_slv2mst_db ();
uint32_t read_reg_msg_slv2mst_dbm ();
uint32_t read_reg_msg_slv2mst_dat0 ();
uint32_t read_reg_msg_slv2mst_dat1 ();

#endif // __FABRIC_H__
