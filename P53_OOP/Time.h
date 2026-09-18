#pragma once
#include <iostream>

using namespace std;
class Time
{
	int hour;
	int minute;
	int second;

public:
	Time() : Time(0) { /*cout << "Constr 0" << endl;*/ }

	Time(int s) : Time(0, s) { /*cout << "Constr 1" << endl;*/ }

	Time(int m, int s) : Time(0, m, s) { /*cout << "Constr 2" << endl;*/ }
	
	Time(int h, int m, int s) : hour(h), minute(m), second(s) { /*cout << "Constr 3" << endl;*/ }

};

