/*
------------------------------Function Test Data------------------------------
+1245
-566
5625

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
NULL pointer
""
character that is not number / '+' / '-'
over/underflow
"+" "-"

*/

#include <stdlib.h>
#include <iostream>
using namespace std;

bool g_valid = true;  // Global variable to indicate whether input is valid?

int StrToInt(string str)
{
	int length = str.size();
	// Negative data: empty string ""
	if(length <= 0)
	{
		g_valid = false;
		return 0;
	}
	int index = 0;
	// If str begin with '+' or '-', then number should begin with [1],
	// otherwise is invalid input.
	if(str[0] == '+' || str[0] == '-')
	{
		// str = "+" or "-"
		if(length == 1)
		{
			g_valid = false;
			return 0;
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
			// Negative data: over/underflow
			if(0x7fffffff < result || result < (signed int)0x80000000)
			{
				g_valid = false;
				return 0;
			}
			++index;
		}
		// Negative data: character that is not number / '+' / '-'
		else
		{
			g_valid = false;
			return 0;
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
