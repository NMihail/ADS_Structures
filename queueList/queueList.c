//
// Created by Worker on 26.10.2023.
//

#include "queueList.h"
bool isQueueListEmpty(queueList *Q) {
    return isListEmpty(Q);
}

void queueListPut(queueList *Q, elementQueueList *E) {
    listMove(Q, 'e');
    listPutAfterPtr(Q, E);
    queueListError = listError;
}

void queueListGet(queueList *Q, elementQueueList **G) {
    listMove(Q, 's');
    listGetIntoPtr(Q, G);
    queueListError = listError;
}