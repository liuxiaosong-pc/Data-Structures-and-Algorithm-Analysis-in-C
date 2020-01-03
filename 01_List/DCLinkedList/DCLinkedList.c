/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：DCLinkedList.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-31
Function List ：
Description   ：Doubly Circular Linked List
******************************************************/

#include "DCLinkedList.h"
#include <stdlib.h>  // for malloc
#include "FatalError.h"

struct Node {
    ElementType Element;
    Position    Prev;
    Position    Next;
};

DCLinkedList MakeEmpty(DCLinkedList L) {
    if (L != NULL) {
        DeleteList(L);
    } else {
        L = (DCLinkedList)malloc(sizeof(struct Node));
        if (L == NULL) {
            FatalError("Out of space!!!");
        }

        L->Prev = L;
        L->Next = L;
    }

    return L;
}

/* Return true if L->Next is L */
int IsEmpty(DCLinkedList L) {
    // return L->Prev == L;
    return L->Next == L;
}

/* Return true if P is the last position in list L */
int IsLast(Position P, DCLinkedList L) {
    // return L->Prev == P;
    return P->Next == L;
}

/* Return Position of X in L; NULL if not found */
Position Find(ElementType X, DCLinkedList L) {
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
void Delete(ElementType X, DCLinkedList L) {
    Position P;

    P = Find(X, L);

    if (P != NULL) {
        P->Next->Prev = P->Prev;
        P->Prev->Next = P->Next;
        free(P);
    }
}

/* Insert (after legal position P) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
void Insert(ElementType X, DCLinkedList L, Position P) {
    Position TmpCell;

    TmpCell = (Position)malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        FatalError("Out of space!!!");
    }

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
    TmpCell->Next->Prev = TmpCell;
    TmpCell->Prev = P;
}

/* Correct DeleteList algorithm */
void DeleteList(DCLinkedList L) {
    Position P, TmpCell;

    P = L->Next;  /* Header assumed */
    L->Prev = L;
    L->Next = L;
    while (P != L) {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
}

Position Header(DCLinkedList L) {
    return L;
}

Position First(DCLinkedList L) {
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

