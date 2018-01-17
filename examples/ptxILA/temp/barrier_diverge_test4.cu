#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cuda.h>

using namespace std;
#define imin(a,b) (a<b?a:b)

const int N = 128;
const int threadsPerBlock = 128;
const int blocksPerGrid = 1;

__global__ void dot(int *a) {
//int gid = threadIdx.x + blockIdx.x * blockDim.x; 
//int i = a[gid];
//int j = b[gid];
//int k = i + j;
    int tid = threadIdx.x;
    for (int i = 0; i < 1; i ++) {
    if (tid >= N/2){
        int t0=0;
        int t1=0;
        for ( int j = 0 ;j < tid; j++) {
            a[N + j] = a[tid];
        }
        t0 = a[tid - N/2];
        t1 = a[tid];
        __syncthreads();
        a[tid] = t0+t1;
        __syncthreads();
        //__syncthreads();

    } else {
        int t0 = a[tid];
        int t1 = a[tid + N/2];
        //__syncthreads();
        a[tid] = t0 + t1;
        __syncthreads();
 
    }
    __syncthreads();
    }
//    else
//        c[gid] =  1;
//    c[gid] = c[gid] + 1;
}
//__global__ void dot2(int *a, int *b, int*c) {
//int gid = threadIdx.x + blockIdx.x * blockDim.x;
//int i = a[gid];
//int j = b[gid];
//int k = i + j;
//}
//__global__ void mykernel(int *data){
//    atomicAdd(data, 10); 
//}
   
int main(){
    int *a;
    int *dev_a;
    
    a = new int[N];
    for (int i = 0; i < N; i++) {
        a[i] = i;
    }
    cudaMalloc((void **)&dev_a, sizeof(int) * N);
    cudaMemcpy(dev_a, a, N*sizeof(int), cudaMemcpyHostToDevice);
    dot<<<blocksPerGrid, threadsPerBlock>>>(dev_a);
    cudaMemcpy( a, dev_a, N*sizeof(int), cudaMemcpyDeviceToHost);
    #define sum_sq(x) (x*(x+1)*(2*x+1)/6)

    for (int i = 0;i < N/2; i++)
        printf("%d  %d\n", a[i], a[i + N/2]);
    cudaFree(dev_a);
    

    delete[]  a;
}
