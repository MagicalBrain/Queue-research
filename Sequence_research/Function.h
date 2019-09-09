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

//使用两个栈来模拟清空队列操作
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