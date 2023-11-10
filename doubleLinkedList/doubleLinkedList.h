//
// Created by Worker on 26.10.2023.
//

#ifndef ADS_STRUCTURES_DOUBLELINKEDLIST_H
#define ADS_STRUCTURES_DOUBLELINKEDLIST_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#define DListOk 0
#define DListEmpty 1
#define DListStart 2
#define DListEnd 3
#define DListNotMem 4

extern int DListError;

typedef void * baseTypeDList;

typedef struct elementDList {
    baseTypeDList data;
    struct elementDList *next;
    struct elementDList *prev;
} elementDList;

typedef struct DList {
    elementDList *start;
    elementDList *ptr;
    elementDList *end;
} DList;

// Предикат пустоты списка L
bool isDListEmpty(DList *D);

bool isDListStart(DList *D);

// Предикат конца списка L
bool isDListEnd(DList *D);

// Передвинуть рабочий указатель на след. эл.
// s - start, e = end, n - next, p - previous
void DListMove(DList *D, char pos);

// Инициализация пустого списка L
void DListInit(DList **D);

// Вставить элемент, хранящийся по указателю E
// в список L после рабочего указателя
void DListPutAfterPtr(DList *D, elementDList *E);

// Вставить элемент, хранящийся по указателю E
// в список L до рабочего указателя
void DListPutBeforePtr(DList *D, elementDList *E);

// Элемент полностью не очищается, он храниться
// по указателю G, но доступа к нему через
// список L уже нет
void DListGetIntoPtr(DList *D, elementDList **G);

// Элемент полностью не очищается, он храниться
// по указателю G, но доступа к нему через
// список L уже нет
void DListGetAfterPtr(DList *D, elementDList **G);

// Полное очищение списка L
void freeDList(DList **D);



#endif //ADS_STRUCTURES_DOUBLELINKEDLIST_H
