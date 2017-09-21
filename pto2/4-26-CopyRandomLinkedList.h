eclipse ../ds/linked_list.cc
RandomListNode *CopyRandomLinkedList(RandomListNode *first)

struct RandomListNode
{
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
	label(x), next(NULL), random(NULL)
	{
	}
};
class Solution
{
public:
	RandomListNode *Clone(RandomListNode *first)
	{
		if(first == nullptr) // Negative test
		{
			return nullptr;
		}
		for(RandomListNode *node = first; node != nullptr;)
		{
			RandomListNode *copy_node = new RandomListNode(node->label);
			copy_node->next = node->next;
			copy_node->random = node->random;
			node->next = copy_node;
			node = copy_node->next;
		}
		for(RandomListNode *copy_node = first->next; copy_node != nullptr;)
		{
			copy_node->random = (copy_node->random != nullptr ? copy_node->random->next : nullptr);
			copy_node = (copy_node->next != nullptr ? copy_node->next->next : nullptr);
		}
		RandomListNode *copy_first = first->next;
		for(RandomListNode *node = first, *copy_node = first->next; node != nullptr;)
		{
			node->next = copy_node->next;
			node = node->next;
			copy_node->next = (node != nullptr ? node->next : nullptr);
			copy_node = copy_node->next;
		}
		return copy_first;
	}
};
