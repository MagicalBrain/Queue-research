#pragma once
#include <iostream>
using namespace std;

class Error
{
public:
	int errcode;
	char errmsg[40];
	Error(int code, char*msg)
	{
		errcode = code;
		strcpy_s(errmsg, msg);
	}
	void showerror()
	{
		cout << errcode << ":" << errmsg << endl;
	}
};

