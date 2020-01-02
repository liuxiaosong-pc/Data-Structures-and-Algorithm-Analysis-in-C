/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：TestMain.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2020-01-02
Function List ：
Description   ：main function
******************************************************/

#include <stdio.h>  // for printf
#include "SqQueue.h"

// PrintQueue for testing
void PrintQueue(SqQueue Q) {
    printf("SqQueue Dequeue:[ ");
    while (!IsEmpty(Q)) {
        printf("%d ", FrontAndDeQueue(Q));
    }
    printf("]\n");
}

// main function
int main(void) {
    SqQueue Q = NULL;

    Q = CreateQueue(10);

    if (IsEmpty(Q)) {
        printf("SqQueue is empty!\n");
    } else {
        printf("SqQueue is not empty!\n");
    }

    {  /* Insert */
        int i = 0;
        printf("SqQueue Enqueue:[ ");
        for (i = 0; i < 5; ++i) {
            printf("%d ", i + 1);
            EnQueue(i + 1, Q);
        }
        printf("]\n");
    }

    if (IsEmpty(Q)) {
        printf("SqQueue is empty!\n");
    } else {
        printf("SqQueue is not empty!\n");
    }

    printf("At the front of the sequential queue is element %d\n", Front(Q));

    PrintQueue(Q);

    if (IsEmpty(Q)) {
        printf("SqQueue is empty!\n");
    } else {
        printf("SqQueue is not empty!\n");
    }

    DisposeQueue(Q);

    return 0;
}

// EOF

