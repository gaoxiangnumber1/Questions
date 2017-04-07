// Function Test:	"gao" "g a o" "g a o x " " g a o x "
// Edge Test:			" " "   "
// Negative Test:	nullptr

#include <stdio.h>
#include <string.h>

// Assume s is the length of str.
// TC = O(s)
// SC = O(1)
void ReplaceSpace(char *str, int length)
{
	// Negative data:
	if(str == nullptr)
	{
		return;
	}
	// Traverse string and get the number of space.
	int space_count = 0;
	for(int index = 0; index < length; ++index)
	{
		if(str[index] == ' ')
		{
			++space_count;
		}
	}
	// Copy/Fill chars from end to begin.
	int src_index = length - 1;
	int dst_index = src_index + 2 * space_count; // one char ' ' -> three chars "%20"
	str[dst_index + 1] = '\0'; // First add terminating null byte.
	// If src_index == dst_index, then there is no space left, and we don't need copy.
	while(src_index != dst_index && src_index >= 0)
	{
		if(str[src_index] != ' ')
		{
			str[dst_index--] = str[src_index--];
		}
		else
		{
			str[dst_index--] = '0';
			str[dst_index--] = '2';
			str[dst_index--] = '%';
			src_index--;
		}
	}
}

const int kBufferSize = 1024;
int main()
{
	char buffer[kBufferSize];
	while(fgets(buffer, sizeof buffer, stdin) != nullptr)
	{
		ReplaceSpace(buffer, strlen(buffer) - 1);
		printf("%s\n", buffer);
	}
}
