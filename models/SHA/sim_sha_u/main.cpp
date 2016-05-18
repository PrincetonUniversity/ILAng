#include "model_sha_class.hpp"

#include <iostream>
#include <sys/time.h>
#include <sys/resource.h>

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

    struct rusage ru;
    getrusage(RUSAGE_SELF, &ru);

    double cpu_time = (double) (ru.ru_utime.tv_sec + ru.ru_stime.tv_sec) +
                      (double) (ru.ru_utime.tv_usec + ru.ru_stime.tv_usec) * 1e-6;

    unsigned long long cnt = 0;

    while (cpu_time < 600) {
        mod.update(WR, addr_rd, rdaddr);
        mod.update(WR, addr_wr, wraddr);
        mod.update(WR, addr_len, len);
        mod.update(WR, addr_start, 1);
        cnt += 4;
        if (cnt % 10000 >= 0 && cnt % 10000 <= 3) {
            getrusage(RUSAGE_SELF, &ru);
            cpu_time = (double) (ru.ru_utime.tv_sec + ru.ru_stime.tv_sec) +
                       (double) (ru.ru_utime.tv_usec + ru.ru_stime.tv_usec) * 1e-6;
        }

        do {
            mod.update(RD, addr_state, 0);
            cnt++;
            if (cnt % 10000 >= 0 && cnt % 10000 <= 3) {
                getrusage(RUSAGE_SELF, &ru);
                cpu_time = (double) (ru.ru_utime.tv_sec + ru.ru_stime.tv_sec) +
                           (double) (ru.ru_utime.tv_usec + ru.ru_stime.tv_usec) * 1e-6;
            }
        } while (mod.dataout != SHA_IDLE);
    }

    std::cout << "Time: " << cpu_time << std::endl;
    std::cout << "#Inctr: " << cnt << std::endl;

    return 0;
}
