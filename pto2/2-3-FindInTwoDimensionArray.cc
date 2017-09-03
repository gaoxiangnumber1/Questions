#include <bits/stdc++.h>
using namespace std;

// T(n) = O(n+m) S(n) = O(1)
bool FindInTwoDimensionArray(const vector<vector<int>> &data, int target)
{
	int total_row = static_cast<int>(data.size());
	int total_col = (total_row != 0 ? static_cast<int>(data[0].size()) : 0);
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

void Test()
{
	// Function Test: nonempty two dimension array and arbitrary integer.
	// 		True: min(-16), between(2, 3), max(30). False: min(-17), between(6, 12), max(31).
	// Edge Test:
	// Negative Test: empty two dimension array and arbitrary integer.
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

int main()
{
	Test();
}
