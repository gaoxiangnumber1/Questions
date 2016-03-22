/*
------------------------------Function Test Data------------------------------
normal stack is ok

---------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
1. both stacks are empty when pop() execute

*/

class Solution
{
public:
    void push(int node)
    {
    	stack1.push(node);
    }

    int pop()
    {
    	if(stack2.empty())
		{
			// negative data:
			if(stack1.empty())
			{
				return 0;
			}

			while(!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}

		int result = stack2.top();
		stack2.pop();
		return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
