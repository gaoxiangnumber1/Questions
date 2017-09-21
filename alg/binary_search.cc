#include "../common_system_header.h"

///////////////////////////////////////////
// Assume: data points to a valid array, first and last are valid indexes.
// Return: nonnegative if found, otherwise -1.
int BinarySearch(int *data, int first, int last, int target) // [first, last)
{
	while(first < last) // []: first <= last
	{
		int middle = first + (last - first) / 2;
		// [first, middle), [middle, middle + 1), [middle + 1, last)
		if(data[middle] > target) // Search left half: [first, middle)
		{
			last = middle; // []: last = middle - 1
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
void TestBinarySearch()
{
	printf("-----TestBinarySearch-----\n");
	vector<int> data { 0, 1, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> target { -1, 0, 2, 3, 6, 9, 10 };
	vector<int> answer { -1, 0, -1, 2, 5, 8, -1 };
	for(int i = 0; i < static_cast<int>(target.size()); ++i)
	{
		assert(BinarySearch(data.data(), 0, static_cast<int>(data.size()), target[i]) == answer[i]);
	}
	printf("All case pass.\n");
}
//////////////////////////////////////////////////////////////////////
// 1. Exist: return target's first position.
// 2. Not exist: return position of first element that is greater than target.
//     If target is greater than all elements, return last.
int LowerBound(int *data, int first, int last, int target)
{
	while(first < last)
	{
		int middle = first + (last - first) / 2;
		data[middle] < target ? first = middle + 1 : last = middle;
	}
	return first;
}
// Return position of first element that is greater than target.
// If target is greater than all elements, return last.
int UpperBound(int *data, int first, int last, int target)
{
	while(first < last)
	{
		int middle = first + (last - first) / 2;
		data[middle] <= target ? first = middle + 1 : last = middle;
	}
	return last;
}
void TestLowerBoundAndUpperBound()
{
	printf("-----TestLowerBoundAndUpperBound-----\n");
	vector<int> data { 0, 1, 1, 1, 3, 5, 5, 7, 8, 9, 9, 9, 20 };
	vector<int> target { -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 20, 30, 40 };
	vector<int> lower { 0, 0, 0, 1, 4, 4, 5, 5, 7, 7, 8, 9, 12, 12, 12, 13, 13 };
	vector<int> upper { 0, 0, 1, 4, 4, 5, 5, 7, 7, 8, 9, 12, 12, 12, 13, 13, 13 };
	for(int i = 0; i < static_cast<int>(target.size()); ++i)
	{
		assert(
			LowerBound(data.data(), 0, static_cast<int>(data.size()), target[i]) == lower[i]
				&& UpperBound(data.data(), 0, static_cast<int>(data.size()), target[i])
					== upper[i]);
	}
	printf("All case pass.\n");
}
//////////////////////////////////////////////////////////////////////
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
	TestBinarySearch();
	TestLowerBoundAndUpperBound();
	TestFindMinNumberInRotateArray();
}
