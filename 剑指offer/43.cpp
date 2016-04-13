/*
------------------------------Function Test Data------------------------------

--------------------------------Edge Test Data--------------------------------

------------------------------Negative Test Data------------------------------

*/
#include <iostream>
#include <string>
using namespace std;
const int kMax = 6;

void Recursive(int left, int sum, int cnt[])
{
	if(left == 0)  // Get one sum.
	{
		cnt[sum]++;
	}
	else
	{
		for(int value = 1; value <= kMax; ++value)
		{
			Recursive(left - 1, value + sum, cnt);
		}
	}
}

int Pow(int base, int exponent)
{
	int result = 1;
	while(exponent)
	{
		if(exponent & 0x1)
		{
			result *= base;
		}
		exponent >>= 1;
		base *= base;
	}
	return result;
}

void Print(int num)
{
	if(num < 1)
	{
		return;
	}

	// First, we allocate an array to store each sum's times,
	// that is, cnt[sum] is the times of sum.
	int max_sum = kMax * num;
	int cnt[max_sum + 1];
	for(int sum = num; sum <= max_sum; ++sum)
	{
		cnt[sum] = 0;
	}

	// Second, get each sum recursively.
	for(int value = 1; value <= kMax; ++value)
	{
		Recursive(num - 1, value, cnt);
	}

	// Third, print the answer:
	int total = Pow(kMax, num);
	for(int sum = num; sum <= max_sum; ++sum)
	{
		double ratio = (double)cnt[sum] / total;
		cout << sum << ":\t" << ratio << endl;
	}
}

int main()
{
	for(int num = 1; num <= 100; ++num)
	{
		cout << "###################################################\n";
		Print(num);
	}

	return 0;
}
