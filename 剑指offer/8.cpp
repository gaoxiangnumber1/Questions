/*
------------------------------Function Test Data------------------------------
nonempty array

---------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
empty array

*/
#include<vector>
using namespace std;

int MinTraverse(vector<int> array, int first, int last)  // return min element in [first, last]
{
	int result = array[first];
	for(int index = first + 1; index <= last; ++index)
	{
		if(result > array[index])
		{
			result = array[index];
		}
	}

	return result;
}

int Min(vector<int> array)
{
	int length = array.size();

	//negative data:
	if(length <= 0)
	{
		return 0;
	}

	int first = 0, last = length - 1;  // the search scope is [first, last].
	int result_index = 0;

	while(array[first] >= array[last])  // if [first] < [last]: this array does't rotate, so we return [0].
	{
		if(last - first == 1)  // [last] is the min element
		{
			result_index = last;
			break;
		}

		int middle = first + ((last - first) >> 1);
		// if we can't know [middle] is in the 1st or 2nd part,
		// we have to traverse the array to find the min element. O(n)
		if(array[middle] == array[first] && array[middle] == array[last])
		{
			return MinTraverse(array, first, last);
		}

		if(array[middle] >= array[first])  // [middle] is in the 1st part
		{
			first = middle;
		}
		else if(array[middle] <= array[last])  // [middle] is in the 2nd part
		{
			last = middle;
		}
	}

	return array[result_index];
}

