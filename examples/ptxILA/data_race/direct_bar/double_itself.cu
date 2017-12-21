__global__ void double_itself(int* A) {
    int tid = threadIdx.x; 
    A[tid] += A[tid];
}
