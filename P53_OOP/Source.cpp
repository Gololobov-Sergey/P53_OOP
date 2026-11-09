#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<vector>
#include<array>
#include<list>
#include<stack>
#include<set>
#include<map>

#include"Student.h"
#include"Array.h"
#include"Time.h"
#include"Reservoir.h"
#include"Fraction.h"

#include"Stack.h"
#include"Calc.h"
#include"Queue.h"
#include"PriorityQueue.h"
#include"Bus.h"
#include"ForwardList.h"
#include"List.h"
#include"BTree.h"
#include"Composition.h"
#include"Inherit.h"
#include"Animal.h"
#include"WarOfWorld.h"
#include"MyException.h"
#include"SmartPointer.h"
#include"md5.h"

using namespace std;

template<class T>
void printArray(Array<T> a)
{
	a.show();
}

void addTimePeople(People& p) noexcept
{
	p.addTime();
}

float div_(int a, int b)
{
	if (b == 0)
		throw new invalid_argument("b = 0");
	return a / b;
}


void PrintAnimal(IPrinable* a)
{
	a->print();
}

Cat fff()
{
	
	return Cat("Tom", 3);
}

void superFunc()
{
	SmartPointer<Cat> c(new Cat("Tom", 3));
	
	SmartPointer<Cat>c1 = move(c);



	int a;
	cin >> a;
	if (a == 0)
		throw new invalid_argument("a = 0");


	//delete c;
}

template<class Cont>
void print(Cont& cont)
{
	for (auto elem : cont)
	{
		cout << elem << endl;
	}
	cout << endl;
}

//bool isEven(int a)
//{
//	return a % 2 == 0;
//}

class MyStack : public stack<int>
{
public:
	MyStack(initializer_list<int> l)
	{
		for (auto elem : l)
		{
			push(elem);
		}
	}

	void show()
	{
		auto it = this->c.begin(); 	//c - protected member of stack
		while (it != this->c.end())
		{
			cout << *it << endl;
			it++;
		}
	}
};

class FromCatName
{
public:
	bool operator()(const Cat& c1, const Cat& c2) const
	{
		return c1.getName() < c2.getName();
	}
};


