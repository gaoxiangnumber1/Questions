// Function Test:	1. "gao718" 2. "gao7188" 3. "gao718xiang"
// Edge Test:			1. ""(empty string)
// Negative Test:	none.

#include <stdio.h>
#include <string.h>

#include <string>

using namespace std;

const int kNumberOfUniqueChar = 128;
// Assume: c is the number of unique chars, s is the length of string.
// s > c:	TC = O(1)			SC = O(1)
// s <= c:	TC = O(c + s)	SC = O(c)
bool IsUnique1(const string &str)
{
	int length = static_cast<int>(str.size());
	if(length > kNumberOfUniqueChar)
	{
		return false;
	}
	bool appeared[kNumberOfUniqueChar];
	memset(appeared, false, sizeof appeared);
	for(int index = 0; index < length; ++index)
	{
		int ch = static_cast<int>(str[index]);
		if(appeared[ch] == true)
		{
			return false;
		}
		appeared[ch] = true;
	}
	return true;
}

// Assume: c is the number of unique chars, s is the length of string.
// s > c:	TC = O(1)			SC = O(1)
// s <= c:	TC = O(c/8 + s)	SC = O(c/8)
using BitArrayUnit = int64_t;
const int kNumberOfBit = static_cast<int>(sizeof(BitArrayUnit));
bool IsUnique2(const string &str)
{
	int length = static_cast<int>(str.size());
	if(length > kNumberOfUniqueChar)
	{
		return false;
	}
	BitArrayUnit appeared[kNumberOfUniqueChar / kNumberOfBit];
	memset(appeared, 0, sizeof appeared);
	for(int index = 0; index < length; ++index)
	{
		int ch = static_cast<int>(str[index]);
		int bit_index = ch / kNumberOfBit;
		int bit_offset = ch % kNumberOfBit;
		if((appeared[bit_index] & (1 << bit_offset)) > 0)
		{
			return false;
		}
		appeared[bit_index] |= (1 << bit_offset);
	}
	return true;
}

const int kBufferSize = 1024;
int main()
{
	char buffer[kBufferSize];
	while(scanf("%s", buffer) == 1)
	{
		printf("%s %s\n",
		       IsUnique1(buffer) ? "true" : "false",
		       IsUnique2(buffer) ? "true" : "false");
	}
}
