//
// Created by Worker on 25.10.2023.
//

#ifndef ADS_STRUCTURES_STACKLIST_H
#define ADS_STRUCTURES_STACKLIST_H

#include "../singleLinkedLinearList/singleLinkedLinearList.h"

const int stackListOk = listOk;
const int stackListEmpty = listEmpty;
const int stackListNotMem = listNotMem;
extern int stackListError;

typedef baseTypeList baseTypeStackList;
typedef elementList elementStackList;
typedef list stackList;

bool isStackListEmpty(stackList *S);

void stackListPut(stackList *S, elementStackList *E);

void stackListGet(stackList *S, elementStackList **G);

#endif //ADS_STRUCTURES_STACKLIST_H
