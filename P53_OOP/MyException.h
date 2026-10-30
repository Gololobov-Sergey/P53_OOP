#pragma once
#include<iostream>
#include<fstream>

using namespace std;

class MyException
{
	int line;
	string file;
	string date;
	string time;
	string message;

public:
	MyException(string d, string t, string f, int l, string m) : date(d), time(t), file(f), line(l), message(m)
	{

	}

	void getConsoleError()
	{
		cerr << date << " | " << time << " | " << file << " | " << line << " | " << message << endl;
	}

	void saveToFile()
	{
		ofstream out("log.txt", ios::app);
		out << date << " | " << time << " | " << file << " | " << line << " | " << message << endl;
		out.close();
	}
};