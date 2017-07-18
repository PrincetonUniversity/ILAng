// Header file for shared variables

#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include "smack.h"

extern int32_t msg_reg_A_CTR;
extern int32_t msg_reg_A_DATA;
extern int32_t msg_reg_B_CTR;
extern int32_t msg_reg_B_DATA;
extern int32_t buffer_A[32];
extern int32_t buffer_B[32];

#define CMD_NONE 0
#define CMD_SIZE_REQUEST 1
#define CMD_SIZE_RESPOND 2

#endif // __COMMON_H_
