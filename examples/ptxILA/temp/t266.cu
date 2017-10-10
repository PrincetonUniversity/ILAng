#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cuda.h>

using namespace std;
#define imin(a,b) (a<b?a:b)

const int N = 1;
const int threadsPerBlock = 1;
const int blocksPerGrid = 1;

__global__ void dot(float *a, float *b, float *c) {
//int gid = threadIdx.x + blockIdx.x * blockDim.x; 
//int i = a[gid];
//int j = b[gid];
//int k = i + j;
    int gid = threadIdx.x + blockIdx.x * blockDim.x;
    int i = a[gid];
    int j = b[gid];
    int k = i + j;
    printf("%d", k);
//    if (gid % 2 == 1)
        c[gid] = k;
//    else
//        c[gid] =  1;
//    c[gid] = c[gid] + 1;
}
//__global__ void dot2(float *a, float *b, float*c) {
//int gid = threadIdx.x + blockIdx.x * blockDim.x;
//int i = a[gid];
//int j = b[gid];
//int k = i + j;
//}
//__global__ void mykernel(int *data){
//    atomicAdd(data, 10); 
//}
   
int main(){
    float *a, *b, *partial_c;
    float *dev_a, *dev_b, *dev_partial_c;
    
    a = new float[N];
    b = new float[N];
    partial_c = new float[N];
    for (int i = 0; i < N; i++) {
        a[i] = i;
        b[i] = i * 2.0f;
    }
    cudaMalloc((void **)&dev_a, sizeof(float) * N);
    cudaMalloc((void **)&dev_b, sizeof(float) * N);
    cudaMalloc((void **)&dev_partial_c, N*sizeof(float));
    cudaMemcpy(dev_a, a, N*sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(dev_b, b, N*sizeof(float), cudaMemcpyHostToDevice);
    dot<<<blocksPerGrid, threadsPerBlock>>>(dev_a, dev_b, dev_partial_c);
    cudaMemcpy( partial_c, dev_partial_c, N*sizeof(float), cudaMemcpyDeviceToHost);
    #define sum_sq(x) (x*(x+1)*(2*x+1)/6)

    cudaFree(dev_a);
    cudaFree(dev_b);
    cudaFree(dev_partial_c);

    delete[]  a;
    delete[]  b;
    delete[]  partial_c;
}
