#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include"Student.h"
#include"Array.h"
#include"Time.h"
#include"Reservoir.h"

using namespace std;

void printArray(Array a)
{
	a.show();
}

int main() 
{
	// 21.09.2026


	Array a(10);
	a.setRand();
	a.show();
	Array b(15);
	b.setRand();
	b = b;
	b.show();


	//printArray(a);
	a.show();

	//Array b(a);
	//Array c = a;



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