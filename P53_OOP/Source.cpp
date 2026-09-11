#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include"Student.h"

using namespace std;


int main() 
{
	Student s1("Vasya", 30);
	Student s2;
	s1.displayInfo();
	s2.displayInfo();




	return 0;
}