//
// Created by Worker on 24.12.2023.
//

#ifndef ADS_STRUCTURES_SINGLELINKEDLINEARLISTCYCLED_H
#define ADS_STRUCTURES_SINGLELINKEDLINEARLISTCYCLED_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#define listCycledOk 0
#define listCycledEmpty 1
#define listCycledNotMem 2
#define listCycledEnd 3
extern int listCycledError;

typedef void * baseTypeListCycled;

// Дескриптор элемента списка L
typedef struct elementListCycled {
    baseTypeListCycled data;
    struct elementListCycled *linkNext;
} elementListCycled;

// Дескриптор списка L
typedef struct listCycled {
    elementListCycled *L;
    elementListCycled *ptr;
    int N;
} listCycled;

// Предикат пустоты списка L
bool isListEmptyCycled(listCycled *L);

// Предикат нахождения рабочего
// указателя в начале ОЛС
bool isListStartCycled(listCycled *L);

// Предикат конца списка L
bool isListEndCycled(listCycled *L);

// Инициализация пустого списка L
void listInitCycled(listCycled **L);

// Передвинуть рабочий указатель на след. эл.
// s - start, e = end, n - next elementDList
void listMoveCycled(listCycled *L, char pos);

// Вставить элемент, хранящийся по указателю E
// в список L после рабочего указателя
void listPutAfterPtrCycled(listCycled *L, elementListCycled *E);

// Вставить элемент, хранящийся по указателю E
// в список L до рабочего указателя
void listPutBeforePtrCycled(listCycled *L, elementListCycled *E);

// Элемент полностью не очищается, он храниться
// по указателю G, но доступа к нему через
// список L уже нет
void listGetIntoPtrCycled(listCycled *L, elementListCycled **G);

// Полное очищение списка L
void freeListCycled(listCycled **L);

#endif //ADS_STRUCTURES_SINGLELINKEDLINEARLISTCYCLED_H
