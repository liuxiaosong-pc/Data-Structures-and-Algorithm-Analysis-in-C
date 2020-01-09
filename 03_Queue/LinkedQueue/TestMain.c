/*****************************************************
Copyright (C) 2019. All rights reserved.
File name     ：TestMain.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2020-01-03
Function List ：
Description   ：main function
******************************************************/

#include <stdio.h>  // for printf
#include "LinkedQueue.h"

// PrintQueue for testing
void PrintQueue(LinkedQueue Q) {
    printf("LinkedQueue Dequeue:[ ");
    while (!IsEmpty(Q)) {
        printf("%d ", FrontAndDeQueue(Q));
    }
    printf("]\n");
}

// main function
int main(void) {
    LinkedQueue Q = NULL;

    Q = CreateQueue();

    if (IsEmpty(Q)) {
        printf("LinkedQueue is empty!\n");
    } else {
        printf("LinkedQueue is not empty!\n");
    }

    {  /* Insert */
        int i = 0;
        printf("LinkedQueue Enqueue:[ ");
        for (i = 0; i < 5; ++i) {
            printf("%d ", i + 1);
            EnQueue(i + 1, Q);
        }
        printf("]\n");
    }

    if (IsEmpty(Q)) {
        printf("LinkedQueue is empty!\n");
    } else {
        printf("LinkedQueue is not empty!\n");
    }

    printf("At the front of the linked queue is element %d\n", Front(Q));

    PrintQueue(Q);

    if (IsEmpty(Q)) {
        printf("LinkedQueue is empty!\n");
    } else {
        printf("LinkedQueue is not empty!\n");
    }

    DisposeQueue(Q);

    return 0;
}

// EOF

