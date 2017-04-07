/*
------------------------------Function Test Data------------------------------
normal vector

--------------------------------Edge Test Data--------------------------------

none

------------------------------Negative Test Data------------------------------
empty vector

*/
#include <iostream>
#include <vector>
using namespace std;

const int kMax = 14;  // Don't use #define

// This sort algorithm is based on counting sort(O(n)), but unstable and quicker.
void NonStableCountingSort(vector<int> &number, int first, int last)
{
	// First, initialize cnt array to all zeros:
	int cnt[kMax];
	for(int num = 0; num < kMax; ++num)
	{
		cnt[num] = 0;
	}

	// Second, get frequency of each number in array number:
	for(int index = first; index <= last; ++index)
	{
		++cnt[number[index]];
	}

	// Third, fill ordered numbers in array number:
	int pos = first;
	for(int num = 0; num < kMax; ++num)
	{
		while(cnt[num]--)
		{
			number[pos++] = num;
		}
	}
}

bool IsContinuous(vector<int> numbers)
{
	int length = numbers.size();
	if(length <= 0)
	{
		return true;
	}

	// First, sort this array:
	NonStableCountingSort(numbers, 0, length - 1);

	// Second, we count the numbers of 0:
	int zero = 0, nonzero = 0;
	for(int index = 0; index < length && numbers[index] == 0; ++index, ++zero);
	nonzero = length - zero;

	// Third, get the differences between each pair numbers:
	int diff_sum = 0;
	for(int index = zero; index <= length - 2; ++index)
	{
		int diff = numbers[index + 1] - numbers[index];
		if(diff == 0)
		{
			return false;
		}
		diff_sum += diff - 1;
	}

	// Fourth, judge whether there is enough zeros to fill gaps.
	if(0 <= diff_sum && diff_sum <= zero)
	{
		return true;
	}
	return false;
}

int main()
{
	const int kSize = 5;
	while(1)
	{
		vector<int> numbers(kSize);
		cout << "Input " << kSize << " numbers: ";
		for(int index = 0; index < kSize; ++index)
		{
			cin >> numbers[index];
		}
		cout << Fun(numbers) << endl;
	}

	return 0;
}

