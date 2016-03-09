#include<iostream>
using namespace std;

void ReplaceSpace(char str[], int length)  // length is the total  size of str array
{
	// size is the number of str's characters; space is the number of str's spaces
	int size = 0, space = 0;
	for(; str[size]; ++size)  // exit when str[size] == '\0', i.e., str[size] == 0
	{
		if(str[size] == ' ')
		{
			++space;
		}
	}
	// old_index/new_index points to the end of old/new string
	// DON'T forget the last null character, it marks the end of string,
	// otherwise old_index = size - 1.
	int old_index = size, new_index = size + space * 2;
	// when the two indexes are equal, there is no need to move character.
	while(old_index != new_index)
	{
		if(str[old_index] == ' ')  // ' ' -> "%20"
		{
			str[new_index--] = '0';
			str[new_index--] = '2';
			str[new_index--] = '%';
		}
		else  // copy
		{
			str[new_index--] = str[old_index];
		}
		--old_index;
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
