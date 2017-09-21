eclipse ../ds/binary_search_tree.cc
BinaryNode<T> *ConvertBSTToSortedDoubleLinkedList(BinaryNode<T> *root)

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
	void InOrderConvertBSTToSortedDoubleLinkedList(TreeNode *node, TreeNode *&last)
	{
		node->left_ != nullptr ? InOrderConvertBSTToSortedDoubleLinkedList(node->left_, last) : void();
		last != nullptr ? last->right_ = node : last;
		node->left_ = last;
		last = node;
		node->right_ != nullptr ? InOrderConvertBSTToSortedDoubleLinkedList(node->right_, last) : void();
	}
	TreeNode *Convert(TreeNode *root)
	{
		if(root == nullptr) // Negative test
		{
			return nullptr;
		}
		TreeNode *last = nullptr;
		InOrderConvertBSTToSortedDoubleLinkedList(root, last);
		for(; last->left_ != nullptr; last = last->left_)
			;
		return last;
	}
};
