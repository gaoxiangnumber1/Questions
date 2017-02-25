/*
------------------------------Function Test Data------------------------------
Normal linked list

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
NULL pointer
*/

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplication(ListNode *pHead)
{
	// Negative data:
	if(pHead == NULL)
	{
		return NULL;
	}

	ListNode *pre_node = NULL, *node = pHead;
	while(node != NULL)
	{
		ListNode *next_node = node->next;
		if(next_node != NULL && node->val == next_node->val)  // Need delete.
		{
			int value = node->val;
			ListNode *delete_node = node;  // Target delete node.
			// Delete duplication nodes:
			while(delete_node != NULL && delete_node->val == value)
			{
				next_node = delete_node->next;
				delete delete_node;
				delete_node = NULL;
				delete_node = next_node;
			}

			if(pre_node == NULL)
			{
				pHead = next_node;
			}
			else
			{
				pre_node->next = next_node;
			}
			node = next_node;
		}
		else
		{
			pre_node = node;
			node = node->next;
		}
	}
	return pHead;
}

int main()
{

	return 0;
}
