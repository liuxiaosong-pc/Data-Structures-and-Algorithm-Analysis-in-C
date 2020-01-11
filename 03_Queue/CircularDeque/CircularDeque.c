/***************************************************************
Copyright (C) 2020. All rights reserved.
File name     ：CircularDeque.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2020-01-11
Function List ：
Description   ：Sequential List Implementation Of Circular Deque
****************************************************************/

#include "CircularDeque.h"
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

int IsEmpty(CircularDeque Q) {
    return Q->Front == Q->Rear;
}

/* Allocate an empty cell */
/* (Q->Rear + 1) % Q->Capacity == Q->Front if queue is full */
int IsFull(CircularDeque Q) {
    return (Q->Rear + 1) % Q->Capacity == Q->Front;
}

CircularDeque CreateQueue(int MaxElements) {
    CircularDeque Q;

    if (MaxElements < MinQueueSize) {
        Error("Queue size is too small");
    }

    Q = (CircularDeque)malloc(sizeof(struct QueueRecord));
    if (Q == NULL) {
        FatalError("Out of space!!!");
    }

    /* Need a empty cell */
    Q->Array = (ElementType *)malloc(sizeof(ElementType) * (MaxElements + 1));
    if (Q->Array == NULL) {
        FatalError("Out of space!!!");
    }

    Q->Capacity = MaxElements + 1;
    MakeEmpty(Q);

    return Q;
}

void DisposeQueue(CircularDeque Q) {
    if (Q != NULL) {
        free(Q->Array);
        free(Q);
    }
}

void MakeEmpty(CircularDeque Q) {
    Q->Front = 0;
    Q->Rear = 0;
}

ElementType Front(CircularDeque Q) {
    if (!IsEmpty(Q)) {
        return Q->Array[Q->Front];
    } else {
        Error("Empty queue");
        return 0;  /* Return value used to avoid warning */
    }
}

ElementType Rear(CircularDeque Q) {
    if (!IsEmpty(Q)) {
        return Q->Array[(Q->Rear - 1 + Q->Capacity) % Q->Capacity];
    } else {
        Error("Empty queue");
        return 0;  /* Return value used to avoid warning */
    }
}

void InsertFront(ElementType X, CircularDeque Q) {
    if (IsFull(Q)) {
        Error("Full queue");
    } else {
        /* 1. Move Q->Front back one space */
        /* 2. Save the element value */
        Q->Front = (Q->Front - 1 + Q->Capacity) % Q->Capacity;
        Q->Array[Q->Front] = X;
    }
}

void InsertRear(ElementType X, CircularDeque Q) {
    if (IsFull(Q)) {
        Error("Full queue");
    } else {
        /* 1. Save the element value */
        /* 2. Move Q->Rear forward one space */
        Q->Array[Q->Rear] = X;
        Q->Rear = (Q->Rear + 1) % Q->Capacity;
    }
}

void DeleteFront(CircularDeque Q) {
    if (IsEmpty(Q)) {
        Error("Empty queue");
    } else {
        Q->Front = (Q->Front + 1) % Q->Capacity;
    }
}

void DeleteRear(CircularDeque Q) {
    if (IsEmpty(Q)) {
        Error("Empty queue");
    } else {
        Q->Rear = (Q->Rear - 1 + Q->Capacity) % Q->Capacity;
    }
}

ElementType FrontAndDequeue(CircularDeque Q) {
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

ElementType RearAndDequeue(CircularDeque Q) {
    ElementType X = 0;

    if (IsEmpty(Q)) {
        Error("Empty queue");
        return 0;  /* Return value used to avoid warning */
    } else {
        Q->Rear = (Q->Rear - 1 + Q->Capacity) % Q->Capacity;
        X = Q->Array[Q->Rear];

        return X;
    }
}

// EOF

