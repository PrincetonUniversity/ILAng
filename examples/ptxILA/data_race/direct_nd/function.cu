__device__ int test(int tid) {
    tid += 1;
    __syncthreads();
    return tid;
}

__global__ void tfunction(int* A) {
    int tid = threadIdx.x;
    A[tid] = test(tid);
    
}
