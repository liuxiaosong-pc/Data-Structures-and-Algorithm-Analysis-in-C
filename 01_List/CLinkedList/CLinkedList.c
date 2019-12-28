/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：CLinkedList.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-27
Function List ：
Description   ：Circular Linked List
******************************************************/

#include "CLinkedList.h"
#include <stdlib.h>  // for malloc
#include "FatalError.h"

struct Node {
    ElementType Element;
    Position    Next;
};

CLinkedList MakeEmpty(CLinkedList L) {
    if (L != NULL) {
        DeleteList(L);
    } else {
        L = (CLinkedList)malloc(sizeof(struct Node));
        if (L == NULL) {
            FatalError("Out of space!!!");
        }

        L->Next = L;
    }

    return L;
}

/* Return true if L->Next is L */
int IsEmpty(CLinkedList L) {
    return L->Next == L;
}

/* Return true if P is the last position in list L */
int IsLast(Position P, CLinkedList L) {
    return P->Next == L;
}

/* Return Position of X in L; NULL if not found */
Position Find(ElementType X, CLinkedList L) {
    Position P;

    P = L->Next;
    while (P != L && P->Element != X) {
        P = P->Next;
    }

    /* Return NULL if P is equal to the head node */
    if (P == L) {
        P = NULL;
    }

    return P;
}

/* Delete from a list */
/* Cell pointed to by P->Next is wiped out */
/* Assume that the position is legal */
/* Assume use of a header node */
void Delete(ElementType X, CLinkedList L) {
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
Position FindPrevious(ElementType X, CLinkedList L) {
    Position P;

    P = L;
    while (P->Next != L && P->Next->Element != X) {
        P = P->Next;
    }

    /* Return NULL if P is equal to the last node */
    if (IsLast(P, L)) {
        P = NULL;
    }

    return P;
}

/* Insert (after legal position P) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
void Insert(ElementType X, CLinkedList L, Position P) {
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
void DeleteList(CLinkedList L) {
    Position P, TmpCell;

    P = L->Next;  /* Header assumed */
    L->Next = L;
    while (P != L) {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
}

Position Header(CLinkedList L) {
    return L;
}

Position First(CLinkedList L) {
    return L->Next;
}

Position Advance(Position P) {
    return P->Next;
}

ElementType Retrieve(Position P) {
    return P->Element;
}

// EOF

