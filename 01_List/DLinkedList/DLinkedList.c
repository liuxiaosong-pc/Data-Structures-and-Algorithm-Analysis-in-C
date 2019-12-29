/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：DLinkedList.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-29
Function List ：
Description   ：Double Linked List
******************************************************/

#include "DLinkedList.h"
#include <stdlib.h>  // for malloc
#include "FatalError.h"

struct Node {
    ElementType Element;
    Position    Prev;
    Position    Next;
};

DLinkedList MakeEmpty(DLinkedList L) {
    /* Allocated if L is NULL */
    if (L != NULL) {
        DeleteList(L);
    } else {
        L = (DLinkedList)malloc(sizeof(struct Node));
        if (L == NULL) {
            FatalError("Out of space!!!");
        }

        L->Prev = NULL;
        L->Next = NULL;
    }

    return L;
}

/* Return true if L is empty */
int IsEmpty(DLinkedList L) {
    // return L->Prev == NULL;
    return L->Next == NULL;
}

/* Return true if P is the last position in list L */
/* Parameter L is unused in this implementation */
int IsLast(Position P, DLinkedList L) {
    return P->Next == NULL;
}

/* Return Position of X in L; NULL if not found */
Position Find(ElementType X, DLinkedList L) {
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
void Delete(ElementType X, DLinkedList L) {
    Position P;

    P = Find(X, L);

    /* Assumption of header use X is found; delete it */
    if (P != NULL) {
        P->Next->Prev = P->Prev;
        P->Prev->Next = P->Next;
        free(P);
    }
}

/* Insert (after legal position P) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
void Insert(ElementType X, DLinkedList L, Position P) {
    Position TmpCell;

    TmpCell = (Position)malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        FatalError("Out of space!!!");
    }

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
    if (TmpCell->Next != NULL) {
        TmpCell->Next->Prev = TmpCell;
        TmpCell->Prev = P;
    }
}

/* Correct DeleteList algorithm */
void DeleteList(DLinkedList L) {
    Position P, TmpCell;

    P = L->Next;  /* Header assumed */
    L->Next = NULL;
    while (P != NULL) {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
}

Position Header(DLinkedList L) {
    return L;
}

Position First(DLinkedList L) {
    return L->Next;
}

Position Postpone(Position P) {
    return P->Prev;
}

Position Advance(Position P) {
    return P->Next;
}

ElementType Retrieve(Position P) {
    return P->Element;
}

// EOF

