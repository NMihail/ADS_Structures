//
// Created by Worker on 26.10.2023.
//

#ifndef ADS_STRUCTURES_QUEUE_LIST_H
#define ADS_STRUCTURES_QUEUE_LIST_H

#include "../singleLinkedLinearList/singleLinkedLinearList.h"

const int queueListOk = listOk;
const int queueListEmpty = 1;
const int queueListNotMem = listNotMem;
extern int queueListError;

typedef elementList elementQueueList;
typedef list queueList;

bool isQueueListEmpty(queueList *Q);

void queueListPut(queueList *Q, elementQueueList *E);

void queueListGet(queueList *Q, elementQueueList **G);

#endif //ADS_STRUCTURES_QUEUE_LIST_H
