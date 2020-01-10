/*****************************************************
Copyright (C) 2020. All rights reserved.
File name     ：CircularQueue.h
Version       ：v1.0
Author        ：zhengqijun
Date          ：2020-01-09
Function List ：
Description   ：Sequential List Implementation Of Circular Queue
******************************************************/

#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

// Type Definition
struct QueueRecord;
typedef int ElementType;
typedef struct QueueRecord *CircularQueue;

// Function Lists
int IsEmpty(CircularQueue Q);
int IsFull(CircularQueue Q);
CircularQueue CreateQueue(int MaxElements);
void DisposeQueue(CircularQueue Q);
void MakeEmpty(CircularQueue Q);
ElementType Front(CircularQueue Q);
void EnQueue(ElementType X, CircularQueue Q);
void DeQueue(CircularQueue Q);
ElementType FrontAndDequeue(CircularQueue Q);

#endif  /* CIRCULARQUEUE_H */

// EOF

