#include "queue.h"
#include <stdio.h>

int InitQueue(SqQueue* Q) {
    Q->rear = Q->front = 0;
    return OK;
}

int QueueEmpty(SqQueue Q) {
    return Q.rear == Q.front;
}

int EnQueue(SqQueue* Q, int x) {
    if ((Q->rear + 1) % MAX_SIZE == Q->front) {
        return FALSE;
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MAX_SIZE;
    return OK;
}

int DeQueue(SqQueue* Q, int* x) {
    if (Q->rear == Q->front) {
        return FALSE;
    }
    *x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAX_SIZE;
    return OK;
}
