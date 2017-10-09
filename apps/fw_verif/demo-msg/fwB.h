// Header file for IP B firmware and hardware model

#ifndef __FW_B_H__
#define __FW_B_H__

#include "common.h"

// main function for IP B firmware 
void mainB ();

// sending message to IP A
void sendMsgB2A (int32_t data);

// receiving message sent to IP B
int32_t receiveMsgB ();


#endif // __FW_B_H__
