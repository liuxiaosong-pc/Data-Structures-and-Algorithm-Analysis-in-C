# 栈

----

## 目录
<!-- vim-markdown-toc GFM -->

* [栈抽象数据类型](#栈抽象数据类型)
* [顺序栈](#顺序栈)
* [链式栈](#链式栈)

<!-- vim-markdown-toc -->

----

## 栈抽象数据类型
```c
ADT Stack {
    int IsEmpty(Stack S);
    Stack CreateStack(void);
    void DisposeStack(Stack S);
    void MakeEmpty(Stack S);
    void Push(ElementType X, Stack S);
    ElementType Top(Stack S);
    void Pop(Stack S);
    ElementType TopAndPop(Stack S);
};
```

----

## 顺序栈

----

## 链式栈

----

**[回到顶部](#栈)**
**[回到首页](https://github.com/zhengqijun0121/Data-Structures-and-Algorithm-Analysis-in-C)**

<!-- EOF -->

