#include<stdio.h>
#include<iostream>
using namespace std;
        /* a sum reduction on the array of floats 'in'.
         * The reduction result is written to the
          * address 'result'.  The number of elements to
           * be reduced is given by 'size'
            *
             * The example contains data races because barrier
              * synchronisation statements, of the form:
               *   __syncthreads();
                * are missing.
                 *
                  * Can you add them to eliminate all data races?
                   */

#define N 4/* Same as blockDim */


__global__ void reduce(int *in) {
    int tid = threadIdx.x;
    for(int d = N/2; d > 0; d >>= 1) {
                                         if(tid < d) {
                                                   in[tid] += in[tid + d];
                                                       }
                                                       __syncthreads();
                                                         }

                                                           /* Master thread writes out result */
                                                                         
}

