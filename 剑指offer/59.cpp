/*
------------------------------Function Test Data------------------------------
Normal binary tree

--------------------------------Edge Test Data--------------------------------
only 1 node

------------------------------Negative Test Data------------------------------
NULL pointer
*/

#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool Recursive(TreeNode *left_node, TreeNode *right_node)
{
	if(left_node == NULL && right_node == NULL)
	{
		return true;
	}
	if(left_node == NULL || right_node == NULL)
	{
		return false;
	}
	if(left_node->val != right_node->val)
	{
		return false;
	}
	return Recursive(left_node->left, right_node->right) &&
	       Recursive(left_node->right, right_node->left);
}

bool isSymmetrical(TreeNode* pRoot)
{
	if(pRoot == NULL)
	{
		return true;
	}
	return Recursive(pRoot->left, pRoot->right);
}

int main()
{

	return 0;
}
