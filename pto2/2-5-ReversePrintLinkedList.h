../ds/linked_list.cc
vector<int> ReversePrintLinkedListStack
vector<int> ReversePrintLinkedListRecursive

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
