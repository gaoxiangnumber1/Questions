/*
------------------------------Function Test Data------------------------------
Normal binary tree

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
NULL pointer
*/

#include <iostream>
using namespace std;

struct TreeLinkNode
{
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

TreeLinkNode *GetNext(TreeLinkNode *pNode)
{
	// Negative data:
	if(pNode == NULL)
	{
		return NULL;
	}

	if(pNode->right != NULL)  // If has right subtree
	{
		pNode = pNode->right;
		while(pNode->left != NULL)
		{
			pNode = pNode->left;
		}
		return pNode;
	}

	if(pNode->next != NULL)  // If has parent node
	{
		TreeLinkNode *parent = pNode->next;
		while(parent != NULL && parent->right == pNode)
		{
			pNode = parent;
			parent = parent->next;
		}
		return parent;
	}
	return NULL;
}

int main()
{

	return 0;
}
