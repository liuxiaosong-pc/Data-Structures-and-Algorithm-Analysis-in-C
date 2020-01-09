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

    Q = (LinkedQueue)malloc(sizeof(struct QNode));
    if (Q == NULL) {
        FatalError("Out of space!!!");
    }

    Q->Front = NULL;
    Q->Rear = NULL;
    MakeEmpty(Q);

    return Q;
}

void DisposeQueue(LinkedQueue Q) {
    MakeEmpty(Q);
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
        return Q->Front->Element;
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
    TmpCell->Next = Q->Front;
    Q->Front = TmpCell;
}

void DeQueue(LinkedQueue Q) {
    PtrToNode TmpCell;

    if (IsEmpty(Q)) {
        Error("Empty queue");
    } else {
        TmpCell = Q->Front;
        Q->Front = TmpCell->Next;
        free(TmpCell);
    }
}

ElementType FrontAndDeQueue(LinkedQueue Q) {
    ElementType X;
    PtrToNode TmpCell;

    if (IsEmpty(Q)) {
        Error("Empty queue");
        return 0;  /* Return value used to avoid warning */
    } else {
        X = Q->Front->Element;  /* Save the value of the first element */

        TmpCell = Q->Front;
        Q->Front = TmpCell->Next;
        free(TmpCell);

        return X;
    }
}

// EOF

