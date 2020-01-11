/***************************************************************
Copyright (C) 2020. All rights reserved.
File name     ：Deque.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2020-01-11
Function List ：
Description   ：Linked List Implementation Of Double Ended Queue
****************************************************************/

#include "Deque.h"
#include <stdlib.h>  // for malloc
#include "FatalError.h"

struct Node {
    ElementType Element;
    PtrToNode   Prev;
    PtrToNode   Next;
};

struct QNode {
    Position Front;
    Position Rear;
};

int IsEmpty(Deque Q) {
    // return Q->Front == Q->Rear->Prev;
    return Q->Front->Next == Q->Rear;
}

Deque CreateQueue(void) {
    Deque Q;

    Q = (Deque)malloc(sizeof(struct QNode));
    if (Q == NULL) {
        FatalError("Out of space!!!");
    }

    Q->Front = (PtrToNode)malloc(sizeof(struct Node));
    if (Q->Front == NULL) {
        FatalError("Out of space!!!");
    }

    Q->Rear = (PtrToNode)malloc(sizeof(struct Node));
    if (Q->Rear == NULL) {
        FatalError("Out of space!!!");
    }

    Q->Front->Prev = NULL;
    Q->Front->Next = Q->Rear;
    Q->Rear->Prev = Q->Front;
    Q->Rear->Next = NULL;
    MakeEmpty(Q);

    return Q;
}

void DisposeQueue(Deque Q) {
    MakeEmpty(Q);
    free(Q->Front);
    free(Q->Rear);
    free(Q);
}

void MakeEmpty(Deque Q) {
    if (Q == NULL) {
        Error("Must use CreateQueue first");
    } else {
        while (!IsEmpty(Q)) {
           DeleteFront(Q);
        }
    }
}

ElementType Front(Deque Q) {
    if (!IsEmpty(Q)) {
        return Q->Front->Next->Element;
    } else {
        Error("Empty queue");
        return 0;  /* Return value used to avoid warning */
    }
}

ElementType Rear(Deque Q) {
    if (!IsEmpty(Q)) {
        return Q->Rear->Prev->Element;
    } else {
        Error("Empty queue");
        return 0;  /* Return value used to avoid warning */
    }
}

void InsertFront(ElementType X, Deque Q) {
    PtrToNode TmpCell;

    TmpCell = (PtrToNode)malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        FatalError("Out of space!!!");
    }

    TmpCell->Element = X;
    TmpCell->Next = Q->Front->Next;
    Q->Front->Next->Prev = TmpCell;
    TmpCell->Prev = Q->Front;
    Q->Front->Next = TmpCell;
}

void InsertRear(ElementType X, Deque Q) {
    PtrToNode TmpCell;

    TmpCell = (PtrToNode)malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        FatalError("Out of space!!!");
    }

    TmpCell->Element = X;
    TmpCell->Next = Q->Rear;
    Q->Rear->Prev->Next = TmpCell;
    TmpCell->Prev = Q->Rear->Prev;
    Q->Rear->Prev = TmpCell;
}

void DeleteFront(Deque Q) {
    PtrToNode TmpCell;

    if (IsEmpty(Q)) {
        Error("Empty queue");
    } else {
        TmpCell = Q->Front->Next;
        Q->Front->Next = TmpCell->Next;
        TmpCell->Next->Prev = Q->Front;
        free(TmpCell);
    }
}

void DeleteRear(Deque Q) {
    PtrToNode TmpCell;

    if (IsEmpty(Q)) {
        Error("Empty queue");
    } else {
        TmpCell = Q->Rear->Prev;
        Q->Rear->Prev = TmpCell->Prev;
        TmpCell->Prev->Next = Q->Rear;
        free(TmpCell);
    }
}

ElementType FrontAndDequeue(Deque Q) {
    PtrToNode TmpCell;
    ElementType X = 0;

    if (IsEmpty(Q)) {
        Error("Empty queue");
        return 0;  /* Return value used to avoid warning */
    } else {
        X = Q->Front->Next->Element;  /* Save the value of the first element */

        TmpCell = Q->Front->Next;
        Q->Front->Next = TmpCell->Next;
        TmpCell->Next->Prev = Q->Front;
        free(TmpCell);

        return X;
    }
}

ElementType RearAndDequeue(Deque Q) {
    PtrToNode TmpCell;
    ElementType X = 0;

    if (IsEmpty(Q)) {
        Error("Empty queue");
        return 0;  /* Return value used to avoid warning */
    } else {
        X = Q->Rear->Prev->Element;  /* Save the value of the first element */

        TmpCell = Q->Rear->Prev;
        Q->Rear->Prev = TmpCell->Prev;
        TmpCell->Prev->Next = Q->Rear;
        free(TmpCell);

        return X;
    }
}

// EOF

