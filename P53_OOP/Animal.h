#pragma once
#include <iostream>

using namespace std;

class Animal
{
	string name;
	int age;


public: 
	Animal(string n, int a) : name(n), age(a) {}

	virtual ~Animal() { cout << "Destr Animal" << endl; }

	string getName() { return name; }

	virtual string getType() { return "Animal"; }

	virtual string getVoice() = 0;
};

string Animal::getVoice()
{
	return "????";
}


class Cat : public Animal
{
public:
	Cat(string n, int a) : Animal(n, a) {}

	~Cat() { cout << "Destr Cat" << endl; }

	virtual string getType() override { return "Cat"; }

	virtual string getVoice() override { return "Mau Mau"; }
};


class SiamCat : public Cat
{
public:
	SiamCat(string n, int a) : Cat(n, a) {}

	virtual string getType() override { return "SiamCat"; }

	virtual string getVoice() override { return "Myau Myau"; }
};


class Dog : public Animal
{
public:
	Dog(string n, int a) : Animal(n, a) {}

	virtual string getType() override { return "Dog"; }

	virtual string getVoice() override { return "Gaw Gaw"; }
};


class Ravlik : public Animal
{
public:
	Ravlik(string n, int a) : Animal(n, a) {}

	virtual string getType() override { return "Ravlik"; }

	virtual string getVoice() override { return Animal::getVoice(); }
};