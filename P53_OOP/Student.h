#pragma once

#include <iostream>

#include"Array.h"

using namespace std;

class Student
{
	char* name      = nullptr;
	int   age       = 0;
	Array marks;

	const int id;

	static int count;

public:

	Student(int id) : id{ id }
	{
		setName("");
		cout << "Default constructor called" << endl;
		count++;
	}

	Student(int id, const char* n, int a) : id{ id }
	{
		cout << "Parameterized constructor called" << endl;
		setName(n);
		setAge(a);
		count++;
	}

	~Student()
	{
		cout << "Destructor called" << endl;
		delete[] name;
		//delete[] marks;
		count--;
	}

	void setAge(int a) 
	{
		if (a < 0 || a > 100) 
		{
			return; // age = 0; // Set to default value if invalid
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
		cout << "ID: " << id << ", Name: " << name << ", Age : " << age << endl;
		cout << "Marks: ";
		marks.show();
	}

	void setMark()
	{
		int m;
		cin >> m;
		setMark(m);
	}

	void setMark(int m)
	{
		marks.add(m);

		//int* newMarks = new int[sizeMarks + 1];
		//for (size_t i = 0; i < sizeMarks; i++)
		//{
		//	newMarks[i] = marks[i];
		//}
		//newMarks[sizeMarks] = m;
		//delete[] marks;
		//marks = newMarks;
		//sizeMarks++;
	}

	static int getCount()
	{
		return count;
	}
};

int Student::count = 0;
