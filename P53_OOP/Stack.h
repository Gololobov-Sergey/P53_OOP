#pragma once

#include"Node.h"


template<class T, size_t maxSize>
class Stack
{
	Node<T>* first;
	size_t   size;

public:
	Stack();
	~Stack();
	Stack(const Stack& obj);
	Stack& operator=(const Stack& obj);

	void   push(const T& value);
	void   pop();
	T&     peek() const;
	bool   isEmpty() const;
	void   clear();
	size_t getSize() const;
	void   print() const;
};

template<class T, size_t maxSize>
Stack<T, maxSize>::Stack() : first(nullptr), size(0) {}

template<class T, size_t maxSize>
Stack<T, maxSize>::~Stack()
{
	clear();
}

template<class T, size_t maxSize>
Stack<T, maxSize>::Stack(const Stack& obj)
{

}

template<class T, size_t maxSize>
Stack<T, maxSize>& Stack<T, maxSize>::operator=(const Stack<T, maxSize> & obj)
{
	return *this;
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::push(const T& value)
{
	if (size < maxSize)
	{
		if (size == 0)
		{
			first = new Node<T>(value);
		}
		else
		{
			Node<T>* newNode = new Node<T>(value);
			newNode->next = first;
			first = newNode;
		}
		size++;
	}
	else
	{
		cout << "Stack overflow!" << endl;
	}
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::pop()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
	}
}

template<class T, size_t maxSize>
T& Stack<T, maxSize>::peek() const
{
	return first->value;
}

template<class T, size_t maxSize>
bool Stack<T, maxSize>::isEmpty() const
{
	return size == 0;
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::clear()
{
	Node<T>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
}

template<class T, size_t maxSize>
size_t Stack<T, maxSize>::getSize() const
{
	return size;
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::print() const
{
	Node<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}
