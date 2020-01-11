/*****************************************************
Copyright (C) 2020. All rights reserved.
File name     ：TestMain.c
Version       ：v1.0
Author        ：zhengqijun
Date          ：2020-01-11
Function List ：
Description   ：main function
******************************************************/

#include <stdio.h>  // for printf
#include "Deque.h"

// PrintQueue for testing
void PrintQueue(Deque Q) {
    printf("Deque FrontAndDequeue:[ ");
    while (!IsEmpty(Q)) {
        printf("%d ", FrontAndDequeue(Q));
    }
    printf("]\n");
}

// main function
int main(void) {
    Deque Q = NULL;

    Q = CreateQueue();

    if (IsEmpty(Q)) {
        printf("Deque is empty!\n");
    } else {
        printf("Deque is not empty!\n");
    }

    {  /* InsertFront */
        int i = 0;
        printf("Deque InsertFront:[ ");
        for (i = 0; i < 5; ++i) {
            printf("%d ", i + 1);
            InsertFront(i + 1, Q);
        }
        printf("]\n");
    }

    if (IsEmpty(Q)) {
        printf("Deque is empty!\n");
    } else {
        printf("Deque is not empty!\n");
    }

    printf("At the front of the double ended queue is element %d\n", Front(Q));
    printf("At the end of the double ended queue is element %d\n", Rear(Q));

    PrintQueue(Q);

    if (IsEmpty(Q)) {
        printf("Deque is empty!\n");
    } else {
        printf("Deque is not empty!\n");
    }

    {  /* InsertRear */
        int i = 0;
        printf("Deque InsertRear:[ ");
        for (i = 0; i < 5; ++i) {
            printf("%d ", i + 1);
            InsertRear(i + 1, Q);
        }
        printf("]\n");
    }

    if (IsEmpty(Q)) {
        printf("Deque is empty!\n");
    } else {
        printf("Deque is not empty!\n");
    }

    printf("At the front of the double ended queue is element %d\n", Front(Q));
    printf("At the end of the double ended queue is element %d\n", Rear(Q));

    PrintQueue(Q);

    if (IsEmpty(Q)) {
        printf("Deque is empty!\n");
    } else {
        printf("Deque is not empty!\n");
    }

    DisposeQueue(Q);

    return 0;
}

// EOF

