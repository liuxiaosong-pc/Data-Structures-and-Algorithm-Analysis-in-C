/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：LinkedList.h
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-25
Function List ：
Description   ：Linked List
******************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Type Definition
struct Node;
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode LinkedList;
typedef PtrToNode Position;

// Function Lists
LinkedList MakeEmpty(LinkedList L);
int IsEmpty(LinkedList L);
int IsLast(Position P, LinkedList L);
Position Find(ElementType X, LinkedList L);
void Delete(ElementType X, LinkedList L);
Position FindPrevious(ElementType X, LinkedList L);
void Insert(ElementType X, LinkedList L, Position P);
void DeleteList(LinkedList L);
Position Header(LinkedList L);
Position First(LinkedList L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif  /* LINKEDLIST_H */

// EOF

