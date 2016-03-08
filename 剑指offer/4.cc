#include<iostream>
using namespace std;

void ReplaceSpace(char str[], int length)  // length is the total  size of str array
{
	if(str == NULL || length <= 0)  // check null pointer
	{
		return;
	}
	int old_length = 0, new_length = 0, space_number = 0;
	// traverse the str array to get old length and space number
	for(int index = 0; str[index] != 0; index++)
	{
		old_length++;
		if(str[index] == ' ')
		{
			space_number++;
		}
	}
	old_length++;  // don't forget the '\0'
	new_length = old_length + 2 * space_number;  // change from " " to "%20"
	if(new_length > length)
	{
		return;
	}
	int old_end = old_length - 1, new_end = new_length - 1;  // two indexes to manipulate array
	for(; old_end >= 0; old_end--)
	{
		if(str[old_end] != ' ')  // not space: copy character
		{
			str[new_end--] = str[old_end];
		}
		else  // space: change from " " to "%20"
		{
			str[new_end--] = '0';
			str[new_end--] = '2';
			str[new_end--] = '%';
		}
	}
}

int main()
{
	while(1)
	{
		cout << "Input:\n";
		char str[100];
		gets(str);  // read a line of string
		cout << str << endl;
		ReplaceSpace(str, 100);
		cout << str << endl;
	}

	return 0;
}

/*
Test data:
1. Have space:
at begin: " lifeishard"
at middle: "life is hard"
at end: "lifeishard "
combine: " life is hard "
many: "  life is   hard   "
2. None space:
"lifeishard"
3. Special:
null pointer: I don't know how to input null pointer
empty string: ""
one space: " "
many spaces: "     "
*/
