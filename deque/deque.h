//
// Created by Worker on 26.10.2023.
//

#ifndef ADS_STRUCTURES_DEQUE_H
#define ADS_STRUCTURES_DEQUE_H

#include "../doubleLinkedList/doubleLinkedList.h"

#define DeqOk DListOk
#define DeqEmpty DListEmpty
#define DeqStart DListStart
#define DeqEnd DListEnd
#define DeqNotMem DListNotMem

extern int DeqError;

typedef baseTypeDList baseTypeDeq;
typedef elementDList elementDeq;
typedef DList Deq;

// Предикат пустоты дека D
bool isDeqEmpty(DList *D);

// Предикат нахождения рабочего
// указателя в начале дека D
bool isDeqStart(DList *D);

// Предикат конца дека D
bool isDeqEnd(DList *D);

// Передвинуть рабочий указатель
// s - start, e = end
void DeqMove(DList *D, char pos);

// Инициализация пустого дека D
void DeqInit(DList **D);

// Вставить элемент, хранящийся по указателю E
// в дек D после рабочего указателя
void DeqPutStart(DList *D, elementDList *E);

// Вставить элемент, хранящийся по указателю E
// в дек D до рабочего указателя
void DeqPutEnd(DList *D, elementDList *E);

// Элемент полностью не очищается, он храниться
// по указателю G, но доступа к нему через
// дек D уже нет
void DeqGetStart(DList *D, elementDList **G);

// Элемент полностью не очищается, он храниться
// по указателю G, но доступа к нему через
// дек D уже нет
void DeqGetEnd(DList *D, elementDList **G);

// Полное очищение дека D
void freeDeq(DList **D);

#endif //ADS_STRUCTURES_DEQUE_H
