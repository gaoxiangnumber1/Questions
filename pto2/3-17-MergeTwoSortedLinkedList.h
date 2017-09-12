../ds/linked_list.cc
Node<T> *MergeTwoSortedLinkedList

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
	ListNode *Merge(ListNode *first, ListNode *second)
	{
		if(first == nullptr || second == nullptr) // Negative test.
		{
			return (first == nullptr ? second : first);
		}

		ListNode *head = nullptr;
		if(first->val <= second->val)
		{
			head = first;
			first = first->next;
		}
		else
		{
			head = second;
			second = second->next;
		}
		ListNode *node = head;
		while(first != nullptr && second != nullptr)
		{
			if(first->val <= second->val)
			{
				node->next = first;
				node = first;
				first = first->next;
			}
			else
			{
				node->next = second;
				node = second;
				second = second->next;
			}
		}
		node->next = (first == nullptr ? second : first);
		return head;
	}
};
