/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：DCLinkedList.h
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-31
Function List ：
Description   ：Doubly Circular Linked List
******************************************************/

#ifndef DCLINKLIST_H
#define DCLINKLIST_H

// Type Definition
struct Node;
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode DCLinkedList;
typedef PtrToNode Position;

// Function Lists
DCLinkedList MakeEmpty(DCLinkedList L);
int IsEmpty(DCLinkedList L);
int IsLast(Position P, DCLinkedList L);
Position Find(ElementType X, DCLinkedList L);
void Delete(ElementType X, DCLinkedList L);
void Insert(ElementType X, DCLinkedList L, Position P);
void DeleteList(DCLinkedList L);
Position Header(DCLinkedList L);
Position First(DCLinkedList L);
Position Postpone(Position P);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif  /* DCLINKLIST_H */

// EOF

