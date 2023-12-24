//
// Created by Worker on 24.12.2023.
//

#include "singleLinkedLinearListCycled.h"

// Предикат пустоты списка L
bool isListEmptyCycled(listCycled *L) {
    return L->L == NULL;
}

// Предикат нахождения рабочего
// указателя в начале ОЛС
bool isListStartCycled(listCycled *L) {
    return L->L == L->ptr;
}

// Предикат конца списка L
bool isListEndCycled(listCycled *L) {
    return L->ptr->linkNext == L->L;
}

// Инициализация пустого списка L
void listInitCycled(listCycled **L) {
    *L = (listCycled *)malloc(sizeof(listCycled));
    if (*L == NULL) {
        listCycledError = listCycledNotMem;
        return;
    }

    (*L)->L = NULL;
    (*L)->ptr = NULL;
    (*L)->N = 0;
}

// Передвинуть рабочий указатель на след. эл.
// s - start, e = end, n - next elementDList
void listMoveCycled(listCycled *L, char pos) {
    switch (pos) {
        case 's':
            L->ptr = L->L;
            listCycledError = listCycledOk;
            break;
        case 'e':
            while (L->ptr->linkNext != NULL) {
                L->ptr = L->ptr->linkNext;
            }

            listCycledError = listCycledOk;

            break;
        case 'n':
            L->ptr = L->ptr->linkNext;
            listCycledError = listCycledOk;

            break;
        default:
            printf("Рабочий указатель не был передвинут, т.к. не правильно "
                   "введена позиция, на которую надо передвинуть рабочий указатель.");
    }
}

// Вставить элемент, хранящийся по указателю E
// в список L после рабочего указателя
void listPutAfterPtrCycled(listCycled *L, elementListCycled *E) {
    if (isListEmptyCycled(L)) {
        L->L = E;
        L->L->linkNext = L->L;
        L->ptr = E;
        listCycledError = listCycledOk;
    } else if (isListEndCycled(L)) {
        L->ptr->linkNext = E;
        E->linkNext = L->L;
        L->ptr = E;
        listCycledError = listCycledOk;
    } else {
        E->linkNext = L->ptr->linkNext;
        L->ptr->linkNext = E;
        listCycledError = listCycledOk;
    }

    L->N++;
}

// Вставить элемент, хранящийся по указателю E
// в список L до рабочего указателя
void listPutBeforePtrCycled(listCycled *L, elementListCycled *E) {
    if (isListEmptyCycled(L)) {
        L->L = E;
        L->L->linkNext = L->L;
        L->ptr = E;
    } else if (isListStartCycled(L)) {
        L->L = E;
        E->linkNext = L->ptr;
        L->ptr = E;
    } else {
        elementListCycled *pntr = L->L;
        while (pntr->linkNext != L->ptr) {
            pntr = pntr->linkNext;
        }

        pntr->linkNext = E;
        E->linkNext = L->ptr;
    }

    listCycledError = listCycledOk;
    L->N++;
}

// Элемент полностью не очищается, он храниться
// по указателю G, но доступа к нему через
// список L уже нет
void listGetIntoPtrCycled(listCycled *L, elementListCycled **G) {
    if (isListEmptyCycled(L)) {
        listCycledError = listCycledEmpty;
    } else if (L->L->linkNext == L->L) {
        *G = L->ptr;
        L->L = NULL;
        L->ptr = NULL;
    } else if (isListStartCycled(L)) {
        *G = L->ptr;
        L->L = L->L->linkNext;
        L->ptr = L->ptr->linkNext;
    } else {
        *G = L->ptr;

        elementListCycled *pntr = L->L;
        while (pntr->linkNext != L->ptr) {
            pntr = pntr->linkNext;
        }

        L->ptr = pntr;
        pntr->linkNext = (*G)->linkNext;
    }

    listCycledError = listCycledOk;
    L->N--;
}

// Полное очищение списка L
void freeListCycled(listCycled **L) {
    elementListCycled *buffer;
    elementListCycled *start = (*L)->L;
    (*L)->ptr = (*L)->L;
    buffer = (*L)->ptr->linkNext;
    free((*L)->ptr->data);
    free((*L)->ptr);
    (*L)->ptr = buffer;
    while (buffer != start) {
        buffer = (*L)->ptr->linkNext;
        free((*L)->ptr->data);
        free((*L)->ptr);
        (*L)->ptr = buffer;
    }

    (*L)->L = NULL;
    (*L)->ptr = NULL;

    free(*L);

    *L = NULL;

    listCycledError = listCycledOk;
}