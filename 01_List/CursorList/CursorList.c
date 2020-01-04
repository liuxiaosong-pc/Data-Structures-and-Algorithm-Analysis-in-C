/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：CursorList.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2020-01-04
Function List ：
Description   ：Cursor Implementation Of Linked List
******************************************************/

#include "CursorList.h"
#include "FatalError.h"

#define SpaceSize (100)

struct Node {
    ElementType Element;
    Position    Next;
};

struct Node CursorSpace[SpaceSize];

// Static Function Lists
static Position CursorAlloc(void);
static void CursorFree(Position P);

static Position CursorAlloc(void) {
    Position P;

    P = CursorSpace[0].Next;
    CursorSpace[0].Next = CursorSpace[P].Next;

    return P;
}

static void CursorFree(Position P) {
    CursorSpace[P].Next = CursorSpace[0].Next;
    CursorSpace[0].Next = P;
}

void InitializeCursorSpace(void) {
    int i;

    for (i = 0; i < SpaceSize; ++i) {
        CursorSpace[i].Next = i + 1;
    }

    CursorSpace[SpaceSize - 1].Next = 0;
}

CursorList MakeEmpty(CursorList L) {
    /* Allocated if L is 0 */
    if (L != 0) {
        DeleteList(L);
    } else {
        L = CursorAlloc();
        if (L == 0) {
            FatalError("Out of space!!!");
        }

        CursorSpace[L].Next = 0;
    }

    return L;
}

/* Return true if L is empty */
int IsEmpty(CursorList L) {
    return CursorSpace[L].Next == 0;
}

/* Return true if P is the last position in list L */
/* Parameter L is unused in this implementation */
int IsLast(Position P, CursorList L) {
    return CursorSpace[P].Next == 0;
}

/* Return Position of X in L; 0 if not found */
/* Uses a header node */
Position Find(ElementType X, CursorList L) {
    Position P;

    P = CursorSpace[L].Next;
    while (P && CursorSpace[P].Element != X) {
        P = CursorSpace[P].Next;
    }

    return P;
}

/* Delete first occurrence of X from a list */
/* Assume use of a header node */
void Delete(ElementType X, CursorList L) {
    Position P, TmpCell;

    P = FindPrevious(X, L);

    /* Assumption of header use X is found; delete it */
    if (!IsLast(P, L)) {
        TmpCell = CursorSpace[P].Next;
        CursorSpace[P].Next = CursorSpace[TmpCell].Next;
        CursorFree(TmpCell);
    }
}

/* If X is not found, then Next field of returned value is 0 */
/* Assumes a header */
Position FindPrevious(ElementType X, CursorList L) {
    Position P;

    P = L;
    while (CursorSpace[P].Next && CursorSpace[CursorSpace[P].Next].Element != X) {
        P = CursorSpace[P].Next;
    }

    return P;
}

/* Insert (after legal position P) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
void Insert(ElementType X, CursorList L, Position P) {
    Position TmpCell;

    TmpCell = CursorAlloc();
    if (TmpCell == 0) {
        FatalError("Out of space!!!");
    }

    CursorSpace[TmpCell].Element = X;
    CursorSpace[TmpCell].Next = CursorSpace[P].Next;
    CursorSpace[P].Next = TmpCell;
}

void DeleteList(CursorList L) {
    Position P, TmpCell;

    P = CursorSpace[L].Next;  /* Header assumed */
    CursorSpace[L].Next = 0;
    while (P != 0) {
        TmpCell = CursorSpace[P].Next;
        CursorFree(P);
        P = TmpCell;
    }
}

Position Header(CursorList L) {
    return L;
}

Position First(CursorList L) {
    return CursorSpace[L].Next;
}

Position Advance(Position P) {
    return CursorSpace[P].Next;
}

ElementType Retrieve(Position P) {
    return CursorSpace[P].Element;
}

// EOF

