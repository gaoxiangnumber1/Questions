/*
------------------------------Function Test Data------------------------------
nonempty linked list

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
empty linked list

*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
	// Negative data: empty linked list
	if(!pHead1 || !pHead2)
	{
		return NULL;
	}

	// First, we get both lists' length:
	int length1 = 0, length2 = 0;
	ListNode *node1 = pHead1, *node2 = pHead2;
	while(node1)
	{
		++length1;
		node1 = node1->next;
	}
	while(node2)
	{
		++length2;
		node2 = node2->next;
	}

	// Second, we justify which list is longer:
	// node1 moves diff steps first and then node2 moves.
	int diff = 0;
	if(length1 >= length2)
	{
		diff = length1 - length2;
		node1 = pHead1;
		node2 = pHead2;
	}
	else
	{
		diff = length2 - length1;
		node1 = pHead2;
		node2 = pHead1;
	}

	// Third, we move node1 and node2 to find the first common node
	while(diff--)
	{
		node1 = node1->next;
	}
	// Now, node1 is at the same position as node2
	while(node1)
	{
		if(node1 == node2)
		{
			return node1;
		}
		node1 = node1->next;
		node2 = node2->next;
	}
	// Error: can't find common node
	return NULL;
}

int main()
{

	return 0;
}
