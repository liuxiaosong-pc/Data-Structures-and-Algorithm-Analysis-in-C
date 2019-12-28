/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：TestMain.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-25
Function List ：
Description   ：main function
******************************************************/

#include <stdio.h>  // for printf
#include "LinkedList.h"

// PrintList for testing
void PrintList(LinkedList L) {
    Position TmpCell;

    TmpCell = Header(L);
    if (IsEmpty(TmpCell)) {
        printf("LinkedList is empty!\n");
    } else {
        TmpCell = Advance(TmpCell);
        printf("LinkedList:[ ");
        while (TmpCell != NULL) {
            printf("%d ", Retrieve(TmpCell));
            TmpCell = Advance(TmpCell);
        }
        printf("]\n");
    }
}

// main function
int main(void) {
    LinkedList L = NULL;

    L = MakeEmpty(L);

    if (IsEmpty(L)) {
        printf("LinkedList is empty!\n");
    } else {
        printf("LinkedList is not empty!\n");
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
        printf("LinkedList is empty!\n");
    } else {
        printf("LinkedList is not empty!\n");
    }

    if (Find(3, L) != NULL) {
        printf("Find element 3 in the linked list!\n");
    } else {
        printf("Can not find element 3 in the linked list!\n");
    }

    if (Find(6, L) != NULL) {
        printf("Find element 6 in the linked list!\n");
    } else {
        printf("Can not Find element 6 in the linked list!\n");
    }

    Delete(3, L);
    printf("Delete element 3 in the linked list!\n");
    PrintList(L);

    printf("At the front of element 4 is element %d\n", Retrieve(FindPrevious(4, L)));

    DeleteList(L);

    if (IsEmpty(L)) {
        printf("LinkedList is empty!\n");
    } else {
        printf("LinkedList is not empty!\n");
    }

    return 0;
}

// EOF

