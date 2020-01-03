/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：TestMain.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-24
Function List ：
Description   ：main function
******************************************************/

#include <stdio.h>  // for printf
#include "SqList.h"

// PrintList for testing
void PrintList(SqList L) {
    if (IsEmpty(L)) {
        printf("SqList is empty!\n");
    } else {
        int i = 0;
        printf("SqList:[ ");
        for (i = 1; i <= Length(L); ++i) {
            printf("%d ", Retrieve(i, L));
        }
        printf("]\n");
    }
}

// main function
int main(void) {
    SqList L = NULL;

    L = CreateList(10);

    if (IsEmpty(L)) {
        printf("SqList is empty!\n");
    } else {
        printf("SqList is not empty!\n");
    }

    {  /* Insert method */
        int i = 0;
        for (i = 0; i < 5; ++i) {
            Insert(i + 1, i + 1, L);
        }
    }

    PrintList(L);

    if (IsEmpty(L)) {
        printf("SqList is empty!\n");
    } else {
        printf("SqList is not empty!\n");
    }

    printf("The 4th element is %d\n", FindKth(4, L));

    if (Find(3, L) != -1) {
        printf("Find element 3 in the sequential list!\n");
    } else {
        printf("Can not find element 3 in the sequential list!\n");
    }

    if (Find(6, L) != -1) {
        printf("Find element 6 in the sequential list!\n");
    } else {
        printf("Can not Find element 6 in the sequential list!\n");
    }

    Delete(3, L);
    printf("Delete element 3 in the sequential list!\n");
    PrintList(L);

    Delete(4, L);
    printf("Delete element 4 in the sequential list!\n");
    PrintList(L);

    DisposeList(L);

    return 0;
}

// EOF

