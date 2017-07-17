// Header file for IP A firmware and hardware model

#ifndef __FW_A_H__
#define __FW_A_H__

#include "common.h"
#include "string.h"

// main function for IP A firmware 
void mainA ();

// sending message to IP B
void sendMsgA2B (int32_t data);

// receiving message sent to IP A
int32_t receiveMsgA ();


#endif // __FW_A_H__
