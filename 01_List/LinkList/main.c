/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：main.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-25
Function List ：
Description   ：main
******************************************************/

#include <stdio.h>
#include "LinkList.h"

int main(void) {
    LinkList L = NULL;

    L = MakeEmpty(L);

    if (IsEmpty(L)) {
        printf("LinkList is empty!\n");
    } else {
        printf("LinkList is not empty!\n");
    }

    {  /* Insert method */
        int i = 0;
        Position TmpCell = L;
        for (i = 0; i < 5; ++i) {
            Insert(i + 1, L, TmpCell);
            TmpCell = Advance(TmpCell);  /* Tail insert if not */
        }
    }

    Display(L);

    if (IsEmpty(L)) {
        printf("LinkList is empty!\n");
    } else {
        printf("LinkList is not empty!\n");
    }

    if (Find(3, L) != NULL) {
        printf("Find element 3 in the linked list!\n");
    } else {
        printf("Can not Find element 3 in the linked list!\n");
    }

    if (Find(6, L) != NULL) {
        printf("Find element 6 in the linked list!\n");
    } else {
        printf("Can not Find element 6 in the linked list!\n");
    }

    Delete(3, L);
    printf("Delete element 3 in the linked list!\n");
    Display(L);

    printf("At the front of element 4 is element %d\n", Retrieve(FindPrevious(4, L)));

    DeleteList(L);

    if (IsEmpty(L)) {
        printf("LinkList is empty!\n");
    } else {
        printf("LinkList is not empty!\n");
    }

    return 0;
}

// EOF

