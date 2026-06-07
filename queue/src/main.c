#include "queue.h"
#include <stdio.h>

int main() {
    SqQueue Q;
    int x;  // 用来接收出队的元素

    // 1. 初始化队列
    InitQueue(&Q);
    printf("队列初始化完成！\n\n");

    // 2. 判断队列是否为空
    if (QueueEmpty(Q)) {
        printf("队列为空 ✔\n");
    }
    else {
        printf("队列不为空 ✘\n");
    }

    // 3. 入队测试
    printf("\n开始入队 10, 20, 30...\n");
    EnQueue(&Q, 10);
    EnQueue(&Q, 20);
    EnQueue(&Q, 30);

    // 4. 出队测试
    printf("\n开始出队：\n");
    DeQueue(&Q, &x); printf("出队元素：%d\n", x);
    DeQueue(&Q, &x); printf("出队元素：%d\n", x);
    DeQueue(&Q, &x); printf("出队元素：%d\n", x);

    // 5. 再出队（测试空队出队）
    printf("\n队列已空，再尝试出队：");
    if (DeQueue(&Q, &x) == FALSE) {
        printf("失败！队空 ✔\n");
    }

    printf("\n所有测试正常结束！\n");
    return 0;
}