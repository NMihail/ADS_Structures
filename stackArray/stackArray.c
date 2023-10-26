//
// Created by Worker on 25.10.2023.
//

#include "stackArray.h"

bool isStackArrayEmpty(stackArray *S) {
    return !S->stackArrayDynamicSize;
}

bool isStackArrayFull(stackArray *S) {
    return S->stackArrayDynamicSize == stackArraySize;
}

void stackArrayFree(stackArray *S) {
    S->stackArrayDynamicSize = 0;
}

void stackArrayPut(stackArray *S, baseTypeStackArray E) {
    if (isStackArrayFull(S)) {
        stackArrayError = stackArrayFull;
    } else {
        S->data[S->stackArrayDynamicSize] = E;
        S->stackArrayDynamicSize++;
        stackArrayError = stackArrayOk;
    }
}

void stackArrayGet(stackArray *S, baseTypeStackArray *G) {
    if (isStackArrayEmpty(S)) {
        stackArrayError = stackArrayEmpty;
    } else {
        *G = S->data[S->stackArrayDynamicSize];
        S->stackArrayDynamicSize--;
        stackArrayError = stackArrayOk;
    }
}