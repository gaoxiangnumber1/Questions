/*
------------------------------Function Test Data------------------------------
normal binary tree
---------------------------------Edge Test Data--------------------------------
none
------------------------------Negative Test Data------------------------------
null pointer
*/

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void Mirror(TreeNode *pRoot)
{
	// negative data
	if(!pRoot)
	{
		return;
	}

	// swap this TreeNode's subtrees
	TreeNode *temp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = temp;
	// recursive swap pRoot's children
	Mirror(pRoot->left);
	Mirror(pRoot->right);
}
