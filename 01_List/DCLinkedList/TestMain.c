/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：TestMain.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-31
Function List ：
Description   ：main function
******************************************************/

#include <stdio.h>
#include "DCLinkedList.h"

// PrintList for testing
void PrintList(DCLinkedList L) {
    Position TmpCell;

    TmpCell = Header(L);
    if (IsEmpty(L)) {
        printf("DCLinkedList is empty!\n");
    } else {
        printf("DCLinkedList:[ ");
        do {
            TmpCell = Advance(TmpCell);
            printf("%d ", Retrieve(TmpCell));
        } while (!IsLast(TmpCell, L));
        printf("]\n");
    }
}

// main function
int main(void) {
    DCLinkedList L = NULL;

    L = MakeEmpty(L);

    if (IsEmpty(L)) {
        printf("DCLinkedList is empty!\n");
    } else {
        printf("DCLinkedList is not empty!\n");
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
        printf("DCLinkedList is empty!\n");
    } else {
        printf("DCLinkedList is not empty!\n");
    }

    if (Find(3, L) != NULL) {
        printf("Find element 3 in the doubly circular linked list!\n");
    } else {
        printf("Can not find element 3 in the doubly circular linked list!\n");
    }

    if (Find(6, L) != NULL) {
        printf("Find element 6 in the doubly circular linked list!\n");
    } else {
        printf("Can not Find element 6 in the doubly circular linked list!\n");
    }

    Delete(3, L);
    printf("Delete element 3 in the doubly circular linked list!\n");
    PrintList(L);

    Delete(5, L);
    printf("Delete element 5 in the doubly circular linked list!\n");
    PrintList(L);

    DeleteList(L);

    if (IsEmpty(L)) {
        printf("DCLinkedList is empty!\n");
    } else {
        printf("DCLinkedList is not empty!\n");
    }

    return 0;
}

// EOF

