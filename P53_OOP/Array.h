#pragma once
#include<iostream>

using namespace std;

class Array
{
	int* arr = nullptr;
	int size = 0;

public:

	Array();

	explicit Array(int s);

	Array(const Array& obj);

	Array& operator=(const Array& obj);

	~Array();

	void create(int s);

	void setRand(int minValue = 0, int maxValue = 9) const;

	void show() const;

	void add(int value);

	void remove(int index);

	void insert(int value, int index);

	void sort() const;

	void reverse() const;

	void clear();

	void resize(int newSize);

	void fill(int value) const;

	int getSize() const;

	int countValue(const int& value) const;

	int findValue(const int& value) const;

	int get(int index) const;

	void set(int index, int value) const;

	int getMax() const;

	int getMin() const;

	int getSum() const;

	double getAverage() const;

	bool contains(int value) const;
};

Array::Array() : arr(nullptr), size(0) {}

Array::Array(int s)
{
	
	create(s);
	cout << "Constr " << arr << endl;
}

Array::Array(const Array& obj)
{
	
	size = obj.size;
	arr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
	cout << "CopyConstr " << arr << endl;
}

Array& Array::operator=(const Array& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	delete[] arr;

	size = obj.size;
	arr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}

	return *this;
}

Array::~Array()
{
	cout << "Destr " << arr << endl;
	delete[] arr;
}

void Array::create(int s)
{
	if (s < 0)
	{
		return;
	}
	size = s;
	arr = new int[size] { 0 };
}

void Array::setRand(int minValue, int maxValue) const
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (maxValue - minValue + 1) + minValue;
	}
}

void Array::show() const
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Array::add(int value)
{
	int* temp = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = value;
	delete[] arr;
	size++;
	arr = temp;
}

void Array::remove(int index)
{
	if (index < 0 || index >= size)
	{
		return;
	}
	int* temp = new int[size - 1];
	for (int i = 0; i < index; i++)
	{
		temp[i] = arr[i];
	}
	for (int i = index; i < size - 1; i++)
	{
		temp[i] = arr[i + 1];
	}
	delete[] arr;
	size--;
	arr = temp;
}

void Array::insert(int value, int index)
{
	if (index < 0 || index > size)
	{
		return;
	}
	int* temp = new int[size + 1];
	for (int i = 0; i < index; i++)
	{
		temp[i] = arr[i];
	}
	temp[index] = value;
	for (int i = index + 1; i <= size; i++)
	{
		temp[i] = arr[i - 1];
	}
	delete[] arr;
	size++;
	arr = temp;
}

void Array::sort() const
{
	for (int j = 0; j < size - 1; j++)
	{
		for (int i = 0; i < size - 1 - j; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
			}
		}
	}
}

void Array::reverse() const
{
	for (int i = 0; i < size / 2; i++)
	{
		swap(arr[i], arr[size - 1 - i]);
	}
}

void Array::clear()
{
	delete[] arr;
	arr = nullptr;
	size = 0;
}

void Array::resize(int newSize)
{
	if (newSize < 0)
	{
		return;
	}
	int limit = (newSize < size) ? newSize : size;
	int* temp = new int[newSize];
	for (int i = 0; i < limit; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	size = newSize;
	arr = temp;
}

void Array::fill(int value) const
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = value;
	}
}

int Array::getSize() const
{
	return size;
}

int Array::countValue(const int& value) const
{
	int countValue = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			countValue++;
		}
	}

	return countValue;
}

int Array::findValue(const int& value) const
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			return i;
		}
	}

	return -1;
}

int Array::get(int index) const
{
	if (index < 0 || index >= size)
	{
		return 0;
	}
	return arr[index];
}

void Array::set(int index, int value) const
{
	if (index < 0 || index >= size)
	{
		return;
	}
	arr[index] = value;
}

int Array::getMax() const
{
	if (size == 0)
	{
		return 0;
	}
	int maxVal = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (maxVal < arr[i])
		{
			maxVal = arr[i];
		}
	}
	return maxVal;
}

int Array::getMin() const
{
	if (size == 0)
	{
		return 0;
	}
	int minVal = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (minVal > arr[i])
		{
			minVal = arr[i];
		}
	}
	return minVal;
}

int Array::getSum() const
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

double Array::getAverage() const
{
	if (size == 0)
	{
		return 0;
	}
	return (double)getSum() / size;
}

bool Array::contains(int value) const
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			return true;
		}
	}
	return false;
}