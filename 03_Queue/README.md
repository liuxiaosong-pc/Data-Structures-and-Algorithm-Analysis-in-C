# 队列

----

## 目录
<!-- vim-markdown-toc GFM -->

* [队列抽象数据类型](#队列抽象数据类型)
* [顺序队列](#顺序队列)
* [链式队列](#链式队列)
* [循环队列](#循环队列)
* [双端队列](#双端队列)
* [循环双端队列](#循环双端队列)

<!-- vim-markdown-toc -->

----

## 队列抽象数据类型
```c
ADT Queue {
    int IsEmpty(Queue Q);
    int IsFull(Queue Q);
    Queue CreateQueue(int MaxElements);
    void DisposeQueue(Queue Q);
    void MakeEmpty(Queue Q);
    ElementType Front(Queue Q);
    void EnQueue(ElementType X, Queue Q);
    void DeQueue(Queue Q);
    ElementType FrontAndDeQueue(Queue Q);
};
```

----

## 顺序队列

----

## 链式队列

----

## 循环队列

----

## 双端队列

----

## 循环双端队列

----

**[回到顶部](#队列)**
**[回到首页](https://github.com/zhengqijun0121/Data-Structures-and-Algorithm-Analysis-in-C)**

<!-- EOF -->

