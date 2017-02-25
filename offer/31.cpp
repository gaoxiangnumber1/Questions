/*
------------------------------Function Test Data------------------------------
normal

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
empty array

*/

#include <vector>
#include <iostream>
using namespace std;

int FindGreatestSumOfSubArray(vector<int> array)
{
	int length = array.size();
	if(length <= 0)
	{
		return 0;
	}
	// "int result = 0" is wrong since the max sum can be negative!
	int result = 0x80000000, current = 0;
	for(int index = 0; index < length; ++index)
	{
		if(current <= 0)
		{
			current = array[index];
		}
		else
		{
			current += array[index];
		}
		result = (result > current ? result : current);
	}
	return result;
}

int main()
{
	vector<int> numbers = {0,-9,-5,87,-6,-5,-4,-85,-8,-5,-7,-4};
	cout << Fun(numbers);

	return 0;
}
