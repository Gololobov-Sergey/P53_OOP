#pragma once

#include <iostream>

using namespace std;

class Student
{
	char* name = nullptr;
	int age = 0;
	int* marks = nullptr;
	int sizeMarks = 0;

	//int id;

public:

	Student()
	{
		setName("");
		cout << "Default constructor called" << endl;
	}

	Student(const char* n, int a)
	{
		cout << "Parameterized constructor called" << endl;
		setName(n);
		setAge(a);
	}

	void setAge(int a) 
	{
		if (a < 0 || a > 100) 
		{
			age = 0; // Set to default value if invalid
		}
		else 
		{
			age = a;
		}
	}

	void setName(const char* n)
	{
		if (n != nullptr)
		{
			name = new char[strlen(n) + 1];
			strcpy(name, n);
		}
		else
		{
			name = nullptr;
		}
	}

	char* getName()
	{
		return name;
	}

	int getAge()
	{
		return age;
	}

	void displayInfo()
	{
		cout << "Name: " << name << ", Age: " << age << endl;
	}

	void setMark()
	{
		int m;
		cin >> m;
		setMark(m);
	}

	void setMark(int m)
	{
		int* newMarks = new int[sizeMarks + 1];
		for (size_t i = 0; i < sizeMarks; i++)
		{
			newMarks[i] = marks[i];
		}
		newMarks[sizeMarks] = m;
		delete[] marks;
		marks = newMarks;
		sizeMarks++;
	}
};
