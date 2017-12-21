__global__ void branch(int *A){
    int tid = threadIdx.x;
    if ((tid % 2) == 1) {
        __syncthreads();
        int a = A[tid + 2];
        A[tid] += a;
    }
}
