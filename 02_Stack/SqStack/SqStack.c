/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：SqStack.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-31
Function List ：
Description   ：Sequential Stack
******************************************************/

#include "SqStack.h"
#include <stdlib.h>  // for malloc
#include "FatalError.h"

/* Stack implementation is a dynamically allocated array */
#define EmptyTOS     (-1)
#define MinStackSize (5)

struct StackRecord {
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

int IsEmpty(SqStack S) {
    return S->TopOfStack == EmptyTOS;
}

int IsFull(SqStack S) {
    return S->TopOfStack == S->Capacity - 1;
}

SqStack CreateStack(int MaxElements) {
    SqStack S;

    if (MaxElements < MinStackSize) {
        Error("Stack size is too small");
    }

    S = (SqStack)malloc(sizeof(struct StackRecord));
    if (S == NULL) {
        FatalError("Out of space!!!");
    }

    S->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
    if (S->Array == NULL) {
        FatalError("Out of space!!!");
    }

    S->Capacity = MaxElements;
    MakeEmpty(S);

    return S;
}

void DisposeStack(SqStack S) {
    if (S != NULL) {
        free(S->Array);
        free(S);
    }
}

void MakeEmpty(SqStack S) {
    S->TopOfStack = EmptyTOS;
}

void Push(ElementType X, SqStack S) {
    if (IsFull(S)) {
        Error("Empty stack");
    } else {
        S->Array[++S->TopOfStack] = X;
    }
}

ElementType Top(SqStack S) {
    if (!IsEmpty(S)) {
        return S->Array[S->TopOfStack];
    } else {
        Error("Empty stack");
        return 0;  /* Return value used to avoid warning */
    }
}

void Pop(SqStack S) {
    if (IsEmpty(S)) {
        Error("Empty stack");
    } else {
        --S->TopOfStack;
    }
}

ElementType TopAndPop(SqStack S) {
    if (!IsEmpty(S)) {
        return S->Array[S->TopOfStack--];
    } else {
        Error("Empty stack");
        return 0;  /* Return value used to avoid warning */
    }
}

// EOF

