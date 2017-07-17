// source file for IP B firmware and hardware model

#include "fwB.h"

void mainB () {
    // wait for request (A-->B)
    while (receiveMsgB() != CMD_SIZE_REQUEST);

    // response the size (B-->A)
    sendMsgB2A (32);
}

void sendMsgB2A (int32_t data) {
    msg_reg_A_DATA = data;
    msg_reg_A_CTR = 1;
}

int32_t receiveMsgB () {
    while (msg_reg_B_CTR == 0);

    msg_reg_B_CTR = 0;
    return msg_reg_B_DATA;
}
