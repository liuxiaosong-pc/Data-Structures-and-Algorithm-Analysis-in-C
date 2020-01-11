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
#include "CircularDeque.h"

typedef enum {
    EN_CIRCULAR_DEQUE_FRONT,
    EN_CIRCULAR_DEQUE_REAR,
} EnCircularDequeLoc;

// PrintQueue for testing
void PrintQueue(CircularDeque Q, EnCircularDequeLoc loc) {
    if (loc == EN_CIRCULAR_DEQUE_FRONT) {
        printf("CircularDeque FrontAndDequeue:[ ");
        while (!IsEmpty(Q)) {
            printf("%d ", FrontAndDequeue(Q));
        }
        printf("]\n");
    } else {
        printf("CircularDeque RearAndDequeue:[ ");
        while (!IsEmpty(Q)) {
            printf("%d ", RearAndDequeue(Q));
        }
        printf("]\n");
    }
}

// main function
int main(void) {
    CircularDeque Q = NULL;

    Q = CreateQueue(10);

    if (IsEmpty(Q)) {
        printf("CircularDeque is empty!\n");
    } else {
        printf("CircularDeque is not empty!\n");
    }

    {  /* InsertFront */
        int i = 0;
        printf("CircularDeque InsertFront:[ ");
        for (i = 0; i < 5; ++i) {
            printf("%d ", i + 1);
            InsertFront(i + 1, Q);
        }
        printf("]\n");
    }

    if (IsEmpty(Q)) {
        printf("CircularDeque is empty!\n");
    } else {
        printf("CircularDeque is not empty!\n");
    }

    printf("At the front of the circular deque is element %d\n", Front(Q));
    printf("At the rear of the circular deque is element %d\n", Rear(Q));

    PrintQueue(Q, EN_CIRCULAR_DEQUE_REAR);

    if (IsEmpty(Q)) {
        printf("CircularDeque is empty!\n");
    } else {
        printf("CircularDeque is not empty!\n");
    }

    {  /* InsertRear */
        int i = 0;
        printf("CircularDeque InsertRear:[ ");
        for (i = 0; i < 7; ++i) {
            printf("%d ", i + 1);
            InsertRear(i + 1, Q);
        }
        printf("]\n");
    }

    if (IsEmpty(Q)) {
        printf("CircularDeque is empty!\n");
    } else {
        printf("CircularDeque is not empty!\n");
    }

    printf("At the front of the circular deque is element %d\n", Front(Q));
    printf("At the rear of the circular deque is element %d\n", Rear(Q));

    PrintQueue(Q, EN_CIRCULAR_DEQUE_FRONT);

    if (IsEmpty(Q)) {
        printf("CircularDeque is empty!\n");
    } else {
        printf("CircularDeque is not empty!\n");
    }

    DisposeQueue(Q);

    return 0;
}

// EOF

