//
// Created by Worker on 24.12.2023.
//

#ifndef ADS_STRUCTURES_DLS_STACK_H
#define ADS_STRUCTURES_DLS_STACK_H

#include "../stackList/stackList.h"

#define DLS_StackOk 0
#define DLS_StackEmpty 1
#define DLS_StackNotMem 2

extern int DLS_StackError;

typedef struct DLS_Stack {
    stackList L;
    stackList R;
    elementStackList *ptr;
    int size;
} DLS_Stack;

void DLS_StackInit(DLS_Stack *D);

bool isDLS_StackEmpty(DLS_Stack *D);

void DLS_StackBeginPtr(DLS_Stack *D);

void DLS_StackEndPtr(DLS_Stack *D);

void DLS_StackPutLeft(DLS_Stack *D, elementStackList *E);

void DLS_StackPutRight(DLS_Stack *D, elementStackList *E);

void DLS_StackGetLeft(DLS_Stack *D, elementStackList **G);

void DLS_StackGetRight(DLS_Stack *D, elementStackList **G);

void DLS_StackMovePtr(DLS_Stack *D);

void DLS_StackReadPtr(DLS_Stack *D, elementStackList **G);

#endif //ADS_STRUCTURES_DLS_STACK_H
