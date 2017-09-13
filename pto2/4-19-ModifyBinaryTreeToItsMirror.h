../ds/binary_tree.cc
void ModifyBinaryTreeToItsMirror(BinaryNode<T> *root)

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL)
	{
	}
};
class Solution
{
public:
	void Mirror(TreeNode *root)
	{
		if(root == nullptr) // Negative test.
		{
			return;
		}
		swap(root->left_, root->right_);
		Mirror(root->left_);
		Mirror(root->right_);
	}
};
