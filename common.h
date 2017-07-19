// File: common.h
// Synopsis: shared variables and functions

#ifndef __COMMON_H__
#define __COMMON_H__

#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
#include "smack.h"

#define MAX_MSG_LENGTH 1

extern uint32_t reg_msg_mst2slv_ctr;
extern uint32_t reg_msg_mst2slv_dat;
extern uint32_t reg_msg_mst2slv_mir;
extern uint32_t reg_msg_slv2mst_ctr;
extern uint32_t reg_msg_slv2mst_mir;
extern uint32_t reg_slv_int;
extern char* mst_sram;

extern pthread_mutex_t int_lock;

#endif // __COMMON_H__
