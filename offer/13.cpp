/*
Function Test Data:
node that is in the linked list and is not the first or last

Edge Test Data:
1.	first node
2.	last node

Negative Test Data:
1.	null pointer
2.	node that is not in the linked list.(we assume this condition never happens)
*/

struct Node
{
	int value;
	Node *next;
};

// Assume node must be in the linked list if it is not a null pointer
void Delete(Node **head, Node *node)
{
	// negative data: 1. null pointer
	if(head == NULL || node == NULL)
	{
		return;
	}

	// edge data: 1. first node
	if(*head == node)
	{
		// make head point to the next node,
		// may be NULL if this linked list only have one node
		*head = node->next;
		// free node's memory and make it a null pointer to avoid dangling pointer
		delete node;
		node = NULL;
	}
	// edge data: 2. last node
	else if(node->next == NULL)
	{
		// we have to begin from head and transfer the list to find the node just before "node"
		Node *before = *head;  // aim: before->next = node;
		while(before->next != node)
		{
			before = before->next;
		}
		// delete node
		before->next = NULL;
		delete node;
		node = NULL;
	}
	// function data:
	else
	{
		Node *after = node->next;
		// we copy after's value and next node to "node" and delete after as if we delete "node"
		node->value = after->value;
		node->next = after->next;
		delete after;
		after = NULL;
	}
}
