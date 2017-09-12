#include <vector>
#include <stdio.h>
#include <assert.h>
using std::vector;
using std::swap;

//////////////////////////////////////////////////////////////////////
bool FindInTwoDimensionArray(const vector<vector<int>> &data, int target)
{
	if(data.size() <= 0) // Negative test.
	{
		return false;
	}

	int total_row = static_cast<int>(data.size()), total_col = static_cast<int>(data[0].size());
	for(int row = 0, col = total_col - 1; row < total_row && col >= 0;)
	{
		if(data[row][col] < target)
		{
			++row;
		}
		else if(data[row][col] == target)
		{
			return true;
		}
		else
		{
			--col;
		}
	}
	return false;
}
void TestFindInTwoDimensionArray()
{
	printf("-----TestFindInTwoDimensionArray-----\n");
	// Negative TestFindInTwoDimensionArray: empty two dimension array and arbitrary integer.
	// Function TestFindInTwoDimensionArray: nonempty two dimension array and arbitrary integer.
	// 		True: min(-16), between(2, 3), max(30). False: min(-17), between(6, 12), max(31).
	vector<vector<int>> good_vec = { { -16, -7, 0, 8 }, { -15, 3, 10, 20 }, { 1, 4, 13, 25 }, { 2,
		5, 19, 30 } };
	vector<vector<int>> bad_vec;
	vector<vector<int>> test_vec = { { -16, 2, 3, 30 }, { -17, 6, 12, 31 } };
	for(int row = 0; row < static_cast<int>(test_vec.size()); ++row)
	{
		for(int col = 0; col < static_cast<int>(test_vec[row].size()); ++col)
		{
			if(FindInTwoDimensionArray(good_vec, test_vec[row][col]) != (row == 0)
				|| FindInTwoDimensionArray(bad_vec, test_vec[row][col]) != false)
			{
				printf("Case not pass: target = %d\n", test_vec[row][col]);
				assert(0);
			}
		}
	}
	printf("All case pass.\n");
}
//////////////////////////////////////////////////////////////////////
inline bool IsEven(int num)
{
	return (num & 1) == 0;
}
void ReOrderArray(vector<int> &vec)
{
	int length = static_cast<int>(vec.size());
	if(length <= 1) // Negative and Edge test.
	{
		return;
	}
	int left = 0, right = length - 1;
	while(left < right)
	{
		for(; left < length && IsEven(vec[left]) == false; ++left)
			;
		for(; right >= 0 && IsEven(vec[right]) == true; --right)
			;
		left < right ? swap(vec[left], vec[right]) : void(0);
	}
}
void TestReOrderArray()
{
	printf("-----TestReOrderArray-----\n");
	vector<vector<int>> test = { {},/*Negative test*/
	{ 0 }, { 1 }, { 1, 3, 5, 7, 9 }, { 0, 2, 4, 6, 8 }, /*Edge test*/
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 }, { 1, 3, 5, 7, 9, 0, 2, 4, 6,
		8 }/*Function test*/};
	for(int i = 0; i < static_cast<int>(test.size()); ++i)
	{
		ReOrderArray(test[i]);
		int j = 0, length = static_cast<int>(test[i].size());
		for(; j < length && (test[i][j] & 1) == 1; ++j)
			;
		for(; j < length; assert((test[i][j] & 1) == 0), ++j)
			;
	}
	printf("All case pass.\n");
}
//////////////////////////////////////////////////////////////////////
int main()
{
	TestFindInTwoDimensionArray();
	TestReOrderArray();
}
