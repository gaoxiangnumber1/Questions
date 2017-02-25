/*
------------------------------Function Test Data------------------------------
normal string stream

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
none
*/

class Solution
{
private:
	int order;  // Indicate current character's position
	// position[char]
	// = -1: "char" has never appeared;
	// = -2: "char" appears at least 2 times;
	// >= 0: "char" appears only once, and this value is the index of "char" in string stream
	int position[256];

public:
	const int kMax = 0x7fffffff;

	Solution() : order(0)
	{
		// Initialize all position[index] to -1:
		for(int index = 0; index < 256; ++index)
		{
			position[index] = -1;
		}
	}

	void Insert(char ch)
	{
		if(position[ch] == -1)  // First appear
		{
			position[ch] = order;
		}
		else if(position[ch] >= 0)  // Has appeared
		{
			position[ch] = -2;
		}
		++order;
	}

	char FirstAppearingOnce()
	{
		char result = '#';  // If there is no such character that appears once, return '#'.
		int min_index = kMax;

		for(int ch = 0; ch < 256; ++ch)
		{
			if(0 <= position[ch] && position[ch] < min_index)
			{
				result = (char)ch;
				min_index = position[ch];
			}
		}
		return result;
	}
};

int main()
{

	return 0;
}
