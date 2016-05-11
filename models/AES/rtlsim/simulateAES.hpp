#include <stdint.h>
#include <verilated.h>
#include "VsimXramAes_top.h"

#include <iostream>
#include <fstream>

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
             aes_keysel,
             aes_ctr,
             aes_key0,
             aes_key1,
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
INT hex2int(const std::string& str);
void hex2array(const std::string& str, INT* res, int byteNum);

void assignCTR();
void assignKEY0();
void assignKEY1();

bool hasChangedCTR();
bool hasChangedKEY0();
bool hasChangedKEY1();
bool hasChangedRD();
bool hasChangedENC();

void init();

void assignFromFile(const std::string& fileName);

bool hasChangedMicro();
bool hasChangedMacro();

void execute();

void writeToFile(const std::string& fileName);


