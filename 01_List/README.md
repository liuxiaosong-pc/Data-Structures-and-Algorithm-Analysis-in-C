# List

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

