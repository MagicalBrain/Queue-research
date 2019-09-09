#pragma once
#include <iostream>
#include "Sequence.h"
#include "stack.h"

using namespace std;

bool func02(Queue *q, SqStack *s)
//���ö���������Ԫ�ص��㷨
// ���� 3.2 T2
{
	if (q->front == q->rear)
		return false;

	int x;

	while (q->front != q->rear)
	{
		DeQueue(*q, x);
		push(*s, x);
	}
	q->front = 0;
	while (s->top != 0)
	{
		pop(*s, x);
		q->elem[q->front++]=x;
	}
	return true;
}
//�����ѭ�������أ�����Ԫ�ص��㷨�ǣ�

//ʹ������ջ��ģ����Ӳ���
bool EnQueue_2S(SqStack *q1,SqStack *q2,ElemType x)
{
	if (isFull(*q1))
		return false;
	push(*q1,x);
	return true;
}

//ʹ������ջ��ģ����Ӳ���
bool DeQueue_2S(SqStack* q1, SqStack* q2, ElemType &x)
{
	if (isEmpty(*q1))
		return false;

	ElemType t;
	while (pop(*q1, t))
	{
		push(*q2, t);
		if (isFull(*q2))
			return false;
	}

	pop(*q2, x);
	return true;
}

//ʹ������ջ��ģ����ն��в���
bool ClearQueue_2S(SqStack *q1,SqStack *q2)
{
	if (q1->top == 0)
	{
		return false;
	}
	else
		q1->top = 0;
	if (q2->top == 0)
	{
		return false;
	}
	else
		q2->top = 0;
	return true;
}