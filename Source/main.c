#include<stdio.h>
#include"Vector.h"

int main(){
    printf("Hello World\n");
    struct Vector vec;
    vec.size = 0;
    vec.values = NULL;

    int sampleInputSize = 100000;
    /*

    printf("===========Testing push_back===========\n");

    for(int i = 0; i < sampleInputSize; i++)
    {
        struct Input sample;
        sample.value = i;
        push_back(&vec, sample);
    }

    printf("testing push_back");

    if(vec.values[5000].value != 5000)
    {
        printf("Expected a value of 5000 at index 5000, got %d\n", vec.values[5000].value);
    }
    else
    {
        printf("test passed\n");
    } */

/*
    printf("\n\n===========Testing push===========\n");
    for(int i = 0; i < sampleInputSize; i++)
    {
        struct Input sample;
        sample.value = i;
        push(&vec, sample, 0);
    }

    printf("done testing push\n");


    if(vec.values[sampleInputSize - 1].value != 0)
    {
        printf("Expected a value of 0 at index %d, got %d\n", sampleInputSize - 1, vec.values[sampleInputSize - 1].value);
    }
    else
    {
        printf("test passed\n");
    }*/

    printf("\n\n===========Testing push_multiple===========\n");
    for(int i = 0; i < sampleInputSize/10; i++)
    {
        struct Input sample[10];
        sample[0].value = i;
        push_multiple(&vec, sample, 10, 0);
    }

    printf("done testing push_multiple\n");


    if(vec.values[10 * 10].value != 10)
    {
        printf("Expected a value of 10 at index %d, got %d\n", 10 * 10, vec.values[10 * 10].value);
    }
    else
    {
        printf("test passed\n");
    }


    return 0;
}