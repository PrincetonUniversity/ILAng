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
    // 1. send request message to slave for status (buffer max size)
    sendMsgMst2Slv (CMD_STATUS_REQUEST, NULL, 0);

    // 2. receive message from slave for status (buffer max size)
    uint32_t recCmd = 0;
    uint32_t recData[MAX_DATA_LENGTH] = {0};
    uint8_t  recDataSize = 0;
    receiveMsgSlv2Mst (&recCmd, recData, &recDataSize);

    // 3. prepare image chunk
    uint32_t imgSize = (recDataSize >= 1 && recData[0] <= MAX_SRAM_SIZE)?
                       recData[0]: MAX_SRAM_SIZE;
#ifdef MEM_OP
    char* mstBuff = (char*) calloc (1, imgSize);
    memcpy (mst_sram, mstBuff, imgSize);
#endif // MEM_OP
    
    // 4. send ready message to slave to indicate image ready
    sendMsgMst2Slv (CMD_IMAGE_READY, &imgSize, 1);

    // 5. receive message from slave for image copy complete
    receiveMsgSlv2Mst (&recCmd, recData, &recDataSize);

    // 6. remove image chunk
#ifdef MEM_OP
    free (mstBuff);
#endif // MEM_OP
    assert (0);

    return;
}

/* sendMsgmst2Slv: send msg to slave
 * arg 1: (IN) command
 * arg 2: (IN) data pointer
 * arg 3: (IN) data size
 * Note: should not exceed max data size MAX_DATA_LENGTH
 */
void sendMsgMst2Slv (uint32_t cmd, uint32_t* data, uint8_t dataSize) {
    while (HW_REG_READ (MST_HW_BASE+MST_HW_OFF_MST2SLV_DBM));

    for (uint8_t i = 0; (i < dataSize) && (i < MAX_DATA_LENGTH); i++) {
        HW_REG_WRITE (MST_HW_BASE+MST_HW_OFF_MST2SLV_DAT0+i, data[i]);
    }
    /*
    if (dataSize == 1)
        HW_REG_WRITE (MST_HW_BASE+MST_HW_OFF_MST2SLV_DAT0, data[0]);
    */

    uint32_t db = (cmd << 9) | (dataSize << 1) | 0x1;
    HW_REG_WRITE (MST_HW_BASE+MST_HW_OFF_MST2SLV_DB, db);

    return;
}

/* receiveMsgSlv2mst: receive msg from slave
 * arg 1: (OUT) command
 * arg 2: (OUT) data pointer
 * arg 3: (OUT) data size
 * Note: should not exceed max data size MAX_DATA_LENGTH
 */
void receiveMsgSlv2Mst (uint32_t* cmd, uint32_t* data, uint8_t* dataSize) {
    while (HW_REG_READ (MST_HW_BASE+MST_HW_OFF_SLV2MST_DB) == 0);

    uint32_t db = HW_REG_READ (MST_HW_BASE+MST_HW_OFF_SLV2MST_DB);
    *cmd = db >> 9;
    *dataSize = (db >> 1) & 0xff;

    for (uint8_t i = 0; i < MAX_DATA_LENGTH; i++) {
        data[i] = HW_REG_READ (MST_HW_BASE+MST_HW_OFF_SLV2MST_DAT0+i);
    }
    /*
    data[0] = HW_REG_READ (MST_HW_BASE+MST_HW_OFF_SLV2MST_DAT0);
    data[1] = HW_REG_READ (MST_HW_BASE+MST_HW_OFF_SLV2MST_DAT1);
    */

    //assert ((*dataSize == 1) || (*dataSize == 0));

    HW_REG_WRITE (MST_HW_BASE+MST_HW_OFF_SLV2MST_DB, 0);

    return;
}
