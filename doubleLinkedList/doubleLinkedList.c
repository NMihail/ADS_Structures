//
// Created by Worker on 26.10.2023.
//

#include "doubleLinkedList.h"

bool isDListEmpty(DList *D) {
    return D->start == NULL;
}

bool isDListStart(DList *D) {
    return D->ptr == D->start;
}

bool isDListEnd(DList *D) {
    return D->ptr == D->end;
}

void DListMove(DList *D, char pos) {
    switch (pos) {
        case 's':
            D->ptr = D->start;
            break;
        case 'e':
            D->ptr = D->end;
            break;
        case 'n':
            D->ptr = D->ptr->next;
            break;
        case 'p':
            D->ptr = D->ptr->prev;
            break;
    }
}

void DListInit(DList **D) {
    *D = (DList *)malloc(sizeof(DList));
    if (*D == NULL) {
        DListError = DListNotMem;
        return;
    }

    (*D)->start = NULL;
    (*D)->ptr = NULL;
}

void DListPutAfterPtr(DList *D, elementDList *E) {
    if (isDListEmpty(D)) {
        E->prev = NULL;
        E->next = NULL;
        D->start = E;
        D->ptr = E;
        D->end = E;
    } else if (isDListEnd(D)) {
        E->prev = D->end;
        E->next = NULL;
        D->end = E;
    } else {
        E->prev = D->ptr;
        E->next = D->ptr->next;
        D->ptr->next = E;
    }

    DListMove(D, 'n');

    DListError = DListOk;
}

void DListPutBeforePtr(DList *D, elementDList *E) {
    if (isDListEmpty(D)) {
        E->prev = NULL;
        E->next = NULL;
        D->start = E;
        D->ptr = E;
        D->end = E;
    } else if (isDListStart(D)) {
        E->prev = NULL;
        E->next = D->start;
        D->start = E;
    } else {
        E->prev = D->ptr;
        E->next = D->ptr->next;
        D->ptr->next = E;
    }

    DListMove(D, 'p');

    DListError = DListOk;
}

void DListGetIntoPtr(DList *D, elementDList **G) {
    *G = D->ptr;

    if (isDListEmpty(D)) {
        DListError = DListEmpty;
        return;
    } else if (isDListStart(D) && isDListEnd(D)) {
        D->start = NULL;
        DListMove(D, 's');
        D->end = NULL;
    } else if (isDListStart(D)) {
        D->start = D->start->next;
        D->ptr = D->start->next;
    } else if (isDListEnd(D)) {
        D->end = D->end->prev;
        D->ptr = D->end->prev;
    } else {
        D->ptr->prev->next = D->ptr->next;
        D->ptr->next->prev = D->ptr->prev;
        DListMove(D, 'n');
    }

    DListError = DListOk;
}

void freeDList(DList **D) {
    elementDList *buffer = (*D)->start;
    (*D)->ptr = (*D)->start;
    while (buffer != NULL) {
        buffer = (*D)->ptr->next;
        free((*D)->ptr->data);
        free((*D)->ptr);
        (*D)->ptr = buffer;
    }

    (*D)->start = NULL;
    (*D)->ptr = NULL;
    (*D)->end = NULL;

    free(*D);

    *D = NULL;

    DListError = DListOk;
}