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

	if (isEmpty(*q1) && isEmpty(*q2))
		return false;
	//else


	ElemType t;
	while (pop(*q1, t))
	{
		push(*q2, t);
		if (isFull(*q2))
			break;
	}

	pop(*q2, x);
	return true;
}

//ʹ������ջ��ģ����У��пղ���
bool IsEmpty_2S(SqStack *q1,SqStack *q2)
{
	if (isEmpty(*q1) && isEmpty(*q2))
	{
		return true;
	}
	else
		return false;
}

//ʹ������ջ��ģ����У���ն��в���
bool ClearQueue_2S(SqStack* q1, SqStack* q2)
{
	if (!isEmpty(*q1) && !isEmpty(*q2))
	{
		q1->top = 0;
		q2->top = 0;
		return true;
	}
	else
		return false;
}

//ʹ������ջ��ģ����У��������ջ�Ĳ���
bool QueueOutStack_2S(SqStack* q1, SqStack* q2)
{
	if (!isEmpty(*q1) && !isEmpty(*q2))
	{
		return false;
	}
	else
	{
		cout << "ջ1��	";
		OutStack(*q1);
		cout << "ջ2��	";
		OutStack(*q2);
		return false;
	}
		
}

bool func04(char *in)
//�������� T3.3 T4
{
	if (NULL == in)
		return false;
	int size = 10;
	struct BoradQueue
	{
		char* queue;
		int front, rear;
		int num;		//Knum:�ͳ�������Hnum:��������
	};

	int num = 0;
	char c,t;
	char s1[100],s2[100];
	c = in[num];
	
	BoradQueue* sK, * sH;
	sK = (BoradQueue*)malloc(sizeof(BoradQueue));
	sH = (BoradQueue*)malloc(sizeof(BoradQueue));
	
	sK->queue = s1;
	sK->front = -1, sK->rear = 0;

	sH->queue = s2;
	sH->front = -1, sH->rear = 0;

	while (in[num]!='\0')
	{
		c = in[num];
		if (c == 'K')
		{
			sK->queue[sK->rear++] = c;
			sK->num++;
		}
		else
		{
			sH->queue[sH->rear++] = c;
			sH->num++;
		}
		num++;
	}

	c = sK->queue[++sK->front];
	num = 0;
	while (sK->front < sK->rear)
	{
		cout << c << ", ";
		num++;
		if (num == 4 && sH->rear > 0)
		{
			cout << sH->queue[++sH->front] << " ,";
			num = 0;
		}
		c = sK->queue[++sK->front];
	}

	if (sH->front <sH->rear-1)
	{
		while (sH->front <sH->rear-1)
		{
			cout << sH->queue[++sH->front] << " ,";
		}
	}
	cout << endl;

	return true;
}