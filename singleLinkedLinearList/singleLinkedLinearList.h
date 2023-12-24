//
// Created by Worker on 24.10.2023.
//

#ifndef ADS_STRUCTURES_SINGLE_LINKED_LINEAR_LIST_H
#define ADS_STRUCTURES_SINGLE_LINKED_LINEAR_LIST_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#define listOk 0
#define listEmpty 1
#define listNotMem 2
#define listEnd 3
extern int listError;

// typedef int baseTypeList;
// typedef baseTypeList * elPtrList;

typedef void * baseTypeList;

// Дескриптор элемента списка L
typedef struct elementList {
    baseTypeList data;
    struct elementList *linkNext;
} elementList;

// Дескриптор списка L
typedef struct list {
    elementList *L;
    elementList *ptr;
    int N;
} list;

// Предикат пустоты списка L
bool isListEmpty(list *L);

// Предикат нахождения рабочего
// указателя в начале ОЛС
bool isListStart(list *L);

// Предикат конца списка L
bool isListEnd(list *L);

// Инициализация пустого списка L
void listInit(list **L);

// Передвинуть рабочий указатель на след. эл.
// s - start, e = end, n - next elementDList
void listMove(list *L, char pos);

// Вставить элемент, хранящийся по указателю E
// в список L после рабочего указателя
void listPutAfterPtr(list *L, elementList *E);

// Вставить элемент, хранящийся по указателю E
// в список L до рабочего указателя
void listPutBeforePtr(list *L, elementList *E);

// Элемент полностью не очищается, он храниться
// по указателю G, но доступа к нему через
// список L уже нет
void listGetIntoPtr(list *L, elementList **G);

// Полное очищение списка L
void freeList(list **L);

#endif //ADS_STRUCTURES_SINGLE_LINKED_LINEAR_LIST_H
