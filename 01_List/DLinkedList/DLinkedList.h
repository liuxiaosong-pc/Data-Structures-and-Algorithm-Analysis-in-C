/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：DLinkedList.h
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-29
Function List ：
Description   ：Doubly Linked List
******************************************************/

#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

// Type Definition
struct Node;
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode DLinkedList;
typedef PtrToNode Position;

// Function Lists
DLinkedList MakeEmpty(DLinkedList L);
int IsEmpty(DLinkedList L);
int IsLast(Position P, DLinkedList L);
Position Find(ElementType X, DLinkedList L);
void Delete(ElementType X, DLinkedList L);
void Insert(ElementType X, DLinkedList L, Position P);
void DeleteList(DLinkedList L);
Position Header(DLinkedList L);
Position First(DLinkedList L);
Position Postpone(Position P);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif  /* DLINKEDLIST_H */

// EOF

