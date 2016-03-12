#include<iostream>
using namespace std;

bool g_invalid_input = false;  // global variable to indicate whether the input is invalid

bool Equal(double num1, double num2)
{
	// since float number can't be represented exactly, if the difference is very small,
	// we think the two numbers are equal.
	if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
	{
		return true;
	}
	return false;
}

double PowerWithNonNegative(double base, int exponent)
{
	if(exponent == 0)
	{
		return 1;
	}
	if(exponent == 1)
	{
		return base;
	}

	double result = PowerWithNonNegative(base, exponent >> 1);  // >> is more efficient than /
	result *= result;
	if(exponent & 0x1 == 1)  // if exponent is odd
	{
		result *= base;
	}
	return result;
}

double Power(double base, int exponent)
{
	if(Equal(base, 0.0) && exponent < 0)  // invalid input: divided by 0
	{
		g_invalid_input = true;
		return 0.0;
	}

	int abs_exponent = exponent >= 0 ? exponent : -exponent;  // exponent's absolute value
	double result = PowerWithNonNegative(base, abs_exponent);

	if(exponent < 0)
	{
		result = 1.0 / result;
	}
	return result;
}

int main()
{
	while(1)
	{

	}

	return 0;
}

/*
Test data:

*/
