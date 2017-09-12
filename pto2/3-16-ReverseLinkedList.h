../ds/linked_list.cc
Node<T> *ReverseLinkedList

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL)
	{
	}
};

class Solution
{
public:
	ListNode *ReverseList(ListNode *first)
	{
		ListNode *before = nullptr, *node = first, *after = nullptr;
		while(node != nullptr) // Including Negative and Edge test.
		{
			after = node->next_;
			node->next_ = before;
			before = node;
			node = after;
		}
		return before;
	}
};
