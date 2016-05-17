#include "model_aes_class.hpp"

#include <iostream>
#include <time.h>
BIT_VEC aes(BIT_VEC cppVar_17, BIT_VEC cppVar_18, BIT_VEC cppVar_19)
{
    return 0;
}

int main() {

    BIT_VEC WR = 2;
    BIT_VEC RD = 1;

    BIT_VEC addr_start = 0xff00;
    BIT_VEC addr_state = 0xff01;
    BIT_VEC addr_rd    = 0xff02;
    BIT_VEC addr_wr    = 0xff04;
    BIT_VEC addr_len   = 0xff06;

    BIT_VEC wraddr = 128;
    BIT_VEC rdaddr = 0;
    BIT_VEC len    = 128;

    model_aes mod;

    mod.aes_state = 0;

    int cnt = 0;

    clock_t t;
    t = clock();

    for (int i=0; i<1000000; i++) {
        mod.update(WR, addr_rd, rdaddr);
        mod.update(WR, addr_wr, wraddr);
        mod.update(WR, addr_len, len);
        mod.update(WR, addr_start, 1);
        cnt += 4;
        do {
            mod.update(RD, addr_state, 0);
            cnt++;
        } while (mod.dataout != 0);
    }

    t = clock() - t;
    std::cout << "time: " << (double)t/CLOCKS_PER_SEC << std::endl;
    std::cout << "cycle: " << cnt << std::endl;

    return 0;
}
