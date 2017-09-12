#include "queue.h"
#include <assert.h>
#include <queue>
using std::queue;

class ImplementStackByTwoQueue
{
public:
	// T = O(1) S = O(1)
	void Push(int data)
	{
		q2_.empty() == true ? q1_.push(data) : q2_.push(data);
	}
	// T = O(n) S = O(1)
	int Pop()
	{
		if(q1_.empty() == true && q2_.empty() == true) // Negative test.
		{
			return 0;
		}
		queue<int> &src = (q1_.empty() == false ? q1_ : q2_);
		queue<int> &dest = (q1_.empty() == false ? q2_ : q1_);
		while(src.size() > 1)
		{
			dest.push(src.front());
			src.pop();
		}
		int result = src.front();
		src.pop();
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
	TestImplementStackByTwoQueue();

#ifdef TEST_QUEUE
	Queue<int> object;
	printf("0: Exit\n1: Create\n2: Enqueue\n3: Dequeue\n");
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
			object.Enqueue(data);
			object.ShowContent();
			break;
			case 3:
			object.Dequeue();
			object.ShowContent();
		}
	}
#endif
}
/*
 1 5 1 2 3 4 5
 2 6 2 7
 3 3 3 3 3 3 3 3
 2 0
 3
 0
 Input: data_number data_content
 05 data: 1 2 3 4 5
 06 data: 1 2 3 4 5 6
 07 data: 1 2 3 4 5 6 7
 06 data: 2 3 4 5 6 7
 05 data: 3 4 5 6 7
 04 data: 4 5 6 7
 03 data: 5 6 7
 02 data: 6 7
 01 data: 7
 00 data:
 00 data:
 01 data: 0
 00 data:
 */
