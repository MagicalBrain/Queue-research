#pragma once
#include <iostream>
#include <string.h>
#include "CreatFunction.h"

using namespace std;

#define ElemType char

typedef struct LNodes
{
	ElemType data;
	struct LNodes *next;
} LNodes, *LinkedList;

//基本操作：

////1、初始化链表
LinkedList LinkedListInit(int tou) {
	/*参数:
	tou:
	1:初始化成带头结点的
	0：~不带头节点的
	*/
	LinkedList L;
	L = (LinkedList)malloc(sizeof(LNodes));   //申请结点空间   
	if (L == NULL) { //判断是否有足够的内存空间   
		printf("申请内存空间失败\n");
	}
	if (tou)
	{
		L->data = -1;
		L->next = NULL;
	}
	//将next设置为NULL,初始长度为0的单链表
	else
		L = NULL;//将next设置为NULL,初始长度为0的单链表   
	return L;
}

////2、求表长
int Length(LNodes* L,int tou)
{
	LNodes* p;
	int re = 0;
	if (tou)
	{
		if (L->next == NULL)
			return 0;
		else
		{
			p = L->next;
			while (p)
			{
				re++;
				p = p->next;
			}

			return re;
		}
	}
	else
	{
		if (L == NULL)
			return 0;
		else
		{
			p = L;
			while (p)
			{
				re++;
				p = p->next;
			}
			return re;
		}
	}

	return 0;
}

////3、按值查找
int LocateElem(LNodes* L, int tou,int e)
{
	LNodes* p;
	int num = 0;
	switch (tou)
	{
	case 1:
		if (L->next != NULL)
		{
			p = L->next;
			while (p)
			{
				if (p->data == e)
				{
					return num;
				}
				p = p->next;
				num++;
			}
		}
		break;
	case 0:
		if (L != NULL)
		{
			p = L;
			while (p)
			{
				if (p->data == e)
				{
					return num;
				}
				p = p->next;
				num++;
			}
		}
		break;
	default:
		break;
	}

	return -1;
}


////4、按序号查找
int GetElem(LNodes* L, int tou, int loca)
{
	LNodes* p;
	int num = 0;
	if (loca < 0)
	{
		return -1;
	}
	if (tou == 1)
	{
		if (L->next != NULL)
		{
			p = L->next;
			while (p)
			{
				if (num == loca)
					return p->data;
				num++;
				p = p->next;
			}
		}
	}
	else if (tou == 0)
	{
		if (L != NULL)
		{
			p = L;
			while (p)
			{
				if (num == loca)
					return p->data;
				num++;
				p = p->next;
			}
		}
	}
	return -1;
}

////5、插入操作
int LinkListInsert(LNodes* L, int tou, int e, int loca)
{
	LNodes* p, * q;
	int num = 0;
	if (loca < 0)
	{
		return -1;
	}
	if (tou == 1)
	{
		if (L->next != NULL)
		{
			p = L->next;

			if (loca == 0)
			{
				q = (LNodes*)malloc(sizeof(LNodes));
				q->data = e;

				q->next = p->next;
				p->next = q;

				int t;
				t = q->data;
				q->data = p->data;
				p->data = t;
				return 1;
			}

			while (p)
			{
				num++;
				if (num == loca)
				{
					q = (LNodes*)malloc(sizeof(LNodes));
					q->data = e;

					q->next = p->next;
					p->next = q;
					return 1;
				}
				
				p = p->next;
			}
		}
	}
	else if (tou == 0)
	{
		if (L != NULL)
		{
			p = L;

			if (loca == 0)
			{
				q = (LNodes*)malloc(sizeof(LNodes));
				q->data = e;

				q->next = p->next;
				p->next = q;

				int t;
				t = q->data;
				q->data = p->data;
				p->data = t;
				return 1;
			}

			while (p)
			{
				num++;
				if (num == loca)
				{
					q = (LNodes*)malloc(sizeof(LNodes));
					q->data = e;

					q->next = p->next;
					p->next = q;
					return 1;
				}
				p = p->next;
			}
		}
	}
	return 0;
}

////6、删除操作
LNodes* LinkListDelete(LNodes* L, int tou, int e)
{
	LNodes* p, * q;
	int num = 0, l = Length(L, tou);
	
	if (tou == 1)
	{
		if (L->next != NULL)
		{
			p = L->next;
			q = L;
			while (p)
			{
				if (p->data == e)
				{
					q->next = p->next;
					free(p);
					return L;
				}
				num++;
				p = p->next;
				q = q->next;
			}

		}
	}
	else if (tou == 0)
	{
		if (L != NULL)
		{
			q = L;
			p = L->next;
			if (L->data == e)
			{
				L = L->next;
				free(q);
				return L;
			}
			while (p)
			{
				if (p->data == e)
				{
					q->next = p->next;
					free(p);
					//L = q;
					//break;
					return L;
				}
				num++;
				p = p->next;
				q = q->next;
			}

		}
	}
	return NULL;
}


