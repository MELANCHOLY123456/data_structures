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
    CreateBiTree(&((*T)->lchild)); // 创建左子树
    CreateBiTree(&((*T)->rchild)); // 创建右子树
    return OK;
}

// 实现先序遍历
void PreOrderTraverse(BiTree T) {
    if (T) {
        printf("%d ", T->data);      // 访问根结点
        PreOrderTraverse(T->lchild); // 遍历左子树
        PreOrderTraverse(T->rchild); // 遍历右子树
    }
}

// 实现中序遍历
void InOrderTraverse(BiTree T) {
    if (T) {
        InOrderTraverse(T->lchild);
        printf("%d ", T->data);
        InOrderTraverse(T->rchild);
    }
}

// 实现后序遍历
void PostOrderTraverse(BiTree T) {
    if (T) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%d ", T->data);
    }
}


