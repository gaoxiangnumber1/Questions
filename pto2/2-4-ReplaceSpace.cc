#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	// T(n) = O(n) S(n)=O(1)
	void ReplaceSpace(char *str, int max_length)
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
};

void Test()
{
	const int kLength = 32;
	char input[][kLength] = { /*nullptr*/"", "                    ", /*Negative Test*/
	"gao", " ", "  ", /*Edge Test*/
	" gao", "g ao", "gao ", "  g  ao  " /*Function Test*/
	};
	char output[][kLength] = { /*nullptr*/"", "                    ", /*Negative Test*/
	"gao", "%20", "%20%20", /*Edge Test*/
	"%20gao", "g%20ao", "gao%20", "%20%20g%20%20ao%20%20" /*Function Test*/
	};
	Solution s;
	for(int index = 0; index < static_cast<int>(sizeof(input) / kLength); ++index)
	{
		s.ReplaceSpace(input[index], kLength);
		if(memcmp(input[index], output[index], strlen(output[index]) + 1) != 0)
		{
			printf("Case not pass: wrong=`%s`, right=`%s`\n", input[index], output[index]);
			assert(0);
		}
	}
	char *null = nullptr;
	s.ReplaceSpace(null, kLength);
	assert(null == nullptr);
	printf("All case pass.\n");
}

int main()
{
	Test();
}
