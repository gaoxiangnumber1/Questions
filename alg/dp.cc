#include "../common_system_header.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int MaxSubArraySum(const vector<int> &arr)
{
	int length = static_cast<int>(arr.size());
	if(length <= 0) // Negative test.
	{
		return 0;
	}
	int max_sum = arr[0];
	for(int current_max_sum = arr[0], index = 1; index < length; ++index)
	{
		current_max_sum <= 0 ? current_max_sum = arr[index] : current_max_sum +=
									arr[index];
		max_sum = max(max_sum, current_max_sum);
	}
	return max_sum;
}
void TestMaxSubArraySum()
{
	printf("----------TestMaxSubArraySum----------\n");
	vector<vector<int>> arr { {},/*Negative test*/{ -1, -2, -3, -4, -5 }, { 0, 0, 0,
		0, 0 }, { 1, 2, 3, 4, 5 },/*Edge test*/{ 1, 1, 1, 1, 1, 1 }, { -1, 0, 1, 1,
		1, 1 }, { -1, 0, -1, 0, -1, 0 }, { -1, 0, 2, -1, 0, 0 }, { -5, -4, -1, -2,
		-3, -6 }, { -5, 0, 10, -2, -3, 9 }, { -2, 11, -4, 13, -5, -2 }, { 5, -8, 3,
		2, 5, 0 } };
	vector<int> answer = { 0, -1, 0, 15, 6, 4, 0, 2, -1, 14, 20, 10 };
	for(int index = 0; index < static_cast<int>(arr.size()); ++index)
	{
		assert(answer[index] == MaxSubArraySum(arr[index]));
	}
	printf("All case pass.\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LongestCommonSubsequence(int *s1, int s1_first, int s1_last, int *s2,
	int s2_first, int s2_last)
{
	int s1_length = s1_last - s1_first, s2_length = s2_last - s2_first;
	int length[s1_length + 1][s2_length + 1];
	for(int row = 0; row <= s1_length; ++row)
	{
		length[row][0] = 0;
	}
	for(int col = 0; col <= s2_length; ++col)
	{
		length[0][col] = 0;
	}
	for(int row = 1; row <= s1_length; ++row)
	{
		for(int col = 1; col <= s2_length; ++col)
		{
			if(s1[s1_first + row - 1] == s2[s2_first + col - 1])
			{
				length[row][col] = length[row - 1][col - 1] + 1;
			}
			else
			{
				length[row][col] = max(length[row - 1][col], length[row][col - 1]);
			}
		}
	}

	// Print LCS
	int max_length = length[s1_length][s2_length];
	//printf("LCS_length = %d: ", max_length);
	int answer[max_length], index = max_length, row = s1_length, col = s2_length;
	while(row >= 1 && col >= 1)
	{
		if(s1[row - 1] == s2[col - 1])
		{
			answer[--index] = s1[row - 1];
			--row;
			--col;
		}
		else if(length[row - 1][col] >= length[row][col - 1])
		{
			--row;
		}
		else
		{
			--col;
		}
	}
	for(index = 0; index < max_length; ++index)
	{
		printf("%d%c", answer[index], (index == max_length - 1 ? '\n' : ' '));
	}
}
void TestLongestCommonSubsequence()
{
	printf("----------TestLongestCommonSubsequence----------\n");
//	int s1[7] = { 1, 2, 3, 2, 4, 1, 2 };
//	int s2[6] = { 2, 4, 3, 1, 2, 1 };
//	LongestCommonSubsequence(s1, 0, 7, s2, 0, 6); // LCS_length = 4: 2 3 2 1
	printf("All case pass.\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	TestMaxSubArraySum();
	TestLongestCommonSubsequence();
}
