eclipse ../ds/binary_node.cc
bool IsSubTree(BinaryNode<T> *large, BinaryNode<T> *small)

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
	bool HasSubtree(TreeNode *large, TreeNode *small)
	{
		if(large == nullptr || small == nullptr) // Negative test
		{
			return small == nullptr ? true : false;
		}
		bool is_sub_tree = false;
		large->val == small->val ? (is_sub_tree = HasSubtree(large->left, small->left)
			&& HasSubtree(large->right, small->right)) : bool();
		is_sub_tree == false ? is_sub_tree = HasSubtree(large->left, small) : bool();
		is_sub_tree == false ? is_sub_tree = HasSubtree(large->right, small) : bool();
		return is_sub_tree;
	}
};
