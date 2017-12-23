__global__ void simple_loop(int *a) {
    int tid = threadIdx.x;
    for (int i = 0; i < 5; i++) {
        a[tid * 4] += a[tid * 4 + i];
    }
}
