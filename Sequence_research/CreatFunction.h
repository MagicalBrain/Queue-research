#pragma once
#include <iostream>
//#include "LinkList.h"
#include <time.h>
#include <windows.h>
#include "Strerror.h"

using namespace std;

/*
CreatFunction.h:
只放辅助测试函数
即用来测试的另外的一些操作，包括生成随机有序序列什么的
*/

//
int Randtou()
{
	srand((unsigned int)time(0));
	int re = rand();
	//re = re % 10;
	re = (re+1) % 2;
	return re;
}

int Randnum(int n)
{
	srand((unsigned int)time(0));
	int re = rand();
	re = re % n;
	return re;
}

//生成随机数列函数
int* CreatRand(int x)
/*
x:1，有序；0，无序。
输入数字n，生成n个随机元素的数组
*/
{
	int* p;
	cout << "输入随机数的个数" << endl;
	int n, len, tmp;
	cin >> n;
	cout << "输入随机数的大小范围：" << endl;
	cin >> len;

	p = (int*)malloc((n + 1) * sizeof(int));
	p[0] = n;

	cout << endl << "生成的随机数：" << endl;
	srand((unsigned int)time(0));
	for (int i = 1; i < n + 1; i++)
	{
		int re = rand();
		p[i] = re % len;
		cout << p[i] << " ";
	}
	cout << endl;

	if (x == 1)
	{
		for (int j = 1; j < p[0] + 1; j++)
		{
			for (int i = 1; i < p[0]; i++)
			{
				if (p[i] > p[i + 1])
				{
					tmp = p[i];
					p[i] = p[i + 1];
					p[i + 1] = tmp;
				}
			}
		}
		for (int i = 1; i <= p[0]; i++)
		{
			cout << p[i] << " ";
		}
		cout << endl;
	}

	return p;
}

int* CreatRand(int n, int x)
/*
x:1，有序；0，无序。
输入数字n，生成n个随机元素的数组
*/
{
	int* p;
	//cout << "输入随机数的个数" << endl;
	int len, tmp;
	//cin >> n;
	cout << "输入随机数的大小范围：" << endl;
	cin >> len;

	p = (int*)malloc((n + 1) * sizeof(int));
	p[0] = n;

	cout << endl << "生成的随机数：" << endl;
	srand((unsigned int)time(0));
	for (int i = 1; i < n + 1; i++)
	{
		int re = rand();
		p[i] = re % len;
		cout << p[i] << " ";
	}
	cout << endl;

	if (x == 1)
	{
		for (int j = 1; j < p[0] + 1; j++)
		{
			for (int i = 1; i < p[0]; i++)
			{
				if (p[i] > p[i + 1])
				{
					tmp = p[i];
					p[i] = p[i + 1];
					p[i + 1] = tmp;
				}
			}
		}
		for (int i = 1; i <= p[0]; i++)
		{
			cout << p[i] << " ";
		}
		cout << endl;
	}

	return p;
}

int* CreatRand(int n, int len, int x)
/*
x:1，有序；0，无序。
输入数字n，生成n个随机元素的数组
*/
{
	int* p;
	//cout << "输入随机数的个数" << endl;
	int tmp;
	//cin >> n;
	//cout << "输入随机数的大小范围：" << endl;
	//cin >> len;

	p = (int*)malloc((n + 1) * sizeof(int));
	p[0] = n;

	cout << endl << "生成的随机数：" << endl;
	srand((unsigned int)time(0));
	for (int i = 1; i < n + 1; i++)
	{
		int re = rand();
		p[i] = re % len;
		cout << p[i] << " ";
	}
	cout << endl;

	if (x == 1)
	{
		for (int j = 1; j < p[0] + 1; j++)
		{
			for (int i = 1; i < p[0]; i++)
			{
				if (p[i] > p[i + 1])
				{
					tmp = p[i];
					p[i] = p[i + 1];
					p[i + 1] = tmp;
				}
			}
		}
		for (int i = 1; i <= p[0]; i++)
		{
			cout << p[i] << " ";
		}
		cout << endl;
	}

	return p;
}