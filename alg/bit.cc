#include "../common_system_header.h"

//////////////////////////////////////////////////////////////////////
int NumberOfOneInBinary(int number)
{
	int count = 0;
	while(number != 0)
	{
		number = number & (number - 1);
		++count;
	}
	return count;
}
int MinChangeBit(int m, int number)
{
	return NumberOfOneInBinary(m ^ number);
}
void TestNumberOfOneInBinary()
{
	printf("-----TestNumberOfOneInBinary-----\n");
	vector<unsigned> test = { 0x80000000, 0xffffffff, 0x0, 0x1, 0x7fffffff };
	vector<int> answer = { 1, 32, 0, 1, 31 };
	for(int index = 0; index < static_cast<int>(test.size()); ++index)
	{
		assert(NumberOfOneInBinary(static_cast<int>(test[index])) == answer[index]);
	}
	assert(MinChangeBit(0x80000000, 0xffffffff) == 31);
	assert(MinChangeBit(0x80000000, 0x0) == 1);
	assert(MinChangeBit(0x80000000, 0x1) == 2);
	assert(MinChangeBit(0x80000000, 0x7fffffff) == 32);
	assert(MinChangeBit(0xffffffff, 0x0) == 32);
	assert(MinChangeBit(0x80000000, 0x80000000) == 0);
	printf("All case pass.\n");
}
//////////////////////////////////////////////////////////////////////
int main()
{
	TestNumberOfOneInBinary();
}
