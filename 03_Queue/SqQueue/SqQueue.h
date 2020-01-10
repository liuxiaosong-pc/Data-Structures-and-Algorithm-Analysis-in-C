/*****************************************************
Copyright (C) 2020. All rights reserved.
File name     ：SqQueue.h
Version       ：v1.0
Author        ：zhengqijun
Date          ：2020-01-02
Function List ：
Description   ：Sequential Queue
******************************************************/

#ifndef SQQUEUE_H
#define SQQUEUE_H

// Type Definition
struct QueueRecord;
typedef int ElementType;
typedef struct QueueRecord *SqQueue;

// Function Lists
int IsEmpty(SqQueue Q);
int IsFull(SqQueue Q);
SqQueue CreateQueue(int MaxElements);
void DisposeQueue(SqQueue Q);
void MakeEmpty(SqQueue Q);
ElementType Front(SqQueue Q);
void EnQueue(ElementType X, SqQueue Q);
void DeQueue(SqQueue Q);
ElementType FrontAndDequeue(SqQueue Q);

#endif  /* SQQUEUE_H */

// EOF

