#ifndef HEADER_H
#define HEADER_H


#include <time.h>
#ifdef _WIN32
#	include <windows.h>
#else
#	include <sys/time.h>
#endif


#define CHECK(call)  \
{ \
    const cudaError_t error = call;\
    if (error != cudaSuccess) \
    {\
        printf("Error: %s:%d", __FILE__, __LINE__);\
        printf("code:%d, reason: %s", error, cudaGetErrorString(error));\
    }\
}\


void initialDta(float *ip, int size) {
    time_t t;
    srand((unsigned)time(&t));

    for (int i=0; i<size; ++i) {
        ip[i] = int(rand()&0xff);
    }
}


void checkResult(float *hostRef, float *gpuRef, const int N) {
    double epsilon = 1.0E-8;
    for (int i=0; i<N; i++) {
        if (abs(hostRef[i] - gpuRef[i]) > epsilon) {
            printf("Result don\'t match!\n");
            printf("%f(hostRef[%d] != %f(gpuRef[%d])\n", hostRef[i], i, gpuRef[i], i);
            return;
        }
    }

    printf("Check result success!\n");
}


#endif