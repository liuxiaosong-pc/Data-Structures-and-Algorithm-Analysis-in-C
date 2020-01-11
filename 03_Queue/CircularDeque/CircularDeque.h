/***************************************************************
Copyright (C) 2020. All rights reserved.
File name     ：CircularDeque.h
Version       ：v1.0
Author        ：zhengqijun
Date          ：2020-01-11
Function List ：
Description   ：Sequential List Implementation Of Circular Deque
****************************************************************/

#ifndef CIRCULARDEQUE_H
#define CIRCULARDEQUE_H

// Type Definition
struct QueueRecord;
typedef int ElementType;
typedef struct QueueRecord *CircularDeque;

// Function Lists
int IsEmpty(CircularDeque Q);
int IsFull(CircularDeque Q);
CircularDeque CreateQueue(int MaxElements);
void DisposeQueue(CircularDeque Q);
void MakeEmpty(CircularDeque Q);
ElementType Front(CircularDeque Q);
ElementType Rear(CircularDeque Q);
void InsertFront(ElementType X, CircularDeque Q);
void InsertRear(ElementType X, CircularDeque Q);
void DeleteFront(CircularDeque Q);
void DeleteRear(CircularDeque Q);
ElementType FrontAndDequeue(CircularDeque Q);
ElementType RearAndDequeue(CircularDeque Q);

/* Circular deque operation considerations! */
/* 1. Head in and Tail out */
/* 2. Tail in and Head out */

#endif  /* CIRCULARDEQUE_H */

// EOF

