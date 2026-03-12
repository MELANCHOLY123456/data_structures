#include <stdio.h>
#include "seqlist.h"

// 测试函数返回值的辅助函数
void test_result(const char* test_name, int result) {
    if (result == OK) {
        printf("✓ %s: 成功\n", test_name);
    }
    else {
        printf("✗ %s: 失败\n", test_name);
    }
}

int main() {
    Seqlist L;
    int data, pos;

    printf("=== 顺序表(Seqlist)功能测试 ===\n\n");

    // 1. 初始化测试
    printf("1. 测试初始化函数 InitList:\n");
    test_result("InitList", InitList(&L));
    printf("   初始化后表长: %d\n", ListLength(&L));
    printf("\n");

    // 2. 插入操作测试
    printf("2. 测试插入操作 ListInsert:\n");
    test_result("插入位置1, 值10", ListInsert(&L, 1, 10));
    test_result("插入位置2, 值20", ListInsert(&L, 2, 20));
    test_result("插入位置2, 值15", ListInsert(&L, 2, 15)); // 在中间插入
    test_result("在末尾插入30", ListInsert(&L, 4, 30));
    printf("   当前表内容: ");
    PrintList(&L);
    printf("   当前表长: %d\n", ListLength(&L));
    printf("\n");

    // 3. 按位查找测试
    printf("3. 测试按位查找 GetElem:\n");
    if (GetElem(&L, 1, &data) == OK) {
        printf("   位置1的元素: %d\n", data);
    }
    if (GetElem(&L, 3, &data) == OK) {
        printf("   位置3的元素: %d\n", data);
    }
    // 测试非法位置
    if (GetElem(&L, 10, &data) == ERROR) {
        printf("   ✓ 非法位置(10)查找失败，符合预期\n");
    }
    printf("\n");

    // 4. 按值查找测试
    printf("4. 测试按值查找 LocateElem:\n");
    pos = LocateElem(&L, 15);
    if (pos > 0) {
        printf("   值15的位置: %d\n", pos);
    }
    pos = LocateElem(&L, 25);
    if (pos == 0) {
        printf("   ✓ 值25未找到，返回0，符合预期\n");
    }
    printf("\n");

    // 5. 删除操作测试
    printf("5. 测试删除操作 ListDelete:\n");
    if (ListDelete(&L, 2, &data) == OK) {
        printf("   删除位置2的元素: %d\n", data);
        printf("   删除后表内容: ");
        PrintList(&L);
    }
    // 测试非法位置删除
    if (ListDelete(&L, 10, &data) == ERROR) {
        printf("   ✓ 非法位置(10)删除失败，符合预期\n");
    }
    printf("\n");

    // 6. 表长测试
    printf("6. 测试表长 ListLength:\n");
    printf("   当前表长: %d\n", ListLength(&L));
    printf("\n");

    // 7. 边界情况测试 - 满表测试
    printf("7. 测试边界情况 - 满表:\n");
    // 先清空表
    DestroyList(&L);
    InitList(&L);

    // 填充到最大容量
    for (int i = 1; i <= MAX_SIZE; i++) {
        ListInsert(&L, i, i * 10);
    }
    printf("   填充%d个元素后的表长: %d\n", MAX_SIZE, ListLength(&L));

    // 尝试插入超过容量
    if (ListInsert(&L, 1, 999) == ERROR) {
        printf("   ✓ 表满时插入失败，符合预期\n");
    }
    printf("\n");

    // 8. 销毁表测试
    printf("8. 测试销毁表 DestroyList:\n");
    test_result("DestroyList", DestroyList(&L));
    printf("   销毁后表长: %d\n", ListLength(&L));
    printf("\n");

    printf("=== 所有测试完成 ===\n");
    return 0;
}