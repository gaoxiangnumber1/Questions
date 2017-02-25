/*
------------------------------Function Test Data------------------------------
normal

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
null pointer

*/

#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
};

void RecursiveConvert(TreeNode *root, TreeNode *&last)
{
	if(root->left)
	{
		RecursiveConvert(root->left, last);
	}

	root->left = last;
	if(last)
	{
		last->right = root;
	}
	last = root;

	if(root->right)
	{
		RecursiveConvert(root->right, last);
	}
}

TreeNode *Convert(TreeNode *pRootOfTree)
{
	// negative data:
	if(!pRootOfTree)
	{
		return NULL;
	}
	TreeNode *last = NULL;
	RecursiveConvert(pRootOfTree, last);

	TreeNode *first = last;
	while(first && first->left)
	{
		first = first->left;
	}
	return first;
}

int main()
{

	return 0;
}
