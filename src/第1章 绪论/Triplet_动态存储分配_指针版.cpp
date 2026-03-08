/*
	���ʵ�ֳ����������͡���Ԫ�� ��Triplet���� ��ÿ����Ԫ��
����������ʵ�������й��ɣ�������������������һ����Ԫ�飬
ȡ��Ԫ�������һ������������Ԫ�������һ������������Ԫ��
������������С��������ʾ��Ԫ�飬������Ԫ��ȡ�

	����2����ָ����������Ԫ�顱��Ҫ�󣺶�̬�����ڴ档
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2 

typedef int Status;
typedef float ElemType;  //��Ԫ��������ȶ���Ϊfloat,������ʱ�任�ɱ������ 
typedef ElemType* Triplet;//����TripletΪElemTypeָ������ 

//��Ԫ��ĳ�ʼ��
Status initTriplet(Triplet* T, ElemType v0, ElemType v1, ElemType v2)  // Triplet *T����д�� ElemType **T 
{
	(*T) = (ElemType*)malloc(3 * sizeof(ElemType));
	if ((*T) == NULL) {
		printf("�����ڴ�ʧ�ܣ�");
		exit(OVERFLOW);
	}
	*(*T + 0) = v0;
	*(*T + 1) = v1;
	*(*T + 2) = v2;
	return OK;
}
Status destroyTriplet(Triplet* T) {
	free(*T);
	*T = NULL;
	printf("�����ڴ����ͷţ�");
	return OK;
}
//��e��ȡT�ĵ�i(1~3)��Ԫ�ص�ֵ�� 
Status getElem(Triplet T, int i, ElemType* e) {
	if (i < 1 || i>3)
		return ERROR;
	else *e = T[i - 1];
	return OK;
}
//��T�ĵ�iԪ��ֵΪe 
Status putElem(Triplet* T, int i, ElemType e) {
	if (i < 1 || i>3)
		return ERROR;
	else *(*T + i - 1) = e;
	return OK;
}
//���T������Ԫ�ذ��������У��򷵻�1�����򷵻�0
Status isAscending(Triplet T) {
	return (T[0] <= T[1]) && (T[1] <= T[2]);
}
//���T������Ԫ�ذ��������У��򷵻�1�����򷵻�0
Status isDescending(Triplet T) {
	return (T[0] >= T[1]) && (T[1] >= T[2]);
}
//��e����ָ��T�����Ԫ�ص�ֵ
ElemType getMax(Triplet T) {
	ElemType e;
	if (T[0] > T[1])
		e = T[0];
	else
		e = T[1];
	if (T[2] > e)
		e = T[2];
	return e;
}
//��e����ָ��T����СԪ�ص�ֵ
ElemType getMin(Triplet T) {
	ElemType e;
	if (T[0] < T[1])
		e = T[0];
	else
		e = T[1];
	if (T[2] < e)
		e = T[2];
	return e;
}
int main() {
	Status flag;
	ElemType v0, v1, v2, e;
	Triplet T;
	printf("�������Ԫ�������ֵv0,v1,v2:\n");
	scanf("%f,%f,%f", &v0, &v1, &v2);
	flag = initTriplet(&T, v0, v1, v2);
	printf("���ó�ʼ��������flag=%d,T������ֵΪ��%4.2f,%4.2f,%4.2f\n", flag, T[0], T[1], T[2]);
	if (isAscending(T))
		printf("����Ԫ��Ԫ��Ϊ����\n");
	if (isDescending(T))
		printf("����Ԫ��Ԫ��Ϊ����\n");
	printf("����Ԫ���е����ֵΪ��%4.2f,��СֵΪ��%4.2f\n", getMax(T), getMin(T));
	destroyTriplet(&T);
	return OK;
}

