/*
------------------------------Function Test Data------------------------------
length >= 2

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
length < 2

*/

#include <iostream>
#include <vector>
using namespace std;

void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
{
	int length = data.size();
	if(length < 2)
	{
		return;
	}

	int result = 0;
	for(int index = 0; index < length; ++index)
	{
		result ^= data[index];
	}
	// Find the first 1-bit in result:
	int num = 1;
	while(num)
	{
		if(num & result)
		{
			break;
		}
		num <<= 1;
	}
	// Traverse to divide array and get two different numbers
	*num1 = *num2 = 0;
	for(int index = 0; index < length; ++index)
	{
		if(num & data[index])
		{
			*num1 ^= data[index];
		}
		else
		{
			*num2 ^= data[index];
		}
	}
}

int main()
{
	for(;;)
	{
		cout << "Input 8 numbers: ";
		vector<int> data(8);
		for(int index = 0; index < 8; ++index)
		{
			cin >> data[index];
		}
		int num1 = 0, num2 = 0;
		Fun(data, &num1, &num2);
		cout << num1 << '\t' << num2 << endl;
	}

	return 0;
}
