//
// Created by Worker on 24.10.2023.
//


#include "singleLinkedLinearList.h"

bool isListEmpty(list *L) {
    return L->L == NULL;
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
}

void getMemToElement(elementList **E) {
    *E = (elementList *) malloc(sizeof(elementList));
    if (*E == NULL) {
        listError = listNotMem;
        return;
    }

    (*E)->data = (elPtrList) malloc(sizeof(baseTypeList));
    if ((*E)->data == NULL) {
        listError = listNotMem;
        return;
    }

    (*E)->linkNext = NULL;

    listError = listOk;
}

void freeMemToElement(elementList *E, elementList **next) {
    *next = E->linkNext;
    free(E->data);
    free(E);
}

void listMove(list *L, char pos) {
    if (isListEnd(L)) {
        listError = listEnd;
    } else if (pos == 'n') {
        L->ptr = L->ptr->linkNext;
    } else if (pos == 's') {
        L->ptr = L->L;
    } else if (pos == 'e') {
        while (L->ptr->linkNext != NULL) {
            L->ptr = L->ptr->linkNext;
        }
    } else {
        freeList(L);
        exit(1);
    }
}

void listPutAfterPtr(list *L, elementList *E) {
    if (isListEmpty(L)) {
        L->L = E;
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
        L->ptr = E;
        listError = listOk;
    }
}

void listPutBeforePtr(list *L, elementList *E) {
    if (isListEmpty(L)) {
        L->L = E;
        L->ptr = E;
        L->N++;
        listError = listOk;
    } else if (L->L == L->ptr) {
        L->L = E;
        E->linkNext = L->ptr;
        L->ptr = E;
        listError = listOk;
    } else {
        elementList *pntr = L->L;
        while (pntr->linkNext != L->ptr) {
            pntr = pntr->linkNext;
        }

        pntr->linkNext = E;
        E->linkNext = L->ptr;
        L->ptr = E;
        listError = listOk;
    }
}

void listGetIntoPtr(list *L, elementList **G) {
    if (isListEmpty(L)) {
        listError = listEmpty;
    } else if (L->L->linkNext == NULL) {
        *G = L->ptr;
        L->N--;

        L->L = NULL;
        L->ptr = NULL;
        listError = listOk;
    } else if (L->L == L->ptr) {
        *G = L->ptr;
        L->L = L->L->linkNext;
        L->ptr = L->ptr->linkNext;
        L->N--;
        listError = listOk;
    } else {
        *G = L->ptr;

        elementList *pntr = L->L;
        while (pntr->linkNext != L->ptr) {
            pntr = pntr->linkNext;
        }

        L->ptr = pntr;
        pntr->linkNext = (*G)->linkNext;
        L->N--;

        listError = listOk;
    }
}

void listGetAfterPtr(list *L, elementList **G) {
    if (isListEmpty(L)) {
        listError = listEmpty;
    } else if (isListEnd(L)) {
        listError = listEnd;
    } else {
        *G = L->ptr->linkNext;
        L->ptr->linkNext = (*G)->linkNext;
        L->N--;
        listError = listOk;
    }
}

void freeList(list **L) {
    elementList *buffer = (*L)->L;
    (*L)->ptr = (*L)->L;
    while (buffer != NULL) {
        freeMemToElement((*L)->ptr, &buffer);
    }

    (*L)->L = NULL;
    (*L)->ptr = NULL;

    free(*L);

    *L = NULL;

    listError = listOk;
}
