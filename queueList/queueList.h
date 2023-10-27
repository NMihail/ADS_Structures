//
// Created by Worker on 26.10.2023.
//

#ifndef ADS_STRUCTURES_QUEUE_LIST_H
#define ADS_STRUCTURES_QUEUE_LIST_H

#include "../singleLinkedLinearList/singleLinkedLinearList.h"

#define queueListOk listOk
#define queueListEmpty listEmpty
#define queueListNotMem listNotMem
extern int queueListError;

typedef elementList elementQueueList;
typedef list queueList;

// Возвращает значение "истина",
// если очередь пуста
bool isQueueListEmpty(queueList *Q);

// Инициализирует очередь
// Требует указатель на уже выделенную
// область памяти для очереди
void queueListInit(queueList *Q);

// Очищает очередь полностью
void queueListFree(queueList *Q);

// Вставляет элемент в очередь
void queueListPut(queueList *Q, elementQueueList *E);

// Получает элемент из очереди
void queueListGet(queueList *Q, elementQueueList **G);

#endif //ADS_STRUCTURES_QUEUE_LIST_H
