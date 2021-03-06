eclipse ../ds/binary_node.cc
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
		swap(root->left, root->right);
		Mirror(root->left);
		Mirror(root->right);
	}
};
