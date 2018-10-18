// source file for IP A firmware and hardware model

#include "fwA.h"

void mainA () {
    // request for source size (A-->B)
    sendMsgA2B (CMD_SIZE_REQUEST);

    // receive source size (B-->A)
    int32_t size = receiveMsgA ();

    assert (size == 32);
    // copy from source
    memcpy (buffer_B, buffer_A, size);
}

void sendMsgA2B (int32_t data) {
    msg_reg_B_DATA = data;
    msg_reg_B_CTR = 1;
}

int32_t receiveMsgA () {
    while (msg_reg_A_CTR == 0);

    msg_reg_A_CTR = 0;
    return msg_reg_A_DATA;
}
