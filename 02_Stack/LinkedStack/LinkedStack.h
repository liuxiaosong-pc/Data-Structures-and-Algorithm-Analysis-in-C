/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：LinkedStack.h
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-28
Function List ：
Description   ：Linked Stack
******************************************************/

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

// Type Definition
struct Node;
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode LinkedStack;

// Function Lists
int IsEmpty(LinkedStack S);
LinkedStack CreateStack(void);
void DisposeStack(LinkedStack S);
void MakeEmpty(LinkedStack S);
void Push(ElementType X, LinkedStack S);
ElementType Top(LinkedStack S);
void Pop(LinkedStack S);
ElementType TopAndPop(LinkedStack S);

#endif  /* LINKEDSTACK_H */

// EOF

