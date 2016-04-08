/*
------------------------------Function Test Data------------------------------
valid pointer

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
null pointer

*/

#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
};

/*Question 1:*/
int TreeDepth(TreeNode *pRoot)
{
	if(pRoot)
	{
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		return left > right ? left + 1 : right + 1;
	}
	return 0;
}

/*Question 2:*/
bool IsBalanced_Solution(TreeNode *pRoot)
{
	if(!pRoot)
	{
		return true;
	}

	int left = TreeDepth(pRoot->left);
	int right = TreeDepth(pRoot->right);
	int diff = left - right;
	if(-1 <= diff && diff <= 1)
	{
		return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
	}
	return false;
}

bool Post(TreeNode *pRoot, int &depth)
{
	if(!pRoot)
	{
		depth = 0;
		return true;
	}

	int left = 0, right = 0;
	if(Post(pRoot->left, left) && Post(pRoot->right, right))
	{
		int diff = left - right;
		if(-1 <= diff && diff <= 1)
		{
			depth = left > right ? left + 1 : right + 1;
			return true;
		}
	}
	return false;
}

bool IsBalanced_Solution(TreeNode *pRoot)
{
	int depth = 0;
	return Post(pRoot, depth);
}

int main()
{
	for(; 0;)
	{

	}

	return 0;
}
