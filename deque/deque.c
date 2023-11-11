//
// Created by Worker on 26.10.2023.
//

#include "deque.h"

bool isDeqEmpty(Deq *D) {
    return isDListEmpty(D);
}

bool isDeqStart(Deq *D) {
    return isDListStart(D);
}

bool isDeqEnd(Deq *D) {
    return isDListEnd(D);
}

void DeqMove(Deq *D, char pos) {
    switch (pos) {
        case 's':
            DListMove(D, pos);
            DeqError = DListError;
            break;
        case 'e':
            DListMove(D, pos);
            DeqError = DListError;
            break;
        default:
            printf("Рабочий указатель не был передвинут, т.к. не правильно "
                   "введена позиция, на которую надо передвинуть рабочий указатель.");
    }
}

void DeqInit(Deq **D) {
    DListInit(D);
    DeqError = DListError;
}

void DeqPutStart(Deq *D, elementDeq *E) {
    DeqMove(D, 's');
    DListPutBeforePtr(D, E);
    DeqError = DListError;
}

void DeqPutEnd(Deq *D, elementDeq *E) {
    DeqMove(D, 'e');
    DListPutAfterPtr(D, E);
    DeqError = DListError;
}

void DeqGetStart(Deq *D, elementDeq **G) {
    DeqMove(D, 's');
    DListGetIntoPtr(D, G);
    DeqError = DListError;
}

void DeqGetEnd(Deq *D, elementDeq **G) {
    DeqMove(D, 'e');
    DListGetIntoPtr(D, G);
    DeqError = DListError;
}

void freeDeq(Deq **D) {
    freeDList(D);
    DeqError = DListError;
}