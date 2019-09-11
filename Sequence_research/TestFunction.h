#pragma once
#include <iostream>
#include "Sequence.h"
#include "Function.h"
#include "TagSequeue.h"
#include "stack.h"
#include "StrError.h"

using namespace std;

void TestQueue_T()
{
	int a[5] = {1,2,3,4,5};
	int x;

	TQueue q;
	InitQueue_T(q, 10);

	if (isEmpty_T(q))
	{
		cout << "����Ϊ�գ�" << endl;
	}
	else
		cout << "���в�Ϊ�գ���ʼ��ʧ�ܣ�" << endl;
	

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
		cout << "����Ϊ�գ������ӳɹ�" << endl;
	}
	else
		cout << "���в�Ϊ�գ�����ʧ�ܣ�" << endl;
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
		cout << "ת���ɹ���" << endl;
		for (int i = 0; i < 5; i++)
		{
			//EnQueue(q, a[i]);
			cout << q->elem[i] << " ,";
		}
		cout << endl;
	}
	else
		cout << "ת��ʧ�ܣ�" << endl;

}

void Testfunc03()
{
	int x = 1;
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
	QueueOutStack_2S(s1, s2);

	EnQueue_2S(s1, s2, x);

	for (int i = 0; i < 5; i++)
	{
		//push(*s, a[i]);
		QueueOutStack_2S(s1, s2);
		DeQueue_2S(s1, s2, a[i]);
	}
	

	if (isFull(*s2))
		cout << "ջ����" << endl;
	else
		cout << "ջδ����" << endl;

	//EnQueue_2S(s1, s2, 10);
	

	if (ClearQueue_2S(s1, s2))
		cout << "����ɹ���" << endl;
	else
		cout << "���ʧ�ܣ�" << endl;
}

void Testfunc04()
{
	char str[100]="";
	cin >> str;
	str[10] = '\0';
	try
	{
		char c;
		int num = 0;
		//c = str[0];
		while (str[num]!= '\0')
		{
			c = str[num];
			if (c != 'K' && c != 'H')
			{
				Error err1(-1, "�����˷Ƿ��ַ���");
				throw(err1);
			}
			num++;
		}
		
		if (num < 10)
		{
			Error err2(-2, "���볤�ȹ��̣�");
			throw(err2);
		}
		else if (num > 10)
		{
			Error err3(-3, "���볤�ȹ�����");
			throw(err3);
		}

		cout << "����s��" << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << str[i] << ", ";
		}
		cout << endl;
		
		//������ñ����Ժ�����
		if (func04(str))
		{
			cout << "����ɹ���" << endl;
		}
		else
		{
			cout << "����ʧ�ܣ�" << endl;
		}
	}
	catch (Error err1)
	{
		err1.showerror();
		exit(0);
	}
	
}