#ifndef QUEUE_H
#define QUEUE_H

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

#define MAX_SIZE 20

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} SqQueue;

int InitQueue(SqQueue* Q);
int QueueEmpty(SqQueue Q);
int EnQueue(SqQueue* Q, int x);
int DeQueue(SqQueue* Q, int* x);

#endif // QUEUE_H