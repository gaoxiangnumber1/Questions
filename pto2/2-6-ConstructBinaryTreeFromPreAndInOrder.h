eclipse ../ds/binary_node.cc
void ConstructBinaryTreeFromPreAndInOrder(BinaryNode<T> *&root, const vector<T> &pre,
	int &pre_index, const vector<T> &in, int in_first, int in_last) // [in_first, in_last)
void ConstructBinaryTreeFromPostAndInOrder(BinaryNode<T> *&root,
	const vector<T> &post, int &post_index, const vector<T> &in, int in_first,
	int in_last) // [in_last, in_last)

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL)
	{
	}
};
class Solution
{
public:
	void ConstructBinaryTreeFromPreAndInOrder(TreeNode *&root, const vector<int> &pre,
		int &pre_index, const vector<int> &in, int in_first, int in_last)
	{
		if(in_first < in_last)
		{
			int in_index = in_first;
			for(; in_index < in_last && pre[pre_index] != in[in_index]; ++in_index)
				;
			root = new TreeNode(pre[pre_index++]);
			ConstructBinaryTreeFromPreAndInOrder(root->left, pre, pre_index, in, in_first,
				in_index);
			ConstructBinaryTreeFromPreAndInOrder(root->right, pre, pre_index, in,
				in_index + 1, in_last);
		}
	}
	TreeNode* reConstructBinaryTree(const vector<int> &pre, const vector<int> &in)
	{
		TreeNode *root = nullptr;
		int data_number = static_cast<int>(pre.size());
		int pre_index = 0;
		ConstructBinaryTreeFromPreAndInOrder(root, pre, pre_index, in, 0, data_number);
		return root;
	}
};
