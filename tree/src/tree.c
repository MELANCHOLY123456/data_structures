#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Status CreateBiTree(BiTree* T) {
    ElemType val;
    scanf("%d", &val);
    if (val == -1) {
        *T = NULL; // 空结点
        return OK;
    }
    *T = (BiTree)malloc(sizeof(BiTNode));
    if (!*T) {
        return ERROR; // 内存分配失败  
    }
    (*T)->data = val;
    CreateBiTree(&(*T)->lchild); // 创建左子树
    CreateBiTree(&(*T)->rchild); // 创建右子树
    return OK;
}

