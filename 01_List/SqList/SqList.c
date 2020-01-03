/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：SqList.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-24
Function List ：
Description   ：Sequential List
******************************************************/

#include "SqList.h"
#include <stdlib.h>  // for malloc
#include "FatalError.h"

/* List implementation is a dynamically allocated array */
#define EmptyTOS    (-1)
#define MinListSize (5)

struct ListRecord {
    int Capacity;
    int Last;
    ElementType *Array;
};

int IsEmpty(SqList L) {
    return L->Last == EmptyTOS;
}

int IsFull(SqList L) {
    return L->Last + 1 == L->Capacity;
}

SqList CreateList(int MaxElements) {
    SqList L;

    if (MaxElements < MinListSize) {
        Error("List size is too small");
    }

    L = (SqList)malloc(sizeof(struct ListRecord));
    if (L == NULL) {
        FatalError("Out of space!!!");
    }

    L->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
    if (L->Array == NULL) {
        FatalError("Out of space!!!");
    }

    L->Capacity = MaxElements;
    MakeEmpty(L);

    return L;
}

void DisposeList(SqList L) {
    if (L != NULL) {
        free(L->Array);
        free(L);
    }
}

void MakeEmpty(SqList L) {
    if (L == NULL) {
        Error("Must use CreateList first");
    } else {
        L->Last = EmptyTOS;
    }
}

int Find(ElementType X, SqList L) {
    Position i = 0;

    while (i <= L->Last && L->Array[i] == X) {
        ++i;
    }

    if (i > L->Last) {
        i = EmptyTOS;
    }

    return i;
}

void Insert(ElementType X, Position P, SqList L) {
    Position i;

    if (IsFull(L)) {
        Error("Full list");
    }

    if (P < 1 || P > L->Last + 2) {
        Error("Error position");
    }

    for (i = L->Last; i >= P - 1; --i) {
        L->Array[i + 1] = L->Array[i];
    }

    L->Array[P - 1] = X;
    ++L->Last;
}

void Delete(Position P, SqList L) {
    Position i;

    if (P < 1 || P > L->Last + 1) {
        Error("Error position");
    }

    for (i = P; i <= L->Last; ++i) {
        L->Array[i - 1] = L->Array[i];
    }

    --L->Last;
}

ElementType FindKth(Position P, SqList L) {
    return L->Array[P - 1];
}

ElementType Retrieve(Position P, SqList L) {
    return L->Array[P - 1];
}

int Length(SqList L) {
    return L->Last + 1;
}

// EOF

