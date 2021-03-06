/*
------------------------------Function Test Data------------------------------
nonempty list

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
empty list
*/

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
};

ListNode *GetMeetingNode(ListNode *head)
{
	// Negative data: empty list.
	if(!head || !(head->next))
	{
		return NULL;
	}

	// Two nodes: slow-node moves 1 step each time; fast-node moves 2 steps.
	ListNode *slow = head, *fast = head->next;
	while(slow && fast)
	{
		if(slow == fast)  // Two nodes meet.
		{
			return slow;
		}

		slow = slow->next;  // Move 1 step
		fast = fast->next ? fast->next->next : NULL;  // Move 2 steps if possible.
	}
	return NULL;
}

ListNode *EntryNodeOfLoop(ListNode *head)
{
	ListNode *meeting_node = GetMeetingNode(head);

	// Negative data: there is no loop at all.
	if(!meeting_node)
	{
		return NULL;
	}

	// Get loop's size:
	int loop_size = 1;
	ListNode *node = meeting_node->next;
	while(node != meeting_node)
	{
		node = node->next;
		++loop_size;
	}

	// Two nodes: first node move loop_size steps first and then move first and second
	// nodes at the same time until they meet, i.e, getting the entry node of loop.
	ListNode *first = head, *second = head;
	while(loop_size--)
	{
		first = first->next;
	}
	while(first != second)
	{
		first = first->next;
		second = second->next;
	}
	return first;
}

int main()
{

	return 0;
}
