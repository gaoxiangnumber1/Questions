// Function Test:	"gaoxiang" "angxiago"; "gaoxiang" "gaaxiang"; "012345" "543210"
// Edge Test:			"aaaaa" "aaaaa"
// Negative Test:	"aa" "aaa"

#include <stdio.h>
#include <string.h>

#include <string>
#include <algorithm>

using namespace std;

// TC = sort's TC
// SC = sort's SC
bool IsPermutationSort(const string &string1, const string &string2)
{
	// Negative Test: Two permutation strings must have the same length.
	if(string1.size() != string2.size())
	{
		return false;
	}
	string str1 = string1;
	string str2 = string2;
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	// Two permutations after sorted must be the same.
	return str1 == str2;
}

// Assume c is the number of unique chars; s is the length of string.
// TC = O(2c + 2s)
// SC = O(c)
const int kNumberOfChar = 128;
bool IsPermutationCount(const string &string1, const string &string2)
{
	if(string1.size() != string2.size())
	{
		return false;
	}
	int length = static_cast<int>(string1.size());
	// count[ch] indicates the number of appearance of ch in both string.
	// Initialize all elements to 0.
	int count[kNumberOfChar];
	memset(count, 0, sizeof count);
	// Traverse two strings, add for string1, subtract for string2.
	for(int index = 0; index < length; ++index)
	{
		++count[static_cast<int>(string1[index])];
		--count[static_cast<int>(string2[index])];
	}
	// If both are permutation, then each char appears the same times in both string,
	// that is, every element in count array is 0, otherwise not permutation.
	for(int index = 0; index < kNumberOfChar; ++index)
	{
		if(count[index] != 0)
		{
			return false;
		}
	}
	return true;
}

// TC = O(2s)
// SC = O(c)
// Restrict: This solution can be only used when the scope of appeared char is small
// and the string is not long.
const unsigned int kPrimeArray[kNumberOfChar] =
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
bool IsPermutationPrime(const string &string1, const string &string2)
{
	if(string1.size() != string2.size())
	{
		return false;
	}
	int length = static_cast<int>(string1.size());
	uint64_t mult = 1; // uint64_t is the maximum integer, avoid overflow.
	// Record(multiply) all char's corresponding prime in mult.
	for(int index = 0; index < length; ++index)
	{
		mult *= kPrimeArray[static_cast<int>(string1[index])];
	}
	// 1.	No repeat char. Every prime appears only once, right obviously.
	// 2.	Have repeat char. Assume prime a repeats n times, then a^n is not prime.
	//		Any non-prime can be decomposed into a product of primes, and the
	//		decomposition is unique. So a^n can only be decomposed into a*a*...*a.
	//		So, the repeated chars can only be matched by same repeated chars.
	// Combine 1 and 2, this algorithm is proved right.
	for(int index = 0; index < length; ++index)
	{
		int ch = static_cast<int>(string2[index]);
		if(mult % kPrimeArray[ch] != 0)
		{
			return false;
		}
		mult /= kPrimeArray[ch];
	}
	return true;
}

const int kBufferSize = 1024;
int main()
{
	char buffer1[kBufferSize], buffer2[kBufferSize];
	while(scanf("%s %s", buffer1, buffer2) == 2)
	{
		printf("%s %s %s\n",
		       IsPermutationSort(buffer1, buffer2) ? "Yes" : "No",
		       IsPermutationCount(buffer1, buffer2) ? "Yes" : "No",
		       IsPermutationPrime(buffer1, buffer2) ? "Yes" : "No");
	}
}
