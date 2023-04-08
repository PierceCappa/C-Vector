#ifndef VECTOR_H
#define VECTOR_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Input
{
    int value;
    char* name;
};

struct Vector{

    struct Input* values;

    unsigned long long size;
};


struct Vector createVector(unsigned long long size, struct Input* starterValues);

void push_back(struct Vector *vector, struct Input newValue);

void push(struct Vector *vector, struct Input newValue, unsigned long long index);

void push_multiple(struct Vector *vector, struct Input* newValues, unsigned long long size, unsigned long long startingIndex);



void removeRange(struct Vector *vector, unsigned long long start, unsigned long long end);

struct Input remove_Value(struct Vector *vector, unsigned long long index);

struct Input pop(struct Vector *vector);

//returns 0 if value not found, returns 1 if found
int at(struct Vector* vector, struct Input *input, unsigned long long index);



#endif