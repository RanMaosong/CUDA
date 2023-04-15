#include <cuda_runtime.h>
#include <stdio.h>

int main(int arg, char **argv) {
    int nElem = 1024;
    dim3 block(1024);
    dim3 grid((nElem - 1) / block.x + 1);
    printf("grid.x %d block.x %d\n", grid.x, block.x);

    block.x = 512;
    grid.x = (nElem - block.x) / block.x;
    printf("grid.x %d block.x %d\n", grid.x, block.x);


    cudaDeviceReset();

    return 0;

}