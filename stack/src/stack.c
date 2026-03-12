#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>

int visit(int c) {
    printf("%d ", c);
    return OK;
}

int InitStack(LinkStack* S) {
    if (!S) return ERROR;
    S->top = NULL;
    S->count = 0;
    return OK;
}

int StackEmpty(LinkStack S) {
    return S.top == NULL ? TRUE : FALSE;
}

int Push(LinkStack* S, int e) {
    if (!S) return ERROR;
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    if (!s) return ERROR;
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count++;
    return OK;
}

int Pop(LinkStack* S, int* e) {
    LinkStackPtr p;
    if (!S || !e) return ERROR;
    if (StackEmpty(*S)) {
        return ERROR;
    }
    *e = S->top->data;
    p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
    return OK;
}

int GetTop(LinkStack S, int* e) {
    if (!e) return ERROR;
    if (S.top == NULL) {
        return ERROR;
    }
    else {
        *e = S.top->data;
    }
    return OK;
}

int ClearStack(LinkStack* S) {
    if (!S) return ERROR;
    LinkStackPtr p = S->top;
    while (p) {
        LinkStackPtr q = p;
        p = p->next;
        free(q);
    }
    S->top = NULL;
    S->count = 0;
    return OK;
}

int StackLength(LinkStack* S) {
    if (!S) return 0;
    return S->count;
}

int StackTraverse(LinkStack S) {
    LinkStackPtr p;
    p = S.top;
    while (p) {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}
