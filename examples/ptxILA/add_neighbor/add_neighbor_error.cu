#include<stdio.h>
#include<iostream>
using namespace std;
__global__ void add_neighbour(int *A, int offset) { 
      int tid = threadIdx.x; 
        A[tid] += A[tid + offset]; 
}

const int N = 8192;
const int threadsPerBlock = 128;
const int blockPerGrid = 64;
int main(){
    int* A, *devA;
    A = new int[N];
    cudaMalloc((void **) &devA, sizeof(int) * N);
    for (int i = 0; i < N; i++)
        A[i] = i;
    cudaMemcpy(devA, A, N * sizeof(int), cudaMemcpyHostToDevice);
    add_neighbour<<<blockPerGrid, threadsPerBlock>>>(devA, 1);
    cudaMemcpy(A, devA, N * sizeof(int), cudaMemcpyDeviceToHost);
    for (int i = 0 ; i < N; i++)
        printf("%d \n", A[i]); 
    return 1;
}
