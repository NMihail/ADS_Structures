//
// Created by Worker on 26.10.2023.
//

#include "queueArray.h"

bool isQueueArrayEmpty(queueArray *Q) {
    return !Q->queueArrayDynamicSize;
}

bool isQueueArrayFull(queueArray *Q) {
    return Q->queueArrayDynamicSize == queueArraySize;
}

void queueArrayFree(queueArray *Q) {
    Q->queueArrayDynamicSize = 0;
}

void queueArrayPut(queueArray *Q, baseTypeQueueArray E) {
    if (isQueueArrayFull(Q)) {
        queueArrayError = queueArrayFull;
    } else {
        Q->data[Q->queueArrayDynamicSize] = E;
        Q->queueArrayDynamicSize++;
        queueArrayError = queueArrayOk;
    }
}

void queueArrayGet(queueArray *Q, baseTypeQueueArray *G) {
    if (isQueueArrayEmpty(Q)) {
        queueArrayError = queueArrayEmpty;
    } else {
        *G = Q->data[Q->queueArrayDynamicSize];
        Q->queueArrayDynamicSize--;
        queueArrayError = queueArrayOk;
    }
}