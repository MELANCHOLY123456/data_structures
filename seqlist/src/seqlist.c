#include "seqlist.h"
#include <stdio.h>

int InitList(Seqlist* L) {
    L->length = 0;
    return OK;
}

int ListLength(Seqlist* L) {
    return L->length;
}

int LocateElem(Seqlist* L, int data) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == data) {
            return i + 1; // 返回位置，位置从1开始
        }
    }
    return 0; // 没有找到
}

int GetElem(Seqlist* L, int pos, int* data) {
    if (pos < 1 || pos > L->length) {
        return ERROR; // 位置不合法
    }
    *data = L->data[pos - 1]; // 获取元素值
    return OK;
}

int ListInsert(Seqlist* L, int pos, int data) {
    if (pos < 1 || pos > L->length + 1 || L->length >= MAX_SIZE) {
        return ERROR; // 位置不合法或表已满
    }
    for (int i = L->length; i >= pos; i--) {
        L->data[i] = L->data[i - 1]; // 元素后移
    }
    L->data[pos - 1] = data; // 插入元素
    L->length++;
    return OK;
}

int ListDelete(Seqlist* L, int pos, int* data) {
    if (pos < 1 || pos > L->length) {
        return ERROR; // 位置不合法
    }
    *data = L->data[pos - 1]; // 获取删除元素的值
    for (int i = pos; i < L->length; i++) {
        L->data[i - 1] = L->data[i]; // 元素前移
    }
    L->length--;
    return OK;
}

void PrintList(Seqlist* L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

int DestroyList(Seqlist* L) {
    L->length = 0; // 仅重置长度，数据不需要清除
    return OK;
}