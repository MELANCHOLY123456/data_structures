#ifndef LINKLIST_H
#define LINKLIST_H

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;
typedef struct Node* LinkList;

// 单向链表
int InitSList(LinkList* L); // 初始化单向链表
int SListLength(LinkList L); // 获取单向链表长度
int SListEmpty(LinkList L); // 判断单向链表是否为空
int InsertSList(LinkList L, int pos, int data); // 按位置插入
int DeleteSList(LinkList L, int pos, int* data); // 按位置删除节点，返回删除值
void TraverseSList(LinkList L); // 遍历单向链表
int DestroySList(LinkList* L); // 销毁单向链表

// 双向链表
int InitDList(LinkList* L); // 初始化双向链表
int DListLength(LinkList L); // 获取双向链表长度
int DListEmpty(LinkList L); // 判断双向链表是否为空
int InsertDNode(LinkList L, int pos, int data); // 按位置插入节点
int DeleteDNode(LinkList L, int pos, int* data); // 按位置删除节点，返回删除值
void TraverseDList(LinkList L); // 遍历双向链表
int DestroyDList(LinkList* L); // 销毁双向链表

// 循环链表
int InitCList(LinkList* L); // 初始化循环链表
int CListLength(LinkList L); // 获取循环链表长度
int CListEmpty(LinkList L); // 判断循环链表是否为空
int InsertCNode(LinkList L, int pos, int data); // 按位置插入节点
int DeleteCNode(LinkList L, int pos, int* data); // 按位置删除节点，返回删除值
void TraverseCList(LinkList L); // 遍历循环链表
int DestroyCList(LinkList* L); // 销毁循环链表


#endif // LINKLIST_H
