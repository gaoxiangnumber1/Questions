/*
------------------------------Function Test Data------------------------------
nonempty binary tree

---------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
empty binary tree

*/

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int g_create_index = 0;
void Create(struct TreeNode* &root, vector<int> pre, vector<int> in, int first, int last)
{
	if(first > last)
	{
		return;
	}
	else if(first == last)
	{
		root = new TreeNode(pre[g_create_index++]);
	}
	else
	{
		int index = first;
		for(; index <= last && in[index] != pre[g_create_index]; ++index);
		root = new TreeNode(pre[g_create_index++]);
		Create(root->left, pre, in, first, index - 1);
		Create(root->right, pre, in, index + 1, last);
	}
}

struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in)
{
	struct TreeNode *root = NULL;  // Don't forget initialize the root!
	int size = pre.size();

	// negative data:
	if(!size)
	{
		return NULL;
	}

	Create(root, pre, in, 0, size - 1);
	return root;
}
