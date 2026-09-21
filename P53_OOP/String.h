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
		size = strlen(str);
		this->str = new char[size + 1];
		strcpy(this->str, str);
	}

	String(const String& obj)
	{
		size = obj.size;
		str = new char[size + 1];
		strcpy(str, obj.str);
	}

	~String()
	{
		delete[] str;
	}

	String reSize()
	{
		size = 50;
		str = new char[size];
		return *this;
	}
};