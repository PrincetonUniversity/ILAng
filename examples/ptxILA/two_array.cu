__global__ void two_threads(int *A, int *B) {
    int tid = threadIdx.x;
    A[tid] += B[tid];
}
