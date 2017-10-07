#include "../common_system_header.h"
/////////////////////////////////////////////////////////////////
void ReplaceStringSpace(char *str, int max_length)
{
	if(str == nullptr || *str == 0) // Negative test.
	{
		return;
	}
	int length = 0, space = 0;
	for(; str[length] != 0; ++length)
	{
		str[length] == ' ' ? ++space : space;
	}
	if(length + space * 2 > max_length) // Negative test
	{
		return;
	}
	for(int left = length, right = length + space * 2; left != right; --left)
	{
		str[left] != ' ' ? str[right--] = str[left] : (str[right--] = '0', str[right--] =
			'2', str[right--] = '%');
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
			printf("Case not pass: wrong=`%s`, right=`%s`\n", input[index],
				output[index]);
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
int HashValue(const char *data, int length) // O(n)
{
	int hash_value = 0;
	for(int index = 0; index < length; ++index)
	{
		hash_value = hash_value * kNumberOfChar + static_cast<int>(data[index]); // %
	}
	return hash_value;
}
vector<int> RKStringMatching(const string &text, const string &pattern)
{
	if(text.size() <= 0 || pattern.size() <= 0 || text.size() < pattern.size()) // Negative test
	{
		return vector<int>();
	}
	int pattern_length = static_cast<int>(pattern.size());
	int substring_number = static_cast<int>(text.size()) - pattern_length + 1;
	vector<int> text_hash_value(substring_number);
	text_hash_value[0] = HashValue(text.data(), pattern_length);
	int pattern_hash_value = HashValue(pattern.data(), pattern_length);
	vector<int> shift;
	const int kMaxPower = static_cast<int>(pow(kNumberOfChar, pattern_length - 1));
	for(int index = 0; index < substring_number; ++index)
	{
		if(text_hash_value[index] == pattern_hash_value
			&& memcmp(&text[index], pattern.data(), pattern_length) == 0)
		{
			shift.push_back(index);
		}
		if(index + 1 < substring_number)
		{
			int to_subtract = static_cast<int>(text[index]) * kMaxPower; // %
			int to_add = static_cast<int>(text[index + pattern_length]);
			text_hash_value[index + 1] = (text_hash_value[index] - to_subtract)
				* kNumberOfChar + to_add; // %
		}
	}
	return shift;
}
/////////////////////////////////////////////////////////////////
void ComputePrefix(const string &str, vector<int> &max_prefix_length)
{
	int matched_length = 0; // Already matched prefix's length.
	max_prefix_length[0] = 0; // string[0] has no prefix, [1, length - 1] has prefix.
	for(int index = 1; index < static_cast<int>(str.size()); ++index)
	{
		// 1.	matched_length == 0: check [0] next, exit while loop.
		// 2.	matched_length != 0: have matched [0, matched_length - 1],
		//		check [matched_length] next.
		// 3.	[matched_length] != [index]: decrease matched_length to current
		//		prefix [0, matched_length - 1]'s max prefix length.
		// 4.	[matched_length] == [index]: increase matched_length by 1.
		while(matched_length > 0 && str[matched_length] != str[index])
		{
			matched_length = max_prefix_length[matched_length - 1];
		}
		str[matched_length] == str[index] ? ++matched_length : matched_length;
		max_prefix_length[index] = matched_length;
	}
}
vector<int> KMPStringMatching(const string &text, const string &pattern)
{
	if(text.size() <= 0 || pattern.size() <= 0 || text.size() < pattern.size()) // Negative test
	{
		return vector<int>();
	}
	int pattern_length = static_cast<int>(pattern.size());
	vector<int> max_prefix_length(pattern_length);
	ComputePrefix(pattern, max_prefix_length);
	vector<int> shift;
	for(int matched_length = 0, index = 0; index < static_cast<int>(text.size());
		++index)
	{
		while(matched_length > 0 && pattern[matched_length] != text[index])
		{
			matched_length = max_prefix_length[matched_length - 1];
		}
		pattern[matched_length] == text[index] ? ++matched_length : matched_length;
		if(matched_length == pattern_length)
		{
			shift.push_back(index - pattern_length + 1);
			matched_length = max_prefix_length[matched_length - 1];
		}
	}
	return shift;
}
void TestStringMatching()
{
	printf("-----TestStringMatching-----\n");
	vector<string> text { "", "a",/*Negative test*/
	"aaa", "aaa", "aaa",/*Edge test*/
	"abcdabcaba", "abcdabcaba", "abcdabcaba", "abcdabcaba", "abcdabcaba",
		"abcdabcaba", "abcdabcaba", /*Function test*/};
	vector<string> pattern { "", "aa",/*Negative test*/
	"a", "aa", "aaa",/*Edge test*/
	"a", "bc", "abc", "bcab", "e", "ac", "dac" /*Function test*/};
	vector<vector<int>> answer { {}, {}, { 0, 1, 2 }, { 0, 1 }, { 0 },
		{ 0, 4, 7, 9 }, { 1, 5 }, { 0, 4 }, { 5 }, {}, {}, {} };
	for(int index = 0; index < static_cast<int>(text.size()); ++index)
	{
		AssertVectorData(RKStringMatching(text[index], pattern[index]),
			answer[index]);
		AssertVectorData(KMPStringMatching(text[index], pattern[index]),
			answer[index]);
	}
	printf("All case pass.\n");
}
/////////////////////////////////////////////////////////////////
int main()
{
	TestReplaceStringSpace();
	TestStringMatching();
}
