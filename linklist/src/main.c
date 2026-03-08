#include "linklist.h"
#include <stdio.h>

int main() {
    LinkList L;
    int i;
    i = InitSList(&L);
    if (i != OK) {
        printf("初始化链表失败\n");
        return 1;
    }
    printf("初始化L后：ListLength(L)=%d\n", CListLength(L));
}
