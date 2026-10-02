#pragma once
#include<iostream>

#include"Stack.h"


using namespace std;

class Calc
{
	string expression;

	int isoperation(char oper);

	int calculate(int a, int b, char oper);

public:
	Calc(const string& exp) : expression(exp) {}

	int getResult();

};


int Calc::isoperation(char oper)
{
	switch (oper)
	{
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	case '^':           return 3;
	default:            return 0;
	}
}

int Calc::calculate(int a, int b, char oper)
{
	switch (oper)
	{
	case '+': return a + b;
	case '-': return b - a;
	case '*': return a * b;
	case '/': return b / a;
	case '^': return pow(b, a);
	}
}

int Calc::getResult()
{
	Stack<int, 10> numbers;
	Stack<char, 10> operators;

	int i = 0;
	while (expression[i] != '\0')
	{
		if (isdigit(expression[i]))
		{
			numbers.push(expression[i] - 48);
		}
		else if (isoperation(expression[i]))
		{
			if (operators.isEmpty())
			{
				operators.push(expression[i]);
			}
			else if (isoperation(operators.peek()) > isoperation(expression[i]))
			{
				while (isoperation(operators.peek()) > isoperation(expression[i]))
				{
					int a = numbers.peek();
					numbers.pop();
					int b = numbers.peek();
					numbers.pop();
					char oper = operators.peek();
					operators.pop();
					int res = calculate(a, b, oper);
					numbers.push(res);
				}
				operators.push(expression[i]);
			}
			else
			{
				operators.push(expression[i]);
			}
		}
		i++;
	}

	while (!operators.isEmpty())
	{
		int a = numbers.peek();
		numbers.pop();
		int b = numbers.peek();
		numbers.pop();
		char oper = operators.peek();
		operators.pop();
		int res = calculate(a, b, oper);
		numbers.push(res);
	}

	return numbers.peek();
}