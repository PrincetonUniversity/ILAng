// File: mst.c
// Synopsis: source file for master firmware

#include "mst.h"

/* Global Variables
 *
 */

/* mainMst: master firmware main function 
 *  1. send request message to slave for status (buffer max size)
 *  2. receive message from slave for status (buffer max size)
 *  3. prepare image chunk
 *  4. send ready message to slave to indicate image ready
 *  5. receive message from slave for image copy complete
 *  6. remove image chunk
 */
void mainMst () {
    // TODO
    return;
}

/* sendMsgmst2Slv: send msg to slave
 * arg 1: (IN) command
 * arg 2: (IN) data pointer
 * arg 3: (IN) data size
 * Note: should not exceed max data size MAX_MSG_LENGTH
 */
void sendMsgMst2Slv (uint32_t cmd, uint32_t* data, uint8_t dataSize) {
    // TODO
    return;
}

/* receiveMsgSlv2mst: receive msg from slave
 * arg 1: (OUT) command
 * arg 2: (OUT) data pointer
 * arg 3: (OUT) data size
 * Note: should not exceed max data size MAX_MSG_LENGTH
 */
void receiveMsgSlv2Mst (uint32_t* cmd, uint32_t* data, uint8_t* dataSize) {
    // TODO
    return;
}
