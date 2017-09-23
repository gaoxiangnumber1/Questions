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
		node->left != nullptr ? InOrderConvertBSTToSortedDoubleLinkedList(node->left, last) : void();
		last != nullptr ? last->right = node : last;
		node->left = last;
		last = node;
		node->right != nullptr ? InOrderConvertBSTToSortedDoubleLinkedList(node->right, last) : void();
	}
	TreeNode *Convert(TreeNode *root)
	{
		if(root == nullptr) // Negative test
		{
			return nullptr;
		}
		TreeNode *last = nullptr;
		InOrderConvertBSTToSortedDoubleLinkedList(root, last);
		for(; last->left != nullptr; last = last->left)
			;
		return last;
	}
};
