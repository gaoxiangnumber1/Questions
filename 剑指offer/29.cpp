/*
------------------------------Function Test Data------------------------------
normal

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
empty vector

*/

#include<vector>
#include<iostream>
using namespace std;

int Partition(vector<int> &numbers, int first, int last)  // numbers[first, last]
{
	int pivot = numbers[last];
	int divide = first;  // return value
	for(int index = first; index < last; ++index)
	{
		if(numbers[index] <= pivot)
		{
			swap(numbers[index], numbers[divide]);
			++divide;
		}
	}
	swap(numbers[divide], numbers[last]);
	return divide;
}

int MoreThanHalfNum_Solution(vector<int> numbers)// 已通过^_^
{
	int length = numbers.size();
	// negative data:
	if(length <= 0)
	{
		return 0;
	}

	int first = 0, middle = length >> 1, last = length - 1;
	// numbers is passed by reference since we need modify it.
	int index = Partition(numbers, first, last);
	while(index != middle)
	{
		if(index < middle)
		{
			first = index + 1;
			index = Partition(numbers, first, last);
		}
		else
		{
			last = index - 1;
			index = Partition(numbers, first, last);
		}
	}
	int result = numbers[middle];
	// check whether result appears more than half times or not,
	int time = 0;
	for(int index = 0; index < length; ++index)
	{
		if(numbers[index] == result)
		{
			++time;
		}
	}
	if(time > (length >> 1))  // yes
	{
		return result;
	}
	return 0;  // no
}

int main()
{
	vector<int> numbers = {1,2,3,4,4,4,4,4,5};
	cout << Solution(numbers);

	return 0;
}

