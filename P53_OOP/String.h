#pragma once
#include <iostream>

using namespace std;

class String
{
	char* str;
	int size;

public:
	String(const char* str)
	{
		int len = strlen(str);
		this->str = new char[len + 1];
		strcpy(this->str, str);
	}

	String reSize()
	{
		size = 50;
		str = new char[size];
		return *this;
	}
};