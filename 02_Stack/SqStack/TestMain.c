/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：TestMain.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2019-12-31
Function List ：
Description   ：main function
******************************************************/

#include <stdio.h>  // for printf
#include "SqStack.h"

// PrintStack for testing
void PrintStack(SqStack S) {
    if (IsEmpty(S)) {
        printf("SqStack is empty!\n");
    } else {
        printf("SqStack Pop:[ ");
        while (!IsEmpty(S)) {
            printf("%d ", TopAndPop(S));
        }
        printf("]\n");
    }
}

// main function
int main(void) {
    SqStack S = NULL;

    S = CreateStack(10);

    if (IsEmpty(S)) {
        printf("SqStack is empty!\n");
    } else {
        printf("SqStack is not empty!\n");
    }

    {  /* Push stack */
        int i = 0;
        printf("SqStack Push:[ ");
        for (i = 0; i < 5; ++i) {
            printf("%d ", i + 1);
            Push(i + 1, S);
        }
        printf("]\n");
    }

    if (IsEmpty(S)) {
        printf("SqStack is empty!\n");
    } else {
        printf("SqStack is not empty!\n");
    }

    PrintStack(S);

    if (IsEmpty(S)) {
        printf("SqStack is empty!\n");
    } else {
        printf("SqStack is not empty!\n");
    }

    DisposeStack(S);

    return 0;
}

// EOF

