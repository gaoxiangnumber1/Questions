eclipse ../ds/array.cc
int FindMoreThanHalfNumberInArray(const vector<int> &arr)

class Solution
{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{

	}
};
int MoreThanHalfNum_Solution2(vector<int> numbers)  // not test!!!
{
	int length = numbers.size();
	// negative data:
	if(length <= 0)
	{
		return 0;
	}

	int result = numbers[0];  // initial value
	int cnt = 1;  // initial time
	for(int index = 1; index < length; ++index)
	{
		if(cnt == 0)  // change result
		{
			result = numbers[index];
			cnt = 1;
		}
		else if(result == numbers[index])
		{
			++cnt;
		}
		else  // cnt != 0 && result != numbers[index]
		{
			--cnt;
		}
	}

	// check whether result appears more than half times or not,
	int time = 0;
	for(int index = 0; index < length; ++index)
	{
		if(numbers[index] == result)
		{
			++time;
		}
	}
	if(time > (length >> 1))  // yes
	{
		return result;
	}
	return 0;  // no
}
