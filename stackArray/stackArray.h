//
// Created by Worker on 25.10.2023.
//

#ifndef ADS_STRUCTURES_STACK_ARRAY_H
#define ADS_STRUCTURES_STACK_ARRAY_H

#include <stdio.h>
#include <stdbool.h>

const int stackArrayOk = 0;
const int stackArrayEmpty = 1;
const int stackArrayFull = 2;
const int stackArraySize = 100;
extern int stackArrayError;

typedef int baseTypeStackArray;
typedef baseTypeStackArray stackArray_[stackArraySize];

typedef struct stackArray {
    int stackArrayDynamicSize;
    stackArray_ data;
} stackArray;

bool isStackArrayEmpty(stackArray *S);

bool isStackArrayFull(stackArray *S);

void stackArrayPut(stackArray *S, baseTypeStackArray E);

void stackArrayGet(stackArray *S, baseTypeStackArray *G);

#endif //ADS_STRUCTURES_STACK_ARRAY_H
