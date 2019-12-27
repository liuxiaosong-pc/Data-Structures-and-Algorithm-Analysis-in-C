/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：LinkList.h
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-25
Function List ：
Description   ：Link List
******************************************************/

#ifndef LINKLIST_H
#define LINKLIST_H

struct Node;
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode LinkList;
typedef PtrToNode Position;

// Function Lists
LinkList MakeEmpty(LinkList L);
int IsEmpty(LinkList L);
int IsLast(Position P, LinkList L);
Position Find(ElementType X, LinkList L);
void Delete(ElementType X, LinkList L);
Position FindPrevious(ElementType X, LinkList L);
void Insert(ElementType X, LinkList L, Position P);
void DeleteList(LinkList L);
Position Header(LinkList L);
Position First(LinkList L);
Position Advance(Position P);
ElementType Retrieve(Position P);

// Display for testing
void Display(LinkList L);

#endif  /* LINKLIST_H */

// EOF

