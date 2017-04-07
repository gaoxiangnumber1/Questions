/*
------------------------------Function Test Data------------------------------
normal

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
1. empty vector: length <= 0 || null pointer
2. k > length || k < 1

*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

vector<int> result;

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

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	int length = input.size();
	// negative data:
	if(length <= 0 || k > length || k < 1)
	{
		return result;
	}

	int first = 0, last = length - 1;
	int index = Partition(input, first, last);
	while(index != k - 1)
	{
		if(index < k - 1)
		{
			first = index + 1;
			index = Partition(input, first, last);
		}
		else
		{
			last = index - 1;
			index = Partition(input, first, last);
		}
	}
	// copy to result:
	for(int index = 0; index < k; ++index)
	{
		result.push_back(input[index]);
	}
	sort(result.begin(), result.end());
	return result;
}

typedef multiset<int, greater<int>> Set;
typedef multiset<int, greater<int>>::iterator Iterator;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	int length = input.size();
	// negative data:
	if(length <= 0 || k > length || k < 1)
	{
		return result;
	}

	Set least;
	for(int index = 0; index < length; ++index)
	{
		if(least.size() < k)
		{
			least.insert(input[index]);
		}
		else
		{
			Iterator it = least.begin();
			if(*it > input[index])
			{
				least.erase(it);
				least.insert(input[index]);
			}
		}
	}

	// copy least k numbers to result
	for(Iterator it = least.begin(); it != least.end(); ++it)
	{
		result.insert(result.begin(), *it);
	}
	return result;
}

int main()
{
	vector<int> numbers = {0,9,5,87,6,-5,4,85,-8,5,7,4};
	Fun2(numbers, 10);
	for(int index = 0; index < result.size(); ++index)
	{
		cout << result[index] << '\t';
	}

	return 0;
}
