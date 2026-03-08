#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

int InitDList(LinkList* L) {
    *L = (LinkList)malloc(sizeof(Node)); // 创建头节点
    if (*L == NULL) {
        return ERROR; // 内存分配失败
    }
    (*L)->next = NULL; // 初始化头节点的next指针为NULL
    (*L)->prev = NULL; // 初始化头节点的prev指针为NULL
    return OK;
}

int DListLength(LinkList L) {
    int length = 0;
    LinkList p = L->next; // 从首元节点开始
    while (p != NULL) { // 遍历链表直到尾节点
        length++;
        p = p->next; // 移动到下一个节点
    }
    return length;
}

int DListEmpty(LinkList L) {
    return (L->next == NULL) ? TRUE : FALSE; // 如果头节点的next指针为NULL，说明链表为空
}

int InsertDNode(LinkList L, int pos, int data) {
    if (pos < 1 || pos > DListLength(L) + 1) {
        return ERROR; // 位置不合法
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
    newNode->next = p->next; // 新节点的后继 = 前驱的后继
    newNode->prev = p; // 新节点的前驱 = 前驱
    if (p->next != NULL) {
        p->next->prev = newNode; // 如果前驱有后继，则后继的前驱 = 新节点
    }
    p->next = newNode; // 前驱的后继 = 新节点
    return OK;
}

int DeleteDNode(LinkList L, int pos, int* data) {
    if (DListEmpty(L) || pos < 1 || pos > DListLength(L) || data == NULL) {
        return ERROR;
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
    if (toDelete->next != NULL) {
        toDelete->next->prev = p; // 如果待删除节点有后继，则后继的前驱 = 前驱
    }
    free(toDelete); // 释放待删除节点的内存
    return OK;
}

void TraverseDList(LinkList L) {
    if (DListEmpty(L)) {
        printf("双向链表为空！\n");
        return;
    }

    // 1. 正向遍历
    printf("正向遍历双向链表：");
    LinkList p = L->next; // 从首元节点开始
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    // 2. 找到尾节点
    LinkList tail = L->next;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    // 3. 反向遍历
    printf("反向遍历双向链表：");
    while (tail != NULL) {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
    printf("\n");
}


int DestroyDList(LinkList* L) {
    LinkList p = (*L)->next; // 从首元节点开始
    while (p != NULL) {
        LinkList temp = p; // 保存当前节点
        p = p->next; // 移动到下一个节点
        free(temp); // 释放当前节点的内存
    }
    free(*L); // 释放头节点的内存
    *L = NULL; // 将链表指针置空
    return OK;
}
