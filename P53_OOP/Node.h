#pragma once


template<class T>
struct Node
{
	T     value;
	Node* next;

	Node(const T& val) : value(val), next(nullptr) {}
};