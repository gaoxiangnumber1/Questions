/*
------------------------------Function Test Data------------------------------
length > 0

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
length <= 0

*/
#include <iostream>
#include <string>
using namespace std;
/**************************Question 1**************************/
// If permitted to create new string and modify new string:
string ReverseSentence1(string str)
{
	string result = str;
	int length = str.size();
	if(length <= 0)
	{
		return result;
	}

	// old_index used in str; new_index use in result
	int old_index = length - 1, new_index = 0;
	while(old_index >= 0)
	{
		if(str[old_index] == ' ')
		{
			result[new_index++] = str[old_index--];
		}
		else
		{
			// Find the letter scope: [first, last]
			int first = old_index, last = old_index;
			for(; first >= 0 && str[first] != ' '; --first);
			// Now: 1. first = -1; 2. first >= 0, but str[first] = ' '.
			// So, the letter scope is [first + 1, last] and old_index should be changed to first.
			old_index = first;
			for(int index = first + 1; index <= last; ++index)
			{
				result[new_index++] = str[index];
			}
		}
	}
	return result;
}

// If not permitted to create new string and must modify input string directly:
void Reverse(string &str, int first, int last)
{
	int length = last - first + 1;
	if(length <= 1)
	{
		return;
	}

	int finish = first + (length >> 1);
	for(int index = first; index < finish; ++index)
	{
		swap(str[index], str[first + last - index]);
	}
}

string ReverseSentence2(string str)
{
	int length = str.size();
	if(length <= 0)
	{
		return str;
	}

	// First, we reverse this string:
	Reverse(str, 0, length - 1);

	// Second, we reverse every letter.
	for(int index = 0; index < length; ++index)
	{
		if(str[index] != ' ')
		{
			int first = index, last = index;  // [first, last] is the scope of letter.
			for(; last < length && str[last] != ' '; ++last);
			// Now: 1. last = length; 2. last < length && [last] = ' '.
			// So, last character is at [last - 1]
			--last;
			index = last;  // Update index
			Reverse(str, first, last);
		}
	}
	return str;
}

/**************************Question 2**************************/
string LeftRotateString(string str, int n)
{
	int length = str.size();
	if(length > 0 && (0 < n && n < length))
	{
		Reverse(str, 0, n - 1);
		Reverse(str, n, length - 1);
		Reverse(str, 0, length - 1);
	}
	return str;
}

int main()
{
	while(1)
	{
		cout << "Input: ";
		string str;
		int n;
		cin >> str;
		cin >> n;
		cout << "###" << Fun(str, n) << "###\n";
	}

	return 0;
}
