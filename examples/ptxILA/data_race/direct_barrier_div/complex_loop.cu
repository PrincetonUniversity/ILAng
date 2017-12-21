__global__ void simple_loop(int *a, int size) {
    int tid = threadIdx.x;
    for (int i = 0; i < size; i++) {
        a[tid * 3] += a[tid * 3 + i];
    }
}
