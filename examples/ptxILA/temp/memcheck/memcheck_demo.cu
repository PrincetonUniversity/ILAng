#include <stdio.h> 
__device__ int x; 
__global__ void unaligned_kernel(void) { *(int*) ((char*)&x + 1) = 42; } 
__device__ void out_of_bounds_function(void) { *(int*) 0x87654320 = 42; } 
__global__ void out_of_bounds_kernel(void) { out_of_bounds_function(); } 

void run_unaligned(void) { printf("Running unaligned_kernel\n"); unaligned_kernel<<<1,1>>>(); printf("Ran unaligned_kernel: %s\n", cudaGetErrorString(cudaGetLastError())); printf("Sync: %s\n", cudaGetErrorString(cudaThreadSynchronize())); } 

void run_out_of_bounds(void) { printf("Running out_of_bounds_kernel\n"); out_of_bounds_kernel<<<1,1>>>(); printf("Ran out_of_bounds_kernel: %s\n", cudaGetErrorString(cudaGetLastError())); printf("Sync: %s\n", cudaGetErrorString(cudaThreadSynchronize())); } 

int main() { int *devMem; printf("Mallocing memory\n"); cudaMalloc((void**)&devMem, 1024); run_unaligned(); run_out_of_bounds(); cudaDeviceReset(); cudaFree(devMem); return 0; }

