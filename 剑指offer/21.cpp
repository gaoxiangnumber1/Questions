/*
------------------------------Function Test Data------------------------------
normal stack

---------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
none

*/
#include<stack>
#include<iostream>
using namespace std;

class Solution
{
public:
	void push(int value)
	{
		data_stack.push(value);
		if(min_stack.empty())
		{
			min_stack.push(value);
		}
		else
		{
			min_stack.push(min_stack.top() < value ? min_stack.top() : value);
		}
	}

	void pop()
	{
		if(!data_stack.empty() && !min_stack.empty())
		{
			data_stack.pop();
			min_stack.pop();
		}
	}

	int top()
	{
		if(!data_stack.empty())
		{
			return data_stack.top();
		}
	}

	int min()
	{
		if(!min_stack.empty())
		{
			return min_stack.top();
		}
	}

private:
	stack<int> data_stack;
	stack<int> min_stack;
};

int main()
{
	Solution obj;

	return 0;
}
