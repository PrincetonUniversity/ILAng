#include "model_sha_class.hpp"

#include <iostream>
#include <time.h>

#define SHA_IDLE  0
#define SHA_READ  1
#define SHA_OP1   2
#define SHA_OP2   3
#define SHA_WRITE 4

BIT_VEC sha(BIT_VEC cppVar_14)
{
    return 0;
}

int main()
{
    BIT_VEC RD = 1;
    BIT_VEC WR = 2;

    BIT_VEC addr_start = 0xfe00;
    BIT_VEC addr_state = 0xfe01;
    BIT_VEC addr_rd    = 0xfe02;
    BIT_VEC addr_wr    = 0xfe04;
    BIT_VEC addr_len   = 0xfe06;

    BIT_VEC wraddr = 128;
    BIT_VEC rdaddr = 0;
    BIT_VEC len = 128;

	model_sha mod;

    mod.sha_state = SHA_IDLE;

    int cnt = 0;

    clock_t t;
    t = clock();

    for (int i = 0; i < 1000000; i++) {
        mod.update(WR, addr_rd, rdaddr);
        mod.update(WR, addr_wr, wraddr);
        mod.update(WR, addr_len, len);
        mod.update(WR, addr_start, 1);
        cnt += 3;
        do {
            mod.update(RD, addr_state, 0);
            cnt++;
        } while (mod.dataout != SHA_IDLE);
    }

    t = clock() - t;
    std::cout << "time: " << (double)t/CLOCKS_PER_SEC << std::endl;
    std::cout << "cycle: " << cnt << std::endl;

    /*
    // set read addr 
    mod.update(WR, addr_rd, rdaddr);
    assert(mod.sha_state == SHA_IDLE);
    assert(mod.sha_rdaddr == rdaddr);

    // set write addr 
    mod.update(WR, addr_wr, wraddr);
    assert(mod.sha_state == SHA_IDLE);
    assert(mod.sha_wraddr == wraddr);

    // set message len 
    mod.update(WR, addr_len, len);
    assert(mod.sha_state == SHA_IDLE);
    assert((mod.sha_len & 0xff) == len);

    // read wraddr
    mod.update(RD, addr_wr, 5);
    assert(mod.dataout == wraddr);

    // read rdaddr
    mod.update(RD, addr_rd, 9);
    assert(mod.dataout == rdaddr);

    // read len
    mod.update(RD, addr_len, 7);
    assert(mod.sha_state == SHA_IDLE);
    assert(mod.sha_len == len);
    assert((mod.sha_len & 0xff) == len);

    // read state, should be IDLE
    mod.update(RD, addr_state, 0);
    assert(mod.dataout == SHA_IDLE);

    // start operation
    mod.update(WR, addr_start, 1);
    assert(mod.sha_state == SHA_READ);
    
    // read state
    mod.update(RD, addr_state, 3);
    assert(mod.sha_state == SHA_OP1);
    assert(mod.dataout == SHA_READ);

    // try to start
    mod.update(WR, addr_start, 1);
    assert(mod.sha_state == SHA_OP2);
    assert(mod.dataout == 0);

    // read state again
    mod.update(RD, addr_state, 1);
    assert(mod.sha_state == SHA_READ);
    assert(mod.dataout == SHA_OP2);

    // read wraddr
    mod.update(RD, addr_wr, 42);
    assert(mod.sha_state == SHA_OP1);
    assert(mod.dataout == wraddr);

    // try to write read address
    mod.update(WR, addr_rd, 7);
    assert(mod.sha_state == SHA_OP2);
    assert(mod.dataout == 0);

    // read len
    mod.update(RD, addr_len, 1);
    assert(mod.sha_state == SHA_WRITE);
    assert(mod.sha_len == len);
    assert((mod.sha_len & 0xff) == len);

    // read  write adderss
    mod.update(RD, addr_wr, 1);
    assert(mod.sha_state == SHA_IDLE);
    assert(mod.dataout == wraddr);

    // read state
    mod.update(RD, addr_state, 1);
    assert(mod.sha_state == SHA_IDLE);
    assert(mod.dataout == SHA_IDLE);

    mod.update(RD, addr_start, 1);
    assert(mod.dataout == SHA_IDLE);
    */

    return 0;
}
