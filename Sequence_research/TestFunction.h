#pragma once
#include <iostream>
#include "Sequence.h"
#include "Function.h"
#include "TagSequeue.h"
#include "stack.h"

using namespace std;

void TestQueue_T()
{
	int a[5] = {1,2,3,4,5};
	int x;

	TQueue q;
	InitQueue_T(q, 10);

	if (isEmpty_T(q))
	{
		cout << "队列为空！" << endl;
	}
	else
		cout << "队列不为空，初始化失败！" << endl;
	

	for (int i = 0; i < 5; i++)
	{
		Enqueue_T(q, a[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		Dequeue_T(q, x);
	}

	if (isEmpty_T(q))
	{
		cout << "队列为空！，出队成功" << endl;
	}
	else
		cout << "队列不为空，出队失败！" << endl;
}

void Testfunc02()
{
	int a[5] = { 1,2,3,4,5 };

	SqStack* s = (SqStack*)malloc(sizeof(SqStack));
	Queue* q = (Queue*)malloc(sizeof(Queue));

	InitStack_Sq(*s, 10, 5);
	InitQueue(*q, 10);

	for (int i = 0; i < 5; i++)
	{
		EnQueue(q, a[i]);
		cout << a[i] << " ,";
	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		//EnQueue(q, a[i]);
		cout << q->elem[i] << " ,";
	}
	cout << endl;
	
	if (func02(q, s))
	{
		cout << "转换成功！" << endl;
		for (int i = 0; i < 5; i++)
		{
			//EnQueue(q, a[i]);
			cout << q->elem[i] << " ,";
		}
		cout << endl;
	}
	else
		cout << "转换失败！" << endl;

}

void Testfunc03()
{
	int a[5] = { 1,2,3,4,5 };

	SqStack* s1 = (SqStack*)malloc(sizeof(SqStack));
	SqStack* s2 = (SqStack*)malloc(sizeof(SqStack));
	//Queue* q = (Queue*)malloc(sizeof(Queue));

	InitStack_Sq(*s1, 5, 0);
	InitStack_Sq(*s2, 5, 0);
	//InitQueue(*q, 10);

	for (int i = 0; i < 5; i++)
	{
		//push(*s, a[i]);
		EnQueue_2S(s1, s2, a[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		//push(*s, a[i]);
		DeQueue_2S(s1, s2, a[i]);
	}

	if (isFull(*s2))
		cout << "栈满！" << endl;
	else
		cout << "栈未满！" << endl;
}