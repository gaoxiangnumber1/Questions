/*
------------------------------Function Test Data------------------------------
normal binary tree is ok

---------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
both of the binary trees' root are null pointers

*/

#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool DoesTree1HaveTree2(TreeNode *pRoot1, TreeNode *pRoot2)
{
	if(!pRoot2)
	{
		return true;
	}
	if(!pRoot1)
	{
		return false;
	}
	if(pRoot1->val != pRoot2->val)
	{
		return false;
	}
	return	DoesTree1HaveTree2(pRoot1->left, pRoot2->left) &&
	        DoesTree1HaveTree2(pRoot1->right, pRoot2->right);
}

bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
{
	bool result = false;
	if(pRoot1 && pRoot2)
	{
		// first, we find the node that is equal to the other tree's root val
		if(pRoot1->val == pRoot2->val)
		{
			// second, compare the two trees:
			result = DoesTree1HaveTree2(pRoot1, pRoot2);
		}
		if(!result)
		{
			result = HasSubtree(pRoot1->left, pRoot2);
		}
		if(!result)
		{
			result = HasSubtree(pRoot1->right, pRoot2);
		}
	}
	return result;
}

int main()
{
	while(1)
	{

	}

	return 0;
}
