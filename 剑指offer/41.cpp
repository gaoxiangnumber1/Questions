/*
------------------------------Function Test Data------------------------------
length > 0

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
length <= 0

*/

#include <iostream>
#include <vector>
using namespace std;

/* Question 1 */
vector<int> FindNumbersWithSum(vector<int> array, int sum)
{
	vector<int> result;
	int length = array.size();
	if(length <= 0)
	{
		return result;
	}

	int first = 0, second = length - 1;
	while(first < second)
	{
		int temp = array[first] + array[second];
		if(temp < sum)
		{
			++first;
		}
		else if(temp == sum)
		{
			result.push_back(array[first]);
			result.push_back(array[second]);
			return result;
		}
		else
		{
			--second;
		}
	}
	return result;
}

/* Question 2 */
vector<vector<int> > FindContinuousSequence(int sum)
{
	vector<vector<int> > result;
	if(sum < 3)
	{
		return result;
	}

	int first = 1, last = 2, finish = sum >> 1, current = 3;
	while(first <= finish)
	{
		if(current < sum)
		{
			++last;
			current += last;
		}
		else if(current == sum)
		{
			vector<int> temp;
			for(int num = first; num <= last; ++num)
			{
				temp.push_back(num);
			}
			result.push_back(temp);
			++last;
			current += last;
		}
		else
		{
			current -= first;
			++first;
		}
	}
	return result;
}

int main()
{
	for(int sum = 3; sum <= 100; ++sum)
	{
		vector<vector<int>> result = Fun2(sum);
		int length1 = result.size();
		if(length1)
		{
			cout << "##########" << sum << "##########\n";
		}
		for(int index1 = 0; index1 < length1; ++index1)
		{
			int length2 = result[index1].size();
			for(int index2 = 0; index2 < length2; ++index2)
			{
				cout << result[index1][index2] << ' ';
			}
			cout << endl;
		}
	}

	return 0;
}
