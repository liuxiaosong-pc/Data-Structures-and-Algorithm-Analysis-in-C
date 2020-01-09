/*****************************************************
Copyright (C) 2020. All rights reserved.
File name     ：CircularQueue.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2020-01-09
Function List ：
Description   ：Circular Queue
******************************************************/

#include "CircularQueue.h"
#include <stdlib.h>  // for malloc
#include "FatalError.h"

/* Queue implementation is a dynamically allocated array */
#define MinQueueSize (5)

struct QueueRecord {
    int Capacity;
    int Front;
    int Rear;
    ElementType *Array;
};

int IsEmpty(CircularQueue Q) {
    return Q->Front == Q->Rear;
}

/* Allocate an empty cell */
/* (Q->Rear + 1) % Q->Capacity == Q->Front if queue is full */
int IsFull(CircularQueue Q) {
    return (Q->Rear + 1) % Q->Capacity == Q->Front;
}

CircularQueue CreateQueue(int MaxElements) {
    CircularQueue Q;

    if (MaxElements < MinQueueSize) {
        Error("Queue size is too small");
    }

    Q = (CircularQueue)malloc(sizeof(struct QueueRecord));
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

void DisposeQueue(CircularQueue Q) {
    if (Q != NULL) {
        free(Q->Array);
        free(Q);
    }
}

void MakeEmpty(CircularQueue Q) {
    Q->Front = 0;
    Q->Rear = 0;
}

ElementType Front(CircularQueue Q) {
    if (!IsEmpty(Q)) {
        return Q->Array[Q->Front];
    } else {
        Error("Empty queue");
        return 0;  /* Return value used to avoid warning */
    }
}

void EnQueue(ElementType X, CircularQueue Q) {
    if (IsFull(Q)) {
        Error("Full queue");
    } else {
        Q->Array[Q->Rear] = X;
        Q->Rear = (Q->Rear + 1) % Q->Capacity;
    }
}

void DeQueue(CircularQueue Q) {
    if (IsEmpty(Q)) {
        Error("Empty queue");
    } else {
        Q->Front = (Q->Front + 1) % Q->Capacity;
    }
}

ElementType FrontAndDeQueue(CircularQueue Q) {
    ElementType X = 0;

    if (IsEmpty(Q)) {
        Error("Empty queue");
        return 0;  /* Return value used to avoid warning */
    } else {
        X = Q->Array[Q->Front];
        Q->Front = (Q->Front + 1) % Q->Capacity;

        return X;
    }
}

// EOF

