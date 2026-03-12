#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

int InitSList(LinkList* L) {
    *L = (LinkList)malloc(sizeof(Node)); // 创建头节点
    if (*L == NULL) {
        return ERROR; // 内存分配失败
    }
    (*L)->next = NULL; // 初始化头节点的next指针为NULL
    return OK;
}

int SListLength(LinkList L) {
    LinkList p = L->next;
    int count = 0;
    while (p) {
        count++;
        p = p->next;
    }
    return count;
}

int SListEmpty(LinkList L) {
    return (L->next == NULL) ? TRUE : FALSE; // 如果头节点的next指针为NULL，说明链表为空
}

int GetSListElem(LinkList L, int pos, int* data) {
    if (L == NULL || pos < 1 || pos > SListLength(L) || data == NULL) {
        return ERROR; // 获取位置不合法
    }
    LinkList p = L->next; // 从第一个节点开始
    int i = 1;
    while (i < pos) {
        p = p->next;
        i++;
    }
    *data = p->data; // 获取目标节点的数据
    return OK;
}

int InsertSList(LinkList L, int pos, int data) {
    if (L == NULL || pos < 1 || pos > SListLength(L) + 1) {
        return ERROR; // 插入位置不合法
    }
    LinkList p = L; // 从头节点开始
    int i = 0;
    // 寻找插入位置的前一个节点
    while (i < pos - 1) {
        p = p->next;
        i++;
    }
    LinkList newNode = (LinkList)malloc(sizeof(Node)); // 创建新节点
    if (newNode == NULL) {
        return ERROR; // 内存分配失败
    }
    newNode->data = data; // 设置新节点的数据
    newNode->next = p->next; // 将新节点的next指向当前
    p->next = newNode; // 将前一个节点的next指向新节点
    return OK;
}

int DeleteSList(LinkList L, int pos, int* data) {
    if (L == NULL || SListEmpty(L) || pos < 1 || pos > SListLength(L) || data == NULL) {
        return ERROR; // 删除位置不合法
    }
    LinkList p = L; // 从头节点开始
    int i = 0;
    // 寻找删除位置的前一个节点
    while (i < pos - 1) {
        p = p->next;
        i++;
    }
    LinkList toDelete = p->next; // 待删除节点
    *data = toDelete->data; // 获取待删除节点的数据
    p->next = toDelete->next; // 前驱的后继 = 待删除节点的后继
    free(toDelete); // 释放待删除节点的内存
    return OK;
}

void TraverseSList(LinkList L) {
    LinkList p = L->next;
    while (p) {
        printf("%d ", p->data); // 访问当前节点的数据
        p = p->next;
    }
    printf("\n");
}

int DestroySList(LinkList* L) {
    if (L == NULL || *L == NULL) {
        return ERROR; // 链表不存在
    }
    LinkList p = *L;
    while (p) {
        LinkList temp = p;
        p = p->next;
        free(temp); // 释放当前节点的内存
    }
    *L = NULL; // 将链表指针置为NULL
    return OK;
}
