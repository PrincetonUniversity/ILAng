// File: main.c
// Synopsis: Testing on smack supported atomic attributes

#include <stdlib.h>
#include <stdint.h>

#include <smack.h>
#include <pthread.h>

uint32_t reg = 0;
pthread_t tidFoo;
pthread_t tidBar;

void* foo (void* in) {
    __VERIFIER_atomic_begin ();
    reg++;
    __VERIFIER_atomic_end ();

    return in;
}

void* bar (void* in) {
    __VERIFIER_atomic_begin ();
    reg--;
    __VERIFIER_atomic_end ();

    return in;
}

int main () {
    reg = 0;

    pthread_create (&tidFoo, NULL, foo, NULL);
    pthread_create (&tidBar, NULL, bar, NULL);

    pthread_join (tidFoo, NULL);
    pthread_join (tidBar, NULL);

    assert (reg == 0);

    return 0;
}

