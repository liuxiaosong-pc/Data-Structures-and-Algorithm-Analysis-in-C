/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：TestMain.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2020-01-04
Function List ：
Description   ：main function
******************************************************/

#include <stdio.h>  // for printf
#include "CursorList.h"

// PrintList for testing
void PrintList(CursorList L) {
    Position TmpCell;

    TmpCell = Header(L);
    if (IsEmpty(TmpCell)) {
        printf("CursorList is empty!\n");
    } else {
        printf("CursorList:[ ");
        do {
            TmpCell = Advance(TmpCell);
            printf("%d ", Retrieve(TmpCell));
        } while (!IsLast(TmpCell, L));
        printf("]\n");
    }
}

// main function
int main(void) {
    CursorList L = 0;

    InitializeCursorSpace();
    L = MakeEmpty(L);

    if (IsEmpty(L)) {
        printf("CursorList is empty!\n");
    } else {
        printf("CursorList is not empty!\n");
    }

    {  /* Insert method */
        int i = 0;
        Position TmpCell = Header(L);
        for (i = 0; i < 5; ++i) {
            Insert(i + 1, L, TmpCell);
            TmpCell = Advance(TmpCell);  /* Tail insert if not */
        }
    }

    PrintList(L);

    if (IsEmpty(L)) {
        printf("CursorList is empty!\n");
    } else {
        printf("CursorList is not empty!\n");
    }

    if (Find(3, L) != 0) {
        printf("Find element 3 in the cursor list!\n");
    } else {
        printf("Can not find element 3 in the cursor list!\n");
    }

    if (Find(6, L) != 0) {
        printf("Find element 6 in the cursor list!\n");
    } else {
        printf("Can not find element 6 in the cursor list!\n");
    }

    Delete(3, L);
    printf("Delete element 3 in the cursor list!\n");
    PrintList(L);

    printf("At the front of element 4 is element %d\n", Retrieve(FindPrevious(4, L)));

    Delete(5, L);
    printf("Delete element 5 in the cursor list!\n");
    PrintList(L);

    DeleteList(L);

    if (IsEmpty(L)) {
        printf("CursorList is empty!\n");
    } else {
        printf("CursorList is not empty!\n");
    }

    return 0;
}

// EOF

