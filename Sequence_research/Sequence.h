#pragma once
#include <iostream>

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;

#define QElemType int

/* ˳��洢�ṹ */
typedef struct
{
	QElemType* elem;
	int length;
	int rear, front;
}Queue;


//ѭ�����еĲ���
////��ʼ��
void InitQueue(Queue &Q,int len)
{
	Q.elem = (QElemType*)malloc(len * sizeof(QElemType));
	Q.rear = Q.front = 0;
}

//�ж϶��п�
bool isEmpty(Queue Q)
{
	if (Q.rear == Q.front)
		return true;
	else
		return false;
}

bool EnQueue(Queue *q,QElemType x)
{
	//����㷨

	if (q->rear == q->front && q->rear != 0)
		return false;

	q->elem[q->rear++] = x;
	return true;
}

//�����㷨
bool DeQueue(Queue &q, QElemType & x)
{
	if (q.rear == q.front)
		return false;

	x = q.elem[q.front++];

	return true;
}

/********************************/


/* ��ʽ���нṹ */
typedef struct QNode
{
	QElemType data;
	struct  QNode *next;
	//int length;
}QNode,*QPtr;

typedef struct
{
	QPtr front, rear;
}Quence;


Status initQuence_L(Quence &s)
//��ʼ��
{
	s.front = s.rear = (QPtr)malloc(sizeof(QNode));
	if (!s.front)
		return OVERFLOW;
	s.front->next = NULL;
	return OK;
}


Status DestroyQuence_L(Quence &q)
{
	while (q.front)
	{
		q.rear = q.front->next;
		free(q.front);
		q.front = q.rear;
	}
	return	OK;
}


Status EnQuence_L(Quence &Q, QElemType e)
{
	QPtr p;
	p = (QPtr)malloc(sizeof(Quence));
	if (!p)
		return OVERFLOW;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}


Status DeQuence_L(Quence &Q,QElemType &e)
{
	QPtr p;
	p = (QPtr)malloc(sizeof(QNode));
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return OK;
}


Status GetHead_L(Quence &Q, QElemType &e)
{
	if (Q.front)
	{
		e = Q.front->data;
		return OK;
	}
	else
		return	ERROR;
}