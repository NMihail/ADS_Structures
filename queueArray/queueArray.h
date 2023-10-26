//
// Created by Worker on 26.10.2023.
//

#ifndef ADS_STRUCTURES_QUEUE_ARRAY_H
#define ADS_STRUCTURES_QUEUE_ARRAY_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const int queueArrayOk = 0;
const int queueArrayEmpty = 1;
const int queueArrayFull = 2;
const int queueArraySize = 100;
extern int queueArrayError;

typedef int baseTypeQueueArray;
typedef baseTypeQueueArray queueArray_[queueArraySize];

typedef struct queueArray {
    int stackArrayDynamicSize;
    queueArray_ data;
} queueArray;

// Возвращает значение "истина",
// если стек пустой
bool isStackArrayEmpty(queueArray *Q);

// Инициализирует стек
// Требует указатель на уже выделенную
// область памяти для стека
bool isStackArrayFull(queueArray *Q);

// Очищает стек полностью
void stackArrayFree(queueArray *Q);

// Вставляет элемент в стек
void stackArrayPut(queueArray *Q, baseTypeQueueArray E);

// Получает элемент из стека
void stackArrayGet(queueArray *Q, baseTypeQueueArray *G);

#endif //ADS_STRUCTURES_QUEUE_ARRAY_H
