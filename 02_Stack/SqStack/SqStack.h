/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：SqStack.h
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-31
Function List ：
Description   ：Sequential Stack
******************************************************/

#ifndef SQSTACK_H
#define SQSTACK_H

// Type Definition
struct StackRecord;
typedef int ElementType;
typedef struct StackRecord *SqStack;

// Function Lists
int IsEmpty(SqStack S);
int IsFull(SqStack S);
SqStack CreateStack(int MaxElements);
void DisposeStack(SqStack S);
void MakeEmpty(SqStack S);
void Push(ElementType X, SqStack S);
ElementType Top(SqStack S);
void Pop(SqStack S);
ElementType TopAndPop(SqStack S);

#endif  /* SQSTACK_H */

// EOF

