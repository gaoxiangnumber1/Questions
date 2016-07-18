/*
------------------------------Function Test Data------------------------------
Normal number string

--------------------------------Edge Test Data--------------------------------
1.
.1

------------------------------Negative Test Data------------------------------
NULL pointer
*/

#include <iostream>
using namespace std;

bool IsDigit(char *string)
{
	if('0' <= *string && *string <= '9')
	{
		return true;
	}
	return false;
}

bool isNumeric(char *string)
{
	// Negative data: null pointer
	if(string == NULL)
	{
		return false;
	}

	/*
	First number:
	1. Sign: optional.	+600, -600
	2. Digit: optional.	.2, +.3, -.56e5, 1.5E8
	1) If has digit: continue scanning until the first non-digit character;
	2) Otherwise: this mean "0.x", so the following characters must be ".2", that is, a dot with digits.
	*/
	if(*string == '+' || *string == '-')
	{
		++string;
	}
	if(!IsDigit(string) && !(*string == '.' && IsDigit(string + 1)))
	{
		return false;
	}
	while(IsDigit(string))
	{
		++string;
	}

	/*
	Second number:
	1. Sign: can't have.	6.3
	2. Digit: optional.		6.e5
	1) If has digit: continue scanning until the first non-digit character;
	2) Otherwise: the following character must be '\0', 'e' or 'E'.
	*/
	if(*string == '.')
	{
		++string;
		if(!IsDigit(string) && !(*string == '\0' || *string == 'e' || *string == 'E'))
		{
			return false;
		}
		while(IsDigit(string))
		{
			++string;
		}
	}

	/*
	Third number:
	1. Sign: optional.	6e-5, 5e6
	2. Digit: must have, otherwise false.
	*/
	if(*string == 'e' || *string == 'E')
	{
		++string;
		if(*string == '+' || *string == '-')
		{
			++string;
		}
		if(!IsDigit(string))
		{
			return false;
		}
		while(IsDigit(string))
		{
			++string;
		}
	}

	// Now, *string must be '\0', otherwise false.
	if(*string == 0)
	{
		return true;
	}
	return false;
}

int main()
{
	return 0;
}
