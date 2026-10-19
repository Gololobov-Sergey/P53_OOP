#pragma once
#include <iostream>

using namespace std;

//class Engine
//{
//	int cilindr = 4;
//
//public:
//
//	void start()
//	{
//		cout << "Engine start" << endl;
//	}
//
//	void stop()
//	{
//		cout << "Engine stop" << endl;
//	}
//};
//
//class Car
//{
//	Engine en;
//
//public:
//
//	void move()
//	{
//		en.start();
//		en.stop();
//	}
//
//};



class Engine
{
	int cilindr = 4;
	int power = 50;

public:

	void start()
	{
		cout << "Engine start" << endl;
	}

	void stop()
	{
		cout << "Engine stop" << endl;
	}

	void powerUpgrade()
	{
		power += 10;
	}
};

class Car
{
	Engine* en;

public:

	Car() { en = new Engine; }
	~Car() { delete en; }

	void move()
	{
		en->start();
		en->stop();
	}

	/*Engine* getEngine()
	{
		return en;
	}*/

};

class STO
{
	Engine* en;

public:
	void setEngine(Engine* en)
	{
		this->en = en;
	}

	void upgrade()
	{
		en->powerUpgrade();
	}


};


class Human
{
	string name;
	int age;

public:
	Human(string n, int a)
	{
		name = n;
		age = a;
		//cout << "Ctor Human" << endl;
	}

	~Human()
	{
		//cout << "Dest Human \n";
	}

	void setAge(int a)
	{
		age = a;
	}

	void info()
	{
		cout << "Name : " << name << endl;
		cout << "Age  : " << age << endl;
	}

	void method()
	{
		// name;
		// age;
	}
};

class Player : public Human
{
	int goal;

public:
	Player(string n, int age, int goal) :  goal(goal), Human(n, age)
	{
		//cout << "Ctor Player" << endl;
	}

	~Player()
	{
		//cout << "Dest Player \n";
	}

	void info()
	{
		Human::info();
		cout << "Goal : " << goal << endl;
	}

	void method() = delete;
};