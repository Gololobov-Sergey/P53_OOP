#pragma once


template<class T>
class SmartPointer
{
	T* ptr;
	int* count;

public:
	SmartPointer(T* p) : ptr(p) {}
	~SmartPointer() { delete ptr; }
	T& operator*() { return *ptr; }
	T* operator->() { return ptr; }

	SmartPointer(const SmartPointer& obj) = delete;
	SmartPointer& operator=(const SmartPointer& obj) = delete;

	SmartPointer(SmartPointer&& obj)
	{
		ptr = obj.ptr;
		obj.ptr = nullptr;
	}

	SmartPointer& operator=(SmartPointer&& obj)
	{
		if (&obj == this)
			return *this;

		delete ptr;

		ptr = obj.ptr;
		obj.ptr = nullptr;

		return *this;
	}

};
