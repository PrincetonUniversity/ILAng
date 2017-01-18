// ILA@SYN_BACKGROUND

#include "stdio.h"
#include "stdlib.h"
#include "AES.h"

struct AES_parameter
{
    uint32_t * PlainTextPointer;
    uint16_t EncryptLength;
    uint32_t  EncryptKey[4];
    uint32_t  EncryptCtr[4];
};

//##LABEL##@_global##//

void AES_CTR_start(struct AES_parameter param)
{
    uint32_t key[4];
    uint32_t plaintext[4];
    uint32_t tmp_result[4];
    uint32_t final_result[4];
    uint32_t AES_ctr[4];
    int byteCount;
    
    memory_move(param.EncryptKey,key,4);
    memory_move(param.EncryptCtr,AES_ctr,4);

    for( byteCount = 0; byteCount <= param.EncryptLength;  byteCount += 16)
    {
		//##LABEL##@_ILA_aes_step_1##//
        loadFromMem(param.PlainTextPointer + byteCount/4, plaintext ); // PlainTextPointer is a word pointer !!
		//##LABEL##@_ILA_aes_step_2##//
        AES_block_encrypt(key,AES_ctr,tmp_result);
        xor(tmp_result,plaintext,final_result,4);
		//##LABEL##@_ILA_aes_step_3##//
        storeToMem(param.PlainTextPointer + byteCount/4, final_result );
        inc(AES_ctr,4,16); // Increase a micro-arch state, in Verilog, no such states
    }
    
    byteCount -= 16;
    //##LABEL##@_ILA_aes_end##//
}

// dummy main for running the code
// also to make the interface as a memory-mapping interface

#include "mmio.h"

int main()
{
	uint8_t cmd;
	uint16_t cmdaddr;
	uint8_t cmddata;
	uint8_t buffer[65536];
    struct AES_parameter param;
	struct mmio mmport;

	//##LABEL##@_ILA_aes_top_0##//
	uint8_t * p = (uint8_t *) & mmport;

	if(cmdaddr >= 0xff00 && cmdaddr < 0xff40)
	{
		if(cmd == 2)
			p[(cmdaddr-0xff00)] = cmddata;
	
		// here we convert mmio -> function parameter
		ToFunctionArg(&mmport, &param, buffer);
		if(cmd == 2 && cmdaddr == 0xff00 && cmddata == 1)
		    AES_CTR_start(param); // let's start
		ToMemoryMap(&param, &mmport);
	}
	
	//##LABEL##@_ILA_aes_end##//	
	
	return 0;
}

