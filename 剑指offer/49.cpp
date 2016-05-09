/*
------------------------------Function Test Data------------------------------
+1245
-566
5625

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
1. NULL pointer
2. ""
3. "+" "-"
4. character that is not number / '+'(only head) / '-'(only head)
5. over/underflow
*/

#include <iostream>
using namespace std;

bool g_valid = true;  // Global variable to indicate whether input is valid?

#define Error() g_valid = false; return 0;  // Just for efficiency

int StrToInt(string str)
{
	int length = str.size();

	// Negative data 2: empty string ""
	if(length <= 0)
	{
		Error();
	}

	int index = 0;
	// If str begin with '+' or '-', then number should begin with [1],
	// otherwise is invalid input.
	if(str[0] == '+' || str[0] == '-')
	{
		// Negative data 3: str = "+" or "-"
		if(length == 1)
		{
			Error();
		}
		++index;
	}

	long long result = 0;  // Use long long type to deal with over/underflow condition
	while(index < length)
	{
		// Valid input:
		if('0' <= str[index] && str[index] <= '9')
		{
			result = result * 10 + str[index] - '0';
			// Negative data 5: over/underflow
			if(0x7fffffff < result || result < 0x80000000)
			{
				Error();
			}
			++index;
		}
		// Negative data 4: character that is not number / '+' / '-'
		else
		{
			Error();
		}
	}

	result = (int)result;
	if(str[0] == '-')
	{
		result *= -1;
	}

	return result;
}

int main()
{
	while(1)
	{
		string str;
		cin >> str;
		cout << StrToInt(str) << endl;
	}

	return 0;
}
