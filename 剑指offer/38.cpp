/*
------------------------------Function Test Data------------------------------
nonempty array

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
empty array

*/

#include <iostream>
#include <vector>
using namespace std;

int GetFirst(vector<int> data, int first, int last, int target)
{
	while(first <= last)
	{
		int middle = first + ((last - first) >> 1);
		if(data[middle] < target)
		{
			first = middle + 1;
		}
		else if(data[middle] == target)
		{
			// I think middle == 0 is not right since we have verify scope beyond [first, last]
			if(middle == first || data[middle - 1] != target)
			{
				return middle;
			}
			else
			{
				last = middle - 1;
			}
		}
		else
		{
			last = middle - 1;
		}
	}
	// Not find:
	return -1;
}

int GetLast(vector<int> data, int first, int last, int target)
{
	while(first <= last)
	{
		int middle = first + ((last - first) >> 1);
		if(data[middle] < target)
		{
			first = middle + 1;
		}
		else if(data[middle] == target)
		{
			if(middle == last || data[middle + 1] != target)
			{
				return middle;
			}
			else
			{
				first = middle + 1;
			}
		}
		else
		{
			last = middle - 1;
		}
	}
	// Not find:
	return -1;
}

// Return: -1 on error, 0 if not find, positive if find.
int GetNumberOfK(vector<int> data, int k)
{
	int length = data.size();
	// Negative data:
	if(length <= 0)
	{
		return -1;
	}

	int first = GetFirst(data, 0, length - 1, k);
	int last = GetLast(data, 0, length - 1, k);
	// Check whether we find the k number?
	if(first > -1 && last > -1)
	{
		return last - first + 1;
	}
	// Not find:
	return 0;
}

int main()
{
	while(1)
	{
		cout << "Input 8 numbers: ";
		vector<int> data(8);
		for(int index = 0; index < 8; ++index)
		{
			cin >> data[index];
		}
		cout << "Input K: ";
		int target;
		cin >> target;
		cout << Get(data, target) << "\n";
	}

	return 0;
}
