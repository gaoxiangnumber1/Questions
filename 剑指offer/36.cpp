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

// Sort data[first, last]
// Note: data must be passed by reference since we need modify it; both are okay for temp
int MergeSort(vector<int> &data, int first, int last, vector<int> temp)
{
	// Recursive end:
	if(first >= last)
	{
		return 0;
	}

	// First, we get the count of sub-left-part and sub-right-part:
	int middle = first + ((last - first) >> 1);
	int left_count = MergeSort(data, first, middle, temp);  // [first, middle]
	int right_count = MergeSort(data, middle + 1, last, temp);  // [middle + 1, last]

	// Second, we get the count of all this part:
	int left = middle, right = last, index = last;
	int all_count = 0;
	// Only if both subparts are not empty, there has inverse pair.
	while(left >= first && right >= middle + 1)
	{
		if(data[left] > data[right])
		{
			all_count += right - (middle + 1) + 1;
			temp[index--] = data[left--];
		}
		// No need at all:
		/*
		else if(data[left] == data[right])  // Note: we have to traverse sub-right-part.
		{
			for(int index2 = right - 1; index2 >= middle + 1; --index2)
			{
				if(data[left] > data[index2])
				{
					all_count += index2 - (middle + 1) + 1;
					break;
				}
			}
			temp[index--] = data[left--];
		}
		*/
		else
		{
			temp[index--] = data[right--];
		}
	}
	// Now, at least one subpart is empty, there can't have any inverse part,
	// so we just copy remaining numbers.
	while(left >= first)
	{
		temp[index--] = data[left--];
	}
	while(right >= middle + 1)
	{
		temp[index--] = data[right--];
	}
	// Finally, copy the ordered part of temp to data:
	for(index = first; index <= last; ++index)
	{
		data[index] = temp[index];
	}
	return left_count + right_count + all_count;
}

int InversePairs(vector<int> data)
{
	int length = data.size();
	// Negative data:
	if(length <= 0)
	{
		return 0;
	}

	vector<int> temp(length);
	return MergeSort(data, 0, length - 1, temp);
}

int main()
{
	while(1)
	{
		cout << "Input 5 numbers: ";
		vector<int> data(5);
		for(int index = 0; index < 5; ++index)
		{
			cin >> data[index];
		}
		cout << InversePairs(data) << endl;
	}

	return 0;
}
