#pragma once
#include <iostream>

using namespace std;


class IPrinable 
{
public:
	virtual void print() = 0;
};


class Animal
{
	string name;
	int age;


public: 
	Animal(string n, int a) : name(n), age(a) {}

	virtual ~Animal() { /*cout << "Destr Animal" << endl;*/ }

	string getName() { return name; } const 

	virtual string getType() { return "Animal"; } 

	virtual string getVoice() = 0;

	int getAge() { return age; }
};

string Animal::getVoice()
{
	return "????";
}


class Cat /*final*/ : public Animal, public IPrinable
{
	int mouse = 0;

public:
	Cat(string n, int a) : Animal(n, a) {}

	~Cat() { /*cout << "Destr Cat" << endl;*/ }

	virtual string getType()  override { return "Cat"; }

	virtual string getVoice() const /*final*/ override { return "Mau Mau"; }

	virtual void print() override { cout << "Cat: " << getName() << endl; }

	void cathMouse() { mouse++; }

	int getMouse() { return mouse; }

	friend ostream& operator<<(ostream& os, Cat& c)
	{
		os << "Cat: " << c.getName() << ", Age: " << c.getAge();
		return os;
	}
};


class SiamCat : public Cat
{
public:
	SiamCat(string n, int a) : Cat(n, a) {}

	virtual string getType() override { return "SiamCat"; }

	virtual string getVoice() override { return "Myau Myau"; }
};


class Dog : public Animal, public IPrinable
{
public:
	Dog(string n, int a) : Animal(n, a) {}

	virtual string getType() override { return "Dog"; }

	virtual string getVoice() override { return "Gaw Gaw"; }

	virtual void print() override { cout << "Dog: " << getName() << endl; }
};


class Ravlik : public Animal
{
public:
	Ravlik(string n, int a) : Animal(n, a) {}

	virtual string getType() override { return "Ravlik"; }

	virtual string getVoice() override { return Animal::getVoice(); }
};