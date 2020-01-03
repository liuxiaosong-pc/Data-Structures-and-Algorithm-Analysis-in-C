/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：SqList.h
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-24
Function List ：
Description   ：Sequential List
******************************************************/

#ifndef SQLIST_H
#define SQLIST_H

// Type Definition
struct ListRecord;
typedef int ElementType;
typedef struct ListRecord *SqList;
typedef int Position;

// Function Lists
int IsEmpty(SqList L);
int IsFull(SqList L);
SqList CreateList(int MaxElements);
void DisposeList(SqList L);
void MakeEmpty(SqList L);
Position Find(ElementType X, SqList L);
void Insert(ElementType X, Position P, SqList L);
void Delete(Position P, SqList L);
ElementType FindKth(Position P, SqList L);
ElementType Retrieve(Position P, SqList L);
int Length(SqList L);

#endif  /* SQLIST_H */

// EOF

