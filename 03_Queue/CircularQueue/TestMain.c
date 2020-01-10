/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：TestMain.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2020-01-09
Function List ：
Description   ：main function
******************************************************/

#include <stdio.h>  // for printf
#include "CircularQueue.h"

// PrintQueue for testing
void PrintQueue(CircularQueue Q) {
    printf("CircularQueue Dequeue:[ ");
    while (!IsEmpty(Q)) {
        printf("%d ", FrontAndDequeue(Q));
    }
    printf("]\n");
}

// main function
int main(void) {
    CircularQueue Q = NULL;

    Q = CreateQueue(10);

    if (IsEmpty(Q)) {
        printf("CircularQueue is empty!\n");
    } else {
        printf("CircularQueue is not empty!\n");
    }

    {  /* Insert */
        int i = 0;
        printf("CircularQueue Enqueue:[ ");
        for (i = 0; i < 5; ++i) {
            printf("%d ", i + 1);
            EnQueue(i + 1, Q);
        }
        printf("]\n");
    }

    if (IsEmpty(Q)) {
        printf("CircularQueue is empty!\n");
    } else {
        printf("CircularQueue is not empty!\n");
    }

    printf("At the front of the circular queue is element %d\n", Front(Q));

    PrintQueue(Q);

    if (IsEmpty(Q)) {
        printf("CircularQueue is empty!\n");
    } else {
        printf("CircularQueue is not empty!\n");
    }

    DisposeQueue(Q);

    return 0;
}

// EOF

