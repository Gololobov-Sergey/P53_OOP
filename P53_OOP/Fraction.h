#pragma once
#include<iostream>

using namespace std;


class Fraction
{

	int numerator;
	int denominator;

	int nsd()
	{
		return 1;
	}

public:
	Fraction() : Fraction(0, 1) { }

	Fraction(int num, int den) : numerator(num), denominator(den)	
	{
		int n = nsd();
		if (n != 1)
		{
			numerator /= n;
			denominator /= n;
		}
	}

	void show() const
	{
		cout << numerator << "/" << denominator << endl;
	}

	Fraction operator+(const Fraction& f)
	{
		int num = numerator * f.denominator + denominator * f.numerator;
		int den = denominator * f.denominator;
		return Fraction(num, den);
	}

	Fraction operator-()
	{
		return Fraction(-numerator, denominator);
	}

	Fraction operator++() //prefix
	{
		return Fraction(numerator + denominator, denominator);
	}

	Fraction operator ++ (int) //postfix
	{
		Fraction temp = *this;
		numerator = numerator + denominator;
		return temp;
	}

	void operator +=(Fraction f)
	{
		*this = *this + f;
	}

	Fraction operator+(int n)
	{
		return Fraction(numerator + denominator * n, denominator);
	}

	auto operator <=> (Fraction f)
	{
		return (double)numerator / denominator <=> (double)f.numerator / f.denominator;
	}

	bool operator == (Fraction f)
	{
		return numerator == f.numerator && denominator == f.denominator;
	}

	bool operator != (Fraction f)
	{
		return numerator != f.numerator || denominator != f.denominator;
	}

	bool operator&&(Fraction f)
	{
		return numerator != 0 && f.numerator != 0;
	}

	void operator()(int a, int b)
	{
		numerator = a;
		denominator = b;
	}

	int operator[](const char* name)
	{
		if (strcmp(name, "num") == 0)
			return numerator;
		if (strcmp(name, "den") == 0)
			return denominator;
	}

	friend ostream& operator<<(ostream& out, const Fraction& f);

	friend istream& operator>>(istream& in, Fraction& f);
};

Fraction operator + (int n, Fraction f2)
{
	return f2 + n;
}

ostream& operator<<(ostream& out, const Fraction& f)
{
	out << f.numerator << "/" << f.denominator << endl;
	return out;
}

istream& operator>>(istream& in, Fraction& f)
{
	cout << "Num: ";
	in >> f.numerator;
	cout << "Den: ";
	in >> f.denominator;
	return in;
}
