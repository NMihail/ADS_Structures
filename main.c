#include "singleLinkedLinearList/singleLinkedLinearList.h"

//TODO: Реализовать tableArray!!!

// Пример работы ОЛС
int listError;

void testList() {
    list *L = NULL;
    listInit(&L);

    // Из-за требования к отсутствию привязывания к
    // одному типу данных, мы должны использовать void *
    elementList *E = (elementList *) malloc(sizeof (elementList));
    E->data = (void *) ((int *) malloc(sizeof(int)));

    // Это из-за того, что указатель data имеет тип void *,
    // из-за чего сначала надо явно привести к нужному нам типу
    // данных (Синюк В.Г. сказал, что нужно void * использовать),
    // а уже после этого обращаться к полю и менять его как-то
    *(int *)E->data = 1;

    listPutAfterPtr(L, E);

    listMove(L, 's');

    // Куда запишем указатель на наш элемент, которых хотим достать из списка
    elementList *G = (elementList *) malloc(sizeof (elementList));
    G->data = (void *) ((int *) malloc(sizeof(int)));

    listGetIntoPtr(L, &G);

    printf("%d", *((int *)G->data));

    // Не смотря на то, что в списке очищаются все элемнты,
    // а потом указатель на сам список, список пуст,
    // а указатель E храниться у нас в G
    // (представим, что Е магическим образом испарилось),
    // и нам надо очистить память, выделенную под E
    freeList(&L);
    free(G->data);
    free(G);
}

void tests() {
    testList();
}

int main() {
    tests();

    return 0;
}