int main()
{

	// 09.11.2026


	map<string, Cat, FromCatName> cats;
	cats.insert(make_pair("Tom", Cat("Tom", 3)));
	cats.insert(make_pair("Bob", Cat("Tom", 3)));
	cats.insert(make_pair("Alice", Cat("Tom", 3)));
	for (auto elem : cats)
	{
		cout << elem.first << endl;
	}



	//set<int> s = { 1, 2, 3, 4, 3, 6, 5, 6, 7 };
	//auto p = s.insert(16);
	//cout << *p.first << " " << p.second << endl;
	//print(s);

	//cout << s.insert(16).second << endl;

	//list<Cat> cats = { Cat("Tom", 3), Cat("Bob", 5), Cat("Alice", 2) };
	//print(cats);
	////cats.sort([](Cat& c1, Cat& c2) { return c1.getAge() < c2.getAge(); });
	//cats.sort([](Cat& c1, Cat& c2) { return c1.getName() < c2.getName(); });
	//print(cats);

	//list<int> l = { 1,2,3,4,54,6 };
	//cout << l.max_size() << endl;
	//auto it = l.begin();
	////advance(it, 3);
	//l.insert(next(l.begin(), 3), 100);
	//print(l);

	//next(l.begin(), 3);


	//MyStack s{ 1,2,3,4,5 };
	//s.show();

	//array<int, 5> arr = { 1,2,3,4,5 };	
	//cout << arr.max_size() << endl;


	//string password = "123456";
	//string phash = md5(password);
	//cout << "Password: " << password << endl;
	//cout << "Hash: " << phash << endl;


	//hash<string> h;
	//auto hash2 = h(password);
	//cout << "Hash2: " << hash2 << endl;

	// 04.11.2026

	//vector<int> v = { 1,2,3,4,5,6 };
	//vector<int> v1 = { 12,23,34,45,56,67 };
	//print(v);

	////v.insert(v.begin() + 3, 99);
	////v.insert(v.begin() + 3, v1.begin()+2, v1.begin()+5);
	//v.insert(v.begin() + 3, {6,7,8,9,});
	//print(v);

	////vector<Cat> vc = { Cat("Tom", 3), Cat("Murka", 2) };
	////vc.insert(vc.begin() + 1, Cat("Barsik", 4));
	////vc.emplace(vc.begin() + 1, "Barsik", 4);

	//erase_if(v, [](int a) { return a % 2 == 0; });
	//print(v);

	//[]() {};

	//auto f = [](const char* message) { cout << message << endl; };
	//f("mama");

	//auto ff = [](int a)->int {
	//	if (a == 0)
	//		return 10;
	//	return 5.0;	};

	//cout << ff(40) << endl;


	//int c = 10, m = 12;
	//auto fff = [=, &c]() { cout << ++c << m << endl; };
	//fff();

	//cout << v.size() << endl;
	//cout << v.capacity() << endl;
	//cout << v.max_size() << endl;

	//auto it = v.begin() + 2;
	//cout << *(it) << endl;



	// 02.11.2026

	
	//int a = 10;
	//int&& b = 10;


	//superFunc();


	//SmartPointer<Cat> c(new Cat("Tom", 3));
	//c->print();

	//SmartPointer<Cat>c1 = move(c);
	//c1->print();
	//c->print();

	//unique_ptr<Cat> c = make_unique<Cat>("Tom", 5);
	//unique_ptr<Cat> c1;
	//cout << c << endl;
	//cout << c1 << endl;

	//c1 = move(c);


	//cout << c << endl;
	//cout << c1 << endl;


	//shared_ptr<Cat> k1 = make_shared<Cat>("Tom", 5);
	//shared_ptr<Cat> k2(k1);
	//shared_ptr<Cat> k3 = k2;
	//shared_ptr<Cat> k4;
	//k4 = k3;

	//int a = 8;
	//int b = 9;
	//swap(a, b);


	//List<Cat>l;
	//Cat c = Cat("Tom", 3);
	//l.push_back(Cat("Tom", 3));
	//l.push_back(c);


	//IPrinable* a = new SiamCat("Barsik", 4);
	//PrintAnimal(a);


	// 30.10.2026


	//throw 1;
	//throw "Error";
	//throw Time();


	//try
	//{
	//	int a, b;
	//	cin >> a >> b;
	//	////if (b == 0)
	//	//	//throw MyException(__DATE__, __TIME__, __FILE__, __LINE__, "Div by zero");
	//	//	//throw new invalid_argument("b = 0");

	//	////if (b == 1)
	//	////	throw 100;

	//	//cout << a / b << endl;

	//	cout << div_(a, b) << endl;
	//}
	//catch (exception* ex)
	//{
	//	cout << ex->what() << endl;
	//}
	//catch (invalid_argument* ex)
	//{
	//	cout << ex->what() << endl;
	//}

	//catch (MyException& ex)
	//{
	//	ex.getConsoleError();
	//	ex.saveToFile();
	//}
	//catch (const char* err)
	//{
	//	cout << err << endl;
	//}
	//catch (int a)
	//{
	//	cout << "Int " << a << endl;
	//}
	


	//List<Light*> l = { new Swordsman(10,10) };
	//List<Warrior*> l1;
	//for (size_t i = 0; i < l.getSize(); i++)
	//{
	//	l1.push_back(l[i]);
	//}
	//l1.print();
	//l.print();


	//PriorityQueue<int, int> p;
	//p.enqueue(10, 10);
	//p.enqueue(20, 20);
	//p.enqueue(50, 50);
	//p.dequeue();
	//p.print();



	//Animal* cat = new Cat("Tom", 3);

	//Cat* c = dynamic_cast<Cat*>(cat);
	//if (c)
	//{
	//	c->cathMouse();
	//	c->cathMouse();
	//	c->cathMouse();
	//	cout << c->getMouse() << endl;
	//}
	//else
	//{
	//	cout << "Not Cat" << endl;
	//}


	// 26.10.2026

	//WarOfWord war(5);
	//war.game();


	// 23.10.2026

	//Animal* a = new Animal("????", 0);
	//cout << a->getName() << endl;
	//cout << a->getType() << endl;
	//cout << a->getVoice() << endl;

	//cout << endl;

	//Animal* c = new Cat("Tom", 3);
	//cout << c->getName() << endl;
	//cout << c->getType() << endl;
	//cout << c->getVoice() << endl;

	//cout << endl;

	//Animal* d = new Dog("Spike", 5);
	//cout << d->getName() << endl;
	//cout << d->getType() << endl;
	//cout << d->getVoice() << endl;


	//Animal* sc = new SiamCat("Barsik", 4);

	//cout << endl;
	//Animal* aa[] = { /*a,*/ c, d, sc, new Ravlik("Vasya", 1)};
	//for (size_t i = 0; i < 4; i++)
	//{
	//	cout << aa[i]->getName() << endl;
	//	cout << aa[i]->getType() << endl;
	//	cout << aa[i]->getVoice() << endl;
	//	cout << endl;
	//}


	//Animal* c = new Cat("Tom2", 3);
	//cout << c->getType() << endl;

	//delete c;

	//Animal& a = c;
	//cout << a.getType() << endl;

	//Animal* aa = &c;
	//cout << aa->getType() << endl;

	//Router r(123, 456, 789, 999);
	//cout << r.LANDevice::getID() << endl;
	//cout << r.WiFiDevice::getID() << endl;

	//r.LANDevice::Device::id = 10;
	//cout << r.LANDevice::Device::id << endl;
	//cout << r.WiFiDevice::Device::id << endl;

	//r.WiFiDevice::Device::id = 20;
	//cout << r.LANDevice::Device::id << endl;
	//cout << r.WiFiDevice::Device::id << endl;


	// 19.10.2026


	//Engine* en = new Engine;
	//{
	//	Car c(en);

	//	STO sto;

	//	sto.setEngine(c.getEngine());
	//	sto.upgrade();
	//}

	//en->start();


	//Human h(20);

	//Player p("Messi", 40, 980);
	//p.info();
	//p.method();


	//A a;
	//a.aaa = 10;
	////a.aa = 10;

	//B b;
	//b.aaa = 10;

	//C c;






	// 16.10.2026


	//BTree<int, int> b;
	//b.push_r(10, 10);
	//b.push_r(5, 5);
	//b.push_r(15, 15);
	//b.push_r(0, 0);
	//b.push_r(1, 1);
	//cout << b.push_r(2, 2) << endl;
	//cout << b.push_r(1, 1) << endl;
	//cout << b.push_r(3, 3) << endl;
	//b.print();
	//b.clear();

	// 12.10.2026


	//List<int> l = { 1,2,3,4,5 };
	////l.push_back(10);
	////l.push_front(20);
	////l.print();
	////l.insert(99, 0);
	//l.print();

	//l.remove(1);
	//l.print();


	// 09.10.2026

	//ForwardList<int> l = { 1,21,3 };
	//cout << l[1] << endl;

	//ForwardList<int> l2 = l;
	//l2.print();

	//ForwardList<int> l3 = l + l2;
	//l3.print();

	// 05.10.2026

	//Queue<int> q = { 1, 2, 3 };
	//q.enqueue(10);
	//q.ring();
	//q.print();
	//cout << q.peek() << endl;
	//q.clear();
	//q.print();

	//PriorityQueue<int> pq;
	//pq.enqueue(10, 1);
	//pq.enqueue(20, 2);
	//pq.enqueue(10, 1);
	//pq.enqueue(30, 3);
	//pq.enqueue(20, 2);
	//pq.print();

	//PriorityQueue<Fraction, float> p;
	//p.enqueue(Fraction(2, 3), (float)Fraction(2, 3));
	//p.enqueue(Fraction(1, 3), (float)Fraction(1, 3));
	//p.enqueue(Fraction(3, 3), (float)Fraction(3, 3));
	//p.enqueue(Fraction(5, 3), (float)Fraction(5, 3));
	//p.enqueue(Fraction(1, 3), (float)Fraction(1, 3));
	//p.print();


	//Queue<Bus> bus = {};
	//Queue<People> p;

	//int i = 0;
	//while (true)
	//{
	//	if (i % 2 == 0)
	//	{
	//		cout << "Add pass" << endl;
	//		p.enqueue(People());
	//	}

	//	if (i % 10 == 0)
	//	{
	//		cout << "Bus arrived" << endl;

	//	}

	//	p.for_each(addTimePeople);

	//	Sleep(1000);
	//	i++;
	//}



	// 02.10.2026

	//Stack<int, 5> s;
	//s.push(10);
	//s.push(5);
	//s.push(20);
	//s.push(15);
	//s.push(25);
	//s.push(35);
	//s.print();
	//cout << s.peek() << endl;
	//s.pop();
	//s.pop();
	//s.print();
	//s.clear();
	//s.print();

	//Calc c("4/2");
	//cout << c.getResult() << endl;


	// 28.09.2026

	//Array<int> arr(10);
	//arr.setRand();
	//arr.show();
	//cout << arr[-2] << endl;

	//Array<Fraction> f(10);
	//f.setRand();
	//f.show();

	//Array<Student> s(5);
	//s.setRand();


	//void* p = new int{ 10 };
	//cout << *((int*)p) << endl;


	// 25.09.2026

	// + - ++ --
	// + - * / += -= *= /= % %=

	// !
	// > < >= <= == != && ||

	//() [] << >>



	//Fraction f1(3, 5);
	//f1.show();
	//Fraction f2(0, 3);
	//f2.show();

	//if (f1 && f2)
	//{
	//	cout << "<<<<" << endl;
	//}
	//else
	//{
	//	cout << ">>>>" << endl;
	//}

	//f2(2, 5);


	//cout << f1["num"] << endl;
	//cout << f1 << endl;

	//cin >> f2;
	//cout << f2 << endl;


	//Fraction f4 = f1 + f2;
	//f4.show();

	//Fraction f3 = -f1;
	//f3.show();

	//(f2++).show();
	////(++f2).show();
	//f2.show();

	//f1 = f2 + 5;
	//f1 = 5 + f2;

	// 21.09.2026


	//Array a(10);
	//a.setRand();
	//cout << a[-10] << endl;
	//int m = a[-3];


	//a.show();
	//Array b(15);
	//b.setRand();
	//b = b;
	//b.show();


	//printArray(a);
	//a.show();

	//Array b(a);
	//Array c;
	//c = a;



	// 18.09.2026


	//Reservoir r(ReservoirType::Lake);

	//if (ReservoirType::Lake == r.getType())
	//{
	//	cout << "Reservoir is a lake." << endl;
	//}
	//else
	//{
	//	cout << "Reservoir is not a lake." << endl;
	//}

	//Time t(1, 1);

	//const Array* arr = new Array(5);
	//arr->setRandom();

	//// 14.09.2026

	//Student s1(1, "Vasya", 30);
	//Array a(10);
	//a.setRandom(); // setRandom(a)
	//a.show();

	//printArray(a);

	//Array b = 10;


	//Array b;

	//Area::romb()


	//==============================================================

	//cout << "Count of students: " << Student::getCount() << endl;

	//Student s1(1, "Vasya", 30);

	//cout << "Count of students: " << s1.getCount() << endl;

	//Student s2(2);
	//
	//cout << "Count of students: " << s1.getCount() << endl;
	//
	//s1.displayInfo();
	//s2.displayInfo();
	//

	//const int a = 5;
	//const int b(5.5);
	//const int c{ (int)5.5 };



	return 0;
}