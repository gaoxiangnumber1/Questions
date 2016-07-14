/*
------------------------------Function Test Data------------------------------
Normal number string

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
NULL pointer
*/

#include <iostream>
using namespace std;

bool IsNumber(char *&string)
{
	if(*string == '-' || *string == '+')
	{
		++string;
	}
	if(!('0' <= *string && *string <= '9'))  // At least one digit.
	{
		return false;
	}
	while('0' <= *string && *string <= '9')
	{
		++string;
	}
	return true;
}

bool isNumeric(char *string)
{
	// Negative data: null pointer
	if(string == NULL)
	{
		return false;
	}

	// string must begin with number.
	if(!IsNumber(string))
	{
		return false;
	}
	// Now, *string must be '.', 'e/E' or '\0', we first judge '.'.
	if(*string == '.')
	{
		++string;
		if(!IsNumber(string))
		{
			return false;
		}
	}
	// Now, *string must be 'e/E' or '\0', we first judge 'e/E'.
	if(*string == 'e' || *string == 'E')
	{
		++string;
		if(!IsNumber(string))
		{
			return false;
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
