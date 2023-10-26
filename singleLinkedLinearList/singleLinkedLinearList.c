//
// Created by Worker on 24.10.2023.
//


#include "singleLinkedLinearList.h"

// Предикат пустоты списка L
bool isListEmpty(list *L) {
    return L->L == NULL;
}

// Предикат конца списка L
bool isListEnd(list *L) {
    return L->ptr->linkNext == NULL;
}

// Инициализация пустого списка L
void listInit(list *L) {
    L->L = NULL;
    L->ptr = NULL;
}

// Выделить память под элемент и сохранить
// указатель для доступа к памяти в указатель E
void getMemToElement(elementList *E) {
    E = (elementList *)malloc(sizeof(elementList));
    if (E == NULL) {
        listError = listNotMem;
        return;
    }

    listError = listOk;
}

// Полностью освободить память, выделенную под эемент E,
// но сохранить указатель на следующий после него элемент
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

// Вставить элемент, хранящийся по указателю E
// в список L после рабочего указателя
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

// Вставить элемент, хранящийся по указателю E
// в список L до рабочего указателя
void listPutBeforePtr(list *L, elementList *E) {
    if (isListEmpty(L)) {
        L->L = E;
        L->ptr = E;
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

// Элемент полностью не очищается, он храниться
// по указателю G, но доступа к нему через
// список L уже нет
void listGetIntoPtr(list *L, elementList **G) {
    if (isListEmpty(L)) {
        listError = listEmpty;
    } else if (L->L->linkNext == NULL) {
        *G = L->ptr;

        L->L = NULL;
        L->ptr = NULL;
        listError = listOk;
    } else if (L->L == L->ptr) {
        *G = L->ptr;
        L->L = L->L->linkNext;
        L->ptr = L->ptr->linkNext;
        listError = listOk;
    } else {
        *G = L->ptr;

        elementList *pntr = L->L;
        while (pntr->linkNext != L->ptr) {
            pntr = pntr->linkNext;
        }

        L->ptr = pntr;
        pntr->linkNext = (*G)->linkNext;

        listError = listOk;
    }
}

// Элемент полностью не очищается, он храниться
// по указателю G, но доступа к нему через
// список L уже нет
void listGetAfterPtr(list *L, elementList **G) {
    if (isListEmpty(L)) {
        listError = listEmpty;
    } else if (isListEnd(L)) {
        listError = listEnd;
    } else {
        *G = L->ptr->linkNext;
        L->ptr->linkNext = (*G)->linkNext;
        listError = listOk;
    }
}

// Полное очищение списка L
void freeList(list *L) {
    elementList *buffer = L->L;
    L->ptr = L->L;
    while (buffer != NULL) {
        freeMemToElement(L->ptr, &buffer);
    }

    listError = listOk;
}
