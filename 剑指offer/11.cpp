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

/*
// recursive quick power
double PowerWithNonNegative(double base, int exponent)  // exponent must >= 0
{
	if(exponent == 0)
	{
		return 1;  // x^0 = 1
	}
	if(exponent == 1)
	{
		return base;  // x^1 = x
	}

	double result = PowerWithNonNegative(base, exponent >> 1);  // >> is more efficient than /
	result *= result;
	if(exponent & 0x1 == 1)  // if exponent is odd
	{
		result *= base;
	}
	return result;
}
*/

double Power(double base, int exponent)
{
	if(Equal(base, 0.0) && exponent < 0)  // invalid input: divided by 0
	{
		g_invalid_input = true;
		return 0.0;
	}

	int abs_exponent = exponent >= 0 ? exponent : -exponent;  // exponent's absolute value
	//double result = PowerWithNonNegative(base, abs_exponent);
	// PowerWithNonNegative is a kind of recursive quick power,
	// which is slower than the following loop quick power.
	double result = 1.0;
	while(abs_exponent != 0)
	{
		if(abs_exponent & 0x1 == 1)  // the lowest bit is 1
		{
			result *= base;
		}
		abs_exponent >>= 1;  // move to right 1 bit
		base *= base;
	}

	if(exponent < 0)
	{
		result = 1.0 / result;
	}
	return result;
}

int main()
{
	double base = 0;
	int exponent = 0;
	while(1)
	{
		cout << "Input 2 numbers(double, int): ";
		cin >> base >> exponent;
		cout << Power(base, exponent) << endl;
	}

	return 0;
}

/*
Function Test Data:
-2 -3
-2 0
-2 5
0 2
2 -3
2 0
2 5
Edge Test Data:
0 0
Negative Test Data:
0 -2
*/
