/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：CursorList.h
Version       ：v1.0
Author        ：zhengqijun
Date          ：2020-01-04
Function List ：
Description   ：Cursor Implementation Of Linked List
******************************************************/

#ifndef CURSORLIST_H
#define CURSORLIST_H

// Type Definition
typedef int ElementType;
typedef int PtrToNode;
typedef PtrToNode CursorList;
typedef PtrToNode Position;

// Function Lists
void InitializeCursorSpace(void);

CursorList MakeEmpty(CursorList L);
int IsEmpty(CursorList L);
int IsLast(Position P, CursorList L);
Position Find(ElementType X, CursorList L);
void Delete(ElementType X, CursorList L);
Position FindPrevious(ElementType X, CursorList L);
void Insert(ElementType X, CursorList L, Position P);
void DeleteList(CursorList L);
Position Header(CursorList L);
Position First(CursorList L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif  /* CURSORLIST_H */

// EOF

