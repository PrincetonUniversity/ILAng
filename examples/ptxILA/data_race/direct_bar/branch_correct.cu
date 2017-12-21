__global__ void branch(int *A) {
    int tid = threadIdx.x;
    if ((tid % 2) == 1) {
        A[tid] += A[tid + 1];
    }
}
