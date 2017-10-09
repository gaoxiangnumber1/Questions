#include "binary_node.h"
template<typename T>
class BinarySearchTree
{
public:
	BinarySearchTree() :
		root_(nullptr)
	{
	}
	~BinarySearchTree();

	BinaryNode<T> *root() const;
	BinaryNode<T> *&root_ref();
	void set_root(BinaryNode<T> *new_root);

	void CreateFromArray(const vector<T> &arr);
	// Return nullptr if fails, otherwise return the new node's pointer.
	BinaryNode<T> *Insert(const T &data);
	// Return nullptr if fails, otherwise return the match node's pointer.
	BinaryNode<T> *Search(const T &data, BinaryNode<T>* &parent_node);
	// Return nullptr if fails, otherwise return the node that replaces deleted node.
	BinaryNode<T> *Delete(const T &data);

private:
	BinaryNode<T> *root_;
};
template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	::Delete(root_);
}
template<typename T>
BinaryNode<T> *BinarySearchTree<T>::root() const
{
	return root_;
}
template<typename T>
BinaryNode<T> *&BinarySearchTree<T>::root_ref()
{
	return root_;
}
template<typename T>
void BinarySearchTree<T>::set_root(BinaryNode<T> *new_root)
{
	root_ = new_root;
}
template<typename T>
void BinarySearchTree<T>::CreateFromArray(const vector<T> &arr)
{
	for(int index = 0; index < static_cast<int>(arr.size()); ++index)
	{
		Insert(arr[index]);
	}
}
template<typename T>
BinaryNode<T>* BinarySearchTree<T>::Insert(const T &data)
{
	BinaryNode<T> *parent_node = nullptr;
	if(Search(data, parent_node) != nullptr)
	{
		return nullptr;
	}
	BinaryNode<T> *new_node = new BinaryNode<T>(data);
	if(parent_node == nullptr) // BST is empty.
	{
		root_ = new_node;
	}
	else
	{
		if(data < parent_node->data_)
		{
			parent_node->left_ = new_node;
		}
		else
		{
			parent_node->right_ = new_node;
		}
	}
	return new_node;
}
template<typename T>
BinaryNode<T>* BinarySearchTree<T>::Search(const T &data,
	BinaryNode<T>* &parent_node)
{
	BinaryNode<T> *search_node = root_;
	while(search_node != nullptr)
	{
		if(data == search_node->data_)
		{
			return search_node;
		}
		parent_node = search_node; // Must after `if(==)` condition.
		if(data < search_node->data_)
		{
			search_node = search_node->left_;
		}
		else
		{
			search_node = search_node->right_;
		}
	}
	return nullptr;
}
template<typename T>
BinaryNode<T>* BinarySearchTree<T>::Delete(const T &data)
{
	BinaryNode<T> *parent_node = nullptr;
	BinaryNode<T> *delete_node = Search(data, parent_node);
	if(delete_node == nullptr) // Must FIRST check data isn't in tree.
	{
		return nullptr;
	}
	// Assume delete_node has 2 subnodes, change it to left_max_node,
	// then it has 1 or 0 subnodes.
	if(delete_node->left_ != nullptr && delete_node->right_ != nullptr)
	{
		BinaryNode<T> *left_max_parent = delete_node, *left_max = delete_node->left_;
		while(left_max->right_ != nullptr)
		{
			left_max_parent = left_max;
			left_max = left_max->right_;
		}
		delete_node->data_ = left_max->data_;
		parent_node = left_max_parent;
		delete_node = left_max;
	}
	BinaryNode<T> *child_node = (
		delete_node->left_ ? delete_node->left_ : delete_node->right_);
	if(parent_node == nullptr)
	{
		root_ = child_node;
	}
	else
	{
		if(delete_node == parent_node->left_)
		{
			parent_node->left_ = child_node;
		}
		else
		{
			parent_node->right_ = child_node;
		}
	}
	delete delete_node;
	return child_node;
}
////////////////////////////////////////////////////////////////////////////////
bool IsPostOrderTraverseOfBSTRecursive(const vector<int> &seq, int first, int last) // []
{
	if(last - first <= 1) // Edge test: 1 or 2 elements, end recursive.
	{
		return true;
	}
	if((seq[first] - seq[last]) * (seq[last - 1] - seq[last]) > 0) // Only has left or right subtree.
	{
		int index = first + 1;
		for(;
			index < last - 1
				&& (seq[first] - seq[last]) * (seq[index] - seq[last]) > 0; ++index)
			;
		return
			index < last - 1 ? false : IsPostOrderTraverseOfBSTRecursive(seq, first,
									last - 1);
	}
	// Now has both subtrees or seq is direct wrong.
	int divide = first, divide_cnt = 0;
	for(int index = first; index < last - 1; ++index)
	{
		if(seq[index] < seq[last] && seq[index + 1] > seq[last])
		{
			++divide_cnt;
			divide = index;
		}
	}
	return
		seq[first] > seq[last] || divide_cnt != 1 ? false : IsPostOrderTraverseOfBSTRecursive(
			seq, first, divide)
														&& IsPostOrderTraverseOfBSTRecursive(
															seq, divide + 1,
															last - 1);
}
// Assume all elements are not equal.
bool IsPostOrderTraverseOfBST(const vector<int> &seq)
{
	return
		seq.size() <= 0 ? false : IsPostOrderTraverseOfBSTRecursive(seq, 0,
								static_cast<int>(seq.size()) - 1);
}
void TestIsPostOrderTraverseOfBST()
{
	printf("-----TestIsPostOrderTraverseOfBST-----\n");
	vector<vector<int>> test { {}, { 1 }, { 1, 2, 3 }, { 3, 2, 1 }, { 1, 3, 2 }, { 5,
		7, 6, 9, 11, 10, 8 }, { 5, 70, 6, 9, 11, 10, 8 }, { 100, 13, 16, 14, 15 } };
	vector<bool> answer { false, true, true, true, true, true, false, false };
	for(int i = 0; i < static_cast<int>(test.size()); ++i)
	{
		assert(IsPostOrderTraverseOfBST(test[i]) == answer[i]);
	}
	printf("All case pass.\n");
}
////////////////////////////////////////////////////////////////////////////////
template<typename T>
void InOrderConvertBSTToSortedDoubleLinkedList(BinaryNode<T> *node,
	BinaryNode<T> *&last)
{
	node->left_ != nullptr ? InOrderConvertBSTToSortedDoubleLinkedList(node->left_,
									last) : void();
	last != nullptr ? last->right_ = node : last;
	node->left_ = last;
	last = node;
	node->right_ != nullptr ? InOrderConvertBSTToSortedDoubleLinkedList(node->right_,
									last) : void();
}
template<typename T>
BinaryNode<T> *ConvertBSTToSortedDoubleLinkedList(BinaryNode<T> *root)
{
	if(root == nullptr) // Negative test
	{
		return nullptr;
	}
	BinaryNode<T> *last = nullptr;
	InOrderConvertBSTToSortedDoubleLinkedList(root, last);
	for(; last->left_ != nullptr; last = last->left_)
		;
	return last;
}
void TestConvertBSTToSortedDoubleLinkedList()
{
	printf("-----TestConvertBSTToSortedDoubleLinkedList-----\n");
	BinarySearchTree<int> tree;
	// Nagative test: nullptr
	assert(ConvertBSTToSortedDoubleLinkedList(tree.root()) == nullptr);
	// Edge test
	tree.Insert(10);
	BinaryNode<int> *root = ConvertBSTToSortedDoubleLinkedList(tree.root());
	assert(
		root != nullptr && root->left_ == nullptr && root->right_ == nullptr
			&& root->data_ == 10);
	// Function test
	vector<int> insert { 6, 14, 4, 8, 12 };
	for(int i = 0; i < static_cast<int>(insert.size()); ++i)
	{
		tree.Insert(insert[i]);
	}
	root = ConvertBSTToSortedDoubleLinkedList(tree.root());
	assert(root->left_ == nullptr);
	vector<int> data { 4, 6, 8, 10, 12, 14 };
	for(int i = 0; i < static_cast<int>(data.size()); ++i)
	{
		assert(root->data_ == data[i]);
		root->right_ != nullptr ? root = root->right_ : root;
	}
	assert(root->right_ == nullptr);
	for(int i = static_cast<int>(data.size()) - 1; i >= 0; --i)
	{
		assert(root->data_ == data[i]);
		root = root->left_;
	}
	assert(root == nullptr);
	printf("All case pass.\n");
	tree.set_root(root);
}
//////////////////////////////////////////////////////////////////////
int main()
{
	TestIsPostOrderTraverseOfBST();
	TestConvertBSTToSortedDoubleLinkedList();
#ifdef TEST_BINARY_SEARCH_TREE
	BinarySearchTree<int> tree;
	printf("0: Exit\n1: Create\n2: Insert\n3: Search\n4: Delete\n");
	int operation, data;
	BinaryNode<int> *temp = nullptr;
	while(scanf("%d", &operation) == 1)
	{
		switch(operation)
		{
			case 0:
			return 0;
			case 1:
			tree.Create();
			break;
			case 2:
			scanf("%d", &data);
			tree.Insert(data);
			break;
			case 3:
			scanf("%d", &data);
			if(tree.Search(data, temp) != nullptr)
			{
				printf("Found\n");
			}
			else
			{
				printf("Not Found\n");
			}
			break;
			case 4:
			scanf("%d", &data);
			if(tree.Delete(data) != nullptr)
			{
				printf("Deleted\n");
			}
			else
			{
				printf("Not Deleted\n");
			}
			break;
		}
		tree.LevelOrder();
		tree.Height();
		tree.NodeCount();
	}
#endif
}
/*
 1 11 6 10 9 0 1 5 7 2 8 3 4
 2 6
 2 2
 2 100
 3 -1
 3 0
 3 100
 3 101
 4 -1
 4 101
 4 4
 4 2
 4 10
 4 6
 0

 LevelOrder: 6 0 10 1 9 5 7 2 8 3 4
 Height:     7
 NodeCount:  11
 LevelOrder: 6 0 10 1 9 5 7 2 8 3 4
 Height:     7
 NodeCount:  11
 LevelOrder: 6 0 10 1 9 5 7 2 8 3 4
 Height:     7
 NodeCount:  11
 LevelOrder: 6 0 10 1 9 100 5 7 2 8 3 4
 Height:     7
 NodeCount:  12
 Not Found
 LevelOrder: 6 0 10 1 9 100 5 7 2 8 3 4
 Height:     7
 NodeCount:  12
 Found
 LevelOrder: 6 0 10 1 9 100 5 7 2 8 3 4
 Height:     7
 NodeCount:  12
 Found
 LevelOrder: 6 0 10 1 9 100 5 7 2 8 3 4
 Height:     7
 NodeCount:  12
 Not Found
 LevelOrder: 6 0 10 1 9 100 5 7 2 8 3 4
 Height:     7
 NodeCount:  12
 Not Deleted
 LevelOrder: 6 0 10 1 9 100 5 7 2 8 3 4
 Height:     7
 NodeCount:  12
 Not Deleted
 LevelOrder: 6 0 10 1 9 100 5 7 2 8 3 4
 Height:     7
 NodeCount:  12
 Not Deleted
 LevelOrder: 6 0 10 1 9 100 5 7 2 8 3
 Height:     6
 NodeCount:  11
 Deleted
 LevelOrder: 6 0 10 1 9 100 5 7 3 8
 Height:     5
 NodeCount:  10
 Deleted
 LevelOrder: 6 0 9 1 7 100 5 8 3
 Height:     5
 NodeCount:  9
 Deleted
 LevelOrder: 5 0 9 1 7 100 3 8
 Height:     4
 NodeCount:  8
 */
