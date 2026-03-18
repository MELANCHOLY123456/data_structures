#include "tree.h"
#include <stdio.h>

int main(int argc, char const* argv[]) {
    BiTree T;
    printf("请按先序输入二叉树结点（空结点输-1）：");
    CreateBiTree(&T); // 示例输入：1 2 -1 -1 3 -1 -1
    printf("先序遍历结果：");
    PreOrderTraverse(T); // 输出：1 2 3
    return 0;
}