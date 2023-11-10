//
// Created by Worker on 26.10.2023.
//

#include "doubleLinkedList.h"

bool isListEmpty(DList *D) {
    return D->start == NULL;
}

bool isListStart(DList *D) {
    return D->ptr == D->start;
}

bool isListEnd(DList *D) {
    return D->ptr == D->end;
}

void listInit(DList **D) {
    *D = (DList *)malloc(sizeof(DList));
    if (*D == NULL) {
        DListError = DListNotMem;
        return;
    }

    (*D)->start = NULL;
    (*D)->ptr = NULL;
}

void getMemToElement(elementDList **E) {

}

void freeMemToElement(elementDList *E, elementDList **next) {

}

void listPutAfterPtr(DList *D, elementDList *E) {

}

void listPutBeforePtr(DList *D, elementDList *E) {

}

void listGetIntoPtr(DList *D, elementDList **G) {

}

void listGetAfterPtr(DList *D, elementDList **G) {

}

void freeList(DList **D) {

}

void listMove(DList *D, char pos) {

}