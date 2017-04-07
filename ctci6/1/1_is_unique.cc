// Function Test:	1. "gao718" 2. "gao7188" 3. "gao718xiang"
// Edge Test:			1. ""(empty string)
// Negative Test:	none.

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include <string>

using namespace std;

// Assume: c is the number of unique chars, s is the length of string.
// s > c:	TC = O(1)			SC = O(1)
// s <= c:	TC = O(s^2)		SC = O(1)
const int kNumberOfUniqueChar = 128;
bool IsUniqueDoubleLoop(const string &str)
{
	int length = static_cast<int>(str.size());
	// If there are at most c unique chars, then the longest unique string's length is c.
	if(length > kNumberOfUniqueChar)
	{
		return false;
	}
	// Use double loops to check.
	for(int outer = 0; outer < length; ++outer)
	{
		for(int inner = outer + 1; inner < length; ++inner)
		{
			if(str[outer] == str[inner])
			{
				return false;
			}
		}
	}
	return true;
}

// s > c:	TC = O(1)			SC = O(1)
// s <= c:	TC = O(c + s)	SC = O(c)
bool IsUniqueBoolArray(const string &str)
{
	int length = static_cast<int>(str.size());
	if(length > kNumberOfUniqueChar)
	{
		return false;
	}
	// appeared[index] indicates that whether the char whose value is index
	// has appeared before is this string. Initialize all elements to false.
	bool appeared[kNumberOfUniqueChar];
	memset(appeared, false, sizeof appeared);
	for(int index = 0; index < length; ++index)
	{
		int ch = static_cast<int>(str[index]);
		// This char has appeared, so is not unique.
		if(appeared[ch] == true)
		{
			return false;
		}
		// Record this appeared char.
		appeared[ch] = true;
	}
	return true;
}

// s > c:	TC = O(1)			SC = O(1)
// s <= c:	TC = O(c/8 + s)	SC = O(c/8)
using BitArrayUnit = int64_t;
const int kNumberOfBit = static_cast<int>(sizeof(BitArrayUnit));
bool IsUniqueBitArray(const string &str)
{
	int length = static_cast<int>(str.size());
	if(length > kNumberOfUniqueChar)
	{
		return false;
	}
	// Use one bit to indicate the appearance of char: 0 means not appear, otherwise 1.
	// Suppose BitArrayUnit is int64_t, then char in [0, 63] are recorded in appeared[0],
	// char in [64, 127] are recorded in appeared[1], and so on.
	// Initialize all to 0.
	BitArrayUnit appeared[kNumberOfUniqueChar / kNumberOfBit];
	memset(appeared, 0, sizeof appeared);
	for(int index = 0; index < length; ++index)
	{
		int ch = static_cast<int>(str[index]);
		// ch = bit_index * kNumberOfBit + bit_offset.
		// bit_index is the index in the appeared array;
		// bit_offset is the offset of this bit in the array's element.
		int bit_index = ch / kNumberOfBit;
		int bit_offset = ch % kNumberOfBit;
		if((appeared[bit_index] & (1 << bit_offset)) > 0)
		{
			return false;
		}
		// Record appearance.
		appeared[bit_index] |= (1 << bit_offset);
	}
	return true;
}

// s > c:	TC = O(1)			SC = O(c)
// s <= c:	TC = O(s)			SC = O(c)
// Restrict: This solution can be only used when the scope of appeared char is small
// and the string is not long.
const unsigned int kPrimeArray[kNumberOfUniqueChar] =
{
	2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79,
	83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163,
	167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251,
	257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
	353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443,
	449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557,
	563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647,
	653, 659, 661, 673, 677, 683, 691, 701, 709, 719
};
bool IsUniquePrimeArray(const string &str)
{
	int length = static_cast<int>(str.size());
	if(length > kNumberOfUniqueChar)
	{
		return false;
	}
	uint64_t mult = 1;
	for(int index = 0; index < length; ++index)
	{
		int ch = static_cast<int>(str[index]);
		// Since every char corresponds to one unique prime, if mult can be divided by
		// this prime, it indicates that this char has appeared before.
		if(mult % kPrimeArray[ch] == 0)
		{
			return false;
		}
		// Record this appearance.
		mult *= kPrimeArray[ch];
	}
	return true;
}

const int kBufferSize = 1024;
int main()
{
	char buffer[kBufferSize];
	while(scanf("%s", buffer) == 1)
	{
		printf("%s %s %s %s\n",
		       IsUniqueDoubleLoop(buffer) ? "true" : "false",
		       IsUniqueBoolArray(buffer) ? "true" : "false",
		       IsUniqueBitArray(buffer) ? "true" : "false",
		       IsUniquePrimeArray(buffer) ? "true" : "false");
	}
}
