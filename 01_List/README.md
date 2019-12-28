# 线性表

----

## 目录
<!-- vim-markdown-toc GFM -->

* [线性表抽线数据类型](#线性表抽线数据类型)
* [顺序表](#顺序表)
    * [优点](#优点)
    * [缺点](#缺点)
* [单链表](#单链表)
* [循环链表](#循环链表)
* [双向链表](#双向链表)
* [双向循环链表](#双向循环链表)

<!-- vim-markdown-toc -->

----

## 线性表抽线数据类型
```c
ADT List {
    List MakeEmpty(List L);
    int IsEmpty(List L);
    int IsLast(List L);
    Position Find(ElementType X, List L);
    void Delete(ElementType X, List L);
    Position FindPrevious(ElementType X, List L);
    void Insert(ElementType X, List L, Position P);
    void DeleteList(List L);
    Position Header(List L);
    Position First(List L);
    Position Advance(Position P);
    ElementType Retrieve(Position P);
};
```

----

## 顺序表
### 优点
- 数组实现`PrintList`和`Find`以线性时间执行
- `FindKth`以常数时间执行

### 缺点
- 插入和删除的花费是昂贵的，插入需要将新增元素后面的所有元素都后移一位，删除需要将删除元素后面的所有元素都前移一位．平均时间复杂度: O(N)
- 顺序表的大小需要提前知道，超出范围可能需要扩容处理．

----

## 单链表

----

## 循环链表

----

## 双向链表

----

## 双向循环链表

----

**[回到顶部](#线性表)**
**[回到首页](https://github.com/zhengqijun0121/Data-Structures-and-Algorithm-Analysis-in-C)**

<!-- EOF -->

