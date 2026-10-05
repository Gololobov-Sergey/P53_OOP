#pragma once
#include<initializer_list>

#include"Node.h"

using namespace std;

template<class T, class TPri = T>
class PriorityQueue
{
	Node<T, TPri>* first;
	Node<T, TPri>* last;
	size_t   size;

public:
	PriorityQueue();
	PriorityQueue(const PriorityQueue& obj);
	PriorityQueue& operator= (const PriorityQueue& obj);
	~PriorityQueue();

	void   enqueue(const T& value, TPri pri);
	void   dequeue();
	T&     peek() const;

	void   print() const;
	void   clear();
	size_t getSize() const;
};

template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue() {}


template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue(const PriorityQueue& obj)
{

}

template<class T, class TPri>
PriorityQueue<T, TPri>& PriorityQueue<T, TPri>::operator=(const PriorityQueue& obj)
{
	return *this;
}

template<class T, class TPri>
PriorityQueue<T, TPri>::~PriorityQueue()
{
	clear();
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::enqueue(const T& value, TPri pri)
{
	Node<T, TPri>* newNode = new Node<T, TPri>(value, pri);

	if (size == 0)
	{
		first = last = newNode;
		size++;
		return;
	}

	if (pri > first->priority)
	{
		newNode->next = first;
		first = newNode;
	}
	else if (pri <= last->priority)
	{
		last->next = newNode;
		last = newNode;
	}
	else
	{
		Node<T, TPri>* pos = first;
		while (pri <= pos->next->priority)
		{
			pos = pos->next;
		}
		newNode->next = pos->next;
		pos->next = newNode;
	}
	size++;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::dequeue()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
	}
}

template<class T, class TPri>
T& PriorityQueue<T, TPri>::peek() const
{
	return first->value;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::print() const
{
	Node<T, TPri>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::clear()
{
	Node<T, TPri>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
	last = nullptr;
}

template<class T, class TPri>
size_t PriorityQueue<T, TPri>::getSize() const
{
	return size;
}