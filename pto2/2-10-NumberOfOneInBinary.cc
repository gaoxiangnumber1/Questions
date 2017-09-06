#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int NumberOfOneInBinary(int n)
	{
		int number = 0;
		while(n != 0)
		{
			n = n & (n - 1);
			++number;
		}
		return number;
	}
	int MinChangeBit(int m, int n)
	{
		return NumberOfOneInBinary(m ^ n);
	}
};

void Test()
{
	vector<unsigned> test = { 0x80000000, 0xffffffff, 0x0, 0x1, 0x7fffffff };
	vector<int> answer = { 1, 32, 0, 1, 31 };
	Solution s;
	for(int index = 0; index < static_cast<int>(test.size()); ++index)
	{
		assert(s.NumberOfOneInBinary(static_cast<int>(test[index])) == answer[index]);
	}
	assert(s.MinChangeBit(0x80000000, 0xffffffff) == 31);
	assert(s.MinChangeBit(0x80000000, 0x0) == 1);
	assert(s.MinChangeBit(0x80000000, 0x1) == 2);
	assert(s.MinChangeBit(0x80000000, 0x7fffffff) == 32);
	assert(s.MinChangeBit(0xffffffff, 0x0) == 32);
	assert(s.MinChangeBit(0x80000000, 0x80000000) == 0);
	printf("All case pass.\n");
}

int main()
{
	Test();
}
