//
// Created by Worker on 25.10.2023.
//

#ifndef ADS_STRUCTURES_STACKLIST_H
#define ADS_STRUCTURES_STACKLIST_H

#include "../singleLinkedLinearList/singleLinkedLinearList.h"

#define stackListOk listOk
#define stackListEmpty listEmpty
#define stackListNotMem listNotMem
extern int stackListError;

typedef baseTypeList baseTypeStackList;
typedef elementList elementStackList;
typedef list stackList;

// Возвращает значение "истина",
// если стек пустой
bool isStackListEmpty(stackList *S);

// Инициализирует стек
// Требует указатель на уже выделенную
// область памяти для стека
void stackListInit(stackList *S);

// Очищает стек полностью
void stackListFree(stackList *S);

// Вставляет элемент в стек
void stackListPut(stackList *S, elementStackList *E);

// Получает элемент из стека
void stackListGet(stackList *S, elementStackList **G);

#endif //ADS_STRUCTURES_STACKLIST_H
