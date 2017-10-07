eclipse ../ds/linked_list.cc
Node<T> *FindKthToTailNode(Node<T> *first, int k)

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
	ListNode *FindKthToTail(ListNode *first, int k)
	{
		if(first == nullptr || k <= 0) // Negative test.
		{
			return nullptr;
		}
		ListNode *slow = first, *fast = first;
		for(int cnt = 1; cnt <= k - 1; ++cnt)
		{
			fast = fast->next;
			if(fast == nullptr) // Negative test.
			{
				return nullptr;
			}
		}
		for(; fast->next != nullptr; fast = fast->next, slow = slow->next)
			;
		return slow;
	}
};