LNodes* LinkListDelete(LNodes* L, int tou, int loca, int* e)
{
	LNodes* p, * q;
	int num = 0, l=Length(L,tou);
	if (loca < 0 || loca >= l)
	{
		return 0;
	}
	if (tou == 1)
	{
		if (L->next != NULL)
		{
			p = L->next;

			while (p)
			{
				if (num == loca)
				{
					q = p;
					p = p->next;
					*e = q->data;
					free(q);
					break;
					//return e;
				}
				num++;
				p = p->next;
			}
			
		}
	}
	else if (tou == 0)
	{
		if (L != NULL)
		{
			p = L;
			if (loca > 0)
			{
				while (p)
				{
					if (num == loca)
					{
						q = p;
						p = p->next;
						*e = q->data;
						free(q);
						break;
						//return e;
					}
					num++;
					p = p->next;
				}
			}
			else
			{
				q = p;
				L = p->next;
				L->next = p->next->next;
				*e = q->data;
				free(q);
				//return e;
			}
			
		}
	}
	return L;
}

////7、输出操作
//输出链表内所有元素的数据
int LinkedOutput(LinkedList L, int tou)
{
	//put(str);
	if (tou)
	{
		if (L->next!=NULL)
		{
			LNodes* p = L->next;
			while (p != NULL)
			{
				cout << p->data << " ,";
				p = p->next;

			}
			cout << endl;
			return 1;
		}
		
	}
	else
	{
		if (L!=NULL)
		{
			LNodes* p = L;
			while (p != NULL)
			{
				cout << p->data << " ";
				p = p->next;
			}
			cout << endl;
			return 1;
		}
		
	}

	cout << "输出失败！表为空！" << endl;
	return 0;
}

////8、判空操作
int isEmpty(LNodes* L, int tou)
{
	if (tou)
	{
		if (L->next == NULL)
			return 1;
		else
			return 0;
	}
	else
	{
		if (L == NULL)
			return 1;
		else
			return 0;
	}
	return 0;
}

////9、销毁操作
LNodes* LinkListDestroy(LNodes* L,int tou)
{
	LNodes* p, *q;
	if (tou==1)
	{
		if (L->next != NULL)
		{
			p = L->next;
			while (p)
			{
				q = p;
				p = p->next;
				
				free(q);
			}
			L->next = NULL;
			return L;
		}
	}
	else if (tou==0)
	{
		if (L != NULL)
		{
			p = L;
			while (p)
			{
				q = p;
				p = p->next;
				free(q);
			}
			L = NULL;
			return L;
		}
	}
	return NULL;
}


//给链表输入数据
////带头结点的
void LinkedInput(LinkedList &L, ElemType a[], int length,int tou) {
	/*参数:
	tou: 
		1:初始化成带头结点的
		0：~不带头节点的
	*/
	if (tou)
	{
		LinkedList q = L;
		for (int i = length - 1; i >= 0; --i)
		{
			LNodes* p = (LinkedList)malloc(sizeof(LNodes));
			p->data = a[i];
			p->next = q->next;
			q->next = p;
		}
	}
	else
	{
		LinkedList q = L;
		//q->data = a[0];
		for (int i = length - 1; i >= 0; --i)
		{
			LNodes* p = (LinkedList)malloc(sizeof(LNodes));
			p->data = a[i];
			p->next = L;
			L = p;
		}
	}
	
}


void LinkedInput(LinkedList& L, int tou) {
	/*参数:
	tou:
		1:初始化成带头结点的
		0：~不带头节点的
	*/
	int* a;
	a = CreatRand(0);
	int length = a[0];
	if (tou)
	{
		LinkedList q = L;
		for (int i = length; i > 0; --i)
		{
			LNodes* p = (LinkedList)malloc(sizeof(LNodes));
			p->data = a[i];
			p->next = q->next;
			q->next = p;
		}
	}
	else
	{
		LinkedList q = L;
		//q->data = a[0];
		for (int i = length; i > 0; --i)
		{
			LNodes* p = (LinkedList)malloc(sizeof(LNodes));
			p->data = a[i];
			p->next = L;
			L = p;
		}
	}

}

void LinkedInput(LinkedList& L, int tou,int x) {
	/*参数:
	tou:
		1:初始化成带头结点的
		0：~不带头节点的
	*/
	int* a;
	switch (x)
	{
	case 1:
		a = CreatRand(1);
		break;
	default:
		a = CreatRand(0);
		break;
	}
	
	int length = a[0];
	if (tou)
	{
		LinkedList q = L;
		for (int i = length; i > 0; --i)
		{
			LNodes* p = (LinkedList)malloc(sizeof(LNodes));
			p->data = a[i];
			p->next = q->next;
			q->next = p;
		}
	}
	else
	{
		LinkedList q = L;
		//q->data = a[0];
		for (int i = length; i > 0; --i)
		{
			LNodes* p = (LinkedList)malloc(sizeof(LNodes));
			p->data = a[i];
			p->next = L;
			L = p;
		}
	}

}

