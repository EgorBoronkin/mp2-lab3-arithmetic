﻿#include "arithmetic.h"



Arithmetic::Arithmetic(std::string str) : string(str)
{

}



void Arithmetic::Convert(std::string str)
{
	int size = str.size();
	std::string buffer;
	Stack<Lexem> stack;
	bool flag = 0;
	for (int i = 0; i < size; ++i)
	{
		
		buffer = "";
		while (i < size && '0' <= str[i] && str[i] <= '9' || str[i] == '.')
		{
			if (buffer.size() == 0 && str[i] == '.')
				throw error = { i,"Wrong Number" };
			buffer += str[i++];
		}
		if (buffer.size() != 0)
		{
			Lexem a;
			a.numb = stod(buffer);
			a.numb *= (1 - 2 * flag);
			flag = 0;
			a.pos = i - 1;
			postfix.push_back(a);
		}
		if (i >= size)
			break;
		//---------------------------------------------------

		if (str[i] == '+' || str[i] == '*' || str[i] == '-' || str[i] == '/')
		{

			if (str[i] == '-' && (i == 0 || str[i - 1] == '('))
			{
				flag = 1;
				continue;
			}

			while (!stack.isEmpty() && (stack.Top().op == '*' || stack.Top().op == '/'))
			{
				Lexem a = stack.Top();
				stack.pop();
				postfix.push_back(a);
			}
			Lexem a;
			a.op = str[i];
			a.isOp = 1;
			a.pos = i;
			stack.push(a);
		}
		else if (str[i] == '(')
		{
			Lexem a;
			a.op = str[i];
			a.isOp = 1;
			a.pos = i;
			stack.push(a);
		}
		else if (str[i] == ')')
		{
			while (!stack.isEmpty() && stack.Top().op != '(')
			{
				Lexem a = stack.Top();
				stack.pop();
				postfix.push_back(a);
			}
			if (stack.isEmpty())
				throw error = { i,"Bracket is missed" };
			else
				stack.pop();
		}
		else 
		{
			throw error = { i,"wrong lexem!" };
		}
	}
	while (!stack.isEmpty())
	{
		Lexem a = stack.Top();
		if (a.isOp && a.op == '(')
			throw error = { a.pos,"Missing bracket" };
		stack.pop();
		postfix.push_back(a);
	}
}

double Arithmetic::Calculate()
{

	Stack<double> stack;
	for (Lexem el : postfix)
	{
		if (!el.isOp)
		{
			stack.push(el.numb);
		}
		else
		{
			char symb = el.op;
			double num1;
			double num2;
			double itog;
			if (!stack.isEmpty())
			{
				num1 = stack.Top();
				stack.pop();
			}
			else
			{
				throw error = { el.pos,"Mising Number" };
			}

			if (!stack.isEmpty())
			{
				num2 = stack.Top();
				stack.pop();
			}
			else
			{
				throw error = { el.pos,"Mising Number" };
			}

			switch (symb)
			{
			case '+':
				itog = num1 + num2;
				break;
			case '-':
				itog = num2 - num1;
				break;
			case '*':
				itog = num1 * num2;
				break;
			case '/':
				if (num1 == 0)
				{
					throw error = { el.pos + 1,"Division by Zero!" };
				}
				itog = num2 / num1;
				break;
			}
			stack.push(itog);
		}
	}
	double ans = stack.Top();
	stack.pop();
	if (!stack.isEmpty())
		throw "Number Left";
	return ans;
}


std::pair<double, int> Arithmetic::Execution()
{
	double x = 0;
	try
	{
		Convert(string);
		x = Calculate();
	}
	catch (std::pair<int, std::string> Error)
	{
		std::cout << "Error:" << Error.second << " on position:" << Error.first + 1 << std::endl;
		return { -1,-1 };
	}
	return { x,0 };
}