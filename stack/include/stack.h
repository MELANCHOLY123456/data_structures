#ifndef STACK_H
#define STACK_H

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

struct StackNode {
    int data;
    struct StackNode* next;
};

typedef struct StackNode StackNode;
typedef struct StackNode* LinkStackPtr;

// top为栈顶指针，始终指向链表的第一个节点（即最新压入的元素）
typedef struct {
    LinkStackPtr top;
    int count;
} LinkStack;

// 初始化栈
int InitStack(LinkStack* S);
// 判断栈是否为空
int StackEmpty(LinkStack S);
// 入栈（压栈）
int Push(LinkStack* S, int e);
// 出栈（弹栈）
int Pop(LinkStack* S, int* e);
// 获取栈顶元素
int GetTop(LinkStack S, int* e);
// 清空栈
int ClearStack(LinkStack* S);
// 获取栈的长度
int StackLength(LinkStack* S);
// 遍历栈
int StackTraverse(LinkStack S);

#endif // STACK_H