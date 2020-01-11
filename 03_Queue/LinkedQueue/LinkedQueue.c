/*****************************************************
Copyright (C) 2020. All rights reserved.
File name     ：LinkedQueue.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2020-01-03
Function List ：
Description   ：Linked Queue
******************************************************/

#include "LinkedQueue.h"
#include <stdlib.h>  // for malloc
#include "FatalError.h"

struct Node {
    ElementType Element;
    PtrToNode   Next;
};

struct QNode {
    Position Front;
    Position Rear;
};

int IsEmpty(LinkedQueue Q) {
    return Q->Front == Q->Rear;
}

LinkedQueue CreateQueue(void) {
    LinkedQueue Q;
    PtrToNode TmpCell;

    Q = (LinkedQueue)malloc(sizeof(struct QNode));
    if (Q == NULL) {
        FatalError("Out of space!!!");
    }

    /* Allocate a header node */
    TmpCell = (PtrToNode)malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        FatalError("Out of space!!!");
    }

    TmpCell->Next = NULL;
    Q->Front = TmpCell;
    Q->Rear = TmpCell;
    MakeEmpty(Q);

    return Q;
}

void DisposeQueue(LinkedQueue Q) {
    MakeEmpty(Q);
    free(Q->Front);
    free(Q);
}

void MakeEmpty(LinkedQueue Q) {
    if (Q == NULL) {
        Error("Must use CreateQueue first");
    } else {
        while (!IsEmpty(Q)) {
            DeQueue(Q);
        }
    }
}

ElementType Front(LinkedQueue Q) {
    if (!IsEmpty(Q)) {
        return Q->Front->Next->Element;
    } else {
        Error("Empty queue");
        return 0;  /* Return value used to avoid warning */
    }
}

void EnQueue(ElementType X, LinkedQueue Q) {
    PtrToNode TmpCell;

    TmpCell = (PtrToNode)malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        FatalError("Out of space!!!");
    }

    TmpCell->Element = X;
    TmpCell->Next = Q->Rear->Next;
    Q->Rear->Next = TmpCell;
    Q->Rear = TmpCell;
}

void DeQueue(LinkedQueue Q) {
    PtrToNode TmpCell;

    if (IsEmpty(Q)) {
        Error("Empty queue");
    } else {
        /* Set empty if deleted node is Q->Rear */
        TmpCell = Q->Front->Next;
        if (TmpCell == Q->Rear) {
            Q->Rear = Q->Front;
        }

        Q->Front->Next = TmpCell->Next;
        free(TmpCell);
    }
}

ElementType FrontAndDequeue(LinkedQueue Q) {
    ElementType X;
    PtrToNode TmpCell;

    if (IsEmpty(Q)) {
        Error("Empty queue");
        return 0;  /* Return value used to avoid warning */
    } else {
        X = Q->Front->Next->Element;  /* Save the value of the first element */

        /* Set empty if deleted node is Q->Rear */
        TmpCell = Q->Front->Next;
        if (TmpCell == Q->Rear) {
            Q->Rear = Q->Front;
        }

        Q->Front->Next = TmpCell->Next;
        free(TmpCell);

        return X;
    }
}

// EOF

