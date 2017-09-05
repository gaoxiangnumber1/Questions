#include <bits/stdc++.h>
using namespace std;

class ImplementQueueByTwoStack
{
public:
	// T(n) = O(1) S(n) = O(1)
	void push(int node)
	{
		s1.push(node);
	}
	// T(n) = O(1) or O(n) S(n) = O(1)
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

void TestImplementQueueByTwoStack()
{
	printf("-----TestImplementQueueByTwoStack-----\n");
	ImplementQueueByTwoStack q;
	q.push(1);
	assert(q.pop() == 1); // Function test.
	assert(q.pop() == 0); // Negative test.
	q.push(2);
	q.push(3);
	assert(q.pop() == 2);
	q.push(4);
	assert(q.pop() == 3);
	assert(q.pop() == 4);
	assert(q.pop() == 0);
	printf("All case pass.\n");
}

class ImplementStackByTwoQueue
{
public:
	// T = O(1) S = O(1)
	void Push(int val)
	{
		q2_.empty() == true ? q1_.push(val) : q2_.push(val);
	}
	// T = O(n) S = O(1)
	int Pop()
	{
		int result = 0;
		if(q1_.empty() == false || q2_.empty() == false)
		{
			queue<int> &src = (q1_.empty() == false ? q1_ : q2_);
			queue<int> &dest = (q1_.empty() == false ? q2_ : q1_);
			while(src.size() > 1)
			{
				dest.push(src.front());
				src.pop();
			}
			result = src.front();
			src.pop();
			assert(src.empty() == true);
		}
		return result;
	}

private:
	queue<int> q1_;
	queue<int> q2_;
};
void TestImplementStackByTwoQueue()
{
	printf("-----TestImplementStackByTwoQueue-----\n");
	ImplementStackByTwoQueue s;
	assert(s.Pop() == 0);
	s.Push(1);
	s.Push(2);
	assert(s.Pop() == 2);
	s.Push(3);
	assert(s.Pop() == 3);
	assert(s.Pop() == 1);
	s.Push(4);
	s.Push(5);
	assert(s.Pop() == 5);
	assert(s.Pop() == 4);
	assert(s.Pop() == 0);
	printf("All case pass.\n");
}

int main()
{
	TestImplementQueueByTwoStack();
	TestImplementStackByTwoQueue();
}
