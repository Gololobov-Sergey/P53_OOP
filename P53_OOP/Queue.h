#pragma once
#include<initializer_list>

#include"Node.h"

template<class T>
class Queue
{
	Node<T>* first;
	Node<T>* last;
	size_t   size;

public:
	Queue();
	Queue(initializer_list<T> list);
	Queue(const Queue& obj);
	Queue& operator= (const Queue& obj);
	~Queue();

	void   enqueue(const T& value);
	void   dequeue();
	T&     peek() const;

	void   print() const;
	void   clear();
	size_t getSize() const;

	void ring();

	void for_each(void(*action)(T&));
};

template<class T>
Queue<T>::Queue() {}

template<class T>
Queue<T>::Queue(initializer_list<T> list)
{
	for (T elem : list)
	{
		enqueue(elem);
	}
}

template<class T>
Queue<T>::Queue(const Queue& obj)
{

}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue& obj)
{
	return *this;
}

template<class T>
Queue<T>::~Queue()
{
	clear();
}

template<class T>
void Queue<T>::enqueue(const T& value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		last->next = new Node<T>(value);
		last = last->next;
	}
	size++;
}

template<class T>
void Queue<T>::dequeue()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
	}
}

template<class T>
T& Queue<T>::peek() const
{
	return first->value;
}

template<class T>
void Queue<T>::print() const
{
	Node<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<class T>
void Queue<T>::clear()
{
	Node<T>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
	last = nullptr;
}

template<class T>
size_t Queue<T>::getSize() const
{
	return size;
}

template<class T>
void Queue<T>::ring()
{
	last->next = first;
	first = first->next;
	last = last->next;
	last->next = nullptr;
}

template<class T>
void Queue<T>::for_each(void(*action)(T&))
{
	Node<T>* temp = first;
	while (temp)
	{
		action(temp->value);
		temp = temp->next;
	}
}
