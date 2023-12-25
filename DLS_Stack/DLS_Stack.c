//
// Created by Worker on 24.12.2023.
//

#include "DLS_Stack.h"

void DLS_StackInit(DLS_Stack *D) {
    stackListInit(&D->L);
    stackListInit(&D->R);
    DLS_StackError = stackListError;
    D->size = 0;
}

bool isDLS_StackEmpty(DLS_Stack *D) {
    return !D->size;
}

void DLS_StackBeginPtr(DLS_Stack *D) {
    D->ptr = D->L.L;
}

void DLS_StackEndPtr(DLS_Stack *D) {
    D->ptr= D->R.L;
}

void DLS_StackPutLeft(DLS_Stack *D, elementStackList *E) {
    stackListPut(&D->L, E);
    DLS_StackError = stackListError;
}

void DLS_StackPutRight(DLS_Stack *D, elementStackList *E) {
    stackListPut(&D->R, E);
    DLS_StackError = stackListError;
}

void DLS_StackGetLeft(DLS_Stack *D, elementStackList **G) {
    stackListGet(&D->L, G);
    DLS_StackError = stackListError;
}

void DLS_StackGetRight(DLS_Stack *D, elementStackList **G) {
    stackListGet(&D->R, G);
    DLS_StackError = stackListError;
}

void DLS_StackMovePtr(DLS_Stack *D) {
    D->ptr = D->ptr->linkNext;
    DLS_StackError = DLS_StackOk;
}

void DLS_StackReadPtr(DLS_Stack *D, elementStackList **G) {
    *G = D->ptr;
    DLS_StackError = DLS_StackOk;
}