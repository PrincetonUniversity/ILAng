__global__ void f(int * A, int *B) {

    int tid = threadIdx.x;
    int diff = (B - A);

    int x = B[tid];
    int y = A[tid + diff - 1];

    B[tid] = x + y;

}

