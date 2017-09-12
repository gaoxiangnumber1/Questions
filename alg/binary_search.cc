#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
using std::vector;

///////////////////////////////////////////
void PrintVector(const vector<int> &vec)
{
	for(int index = 0; index < static_cast<int>(vec.size()); ++index)
	{
		printf("%d ", vec[index]);
	}
	printf("\n");
}
///////////////////////////////////////////
// Assume: data points to a valid array, first and last are valid indexes.
// Return: nonnegative if found, otherwise -1.
int BinarySearchIterate(int *data, int first, int last, int target) // Search target in [first, last)
{
	while(first < last)
	{
		int middle = first + ((last - first) >> 1);
		// [first, middle), [middle, middle + 1), [middle + 1, last)
		if(data[middle] > target) // Search left half: [first, middle)
		{
			last = middle;
		}
		else if(data[middle] == target) // Return result.
		{
			return middle;
		}
		else // Search right half: [middle + 1, last)
		{
			first = middle + 1;
		}
	}
	return -1;
}
int BinarySearchRecursive(int *data, int first, int last, int target)
{
	if(first >= last)
	{
		return -1;
	}
	int middle = first + ((last - first) >> 1);
	// [first, middle), [middle, middle + 1), [middle + 1, last)
	if(data[middle] > target)
	{
		return BinarySearchRecursive(data, first, middle, target);
	}
	else if(data[middle] == target)
	{
		return middle;
	}
	else
	{
		return BinarySearchRecursive(data, middle + 1, last, target);
	}
}
///////////////////////////////////////////
int TraverseRotateArray(const vector<int> &vec, int first, int last)
{
	int min = vec[first];
	for(int index = first + 1; index <= last; ++index)
	{
		min = (min > vec[index] ? vec[index] : min);
	}
	return min;
}
// T = logn(average), n(worst) S = 1
int FindMinNumberInRotateArray(const vector<int> &vec)
{
	if(vec.size() <= 0) // Negative test: empty array.
	{
		return 0;
	}
	if(vec.front() < vec.back()) // Edge test: not rotated.
	{
		return vec.front();
	}

	int first = 0, last = static_cast<int>(vec.size()) - 1; // [first, last].
	while(last - first > 1)
	{
		int middle = first + (last - first) / 2;
		// Can't know [middle] is in the 1st or 2nd part, have to traverse.
		if(vec[first] == vec[middle] && vec[middle] == vec[last])
		{
			return TraverseRotateArray(vec, first, last);
		}
		if(vec[middle] <= vec[last])  // [middle] is in the 2nd part.
		{
			last = middle;
		}
		else if(vec[middle] >= vec[first])  // [middle] is in the 1st part.
		{
			first = middle;
		}
	}
	return vec[last];
}
void TestFindMinNumberInRotateArray()
{
	printf("-----TestFindMinNumberInRotateArray-----\n");
	vector<int> bad_vec; // Negative test
	assert(FindMinNumberInRotateArray(bad_vec) == 0);
	vector<vector<int>> good_vec = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0 },/*Edge test*/
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, { 0, 0, 1, 1, 2, 2, 3, 3, 4, 4 }/*Function test*/
	};
	for(int row = 0; row < static_cast<int>(good_vec.size()); ++row)
	{
		for(int col = 0; col < static_cast<int>(good_vec[row].size()); ++col)
		{
			//PrintVector(good_vec[row]);
			assert(FindMinNumberInRotateArray(good_vec[row]) == 0);
			int last = good_vec[row].back();
			good_vec[row].pop_back();
			good_vec[row].insert(good_vec[row].begin(), last);
		}
	}
	printf("All case pass.\n");
}
///////////////////////////////////////////

int main()
{
	TestFindMinNumberInRotateArray();
}
