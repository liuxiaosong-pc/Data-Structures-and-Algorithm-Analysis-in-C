/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：LinkedStack.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-28
Function List ：
Description   ：Linked Stack
******************************************************/

#include "LinkedStack.h"
#include <stdlib.h>  // for malloc
#include "FatalError.h"

/* Stack implementation is a linked list with a header */
struct Node {
    ElementType Element;
    PtrToNode   Next;
};

int IsEmpty(LinkedStack S) {
    return S->Next == NULL;
}

LinkedStack CreateStack(void) {
    LinkedStack S;

    S = (LinkedStack)malloc(sizeof(struct Node));
    if (S == NULL) {
        FatalError("Out of space!!!");
    }

    S->Next = NULL;

    MakeEmpty(S);

    return S;
}

void DisposeStack(LinkedStack S) {
    MakeEmpty(S);
    free(S);
}

void MakeEmpty(LinkedStack S) {
    if (S == NULL) {
        Error("Must use CreateStack first");
    } else {
        while (!IsEmpty(S)) {
            Pop(S);
        }
    }
}

void Push(ElementType X, LinkedStack S) {
    PtrToNode TmpCell;

    TmpCell = (PtrToNode)malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        FatalError("Out of space!!!");
    } else {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

ElementType Top(LinkedStack S) {
    if (!IsEmpty(S)) {
        return S->Next->Element;
    } else {
        Error("Empty stack");
        return 0;  /* Return value used to avoid warning */
    }
}

void Pop(LinkedStack S) {
    PtrToNode FirstCell;

    if (IsEmpty(S)) {
        Error("Empty stack");
    } else {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}

// EOF

