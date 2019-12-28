/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：TestMain.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-28
Function List ：
Description   ：main function
******************************************************/

#include <stdio.h>  // for printf
#include "LinkedStack.h"

// PrintStack for testing
void PrintStack(LinkedStack S) {
    printf("LinkedStack Pop:[ ");
    while (!IsEmpty(S)) {
        printf("%d ", Top(S));
        Pop(S);
    }
    printf("]\n");
}

// main function
int main(void) {
    LinkedStack S = NULL;

    S = CreateStack();

    if (IsEmpty(S)) {
        printf("LinkedStack is empty!\n");
    } else {
        printf("LinkedStack is not empty!\n");
    }

    {  /* Push stack */
        int i = 0;
        printf("LinkedStack Push:[ ");
        for (i = 0; i < 5; ++i) {
            printf("%d ", i + 1);
            Push(i + 1, S);
        }
        printf("]\n");
    }

    if (IsEmpty(S)) {
        printf("LinkedStack is empty!\n");
    } else {
        printf("LinkedStack is not empty!\n");
    }

    PrintStack(S);

    if (IsEmpty(S)) {
        printf("LinkedStack is empty!\n");
    } else {
        printf("LinkedStack is not empty!\n");
    }

    DisposeStack(S);

    return 0;
}

// EOF

