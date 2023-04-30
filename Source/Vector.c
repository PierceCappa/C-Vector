#include "Vector.h"



struct Vector createVector(unsigned long long size, struct Input* starterValues)
{
    struct Vector *vec = malloc(sizeof(struct Vector));
    vec->size = 0;
    vec->values = 0;
}

void push_back(struct Vector* vector, struct Input newValue)
{
    struct Input* newVectorValues = malloc(sizeof(struct Input) * (vector->size + 1));
    if(vector->size != 0)
    {
        memcpy(newVectorValues, vector->values, sizeof(struct Input) * (vector->size));
        free(vector->values);
    }
    vector->values = newVectorValues;
    
    vector->values[vector->size] = newValue;
    vector->size = vector->size + 1;
}

void push(struct Vector* vector, struct Input newValue, unsigned long long index)
{
    struct Input* newVectorValues = malloc(sizeof(struct Input) * (vector->size + 1));
    if(vector->size != 0)
    {
        unsigned long long above = vector->size - index + 1;
        unsigned long long below = vector->size - index - 1;
        if(above < vector->size)
        {
            memcpy(newVectorValues + above, vector->values + above, sizeof(struct Input) * (vector->size - above));
        }
        if(below > -1)
        {
            memcpy(newVectorValues + below, vector->values + below, sizeof(struct Input) * (below));
        }
        free(vector->values);
    }
    vector->values = newVectorValues;
    
    vector->values[index] = newValue;
    vector->size = vector->size + 1;
}

void push_multiple(struct Vector* vector, struct Input* newValues, unsigned long long size, unsigned long long startingIndex)
{
    if(startingIndex > vector->size || startingIndex < 0 )
    {
        printf("error %d\n", startingIndex);
        return;
    }

    unsigned long long newVectorSize = sizeof(struct Input) * (vector->size + size);
    unsigned long long oldVectorSize = sizeof(struct Input) * (vector->size);
    struct Input* newVectorValues = malloc(newVectorSize);

    if(vector->size != 0)
    {
        unsigned long long above = vector->size - startingIndex + size + 1;
        unsigned long long below = vector->size - startingIndex - 1;
        if(above < vector->size)
        {
            memcpy(newVectorValues + above, vector->values + above, sizeof(struct Input) * (vector->size - above));
        }
        if(below > -1)
        {
            memcpy(newVectorValues + below, vector->values + below, sizeof(struct Input) * (below));
        }
        free(vector->values);
    }
    memcpy(newValues + startingIndex, newValues, sizeof(struct Input) * size);
    vector->values = newValues;
    vector->size = vector->size + size;



}






void removeRange(struct Vector* vector, unsigned long long start, unsigned long long end)
{
    unsigned long long newVectorSize = vector->size - (end - start);
    memcpy(&(vector[start - 1]), &(vector[end  + 1]), vector->size - end);
    for(unsigned long long i = vector -> size - 1; i > end; i--)
    {
        free(&(vector->values[i]));
    }
    vector ->size = newVectorSize;
}

struct Input remove_Value(struct Vector* vector, unsigned long long index)
{
    struct Input removedValue =  vector->values[index];
    memcpy(&(vector[index - 1]), &(vector[index  + 1]), vector->size - index);
    free(&(vector->values[vector->size - 1]));
    vector ->size--;
    return removedValue;
}

struct Input pop(struct Vector* vector)
{
    struct Input removedValue =  vector->values[0];
    free(&(vector->values[0]));
    vector->values = &(vector->values[1]);
    vector ->size--;
    return removedValue;
}


int at(struct Vector* vector, struct Input *input, unsigned long long index)
{
    if(index >= 0 && index <= vector->size - 1)
    {
        input = &(vector->values[index]);
        return 1;
    }
    return 0;
}