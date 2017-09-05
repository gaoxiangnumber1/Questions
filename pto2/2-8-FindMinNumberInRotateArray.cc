#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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
				return Traverse(vec, first, last);
			}
			if(vec[middle] >= vec[first])  // [middle] is in the 1st part.
			{
				first = middle;
			}
			else if(vec[middle] <= vec[last])  // [middle] is in the 2nd part.
			{
				last = middle;
			}
		}
		return vec[last];
	}

	int Traverse(const vector<int> &vec, int first, int last)
	{
		int min = vec[first];
		for(int index = first + 1; index <= last; ++index)
		{
			min = (min > vec[index] ? vec[index] : min);
		}
		return min;
	}
};

void PrintVector(const vector<int> &vec)
{
	for(int index = 0; index < static_cast<int>(vec.size()); ++index)
	{
		printf("%d ", vec[index]);
	}
	printf("\n");
}
void Test()
{
	Solution s;
	vector<int> bad_vec; // Negative test
	assert(s.FindMinNumberInRotateArray(bad_vec) == 0);
	vector<vector<int>> good_vec = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0 },/*Edge test*/
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, { 0, 0, 1, 1, 2, 2, 3, 3, 4, 4 }/*Function test*/
	};
	for(int row = 0; row < static_cast<int>(good_vec.size()); ++row)
	{
		for(int col = 0; col < static_cast<int>(good_vec[row].size()); ++col)
		{
			//PrintVector(good_vec[row]);
			assert(s.FindMinNumberInRotateArray(good_vec[row]) == 0);
			int last = good_vec[row].back();
			good_vec[row].pop_back();
			good_vec[row].insert(good_vec[row].begin(), last);
		}
	}
	printf("All case pass.\n");
}

int main()
{
	Test();
}
