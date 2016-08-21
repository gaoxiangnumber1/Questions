/*
------------------------------Function Test Data------------------------------
1. negative integer
2. zero
3. positive integer
---------------------------------Edge Test Data--------------------------------
none
------------------------------Negative Test Data------------------------------
none
*/

#include<iostream>
using namespace std;

int NumberOf11(int n)  // cast n to unsigned int
{
	unsigned int num2 = (unsigned int)n;
	int result = 0;

	while(num2)
	{
		if(num2 & 0x1)
		{
			++result;
		}
		num2 >>= 1;
	}

	return result;
}

int NumberOf12(int n)  // keep n unchanged
{
	int flag = 1;
	int result = 0;

	while(flag)
	{
		if(n & flag)
		{
			++result;
		}
		flag <<= 1;
	}

	return result;
}

int NumberOf13(int n)
{
	int result = 0;

	while(n)
	{
		++result;
		n = n & (n - 1);
	}

	return result;
}

int main()
{
	while(1)
	{
		cout << "Input: ";
		int num;
		cin >> num;
		cout << NumberOf11(num) << '\t';
		cout << NumberOf12(num) << '\t';
		cout << NumberOf13(num) << '\n';
	}
	return 0;
}
