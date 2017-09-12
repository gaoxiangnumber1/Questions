#include <stdio.h>
#include <assert.h>
#include <string.h>

/////////////////////////////////////////////////////////////////
void ReplaceStringSpace(char *str, int max_length)
{
	if(str == nullptr || *str == 0) // Negative test.
	{
		return;
	}

	int length = 0, space = 0;
	for(; str[length] != 0; str[length] == ' ' ? ++space : 0, ++length)
		;
	if(length + space * 2 > max_length) // Negative test
	{
		return;
	}

	for(int before = length, after = length + space * 2; before != after; --before)
	{
		if(str[before] != ' ')
		{
			str[after--] = str[before];
		}
		else
		{
			str[after--] = '0';
			str[after--] = '2';
			str[after--] = '%';
		}
	}
}
void TestReplaceStringSpace()
{
	printf("-----TestReplaceStringSpace-----\n");
	const int kLength = 32;
	char input[][kLength] = { /*nullptr*/"", "                    ", /*Negative TestReplaceStringSpace*/
	"gao", " ", "  ", /*Edge TestReplaceStringSpace*/
	" gao", "g ao", "gao ", "  g  ao  " /*Function TestReplaceStringSpace*/
	};
	char output[][kLength] = { /*nullptr*/"", "                    ", /*Negative TestReplaceStringSpace*/
	"gao", "%20", "%20%20", /*Edge TestReplaceStringSpace*/
	"%20gao", "g%20ao", "gao%20", "%20%20g%20%20ao%20%20" /*Function TestReplaceStringSpace*/
	};
	for(int index = 0; index < static_cast<int>(sizeof(input) / kLength); ++index)
	{
		ReplaceStringSpace(input[index], kLength);
		if(memcmp(input[index], output[index], strlen(output[index]) + 1) != 0)
		{
			printf("Case not pass: wrong=`%s`, right=`%s`\n", input[index], output[index]);
			assert(0);
		}
	}
	char *null = nullptr;
	ReplaceStringSpace(null, kLength);
	assert(null == nullptr);
	printf("All case pass.\n");
}
/////////////////////////////////////////////////////////////////
const int kNumberOfChar = 128;
// const int kMod = TODO;
int QuickPower(int base, int exponent)
{
	int power = 1;
	while(exponent > 0)
	{
		if((exponent & 0x1) == 1)
		{
			power *= base; // %
		}
		exponent >>= 1;
		base *= base;
	}
	return power;
}
int HashValue(const char *data, const int length) // O(length)
{
	int hash_value = 0;
	for(int index = 0; index < length; ++index)
	{
		hash_value = hash_value * kNumberOfChar + static_cast<int>(data[index]); // %
	}
	return hash_value;
}
void RKStringSearch(const char *haystack, const char *needle)
{
	printf("----------RKStringSearch----------\n");
	int long_length = static_cast<int>(strlen(haystack));
	int short_length = static_cast<int>(strlen(needle));
	// Pre-process
	int target_hash_value = HashValue(needle, short_length);
	int substring_number = long_length - short_length + 1;
	int hash_value[substring_number];
	hash_value[0] = HashValue(haystack, short_length);
	int max_power = QuickPower(kNumberOfChar, short_length - 1);
	bool good_match = false;
	for(int index = 0; index < substring_number; ++index)
	{
		if(hash_value[index] == target_hash_value
			&& strncmp(haystack + index, needle, short_length) == 0)
		{
			printf("%d ", index);
			good_match = true;
		}
		if(index < substring_number - 1)
		{
			int to_subtract = static_cast<int>(haystack[index]) * max_power; // %
			int to_add = static_cast<int>(haystack[index + short_length]);
			hash_value[index + 1] = (hash_value[index] - to_subtract) * kNumberOfChar + to_add; // %
		}
	}
	if(good_match == false)
	{
		printf("null");
	}
	printf("\n");
}
/////////////////////////////////////////////////////////////////
void ComputePrefix(const char *string, int *max_prefix_length, int length)
{
	max_prefix_length[0] = 0; // string[0] has no prefix.
	int matched = 0; // Already matched prefix's length.
	for(int index = 1; index < length; ++index) // string[1, length - 1] has prefix.
	{
		// 1.	matched == 0: we should check string[0] next, since string[0] has no
		//		prefix, thus exit while loop.
		// 2.	matched != 0: we have matched string[0, matched - 1],
		//		check string[matched] next.
		// 3.	string[matched] != string[index]: decrease matched to current prefix
		//		string[0, matched - 1] 's matched prefix length.
		// 4.	string[matched] == string[index]: match success, increase matched by 1.
		while(matched > 0 && string[matched] != string[index])
		{
			matched = max_prefix_length[matched - 1];
		}
		if(string[matched] == string[index])
		{
			++matched;
		}
		max_prefix_length[index] = matched;
	}
}
void KMPStringSearch(const char *haystack, const char *needle)
{
	printf("----------KMPStringSearch----------\n");
	int long_length = static_cast<int>(strlen(haystack));
	int short_length = static_cast<int>(strlen(needle));
	int max_prefix_length[short_length];
	ComputePrefix(needle, max_prefix_length, short_length);
	int matched = 0;
	bool good_match = false;
	for(int index = 0; index < long_length; ++index)
	{
		while(matched > 0 && needle[matched] != haystack[index])
		{
			matched = max_prefix_length[matched - 1];
		}
		if(needle[matched] == haystack[index])
		{
			++matched;
		}
		if(matched == short_length)
		{
			good_match = true;
			printf("%d ", index - matched + 1);
			matched = max_prefix_length[matched - 1];
		}
	}
	if(good_match == false)
	{
		printf("null");
	}
	printf("\n");
}
void TestStringSearch()
{
	const int kLongStringSize = 1024;
	const int kShortStringSize = 64;
	char haystack[kLongStringSize], needle[kShortStringSize];
	while(scanf("%s %s", haystack, needle) == 2)
	{
		RKStringSearch(haystack, needle);
		KMPStringSearch(haystack, needle);
	}
}
/////////////////////////////////////////////////////////////////

int main()
{
	TestReplaceStringSpace();
}
