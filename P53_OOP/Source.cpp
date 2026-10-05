#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>

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

using namespace std;

template<class T>
void printArray(Array<T> a)
{
	a.show();
}

int main() 
{

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


	Queue<Bus> bus = {};
	Queue<People> p;

	int i = 0;
	while (true)
	{
		if (i % 2 == 0)
		{
			cout << "Add pass" << endl;
			p.enqueue(People());
		}

		if (i % 10 == 0)
		{
			cout << "Bus arrived" << endl;

		}
		Sleep(1000);
		i++;
	}



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