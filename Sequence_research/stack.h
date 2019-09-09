#pragma once
#include <iostream>

using namespace std;

#define ElemType int

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0
//#define OVERFLOW -1

typedef int Status;

typedef struct
{
	ElemType *elem;
	int top;
	int size;
	int increment;
}SqStack;


//初始化栈
Status InitStack_Sq(SqStack &S, int size, int inc)
{
	S.elem = (ElemType*)malloc(size * sizeof(ElemType));
	if (NULL == S.elem) return OVERFLOW;
	S.top = 0;
	S.size = size;
	S.increment = inc;
	return OK;
}


//判空函数
Status isEmpty(SqStack S)
{
	if (S.top == 0)
		return OK;
	else
		return ERROR;
}


//判满函数
Status isFull(SqStack S)
{
	if (S.top >= S.size)
		return OK;
	else
		return ERROR;
}


//置空函数
void ClearStack(SqStack &S)
{
	S.top = 0;
}


//销毁栈
void DestoryStack(SqStack &S)
{
	free(S.elem);
}

//出栈
Status pop(SqStack &S, ElemType &e)
{
	//判断栈是否为空
	if (S.top == 0) //如果top变量为指针则为（S.top==S.elem）
		return ERROR;
	S.top -= 1;
	e = S.elem[S.top];
	return OK;
}


//入栈
Status push(SqStack &S, ElemType e)
{
	//判断栈是否为满
	if (S.top >= S.size) //如果top变量为指针则为（S.top-S.elem>=S.size）
	{
		S.elem = (ElemType*)realloc(S.elem,(S.size + S.increment) * sizeof(ElemType));
		if (S.elem == NULL)
			return OVERFLOW;
		S.top = S.size;
		S.size += S.increment;
	}
	S.elem[S.top] = e;
	S.top++;
	return OK;
}


//输出栈里面的元素
void OutStack(SqStack S)
{
	ElemType e;
	//SqStack L = S;
	while (S.top)
	{
		pop(S,e);
		cout << e << " ";
	}
	cout << endl;
}


//逆序输出栈里面的元素
void OutStack_Inv(SqStack S)
{
	SqStack S0;
	InitStack_Sq(S0, 10, 4);

	ElemType e;
	//SqStack L = S;

	while (S.top)
	{
		pop(S, e);
		push(S0, e);
	}

	while (S0.top)
	{
		pop(S0, e);
		cout << e << " ";
	}
	cout << endl;
}

