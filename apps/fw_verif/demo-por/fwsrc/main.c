// File: main.c
// Synopsis: Use smack supported atomic attribute for bounded context switch
//           as partial order reduction

#include <stdlib.h>
#include <stdint.h>

#include <smack.h>
#include <pthread.h>

uint32_t gvar;
pthread_t tidFoo;
pthread_t tidBar;

void rmw (uint32_t val) {
    __VERIFIER_atomic_end ();

    __VERIFIER_atomic_begin ();
    if (val == 1) 
        gvar++;
    else
        gvar--;
    __VERIFIER_atomic_end ();

    __VERIFIER_atomic_begin ();
    return;
}

void* foo (void* in) {
    __VERIFIER_atomic_begin ();
    rmw (0);
    __VERIFIER_atomic_end ();
    return in;
}

void* bar (void* in) {
    __VERIFIER_atomic_begin ();
    __VERIFIER_atomic_end ();
    rmw (1);
    return in;
}

int main () {
    gvar = 0;

    pthread_create (&tidFoo, NULL, foo, NULL);
    pthread_create (&tidBar, NULL, bar, NULL);

    pthread_join (tidFoo, NULL);
    pthread_join (tidBar, NULL);

    assert (gvar == 0);

    return 0;
}

