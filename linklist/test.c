#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

// 链栈的单个节点
struct StackNode {
    int data;
    struct StackNode* next;
};

typedef struct StackNode StackNode;
typedef struct StackNode* LinkStackPtr;

// 链栈的整体结构
struct LinkStack {
    LinkStackPtr top; // 栈顶指针
    int count; // 栈中元素的数量
};
typedef struct LinkStack LinkStack;

int visit(int c) {
    printf("%d ", c);
    return OK;
}

// 构造一个空栈 
int InitStack(LinkStack* S) {
    S->top = NULL; // 初始化栈顶指针为NULL
    S->count = 0; // 初始化元素数量为0
    return OK;
}

// 把S置为空栈
int ClearStack(LinkStack* S) {
    LinkStackPtr p, q;
    p = S->top;
    while (p) {
        q = p;
        p = p->next;
        free(q); // 释放每个节点的内存
    }
    S->top = NULL; // 重置栈顶指针
    S->count = 0; // 重置元素数量
    return OK;
}

int StackEmpty(LinkStack S) {
    return S.count == 0 ? TRUE : FALSE; // 判断栈是否为空
}

int StackLength(LinkStack S) {
    return S.count; // 返回栈中元素的数量
}

int GetTop(LinkStack S, int* e) {
    if (StackEmpty(S)) {
        return ERROR; // 栈空时无法获取栈顶元素
    }
    *e = S.top->data; // 获取栈顶元素的值
    return OK;
}

int Push(LinkStack* S, int e) {
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode)); // 创建新节点
    if (!p) {
        return ERROR; // 内存分配失败
    }
    p->data = e; // 设置节点数据
    p->next = S->top; // 将新节点的next指向当前栈顶
    S->top = p; // 更新栈顶指针
    S->count++; // 增加元素数量
    return OK;
}

int Pop(LinkStack* S, int* e) {
    if (StackEmpty(*S)) {
        return ERROR; // 栈空时无法弹出元素
    }
    LinkStackPtr p = S->top; // 临时指针指向当前栈顶
    *e = p->data; // 获取栈顶元素的值
    S->top = p->next; // 更新栈顶指针
    free(p); // 释放原栈顶节点的内存
    S->count--; // 减少元素数量
    return OK;
}

int StackTraverse(LinkStack S) {
    LinkStackPtr p = S.top; // 从栈顶开始遍历
    while (p) {
        visit(p->data); // 访问当前节点的数据
        p = p->next; // 移动到下一个节点
    }
    printf("\n");
    return OK;
}

int main() {
    LinkStack S;
    int e; // 存储栈顶/出栈元素

    // 1. 测试初始化函数 InitStack
    printf("===== 1. 初始化栈 =====\n");
    if (InitStack(&S) == OK) {
        printf("栈初始化成功！当前栈元素数量：%d\n", S.count);
        printf("栈是否为空：%s\n", StackEmpty(S) ? "是" : "否");
    }
    else {
        printf("栈初始化失败！\n");
        return -1;
    }

    // 2. 测试入栈函数 Push + 栈长度 StackLength + 遍历 StackTraverse
    printf("\n===== 2. 入栈操作（入栈10、20、30、40）=====\n");
    Push(&S, 10);
    Push(&S, 20);
    Push(&S, 30);
    Push(&S, 40);
    printf("入栈后栈元素数量：%d\n", StackLength(S));
    printf("栈是否为空：%s\n", StackEmpty(S) ? "是" : "否");
    printf("栈内元素（栈顶→栈底）：");
    StackTraverse(S); // 遍历顺序：栈顶(40)→30→20→10(栈底)

    // 3. 测试获取栈顶元素 GetTop
    printf("\n===== 3. 获取栈顶元素 =====\n");
    if (GetTop(S, &e) == OK) {
        printf("当前栈顶元素：%d\n", e);
    }
    else {
        printf("获取栈顶元素失败（栈为空）！\n");
    }

    // 4. 测试出栈函数 Pop
    printf("\n===== 4. 出栈操作 =====\n");
    if (Pop(&S, &e) == OK) {
        printf("出栈元素：%d\n", e);
        printf("出栈后栈元素数量：%d\n", StackLength(S));
        printf("出栈后栈内元素（栈顶→栈底）：");
        StackTraverse(S); // 遍历顺序：栈顶(30)→20→10
    }
    else {
        printf("出栈失败（栈为空）！\n");
    }

    // 5. 测试清空栈函数 ClearStack
    printf("\n===== 5. 清空栈 =====\n");
    if (ClearStack(&S) == OK) {
        printf("栈清空成功！当前栈元素数量：%d\n", S.count);
        printf("栈是否为空：%s\n", StackEmpty(S) ? "是" : "否");
    }
    else {
        printf("栈清空失败！\n");
    }

    // 6. 测试空栈状态下的GetTop/Pop（边界测试）
    printf("\n===== 6. 空栈边界测试 =====\n");
    if (GetTop(S, &e) == ERROR) {
        printf("空栈获取栈顶元素：失败（符合预期）\n");
    }
    if (Pop(&S, &e) == ERROR) {
        printf("空栈出栈操作：失败（符合预期）\n");
    }

    printf("\n===== 所有函数测试完成 =====\n");
    return 0;
}

// 链式栈的栈顶节点，就是其底层链表的 “首元节点（第一个节点）