#ifndef TREE_H
#define TREE_H

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

struct BiTNode {
    ElemType data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
};

typedef struct BiTNode BiTNode;
typedef struct BiTNode* BiTree;


// ===================== 二叉树常用操作函数声明 =====================
// 1. 创建二叉树（按先序遍历输入，空结点用特殊值标识，如-1）
// 示例输入：1 2 -1 -1 3 -1 -1  表示：根1，左孩子2（无子孙），右孩子3（无子孙）
Status CreateBiTree(BiTree* T);

// 2. 销毁二叉树（释放所有结点内存，避免内存泄漏）
void DestroyBiTree(BiTree* T);

// 3. 先序遍历二叉树（根 -> 左 -> 右）
void PreOrderTraverse(BiTree T);

// 4. 中序遍历二叉树（左 -> 根 -> 右）
void InOrderTraverse(BiTree T);

// 5. 后序遍历二叉树（左 -> 右 -> 根）
void PostOrderTraverse(BiTree T);

// 6. 层序遍历二叉树（按层次从上到下、从左到右）
void LevelOrderTraverse(BiTree T);

// 7. 获取二叉树的结点个数
int GetBiTreeSize(BiTree T);

// 8. 获取二叉树的深度（高度）
int GetBiTreeDepth(BiTree T);

// 9. 查找指定值的结点（找到返回结点指针，否则返回NULL）
BiTNode* FindNode(BiTree T, ElemType target);

// 10. 清空二叉树（保留根结点，清空所有子结点）
Status ClearBiTree(BiTree T);


#endif // TREE_H