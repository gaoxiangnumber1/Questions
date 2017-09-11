#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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
};
void Test()
{
	vector<vector<int>> test = { {},/*Negative test*/
	{ 0 }, { 1 }, { 1, 3, 5, 7, 9 }, { 0, 2, 4, 6, 8 }, /*Edge test*/
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 }, { 1, 3, 5, 7, 9, 0, 2, 4, 6,
		8 }/*Function test*/};
	Solution s;
	for(int i = 0; i < static_cast<int>(test.size()); ++i)
	{
		s.ReOrderArray(test[i]);
		int j = 0, length = static_cast<int>(test[i].size());
		for(; j < length && (test[i][j] & 1) == 1; ++j)
			;
		for(; j < length; assert((test[i][j] & 1) == 0), ++j)
			;
	}
	printf("All case pass.\n");
}

int main()
{
	Test();
}
