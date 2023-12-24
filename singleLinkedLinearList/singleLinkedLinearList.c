//
// Created by Worker on 24.10.2023.
//


#include "singleLinkedLinearList.h"

bool isListEmpty(list *L) {
    return L->L == NULL;
}

bool isListStart(list *L) {
    return L->L == L->ptr;
}

bool isListEnd(list *L) {
    return L->ptr->linkNext == NULL;
}

void listInit(list **L) {
    *L = (list *)malloc(sizeof(list));
    if (*L == NULL) {
        listError = listNotMem;
        return;
    }

    (*L)->L = NULL;
    (*L)->ptr = NULL;
    (*L)->N = 0;
}

void listMove(list *L, char pos) {
    switch (pos) {
        case 's':
            L->ptr = L->L;
            listError = listOk;
            break;
        case 'e':
            while (L->ptr->linkNext != NULL) {
                L->ptr = L->ptr->linkNext;
            }

            listError = listOk;

            break;
        case 'n':
            if (isListEnd(L)) {
                listError = listEnd;
            } else {
                L->ptr = L->ptr->linkNext;
                listError = listOk;
            }

            break;
        default:
            printf("Рабочий указатель не был передвинут, т.к. не правильно "
                   "введена позиция, на которую надо передвинуть рабочий указатель.");
    }
}

void listPutAfterPtr(list *L, elementList *E) {
    if (isListEmpty(L)) {
        L->L = E;
        L->L->linkNext = NULL;
        L->ptr = E;
        listError = listOk;
    } else if (isListEnd(L)) {
        L->ptr->linkNext = E;
        E->linkNext = NULL;
        L->ptr = E;
        listError = listOk;
    } else {
        E->linkNext = L->ptr->linkNext;
        L->ptr->linkNext = E;
        listError = listOk;
    }

    L->N++;
}

void listPutBeforePtr(list *L, elementList *E) {
    if (isListEmpty(L)) {
        L->L = E;
        L->L->linkNext = NULL;
        L->ptr = E;
    } else if (isListStart(L)) {
        L->L = E;
        E->linkNext = L->ptr;
        L->ptr = E;
    } else {
        elementList *pntr = L->L;
        while (pntr->linkNext != L->ptr) {
            pntr = pntr->linkNext;
        }

        pntr->linkNext = E;
        E->linkNext = L->ptr;
        L->ptr = E;
    }

    listError = listOk;
    L->N++;
}

void listGetIntoPtr(list *L, elementList **G) {
    if (isListEmpty(L)) {
        listError = listEmpty;
    } else if (L->L->linkNext == NULL) {
        *G = L->ptr;
        L->L = NULL;
        L->ptr = NULL;
    } else if (isListStart(L)) {
        *G = L->ptr;
        L->L = L->L->linkNext;
        L->ptr = L->ptr->linkNext;
    } else {
        *G = L->ptr;

        elementList *pntr = L->L;
        while (pntr->linkNext != L->ptr) {
            pntr = pntr->linkNext;
        }

        L->ptr = pntr;
        pntr->linkNext = (*G)->linkNext;
    }

    listError = listOk;
    L->N--;
}

void freeList(list **L) {
    elementList *buffer = (*L)->L;
    (*L)->ptr = (*L)->L;
    while (buffer != NULL) {
        buffer = (*L)->ptr->linkNext;
        free((*L)->ptr->data);
        free((*L)->ptr);
        (*L)->ptr = buffer;
    }

    (*L)->L = NULL;
    (*L)->ptr = NULL;

    free(*L);

    *L = NULL;

    listError = listOk;
}
