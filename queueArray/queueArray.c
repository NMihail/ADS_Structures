//
// Created by Worker on 26.10.2023.
//

#include "queueArray.h"

void QueueArrayInit(queueArray *Q) {
    Q->queueArrayDynamicSize = 0;
}

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
        *G = Q->data[0];
        Q->queueArrayDynamicSize--;
        for (int i = 1; i < Q->queueArrayDynamicSize; i++) {
            Q->data[i - 1] = Q->data[i];
        }
        queueArrayError = queueArrayOk;
    }
}