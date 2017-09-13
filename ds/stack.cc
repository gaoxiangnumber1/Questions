#include "../common_system_header.h"

class ImplementQueueByTwoStack
{
public:
	// T(n) = O(1) S(n) = O(1)
	void Push(int data)
	{
		s1_.push(data);
	}
	// T(n) = O(1) or O(n) S(n) = O(1)
	int Pop()
	{
		if(s1_.empty() == true && s2_.empty() == true) // Negative test.
		{
			return 0;
		}

		if(s2_.empty() == true)
		{
			while(s1_.empty() == false)
			{
				s2_.push(s1_.top());
				s1_.pop();
			}
		}
		int result = s2_.top();
		s2_.pop();
		return result;
	}

private:
	stack<int> s1_;
	stack<int> s2_;
};
void TestImplementQueueByTwoStack()
{
	printf("-----TestImplementQueueByTwoStack-----\n");
	ImplementQueueByTwoStack q;
	q.Push(1);
	assert(q.Pop() == 1); // Function test.
	assert(q.Pop() == 0); // Negative test.
	q.Push(2);
	q.Push(3);
	assert(q.Pop() == 2);
	q.Push(4);
	assert(q.Pop() == 3);
	assert(q.Pop() == 4);
	assert(q.Pop() == 0);
	printf("All case pass.\n");
}

int main()
{
	TestImplementQueueByTwoStack();

#ifdef TEST_STACK
	Stack<int> object;
	printf("0: Exit\n1: Create\n2: Push\n3: Pop\n4: Top\n");
	int operation, data;
	while(scanf("%d", &operation) == 1)
	{
		switch(operation)
		{
			case 0:
			return 0;
			case 1:
			object.Create();
			object.ShowContent();
			break;
			case 2:
			scanf("%d", &data);
			object.Push(data);
			object.ShowContent();
			break;
			case 3:
			object.Pop();
			object.ShowContent();
			break;
			case 4:
			printf("Top = %d\n", object.Top());
			object.ShowContent();
		}
	}
#endif
}
/*
 1 5 1 2 3 4 5
 2 6 2 7
 3 3 3 3 3 3 3 3 3 3
 4
 2 0
 4
 0
 Input: data_number data_content
 05 data: 5 4 3 2 1
 06 data: 6 5 4 3 2 1
 07 data: 7 6 5 4 3 2 1
 06 data: 6 5 4 3 2 1
 05 data: 5 4 3 2 1
 04 data: 4 3 2 1
 03 data: 3 2 1
 02 data: 2 1
 01 data: 1
 00 data:
 00 data:
 00 data:
 00 data:
 Top = 0
 00 data:
 01 data: 0
 Top = 0
 01 data: 0
 */
