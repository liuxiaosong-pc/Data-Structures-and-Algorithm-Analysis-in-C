/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：LinkList.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-25
Function List ：
Description   ：Link List
******************************************************/

#include "LinkList.h"
#include <stdlib.h>
#include "FatalError.h"

struct Node {
    ElementType Element;
    Position    Next;
};

LinkList MakeEmpty(LinkList L) {
    if (L != NULL) {
        DeleteList(L);
    }

    L = (LinkList)malloc(sizeof(struct Node));
    if (L == NULL) {
        FatalError("Out of space!!!");
    }

    L->Next = NULL;

    return L;
}

/* Return true if L is empty */
int IsEmpty(LinkList L) {
    return L->Next == NULL;
}

/* Return true if P is the last position in list L */
/* Parameter L is unused in this implementation */
int IsLast(Position P, LinkList L) {
    return P->Next == NULL;
}

/* Return Position of X in L; NULL if not found */
Position Find(ElementType X, LinkList L) {
    Position P;

    P = L->Next;
    while (P != NULL && P->Element != X) {
        P = P->Next;
    }

    return P;
}

/* Delete from a list */
/* Cell pointed to by P->Next is wiped out */
/* Assume that the position is legal */
/* Assume use of a header node */
void Delete(ElementType X, LinkList L) {
    Position P, TmpCell;

    P = FindPrevious(X, L);

    /* Assumption of header use X is found; delete it */
    if (!IsLast(P, L)) {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

/* If X is not found, then Next field of returned */
/* Position is NULL */
/* Assumes a header */
Position FindPrevious(ElementType X, LinkList L) {
    Position P;

    P = L;
    while (P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }

    return P;
}

/* Insert (after legal position P) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
void Insert(ElementType X, LinkList L, Position P) {
    Position TmpCell;

    TmpCell = (Position)malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        FatalError("Out of space!!!");
    }

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

/* Correct DeleteList algorithm */
void DeleteList(LinkList L) {
    Position P, TmpCell;

    P = L->Next;  /* Header assumed */
    L->Next = NULL;
    while (P != NULL) {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
}

Position Header(LinkList L) {
    return L;
}

Position First(LinkList L) {
    return L->Next;
}

Position Advance(Position P) {
    return P->Next;
}

ElementType Retrieve(Position P) {
    return P->Element;
}

void Display(LinkList L) {
    Position TmpCell;

    TmpCell = L->Next;
    printf("LinkList:[ ");
    while (TmpCell != NULL) {
        printf("%d ", TmpCell->Element);
        TmpCell = TmpCell->Next;
    }
    printf("]\n");
}

// EOF

