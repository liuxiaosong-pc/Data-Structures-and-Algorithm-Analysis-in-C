/*****************************************************
Copyright (C) 2020. All rights reserved.
File name     ：SqQueue.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2020-01-02
Function List ：
Description   ：Sequential Queue
******************************************************/

#include "SqQueue.h"
#include <stdlib.h>  // for malloc
#include "FatalError.h"

/* Queue implementation is a dynamically allocated array */
#define MinQueueSize (5)

struct QueueRecord {
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

// Static Function Lists
static int Succ(int value, SqQueue Q);

int IsEmpty(SqQueue Q) {
    return Q->Size == 0;
}

int IsFull(SqQueue Q) {
    return Q->Size == Q->Capacity;
}

SqQueue CreateQueue(int MaxElements) {
    SqQueue Q;

    if (MaxElements < MinQueueSize) {
        Error("Queue size is too small");
    }

    Q = (SqQueue)malloc(sizeof(struct QueueRecord));
    if (Q == NULL) {
        FatalError("Out of space!!!");
    }

    Q->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
    if (Q->Array == NULL) {
        FatalError("Out of space!!!");
    }

    Q->Capacity = MaxElements;
    MakeEmpty(Q);

    return Q;
}

void DisposeQueue(SqQueue Q) {
    if (Q != NULL) {
        free(Q->Array);
        free(Q);
    }
}

void MakeEmpty(SqQueue Q) {
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

ElementType Front(SqQueue Q) {
    if (!IsEmpty(Q)) {
        return Q->Array[Q->Front];
    } else {
        Error("Empty queue");
        return 0;  /* Return value used to avoid warning */
    }
}

static int Succ(int Value, SqQueue Q) {
    if (++Value == Q->Capacity) {
        Value = 0;
    }

    return Value;
}

void EnQueue(ElementType X, SqQueue Q) {
    if (IsFull(Q)) {
        Error("Full queue");
    } else {
        ++Q->Size;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

void DeQueue(SqQueue Q) {
    if (IsEmpty(Q)) {
        Error("Empty queue");
    } else {
        --Q->Size;
        Q->Front = Succ(Q->Front, Q);
    }
}

ElementType FrontAndDequeue(SqQueue Q) {
    ElementType X = 0;

    if (IsEmpty(Q)) {
        Error("Empty queue");
        return 0;  /* Return value used to avoid warning */
    } else {
        --Q->Size;
        X = Q->Array[Q->Front];
        Q->Front = Succ(Q->Front, Q);

        return X;
    }
}

// EOF

