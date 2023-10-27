//
// Created by Worker on 26.10.2023.
//

#ifndef ADS_STRUCTURES_QUEUE_ARRAY_H
#define ADS_STRUCTURES_QUEUE_ARRAY_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define queueArrayOk 0
#define queueArrayEmpty 1
#define queueArrayFull 2
#define queueArraySize 100
extern int queueArrayError;

typedef int baseTypeQueueArray;
typedef baseTypeQueueArray queueArray_[100];

typedef struct queueArray {
    int queueArrayDynamicSize;
    queueArray_ data;
} queueArray;

// Возвращает значение "истина",
// если стек пустой
bool isQueueArrayEmpty(queueArray *Q);

// Инициализирует стек
// Требует указатель на уже выделенную
// область памяти для стека
bool isQueueArrayFull(queueArray *Q);

// Очищает стек полностью
void queueArrayFree(queueArray *Q);

// Вставляет элемент в стек
void queueArrayPut(queueArray *Q, baseTypeQueueArray E);

// Получает элемент из стека
void queueArrayGet(queueArray *Q, baseTypeQueueArray *G);

#endif //ADS_STRUCTURES_QUEUE_ARRAY_H
