/*
------------------------------Function Test Data------------------------------
normal

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
empty sequence

*/

#include<vector>
#include<iostream>
using namespace std;

struct RandomListNode
{
	int label;
	RandomListNode *next;
	RandomListNode *random;
	RandomListNode(int val) : label(val), next(NULL), random(NULL) {}
};

void CloneNext(RandomListNode *head)
{
	RandomListNode *node = head;
	while(node)
	{
		// copy node
		RandomListNode *copy_node = new RandomListNode(node->label);
		// save node's next node
		RandomListNode *next_node = node->next;
		// update links:
		node->next = copy_node;
		copy_node->next = next_node;
		// update node
		node = next_node;
	}
}

void CloneRandom(RandomListNode *head)
{
	RandomListNode *node = head;
	while(node)
	{
		if(node->random)
		{
			node->next->random = node->random->next;
		}
		// we move 2 node each time
		node = node->next->next;
	}
}

RandomListNode *CloneSplit(RandomListNode *head)
{
	RandomListNode *old_node = head, *new_node = head->next;
	while(old_node)  // while(new_node) is also ok.
	{
		old_node->next = new_node->next;
		old_node = old_node->next;
		new_node->next = (old_node ? old_node->next : NULL);
		new_node = new_node->next;
	}
	return head->next;
}

RandomListNode *Clone(RandomListNode *pHead)
{
	if(!pHead)
	{
		return NULL;
	}

	CloneNext(pHead);
	CloneRandom(pHead);
	return CloneSplit(pHead);
}

int main()
{

	return 0;
}
