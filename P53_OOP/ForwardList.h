#pragma once
#include<initializer_list>

#include"Node.h"

using namespace std;

template<class T>
class ForwardList
{
	Node<T>* first;
	Node<T>* last;
	size_t   size;

	Node<T>* getNode(size_t index) const;


public:
	ForwardList();
	ForwardList(initializer_list<T> list);
	ForwardList(const ForwardList& obj);
	ForwardList<T>& operator=(const ForwardList<T>& obj);
	~ForwardList();

	void push_front(const T& value);
	void push_back(const T& value);
	void insert(const T& value, size_t index);

	void pop_front();
	void pop_back();
	void remove(size_t index);

	T& front() const;
	T& back() const;
	T at(size_t index) const;
	T& operator[](int index) const;

	ForwardList<T> operator+(const ForwardList<T>& list) const;
	void operator+=(const ForwardList<T>& list);

	void clear();
	void print() const;
	size_t getSize() const;

	size_t firstIndex(const T& value);
	size_t lastIndex(const T& value);

	int count(const T& value);
	int count_if(bool(*predicate)(const T& value));

};

template<class T>
Node<T>* ForwardList<T>::getNode(size_t index) const
{
	Node<T>* temp = first;
	for (size_t i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	return temp;
}

template<class T>
ForwardList<T>::ForwardList() {}

template<class T>
ForwardList<T>::ForwardList(initializer_list<T> list)
{
	for (T elem : list)
	{
		push_back(elem);
	}
}

template<class T>
ForwardList<T>::ForwardList(const ForwardList& obj)
{
	Node<T>* temp = obj.first;
	for (size_t i = 0; i < obj.size; i++)
	{
		push_back(temp->value);
		temp = temp->next;
	}
}

template<class T>
ForwardList<T>& ForwardList<T>::operator=(const ForwardList<T>&obj)
{
	return *this;
}

template<class T>
ForwardList<T>::~ForwardList()
{
	clear();
}

template<class T>
void ForwardList<T>::push_front(const T& value)
{

	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = first;
		first = newNode;
	}
	size++;
}

template<class T>
void ForwardList<T>::push_back(const T& value)
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
void ForwardList<T>::insert(const T& value, size_t index)
{
	if (index > size)
	{
		return;
	}

	if (index == 0)
	{
		push_front(value);
	}
	else if (index == size)
	{
		push_back(value);
	}
	else
	{
		Node<T>* pos = getNode(index - 1);
		Node<T>* newNode = new Node<T>(value);
		newNode->next = pos->next;
		pos->next = newNode;
		size++;
	}
}

template<class T>
void ForwardList<T>::pop_front()
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
void ForwardList<T>::pop_back()
{
	if (size > 0)
	{
		last = getNode(size - 2);
		delete last->next;
		last->next = nullptr;
		size--;
	}
}

template<class T>
void ForwardList<T>::remove(size_t index)
{
	if (index >= size)
	{
		return;
	}

	if (index == 0)
	{
		push_front();
	}
	else if (index == size - 1)
	{
		push_back();
	}
	else
	{
		Node<T>* pos = getNode(index - 1);
		Node<T>* temp = pos->next;
		pos->next = pos->next->next;
		delete temp;
		size--;
	}
}

template<class T>
T& ForwardList<T>::front() const
{
	return first->value;
}

template<class T>
T& ForwardList<T>::back() const
{
	return last->value;
}

template<class T>
T ForwardList<T>::at(size_t index) const
{
	return getNode(index)->value;
}

template<class T>
T& ForwardList<T>::operator[](int index) const
{
	return getNode(index)->value;
}

template<class T>
ForwardList<T> ForwardList<T>::operator+(const ForwardList<T>& list) const
{
	ForwardList<T> l1 = *this;
	Node<T>* temp = list.first;
	for (size_t i = 0; i < list.size; i++)
	{
		l1.push_back(temp->value);
		temp = temp->next;
	}
	return l1;
}

template<class T>
void ForwardList<T>::operator+=(const ForwardList<T>& list)
{}

template<class T>
void ForwardList<T>::clear()
{

}

template<class T>
void ForwardList<T>::print() const
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
size_t ForwardList<T>::getSize() const
{
	return size_t();
}

template<class T>
size_t ForwardList<T>::firstIndex(const T& value)
{
	return size_t();
}

template<class T>
size_t ForwardList<T>::lastIndex(const T& value)
{
	return size_t();
}

