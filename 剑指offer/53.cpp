/*
------------------------------Function Test Data------------------------------
normal string

--------------------------------Edge Test Data--------------------------------
1. *str = 0 && *pattern = 0
2. *str != 0 && *pattern = 0
3. *str = 0 && *pattern != 0

------------------------------Negative Test Data------------------------------
str = NULL || pattern = NULL
*/

bool Match(char *str, char *pattern)
{
	// Edge data 1:
	if(*str == 0 && *pattern == 0)
	{
		return true;
	}

	// Edge data 2:
	if(*str != 0 && *pattern == 0)
	{
		return false;
	}

	if(*(pattern + 1) == '*')
	{
		if(*str == *pattern || (*str != 0 && *pattern == '.'))  // These two chars match.
		{
			return Match(str + 1, pattern + 2)  // Move to the next state.
			       || Match(str + 1, pattern)  // Stay on this state
			       || Match(str, pattern + 2);  // Ignore this char.
		}
		return Match(str, pattern + 2);  // Ignore this char.
	}

	// Up to now, *(pattern + 1) != '*'
	if(*str == *pattern || (*str != 0 && *pattern == '.'))  // These two chars match.
	{
		return Match(str + 1, pattern + 1);
	}

	// No match possibility
	return false;
}

bool match(char *str, char *pattern)
{
	// Negative data:
	if(!str || !pattern)
	{
		return false;
	}

	return Match(str, pattern);
}

int main()
{

	return 0;
}
