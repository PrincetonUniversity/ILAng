#include<stdio.h>
#include<iostream>
using namespace std;
__global__ void add_neighbour(int *A) { 
      int tid = threadIdx.x; 
/*      int a = A[tid + offset];
      printf("%d, %d\n", tid, a);
      __syncthreads();
      A[tid + offset] = A[tid]; 
      __syncthreads();
      A[tid] = A[tid + offset];
      printf("%d, %d\n",tid ,A[tid]);*/
      A[tid] += A[tid + 2];//A[tid + offset];
}

const int N = 2;
const int threadsPerBlock = 2;
const int blockPerGrid = 1;
int main(){
    int* A, *devA;
    A = new int[N];
    cudaMalloc((void **) &devA, sizeof(int) * N);
    for (int i = 0; i < N; i++)
        A[i] = i;
    cudaMemcpy(devA, A, N * sizeof(int), cudaMemcpyHostToDevice);
    add_neighbour<<<blockPerGrid, threadsPerBlock>>>(devA);
    cudaMemcpy(A, devA, N * sizeof(int), cudaMemcpyDeviceToHost);
    for (int i = 0 ; i < N; i++)
        printf("%d \n", A[i]); 
    return 1;
}
