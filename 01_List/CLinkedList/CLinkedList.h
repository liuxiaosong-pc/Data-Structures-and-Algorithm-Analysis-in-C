/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：CLinkedList.h
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-27
Function List ：
Description   ：Circular Linked List
******************************************************/

#ifndef CLINKLIST_H
#define CLINKLIST_H

// Type Definition
struct Node;
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode CLinkedList;
typedef PtrToNode Position;

// Function Lists
CLinkedList MakeEmpty(CLinkedList L);
int IsEmpty(CLinkedList L);
int IsLast(Position P, CLinkedList L);
Position Find(ElementType X, CLinkedList L);
void Delete(ElementType X, CLinkedList L);
Position FindPrevious(ElementType X, CLinkedList L);
void Insert(ElementType X, CLinkedList L, Position P);
void DeleteList(CLinkedList L);
Position Header(CLinkedList L);
Position First(CLinkedList L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif  /* CLINKLIST_H */

// EOF

