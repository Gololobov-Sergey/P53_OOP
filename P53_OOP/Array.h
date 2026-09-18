#pragma once
#include <iostream>

using namespace std;

class Array
{
	int* arr;
	int size;

public:

	Array();

	explicit Array(int s);

	~Array();

	void setRandom() const;

	void show() const;

	void add(int value);

	void remove(int index);

	void insert(int index, int value);

	void sort() const;

	void reverse() const;

	void clear();

	void resize(int newSize);

	void fill(int value);

	int getSize();
};


Array::Array() : arr(nullptr), size(0)
{

}

Array::Array(int s)
{
	size = s;
	arr = new int[size];
}

Array::~Array()
{
	delete[] arr;
}

void Array::setRandom() const
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

void Array::show() const
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Array::add(int value)
{

}

void Array::remove(int index)
{

}

void Array::insert(int index, int value)
{

}

void Array::sort() const
{

}

void Array::reverse() const
{

}

void Array::clear()
{

}

void Array::resize(int newSize)
{

}

void Array::fill(int value)
{

}

int Array::getSize()
{
	return size;
}
