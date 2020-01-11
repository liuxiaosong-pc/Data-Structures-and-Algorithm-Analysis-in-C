/***************************************************************
Copyright (C) 2020. All rights reserved.
File name     ：Deque.h
Version       ：v1.0
Author        ：zhengqijun
Date          ：2020-01-11
Function List ：
Description   ：Linked List Implementation Of Double Ended Queue
****************************************************************/

#ifndef DEQUE_H
#define DEQUE_H

// Type Definition
struct Node;
struct QNode;
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef struct QNode *Deque;
typedef PtrToNode Position;

// Function Lists
int IsEmpty(Deque Q);
Deque CreateQueue(void);
void DisposeQueue(Deque Q);
void MakeEmpty(Deque Q);
ElementType Front(Deque Q);
ElementType Rear(Deque Q);
void InsertFront(ElementType X, Deque Q);
void InsertRear(ElementType X, Deque Q);
void DeleteFront(Deque Q);
void DeleteRear(Deque Q);
ElementType FrontAndDequeue(Deque Q);
ElementType RearAndDequeue(Deque Q);

#endif  /* DEQUE_H */

// EOF

