/*
------------------------------Function Test Data------------------------------
nonempty string and has at least one char that appears only time

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
1. empty string
2. nonempty string but has no right char

*/

#include <iostream>
using namespace std;

int FirstNotRepeatingChar(string str)
{
	int length = str.size();
	// Negative data 1: empty string
	if(length <= 0)
	{
		return -1;
	}

	// Since char is 8-bit, there is at most 2^8 chars(256).
	// cnt[index][0]: the first index that this char appears
	// cnt[index][1]: the total appear times of this char
	int cnt[256][2];
	// Empty this array:
	for(int index = 0; index < 256; ++index)
	{
		cnt[index][0] = cnt[index][1] = 0;
	}

	// Traverse string to get each char's appear times:
	for(int index = 0; index < length; ++index)
	{
		int key = (int)str[index];  // Hash key
		if(cnt[key][1] == 0)  // The first appear time
		{
			cnt[key][0] = index;
			cnt[key][1] = 1;
		}
		else
		{
			++cnt[key][1];
		}
	}

	// Traverse string to get the first char that appears only one time
	for(int index = 0; index < length; ++index)
	{
		int key = (int)str[index];
		if(cnt[key][1] == 1)
		{
			return cnt[key][0];
		}
	}
	/*
	NOTE: Not traverse the cnt array! This will get the smallest char that appears only
	one time, not the first char!
	E.g.: "google"
	Right: l
	Wrong: e
	for(int index = 0; index < 256; ++index)
	{
		if(cnt[index][1] == 1)
		{
			return cnt[index][0];
		}
	}
	*/

	// Negative data 2: nonempty string but has no right char
	return -1;
}

int main()
{
	while(1)
	{
		cout << "Input: ";
		string str;
		cin >> str;
		cout << FirstNotRepeatingChar(str) << '\t' << str[FirstNotRepeatingChar(str)] << endl;
	}

	return 0;
}
