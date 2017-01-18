#include <stdint.h>
#include <verilated.h>
#include "VsimXramAes_top.h"

#include <iostream>
#include <fstream>
#include <map>

typedef vluint32_t INT;

/******************************************************************************
                                  File Format:
-------------------------------------------------------------------------------
Input: 

    .AES_IP_START
    [.varname varvalue]
    .AES_IP_END

    varname: cmd, 
             cmdaddr, 
             cmddata, 
             aes_state,
             aes_addr,
             aes_len,
             aes_ctr,
             aes_key0,
             byte_cnt,
             rd_data,
             enc_data,
             xram

     varvalue: (hex form)
            xram: default [( addr data )]

Output:
    .AES_OP_START
    [.varname varvalue]
    .AES_OP_END

    varname: same as input except cmd, cmdaddr, and cmddata

******************************************************************************/

// Assign aes_state 
void assignState();
// Assign aes_addr
void assignAddr();
// Assign aes_len
void assignLen();
// Assign aes_ctr 
void assignCTR();
// Assign aes_key0 
void assignKEY0();
// Assign aes_key1 
void assignDataOut();
// Assign byte_cnt
void assignByteCnt();
// Assign oped_byte_cnt
void assignOpedByteCnt();
// Assign blk_cnt
void assignBlkCnt();

// Check that aes_addr has been updated.
bool hasChangedAddr();
// Check that aes_len has been updated.
bool hasChangedLen();
// Check that aes_ctr has been updated.
bool hasChangedCTR();
// Check that aes_key0 has been updated.
bool hasChangedKEY0();
// Check that rd_data has been updated.
bool hasChangedRD();
// Check that enc_data has been updated.
bool hasChangedENC();
// Check if it is a read
bool isRead();

// Initialize states.
void init();

// Read from state assignment file and assign states.
void assignFromFile(const std::string& fileName);
// Micro states has been updated.
bool hasChangedMicro();
// Macro states has been updated. Not completed yet.
bool hasChangedMacro();
// Ececute on cycle.
void execute();
// Extract state values and write to file.
void writeToFile(const std::string& fileName);

// Convert hex format string into int
INT hex2int(const std::string& str);
// Convert hex format long string into array of int, each array element has 
// hexNum/2 .
void hex2array(const std::string& str, INT* res, int hexNum);

// Helper functions for parsing
char nextChar(std::istream& in);
INT memSplitA(const std::string& buff);
INT memSplitD(const std::string& buff);
