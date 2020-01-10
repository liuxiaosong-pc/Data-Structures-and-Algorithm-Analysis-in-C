/*****************************************************
Copyright (C) 2020. All rights reserved.
File name     ：LinkedQueue.h
Version       ：v1.0
Author        ：zhengqijun
Date          ：2020-01-03
Function List ：
Description   ：Linked Queue
******************************************************/

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

// Type Definition
struct Node;
struct QNode;
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef struct QNode *LinkedQueue;
typedef PtrToNode Position;

// Function Lists
int IsEmpty(LinkedQueue Q);
LinkedQueue CreateQueue(void);
void DisposeQueue(LinkedQueue Q);
void MakeEmpty(LinkedQueue Q);
ElementType Front(LinkedQueue Q);
void EnQueue(ElementType X, LinkedQueue Q);
void DeQueue(LinkedQueue Q);
ElementType FrontAndDequeue(LinkedQueue Q);

#endif  /* LINKEDQUEUE_H */

// EOF

