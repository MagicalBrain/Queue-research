#pragma once
#include <iostream>

using namespace std;

#define ElemType int

typedef struct TQueue
{
	ElemType* elem;
	int rear, front, tag;
	int maxsize;
	/*
	* tag��
	* 0����ʾ��ͷ��βָ����ͬʱ������Ϊ�գ�
	* 1�����ʾ��ͷ��β��ͬʱ����Ϊ��
	*/
}TQueue;

void InitQueue_T(TQueue &q,int len)
{
	q.elem = (ElemType*)malloc(len * sizeof(ElemType));
	q.front = q.rear = 0;
	q.tag = 0;
	q.maxsize = len;
}

bool isEmpty_T(TQueue q)
{
	if (q.tag == 0 && q.rear == q.front)
		return true;
	else
		return false;
}

//����㷨
bool Enqueue_T(TQueue &q,ElemType x)
{
	if (q.tag == 1 && q.rear == q.front)
		return false;

	q.elem[q.rear] = x;
	q.rear = (q.rear + 1) % q.maxsize;

	if (q.front == q.rear)
	{
		q.tag = 1;
	}
	return true;
}

//�����㷨
bool Dequeue_T(TQueue &q,ElemType &x)
{
	if (q.tag == 1 && q.rear == q.front)
		return false;

	x = q.elem[q.front];
	q.front = (q.front + 1) % q.maxsize;

	if (q.front == q.rear)
	{
		q.tag = 0;
	}
	return true;
}