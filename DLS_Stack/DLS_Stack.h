//
// Created by Worker on 24.12.2023.
//

#ifndef ADS_STRUCTURES_DLS_STACK_H
#define ADS_STRUCTURES_DLS_STACK_H

#include "../stackList/stackList.h"

#define DLS_StackOk 0
#define DLS_StackEmpty 1
#define DLS_StackNotMem 2
#define DLS_StackUnder 3

extern int DLS_StackError;

typedef struct DLS_Stack {
    stackList L;
    stackList R;
    elementStackList *current;
    int size;
} DLS_Stack;

void DLS_StackInit(DLS_Stack *D);

bool isDLS_StackEmpty(DLS_Stack *D);

void DLS_StackBeginPtr(DLS_Stack *D);

void DLS_StackEndPtr(DLS_Stack *D);

void DLS_StackPutBeforeCurrent(DLS_Stack *D, elementStackList *E);

void DLS_StackPutAfterCurrent(DLS_Stack *D, elementStackList *E);

void DLS_StackGetBeforeCurrent(DLS_Stack *D, elementStackList **G);

void DLS_StackGetAfterCurrent(DLS_Stack *D, elementStackList **G);

void DLS_StackMoveCurrentLeft(DLS_Stack *D);

void DLS_StackMoveCurrentRight(DLS_Stack *D);

void DLS_StackGetCurrent(DLS_Stack *D, elementStackList **G);

void DLS_StackReadCurrent(DLS_Stack *D, elementStackList **G);

#endif //ADS_STRUCTURES_DLS_STACK_H
