#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

int InitCList(LinkList* L) {
    *L = (LinkList)malloc(sizeof(Node)); // 创建头节点
    if (*L == NULL) {
        return ERROR; // 内存分配失败
    }
    (*L)->next = *L; // 初始化头节点的next指针指向自己，形成循环
    return OK;
}

int CListLength(LinkList L) {
    LinkList p = L->next;
    int count = 0;
    while (p != L) { // 循环直到回到头节点
        count++;
        p = p->next;
    }
    return count;
}

int CListEmpty(LinkList L) {
    return L->next == L ? TRUE : FALSE; // 判断循环链表是否为空
}

// 按位置插入节点（pos从1开始，支持尾插）
// 找到前驱节点，插入后保持闭环
int InsertCNode(LinkList L, int pos, int data) {
    if (L == NULL || pos<1 || pos>CListLength(L) + 1) {
        return ERROR; // 插入位置不合法
    }
    LinkList p = L;
    int i = 0;
    while (i < pos - 1) { // 找到插入位置的前一个节点
        p = p->next;
        i++;
    }
    LinkList newNode = (LinkList)malloc(sizeof(Node)); // 创建新节点
    if (newNode == NULL) {
        return ERROR; // 内存分配失败   
    }
    newNode->data = data; // 设置节点数据
    newNode->next = p->next; // 将新节点的next指向当前
    p->next = newNode; // 将前一个节点的next指向新节点
    return OK;
}

int DeleteCNode(LinkList L, int pos, int* data) {
    if (L == NULL || pos < 1 || pos > CListLength(L) || CListEmpty(L)) {
        return ERROR; // 删除位置不合法
    }
    LinkList p = L;
    int i = 0;
    while (i < pos - 1) { // 找到删除位置的前一个节点
        p = p->next;
        i++;
    }
    LinkList toDelete = p->next; // 待删除节点
    *data = toDelete->data; // 获取待删除节点的数据
    p->next = toDelete->next; // 将前一个节点的next指向待删除节点的下一个节点
    free(toDelete); // 释放待删除节点的内存
    return OK;
}

void TraverseCList(LinkList L) {
    LinkList p = L->next;
    while (p != L) { // 循环直到回到头节点
        printf("%d ", p->data); // 访问当前节点的数据
        p = p->next; // 移动到下一个节点
    }
    printf("\n");
}

int DestroyCList(LinkList* L) {
    if (L == NULL || *L == NULL) {
        return ERROR; // 链表不存在
    }
    LinkList p = (*L)->next;
    while (p != *L) { // 循环直到回到头节点
        LinkList temp = p;
        p = p->next; // 移动到下一个节点
        free(temp); // 释放当前节点的内存
    }
    free(*L); // 释放头节点的内存
    *L = NULL; // 将链表指针置空
    return OK;
}
