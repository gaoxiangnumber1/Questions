#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr)
	{
	}
};

class Solution
{
public:
	// T(n) = O(n) S(n) = O(n)
	vector<int> ReversePrintLinkedListStack(ListNode *node)
	{
		stack<int> s;
		while(node != nullptr)
		{
			s.push(node->val);
			node = node->next;
		}
		vector<int> vec;
		while(s.empty() == false)
		{
			vec.push_back(s.top());
			s.pop();
		}
		return vec;
	}
	// T(n) = O(n) S(n) = O(n)
	vector<int> ReversePrintLinkedListRecursive(ListNode *node)
	{
		if(node == nullptr)
		{
			vec_.clear();
		}
		else
		{
			ReversePrintLinkedListRecursive(node->next);
			vec_.push_back(node->val);
		}
		return vec_;
	}
private:
	vector<int> vec_;
};

void Test()
{
	ListNode node0(0);
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	node0.next = &node1;
	node1.next = &node2;
	node2.next = &node3;
	vector<int> output1 = { 3 };
	Solution s;
	assert(
		memcmp(output1.data(), s.ReversePrintLinkedListStack(&node3).data(), output1.size()) == 0);
	assert(
		memcmp(output1.data(), s.ReversePrintLinkedListRecursive(&node3).data(), output1.size())
			== 0);
	vector<int> output2 = { 3, 2, 1, 0 };
	assert(
		memcmp(output2.data(), s.ReversePrintLinkedListStack(&node0).data(), output2.size()) == 0);
	assert(
		memcmp(output2.data(), s.ReversePrintLinkedListRecursive(&node0).data(), output2.size())
			== 0);
	assert(
		s.ReversePrintLinkedListStack(nullptr).size() == 0
			&& s.ReversePrintLinkedListRecursive(nullptr).size() == 0);
	printf("All case pass.\n");
}

int main()
{
	Test();
}
