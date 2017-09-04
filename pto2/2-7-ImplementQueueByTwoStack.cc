#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	void push(int node)
	{
		s1.push(node);
	}

	int pop()
	{
		int result = 0;
		if(s2.empty() == true)
		{
			while(s1.empty() == false)
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		if(s2.empty() == false)
		{
			result = s2.top();
			s2.pop();
		}
		return result;
	}

private:
	stack<int> s1;
	stack<int> s2;
};

void Test()
{
	Solution s;
	s.push(1);
	assert(s.pop() == 1); // Function test.
	assert(s.pop() == 0); // Negative test.
	s.push(2);
	s.push(3);
	assert(s.pop() == 2);
	s.push(4);
	assert(s.pop() == 3);
	assert(s.pop() == 4);
	assert(s.pop() == 0);
	printf("All case pass.\n");
}

int main()
{
	Test();
}
