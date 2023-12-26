//
// Created by Worker on 25.10.2023.
//

#include "stackList.h"

bool isStackListEmpty(stackList *S) {
    return isListEmpty(S);
}

void stackListInit(stackList *S) {
    listInit(&S);
    stackListError = listError;
}

void stackListFree(stackList *S) {
    freeList(&S);
}

void stackListPut(stackList *S, elementStackList *E) {
    listPutAfterPtr(S, E);
    stackListError = listError;
}

void stackListGet(stackList *S, elementStackList **G) {
    listGetIntoPtr(S, G);
    stackListError = listError;
}