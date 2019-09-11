#pragma once
#include <iostream>
#include "Sequence.h"
#include "stack.h"

using namespace std;

bool func02(Queue *q, SqStack *s)
//逆置队列中所有元素的算法
// 王道 3.2 T2
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
//如果是循环队列呢？逆置元素的算法是？

//使用两个栈来模拟入队操作
bool EnQueue_2S(SqStack *q1,SqStack *q2,ElemType x)
{
	if (isFull(*q1))
		return false;
	push(*q1,x);
	return true;
}

//使用两个栈来模拟出队操作
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

//使用两个栈来模拟队列，判空操作
bool IsEmpty_2S(SqStack *q1,SqStack *q2)
{
	if (isEmpty(*q1) && isEmpty(*q2))
	{
		return true;
	}
	else
		return false;
}

//使用两个栈来模拟队列，清空队列操作
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

//使用两个栈来模拟队列，输出两个栈的操作
bool QueueOutStack_2S(SqStack* q1, SqStack* q2)
{
	if (!isEmpty(*q1) && !isEmpty(*q2))
	{
		return false;
	}
	else
	{
		cout << "栈1：	";
		OutStack(*q1);
		cout << "栈2：	";
		OutStack(*q2);
		return false;
	}
		
}

bool func04(char *in)
//《王道》 T3.3 T4
{
	if (NULL == in)
		return false;
	int size = 10;
	struct BoradQueue
	{
		char* queue;
		int front, rear;
		int num;		//Knum:客车数量，Hnum:货车数量
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