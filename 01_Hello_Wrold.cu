#include "iostream"

__global__ void sayHelloWorld();

int main(){

    printf("HelloWorld! CPU \n");
    sayHelloWorld<<<2, 1>>>();

    cudaDeviceReset();

    system("pause");
    return 0;
}

__global__ void sayHelloWorld(){
    printf("HelloWorld! GPU \n");
}