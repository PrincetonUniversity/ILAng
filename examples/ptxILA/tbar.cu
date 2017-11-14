#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cuda.h>

using namespace std;
#define imin(a,b) (a<b?a:b)
#define BAR_INIT 0
#define BAR_ENTER 1
#define BAR_WAIT 2
#define BAR_EXIT 3
#define BAR_FINISH 4

const int N = 128;
const int threadsPerBlock = 128;
const int blocksPerGrid = 1;
/*
__global__ void dot(int *a, int *b, int *c, int *d) {
//int gid = threadIdx.x + blockIdx.x * blockDim.x; 
//int i = a[gid];
//int j = b[gid];
//int k = i + j;
    __shared__ int counter_enter;
    __shared__ int counter_exit;
    counter_enter = 0;
    counter_exit = N;
    //__syncthreads();
    int gid = threadIdx.x + blockIdx.x * blockDim.x;
    if (gid == 0) {
    
    } else {
    }
    //atomic add 1 to counter
    int r = atomicAdd(&counter_enter, 1); 
    for (;;) {
        if (r == N)
            break;
        else
            r = atomicAdd(&counter_enter, 0);
    }
    c[gid] = r;
    r = atomicSub(&counter_exit, 1);
    //__syncthreads();
    while(r != 0) {
        r = atomicSub(&counter_exit, 0);
    }
    d[gid] = r;
    //d[gid] = counter_exit;
    //printf("post_print, %d\n", gid);
//    if (gid % 2 == 1)
//    else
//        c[gid] =  1;
//    c[gid] = c[gid] + 1;
}*/
//__global__ void dot2(float *a, float *b, float*c) {
//int gid = threadIdx.x + blockIdx.x * blockDim.x;
//int i = a[gid];
//int j = b[gid];
//int k = i + j;
//}
//__global__ void mykernel(int *data){
//    atomicAdd(data, 10); 
//}
__global__ void dot(int *bar_state_array, int *bar_counter_enter_array, int *bar_counter_exit_array) {
    int gid = threadIdx.x + blockIdx.x * blockDim.x;
    int bar_state = bar_state_array[gid];
    int bar_counter_enter = bar_counter_enter_array[gid];
    int bar_counter_exit = bar_counter_exit_array[gid];
    if (gid == 0) {
        if (bar_state == BAR_INIT) {
            bar_state = BAR_ENTER;
        } else if(bar_state == BAR_ENTER) {
            if (bar_counter_exit == 0) {
                if (bar_counter_enter == (N-1)) {
                    bar_counter_enter = N;
                    bar_state = BAR_EXIT;
                    bar_counter_exit = N;
                }
                else {
                    bar_counter_enter += 1;
                    bar_state = BAR_WAIT;
                }
            }
        } else if(bar_state == BAR_WAIT) {
            if (bar_counter_enter == N) {
                bar_state = BAR_EXIT;
            }
        } else if (bar_state == BAR_EXIT) {
            if (bar_counter_exit == 1) {
                bar_counter_enter = 0;
                bar_counter_exit = 0;
                bar_state = BAR_FINISH;
            } else {
                bar_counter_exit -= 1;
                bar_state = BAR_FINISH;
            }
        } else if (bar_state == BAR_FINISH) 
            bar_state = BAR_INIT;
    }
    bar_state_array[gid] = bar_state;
    bar_counter_enter_array[gid] = bar_counter_enter;
    bar_counter_exit_array[gid] = bar_counter_exit;


}
int main(){
    //int *a, *b, *partial_c, *partial_d;
    int *bar_state_array, *bar_counter_enter_array, *bar_counter_exit_array;
    int *dev_bar_state_array, *dev_bar_counter_enter_array, *dev_bar_counter_exit_array; 
    
    bar_state_array = new int[N];
    bar_counter_enter_array = new int[N];
    bar_counter_exit_array = new int[N];

    cudaMalloc((void **)&dev_bar_state_array, sizeof(int) * N);
    cudaMalloc((void **)&dev_bar_counter_enter_array, sizeof(int) * N);
    cudaMalloc((void **)&dev_bar_counter_exit_array, sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        bar_state_array[i] = 0;
        bar_counter_enter_array[i] = 0;
        bar_counter_exit_array[i] = 0;
    }
    bar_state_array[0] = 1;
    bar_counter_enter_array[0] = N - 1;
    bar_counter_exit_array[0] = 0;
    cudaMemcpy(dev_bar_state_array, bar_state_array, N*sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(dev_bar_counter_enter_array, bar_counter_enter_array, N*sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(dev_bar_counter_exit_array, bar_counter_exit_array, N*sizeof(int), cudaMemcpyHostToDevice);
    dot<<<blocksPerGrid, threadsPerBlock>>>(dev_bar_state_array, dev_bar_counter_enter_array, dev_bar_counter_exit_array);
    cudaMemcpy(bar_state_array, dev_bar_state_array, N*sizeof(int), cudaMemcpyDeviceToHost);
    cudaMemcpy(bar_counter_enter_array, dev_bar_counter_enter_array, N*sizeof(int), cudaMemcpyDeviceToHost);
    cudaMemcpy(bar_counter_exit_array, dev_bar_counter_exit_array, N*sizeof(int), cudaMemcpyDeviceToHost);
    cudaFree(dev_bar_state_array);
    cudaFree(dev_bar_counter_enter_array);
    cudaFree(dev_bar_counter_exit_array);
    printf("%d\n", bar_state_array[0]);
    printf("%d\n", bar_counter_enter_array[0]);
    printf("%d\n", bar_counter_exit_array[0]);
    delete[] bar_state_array;
    delete[] bar_counter_enter_array;
    delete[] bar_counter_exit_array;
    //int *dev_a, *dev_b, *dev_partial_c, *dev_partial_d;
    /*
    a = new int[N];
    b = new int[N];
    partial_c = new int[N];
    partial_d = new int[N];
    for (int i = 0; i < N; i++) {
        a[i] = i;
        b[i] = i * 2.0f;
        partial_c[i] = 200;
        partial_d[i] = 250;
    }
    cudaMalloc((void **)&dev_a, sizeof(int) * N);
    cudaMalloc((void **)&dev_b, sizeof(int) * N);
    cudaMalloc((void **)&dev_partial_c, N*sizeof(int));
    cudaMalloc((void **)&dev_partial_d, N*sizeof(int));
    cudaMemcpy(dev_a, a, N*sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(dev_b, b, N*sizeof(int), cudaMemcpyHostToDevice);
    dot<<<blocksPerGrid, threadsPerBlock>>>(dev_a, dev_b, dev_partial_c, dev_partial_d);
    cudaMemcpy( partial_c, dev_partial_c, N*sizeof(int), cudaMemcpyDeviceToHost);
    cudaMemcpy( partial_d, dev_partial_d, N*sizeof(int), cudaMemcpyDeviceToHost);
    #define sum_sq(x) (x*(x+1)*(2*x+1)/6)
    
    cudaFree(dev_a);
    cudaFree(dev_b);
    cudaFree(dev_partial_c);
    cudaFree(dev_partial_d);
    for(int i = 0 ; i < N; i++) {
        printf("enter %d has %d\n", i, partial_c[i]);
    }
    for (int i = 0; i < N; i++) {
        printf("exit %d, has %d\n", i, partial_d[i]);
    }
    
    delete[]  a;
    delete[]  b;
    delete[]  partial_c;
    */
}
