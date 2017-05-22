// verifyC.c
#include "assert.h"
#include "t1.c"
#include "cbmcAesAuto.c"

// endian change
#define SWAP(num) (((num>>24)&0xff) |  ((num<<8)&0xff0000) | ((num>>8)&0xff00) |  ((num<<24)&0xff000000))

int main()
{
    word Key1[4];
    word Key2[4];// = {0x00906000,0x22345678,0x32345678,0x09300100};
    word Plt1[4];
    word Plt2[4];// = {0xa2345678,0xb2345678,0xc2345678,0xd2345678};

    Key1[0] = SWAP(Key2[0]);
    Key1[1] = SWAP(Key2[1]);
    Key1[2] = SWAP(Key2[2]);
    Key1[3] = SWAP(Key2[3]);
    Plt1[0] = SWAP(Plt2[0]);
    Plt1[1] = SWAP(Plt2[1]);
    Plt1[2] = SWAP(Plt2[2]);
    Plt1[3] = SWAP(Plt2[3]);


    struct model_aesr aes;
    aes.i=1; aes.rcon = 1; aes.table = table_0;
    aes.in_key0 = Key2[0];
    aes.in_key1 = Key2[1];
    aes.in_key2 = Key2[2];
    aes.in_key3 = Key2[3];
    aes.state0 = Plt2[0];
    aes.state1 = Plt2[1];
    aes.state2 = Plt2[2];
    aes.state3 = Plt2[3];
    //printf("C\n");
    encrypt_128_key_expand_inline_no_branch(Plt1,Key1);

    //printf("U\n");
    model_aesr_init(&aes);
    update(&aes);
    //prtp(aes.debug);

    //printf("E\n");
    //prtp(aes.state0);
    //prtp(Plt1[0]);
    assert(aes.rcon == grcon);

    assert(aes.in_key0 == SWAP(gkey[0]) );
    assert(aes.in_key1 == SWAP(gkey[1]) );
    assert(aes.in_key2 == SWAP(gkey[2]) );
    assert(aes.in_key3 == SWAP(gkey[3]) );

    assert(aes.state0 == SWAP(Plt1[0]) );
    assert(aes.state1 == SWAP(Plt1[1]) );
    assert(aes.state2 == SWAP(Plt1[2]) );
    assert(aes.state3 == SWAP(Plt1[3]) );
    
    printf("E\n");
    prtp(gkey[0]);
    prtp(gkey[1]);
    prtp(gkey[2]);
    prtp(gkey[3]);
    prtp(Plt1[0]);
    prtp(Plt1[1]);
    prtp(Plt1[2]);
    prtp(Plt1[3]);
    

    return 0;
}
