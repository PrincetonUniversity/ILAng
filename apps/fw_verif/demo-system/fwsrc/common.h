// File: common.h
// Synopsis: shared variables and functions

#ifndef __COMMON_H__
#define __COMMON_H__

#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "smack.h"

#define MAX_DATA_LENGTH 2
#define MAX_SRAM_SIZE 32

#define CMD_STATUS_REQUEST  0x1
#define CMD_STATUS_REPLY    0x2
#define CMD_IMAGE_READY     0x3
#define CMD_IMAGE_DONE      0x4

extern uint32_t reg_slv_int;
extern char mst_sram[];

extern pthread_mutex_t int_lock;
extern pthread_mutex_t fab_lock;
extern pthread_mutex_t ctx_lock;

#endif // __COMMON_H__
