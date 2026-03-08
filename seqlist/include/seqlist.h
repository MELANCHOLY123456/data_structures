#ifndef SEQLIST_H
#define SEQLIST_H

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

#define MAX_SIZE 20

struct Seqlist {
    int data[MAX_SIZE];
    int length;
};
typedef struct Seqlist Seqlist;


int InitList(Seqlist* L); // 初始化表。构造一个空的顺序表。
int ListLength(Seqlist* L); // 求表长。返回顺序表L的长度，即其中数据元素的个数。
int LocateElem(Seqlist* L, int data); // 按值查找操作。在表L中查找值为data的数据元素并返回其位置。
int GetElem(Seqlist* L, int pos, int* data); // 按位查找操作。获取表L中第pos个位置的元素值。
int ListInsert(Seqlist* L, int pos, int data); // 插入操作。在表L的第pos个位置插入值为data的数据元素。
int ListDelete(Seqlist* L, int pos, int* data); // 删除操作。删除表L中第pos个位置的元素，并返回其值。
void PrintList(Seqlist* L); // 输出操作。输出表L中所有元素的值。
int DestroyList(Seqlist* L); // 销毁表。销毁顺序表L，释放其占用的内存空间。

#endif // SEQLIST_H