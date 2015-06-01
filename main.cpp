
//#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "helpers.h"
using namespace std;

//test for CUDA errors
#define CUDA_CHECK(condition) \
  /* Code block avoids redefinition of cudaError_t error */ \
  do { \
    cudaError_t error = condition; \
    CHECK_EQ(error, cudaSuccess) << " " << cudaGetErrorString(error); \
  } while (0)


//vector+vector add on CPU
void vvadd_cpu(float* h_vec1, float* h_vec2, float* h_result, int length){
    for(int i=0; i<length; i++){
        h_result[i] = h_vec1[i] + h_vec2[i];
    }

}

int main (int argc, char **argv)
{
    int length = 10000;
    float* h_vec1 = (float*)malloc( length * sizeof(float));
    float* h_vec2 = (float*)malloc( length * sizeof(float));
    float* h_result = (float*)malloc( length * sizeof(float));

    //fill with arbitrary data
    for(int i=0; i<length; i++){
        h_vec1[i] = i;
        h_vec2[i] = 1;
    }

    vvadd_cpu(h_vec1, h_vec2, h_result, length);

    //TODO: implement vvadd_gpu()


    //TODO: printouts or tests for whether vector+vector add worked properly

    free(h_vec1);
    free(h_vec2);
    free(h_result);

    return 0;
}
