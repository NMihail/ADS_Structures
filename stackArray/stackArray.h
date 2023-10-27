//
// Created by Worker on 25.10.2023.
//

#ifndef ADS_STRUCTURES_STACK_ARRAY_H
#define ADS_STRUCTURES_STACK_ARRAY_H

#include <stdio.h>
#include <stdbool.h>

#define stackArrayOk 0
#define stackArrayEmpty 1
#define stackArrayFull 2
#define stackArraySize 100
extern int stackArrayError;

typedef int baseTypeStackArray;
typedef baseTypeStackArray stackArray_[100];

typedef struct stackArray {
    int stackArrayDynamicSize;
    stackArray_ data;
} stackArray;

// Возвращает значение "истина",
// если стек пустой
bool isStackArrayEmpty(stackArray *S);

// Инициализирует стек
// Требует указатель на уже выделенную
// область памяти для стека
bool isStackArrayFull(stackArray *S);

// Очищает стек полностью
void stackArrayFree(stackArray *S);

// Вставляет элемент в стек
void stackArrayPut(stackArray *S, baseTypeStackArray E);

// Получает элемент из стека
void stackArrayGet(stackArray *S, baseTypeStackArray *G);

#endif //ADS_STRUCTURES_STACK_ARRAY_H
