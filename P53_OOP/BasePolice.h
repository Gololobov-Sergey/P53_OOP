#pragma once
#include<iostream>

#include"List.h"
#include"BTree.h"

using namespace std;

class Protocol
{
	string number;
	string date;
	int sum;
	bool isPay = false;

public:

	string getNumber();

	friend ostream& operator<<(ostream& out, const Protocol& p);
	friend ostream& operator<<(ostream& out, const Protocol* p);
};

ostream& operator<<(ostream& out, const Protocol& p)
{
	// TODO: вставьте здесь оператор return
}


class BasePolice
{
	BTree<string, List<Protocol*>> base;

public:

	void addProtocol();

	void print();

	void print(string number1, string number2);

	void save();

	void load();

	void pay();
};

void BasePolice::addProtocol()
{
	Protocol* p = new Protocol;
	// p.input()
	// cin >> p;
	cout << p << endl;

	List<Protocol*>* l = base.getValue(p->getNumber());
	if (l)
	{
		l->push_back(p);
	}
	else
	{
		List<Protocol*> newList;
		newList.push_back(p);
		base.push_r(p->getNumber(), newList);
	}
}