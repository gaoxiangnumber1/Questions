/*
------------------------------Function Test Data------------------------------
index > 0

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
index <= 0

*/

#include <iostream>
using namespace std;

bool IsUgly(int num)
{
	while(num % 2 == 0)
	{
		num /= 2;
	}
	while(num % 3 == 0)
	{
		num /= 3;
	}
	while(num % 5 == 0)
	{
		num /= 5;
	}
	return num == 1 ? true : false;
}

int GetUglyNumber_Solution(int index)
{
	// Negative data:
	if(index <= 0)
	{
		return 0;
	}

	int num = 1, my_index = 1;
	while(my_index < index)
	{
		if(IsUgly(++num))
		{
			++my_index;
		}
	}
	return num;
}

int Min(int num1, int num2, int num3)
{
	int min1 = num1 < num2 ? num1 : num2;
	int min2 = min1 < num3 ? min1 : num3;
	return min2;
}

int GetUglyNumber_Solution(int index)
{
	// Negative data:
	if(index <= 0)
	{
		return 0;
	}

	int num[index];
	num[0] = 1;
	int next_index = 1;
	int multiply2 = 0, multiply3 = 0, multiply5 = 0;
	while(next_index <= index - 1)
	{
		int next_num = Min(num[multiply2] * 2, num[multiply3] * 3, num[multiply5] * 5);
		num[next_index++] = next_num;

		while(num[multiply2] * 2 <= next_num)
		{
			++multiply2;
		}
		while(num[multiply3] * 3 <= next_num)
		{
			++multiply3;
		}
		while(num[multiply5] * 5 <= next_num)
		{
			++multiply5;
		}
	}
	return num[index - 1];
}

int main()
{
	cout << Get1(1500) << '\t' << Get2(1500);

	return 0;
}
