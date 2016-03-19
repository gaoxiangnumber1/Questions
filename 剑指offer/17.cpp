/*
------------------------------Function Test Data------------------------------
normal linked list is ok

---------------------------------Edge Test Data--------------------------------
one of the linked list head is a null pointer

------------------------------Negative Test Data------------------------------
both of the linked lists' head are null pointers

*/

#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* LoopMerge(ListNode* pHead1, ListNode* pHead2)
{
	// negative data and edge data:
	if(pHead1 == NULL)
	{
		return pHead2;
	}
	if(pHead2 == NULL)
	{
		return pHead1;
	}

	// normal data:
	// select the smaller head as the new head
	ListNode *node1 = pHead1, *node2 = pHead2, *new_list_node;
	if(node1->val <= node2->val)
	{
		new_list_node = node1;
		node1 = node1->next;
	}
	else
	{
		new_list_node = node2;
		node2 = node2->next;
	}

	while(node1 && node2)  // when both linked list are not empty
	{
		if(node1->val <= node2->val)
		{
			new_list_node->next = node1;
			new_list_node = node1;
			node1 = node1->next;
		}
		else
		{
			new_list_node->next = node2;
			new_list_node = node2;
			node2 = node2->next;
		}
	}

	// now one of the linked list is empty,
	// we only need join the nonempty list after the new list
	new_list_node->next = node1 ? node1 : node2;
	return (pHead1->val <= pHead2->val) ? pHead1 : pHead2;
}

ListNode* RecursiveMerge(ListNode* pHead1, ListNode* pHead2)
{
	// negative data and edge data:
	if(pHead1 == NULL)
	{
		return pHead2;
	}
	if(pHead2 == NULL)
	{
		return pHead1;
	}

	// normal data:
	// select the smaller head as the new head
	ListNode *node1 = pHead1, *node2 = pHead2, *new_list_node;
	if(pHead1->val <= pHead2->val)
	{
		new_list_node = pHead1;
		new_list_node->next = RecursiveMerge(pHead1->next, pHead2);
	}
	else
	{
		new_list_node = pHead2;
		new_list_node->next = RecursiveMerge(pHead1, pHead2->next);
	}
	return new_list_node;
}


int main()
{
	while(1)
	{

	}

	return 0;
}
