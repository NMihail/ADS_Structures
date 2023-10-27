#include "singleLinkedLinearList/singleLinkedLinearList.h"

//TODO: Реализовать deque dlist table!!!

int listError;

void testList() {
    list *L = NULL;
    listInit(&L);

    elementList *E = NULL;
    getMemToElement(&E);

    *(E->data) = (baseTypeList)1;

    listPutAfterPtr(L, E);

    E = NULL;
    getMemToElement(&E);
    *E->data = 2;

    listMove(L, 's');
    listGetIntoPtr(L, &E);

    printf("%d", *E->data);

    freeList(&L);
}

void tests() {
    testList();
}

int main() {
    tests();

    return 0;
}
