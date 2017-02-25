/*
------------------------------Function Test Data------------------------------
normal stack

---------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
empty vector

*/

#include<stack>
#include<vector>
#include<iostream>
using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
	int length = pushV.size();

	//negative data:
	if(length <= 0 || length != popV.size())
	{
		return false;
	}

	int push_index = 0, pop_index = 0;
	stack<int> data;
	for(;;)
	{
		while(data.empty() || data.top() != popV[pop_index])
		{
			if(push_index == length)
			{
				return false;
			}
			data.push(pushV[push_index++]);
		}

		// now, data is not empty and data.top() = popV[pop_index]
		data.pop();
		++pop_index;

		if(data.empty() && pop_index == length)
		{
			return true;
		}
	}
}

int main()
{
	vector<int> pushV = {1, 2, 3, 4, 5}, popV = {4, 3, 5, 1, 2};
	cout << (IsPopOrder(pushV, popV) ? "YES\n" : "NO\n");


	return 0;
}
