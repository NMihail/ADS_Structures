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
    D->current = D->L.L;
}

void DLS_StackEndPtr(DLS_Stack *D) {
    D->current= D->R.L;
}

void DLS_StackPutBeforeCurrent(DLS_Stack *D, elementStackList *E) {
    stackListPut(&D->L, E);
    DLS_StackError = stackListError;
}

void DLS_StackPutAfterCurrent(DLS_Stack *D, elementStackList *E) {
    stackListPut(&D->R, E);
    DLS_StackError = stackListError;
}

void DLS_StackGetBeforeCurrent(DLS_Stack *D, elementStackList **G) {
    stackListGet(&D->L, G);

    if (stackListError == stackListEmpty) {
        DLS_StackError = DLS_StackUnder;
    } else {
        D->size--;
        DLS_StackError = stackListError;
    }
}

void DLS_StackGetAfterCurrent(DLS_Stack *D, elementStackList **G) {
    stackListGet(&D->R, G);

    if (stackListError == stackListEmpty) {
        DLS_StackError = DLS_StackUnder;
    } else {
        D->size--;
        DLS_StackError = stackListError;
    }
}

void DLS_StackMoveCurrentLeft(DLS_Stack *D) {
    if (D->L.N == 0) {
        DLS_StackError = DLS_StackUnder;
        return;
    }

    stackListPut(&D->R, D->current);
    stackListGet(&D->L, &D->current);
    D->size--;
    DLS_StackError = stackListError;
}

void DLS_StackMoveCurrentRight(DLS_Stack *D) {
    if (D->R.N == 0) {
        DLS_StackError = DLS_StackUnder;
        return;
    }

    stackListPut(&D->L, D->current);
    stackListGet(&D->R, &D->current);
    D->size--;
    DLS_StackError = stackListError;
}

void DLS_StackGetCurrent(DLS_Stack *D, elementStackList **G) {
    *G = D->current;
    if (D->L.N) {
        stackListGet(&D->L, &D->current);
        D->size--;
    } else if (D->R.N) {
        stackListGet(&D->R, &D->current);
        D->size--;
    } else {
        D->size = 0;
        DLS_StackError = DLS_StackEmpty;
        return;
    }

    DLS_StackError = DLS_StackOk;
}

void DLS_StackReadCurrent(DLS_Stack *D, elementStackList **G) {
    *G = D->current;
    DLS_StackError = DLS_StackOk;
}
