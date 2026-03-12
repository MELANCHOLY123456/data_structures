#include "linklist.h"
#include <stdio.h>

int main() {
    LinkList L;
    int result, data;

    printf("=== 单向链表功能测试 ===\n\n");

    // 1. 初始化链表
    printf("1. 测试初始化链表...\n");
    result = InitSList(&L);
    if (result != OK) {
        printf("初始化链表失败！\n");
        return 1;
    }
    printf("初始化成功！\n");

    // 2. 测试判断是否为空
    printf("\n2. 测试判断链表是否为空...\n");
    if (SListEmpty(L)) {
        printf("链表为空，正确！\n");
    }
    else {
        printf("链表不为空，错误！\n");
    }

    // 3. 测试获取长度
    printf("\n3. 测试获取链表长度...\n");
    printf("当前链表长度: %d\n", SListLength(L));

    // 4. 测试插入操作
    printf("\n4. 测试插入操作...\n");
    printf("在位置1插入元素10: ");
    result = InsertSList(L, 1, 10);
    if (result == OK) {
        printf("成功！\n");
    }
    else {
        printf("失败！\n");
    }

    printf("在位置2插入元素20: ");
    result = InsertSList(L, 2, 20);
    if (result == OK) {
        printf("成功！\n");
    }
    else {
        printf("失败！\n");
    }

    printf("在位置3插入元素30: ");
    result = InsertSList(L, 3, 30);
    if (result == OK) {
        printf("成功！\n");
    }
    else {
        printf("失败！\n");
    }

    printf("尝试在非法位置0插入元素50: ");
    result = InsertSList(L, 0, 50);
    if (result == OK) {
        printf("成功！(这不应该发生)\n");
    }
    else {
        printf("失败！(正确，位置非法)\n");
    }

    printf("当前链表长度: %d\n", SListLength(L));
    printf("当前链表内容: ");
    TraverseSList(L);

    // 5. 测试获取元素
    printf("\n5. 测试获取元素...\n");
    printf("获取位置1的元素: ");
    result = GetSListElem(L, 1, &data);
    if (result == OK) {
        printf("成功！值为 %d\n", data);
    }
    else {
        printf("失败！\n");
    }

    printf("获取位置2的元素: ");
    result = GetSListElem(L, 2, &data);
    if (result == OK) {
        printf("成功！值为 %d\n", data);
    }
    else {
        printf("失败！\n");
    }

    printf("尝试获取非法位置4的元素: ");
    result = GetSListElem(L, 4, &data);
    if (result == OK) {
        printf("成功！值为 %d (这不应该发生)\n", data);
    }
    else {
        printf("失败！(正确，位置非法)\n");
    }

    // 6. 测试删除操作
    printf("\n6. 测试删除操作...\n");
    printf("删除位置2的元素: ");
    result = DeleteSList(L, 2, &data);
    if (result == OK) {
        printf("成功！删除的值为 %d\n", data);
    }
    else {
        printf("失败！\n");
    }

    printf("当前链表长度: %d\n", SListLength(L));
    printf("当前链表内容: ");
    TraverseSList(L);

    printf("尝试删除非法位置5的元素: ");
    result = DeleteSList(L, 5, &data);
    if (result == OK) {
        printf("成功！删除的值为 %d (这不应该发生)\n", data);
    }
    else {
        printf("失败！(正确，位置非法)\n");
    }

    // 7. 再次测试判断是否为空和长度
    printf("\n7. 再次测试链表状态...\n");
    printf("当前链表是否为空: %s\n", SListEmpty(L) ? "是" : "否");
    printf("当前链表长度: %d\n", SListLength(L));

    // 8. 清空链表并测试
    printf("\n8. 清空链表...\n");
    while (!SListEmpty(L)) {
        DeleteSList(L, 1, &data);
        printf("删除元素: %d\n", data);
    }

    printf("清空后链表是否为空: %s\n", SListEmpty(L) ? "是" : "否");
    printf("清空后链表长度: %d\n", SListLength(L));

    // 9. 销毁链表
    printf("\n9. 测试销毁链表...\n");
    result = DestroySList(&L);
    if (result == OK) {
        printf("销毁成功！\n");
    }
    else {
        printf("销毁失败！\n");
    }

    printf("\n=== 所有测试完成 ===\n");
    return 0;
}
