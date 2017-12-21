__global__ void branch(int *A){
    int tid = threadIdx.x;
    if ((tid % 2) == 1) {
        int a = A[tid + 2];
        __syncthreads();
        A[tid] += a;
    }
}
