#include "binary_node.h"
template<typename T>
class BinaryTree
{
public:
	BinaryTree() :
		root_(nullptr)
	{
	}
	~BinaryTree();

	void CreateCompleteBinaryTreeByLevel(const vector<T> &data);
	void ConstructBinaryTreeFromPreAndInOrder();
	void ConstructBinaryTreeFromPostAndInOrder();
	// No `CreateTreeByPreAndPost` because we must need In to know scope [first, last),
	// otherwise the recursion won't stop.
	void PreOrderRecursive() const;
	void PreOrderLoop() const;
	void InOrderRecursive() const;
	void InOrderLoop() const;
	void PostOrderRecursive() const;
	void PostOrderLoop() const;
	vector<T> LevelOrder() const;
	void Height() const;
	void NodeCount() const;
	BinaryNode<T> *root() const;

private:
	BinaryNode<T> *root_;
};
template<typename T>
BinaryTree<T>::~BinaryTree()
{
	::Delete(root_);
}
template<typename T>
void BinaryTree<T>::CreateCompleteBinaryTreeByLevel(const vector<T> &data)
{
	if(data.size() <= 0)
	{
		return;
	}
	root_ = new BinaryNode<T>(data[0]);
	queue<BinaryNode<T>*> my_queue;
	my_queue.push(root_);
	int length = static_cast<int>(data.size());
	for(int index = 1; index < length;)
	{
		BinaryNode<T> *node = my_queue.front();
		my_queue.pop();
		node->left_ = new BinaryNode<T>(data[index++]);
		my_queue.push(node->left_);
		if(index < length)
		{
			node->right_ = new BinaryNode<T>(data[index++]);
			my_queue.push(node->right_);
		}
	}
}
template<typename T>
void BinaryTree<T>::ConstructBinaryTreeFromPreAndInOrder()
{
	int data_number;
	scanf("%d", &data_number);
	T pre[data_number], in[data_number];
	for(int index = 0; index < data_number; ++index)
	{
		scanf("%d", &pre[index]);
	}
	for(int index = 0; index < data_number; ++index)
	{
		scanf("%d", &in[index]);
	}
	int pre_index = 0;
	::ConstructBinaryTreeFromPreAndInOrder(root_, pre, pre_index, in, 0, data_number);
}
template<typename T>
void BinaryTree<T>::ConstructBinaryTreeFromPostAndInOrder()
{
	int data_number;
	scanf("%d", &data_number);
	T post[data_number], in[data_number];
	for(int index = 0; index < data_number; ++index)
	{
		scanf("%d", &post[index]);
	}
	for(int index = 0; index < data_number; ++index)
	{
		scanf("%d", &in[index]);
	}
	int post_index = data_number - 1;
	::ConstructBinaryTreeFromPostAndInOrder(root_, post, post_index, in, 0, data_number);
}
template<typename T>
void BinaryTree<T>::PreOrderRecursive() const
{
	printf("PreOrder:   ");
	::PreOrderRecursive(root_);
	printf("\n");
}
template<typename T>
void BinaryTree<T>::PreOrderLoop() const
{
	printf("PreOrder:   ");
	::PreOrderLoop(root_);
	printf("\n");
}
template<typename T>
void BinaryTree<T>::InOrderRecursive() const
{
	printf("InOrder:    ");
	::InOrderRecursive(root_);
	printf("\n");
}
template<typename T>
void BinaryTree<T>::InOrderLoop() const
{
	printf("InOrder:    ");
	::InOrderLoop(root_);
	printf("\n");
}
template<typename T>
void BinaryTree<T>::PostOrderRecursive() const
{
	printf("PostOrder:  ");
	::PostOrderRecursive(root_);
	printf("\n");
}
template<typename T>
void BinaryTree<T>::PostOrderLoop() const
{
	printf("PostOrder:  ");
	::PostOrderLoop(root_);
	printf("\n");
}
template<typename T>
vector<T> BinaryTree<T>::LevelOrder() const
{
//	printf("LevelOrder: ");
	return ::LevelOrder(root_);
//	printf("\n");
}
template<typename T>
void BinaryTree<T>::Height() const
{
	printf("Height:     %d\n", ::Height(root_));
}
template<typename T>
void BinaryTree<T>::NodeCount() const
{
	printf("NodeCount:  %d\n", ::NodeCount(root_));
}
template<typename T>
BinaryNode<T> *BinaryTree<T>::root() const
{
	return root_;
}
////////////////////////////////////////////////////////////////////////////////
template<typename T>
bool IsSubTree(BinaryNode<T> *large, BinaryNode<T> *small)
{
	if(large == nullptr || small == nullptr) // Negative test
	{
		return small == nullptr ? true : false;
	}
	bool is_sub_tree = false;
	large->data_ == small->data_ ? (is_sub_tree = IsSubTree(large->left_, small->left_)
		&& IsSubTree(large->right_, small->right_)) : bool();
	is_sub_tree == false ? is_sub_tree = IsSubTree(large->left_, small) : bool();
	is_sub_tree == false ? is_sub_tree = IsSubTree(large->right_, small) : bool();
	return is_sub_tree;
}
void TestIsSubTree()
{
	printf("-----TestIsSubTree-----\n");
	BinaryTree<int> large_null, large_zero, large_one_to_seven;
	BinaryTree<int> small_null, small_zero, small_one, small_two_four_five, small_three_four_five;
	large_zero.CreateCompleteBinaryTreeByLevel( { 0 });
	large_one_to_seven.CreateCompleteBinaryTreeByLevel( { 1, 2, 3, 4, 5, 6, 7 });
	small_zero.CreateCompleteBinaryTreeByLevel( { 0 });
	small_one.CreateCompleteBinaryTreeByLevel( { 1 });
	small_two_four_five.CreateCompleteBinaryTreeByLevel( { 2, 4, 5 });
	small_three_four_five.CreateCompleteBinaryTreeByLevel( { 3, 4, 5 });
	// Negative test: nullptr
	assert(IsSubTree(large_null.root(), small_null.root()) == true); // nullptr, nullptr
	assert(IsSubTree(large_null.root(), small_zero.root()) == false); // nullptr, non-null
	assert(IsSubTree(large_zero.root(), small_null.root()) == true); // non-null, nullptr
	// Function test.
	assert(IsSubTree(large_zero.root(), small_zero.root()) == true); // 1 node, true
	assert(IsSubTree(large_zero.root(), small_one.root()) == false); // 1 node, false
	assert(IsSubTree(large_one_to_seven.root(), small_two_four_five.root()) == true); // 3 node, true
	assert(IsSubTree(large_one_to_seven.root(), small_three_four_five.root()) == false); // 3 node, false
	printf("All case pass.\n");
}
////////////////////////////////////////////////////////////////////////////////
template<typename T>
void ModifyBinaryTreeToItsMirror(BinaryNode<T> *root)
{
	if(root == nullptr) // Negative test.
	{
		return;
	}
	swap(root->left_, root->right_);
	ModifyBinaryTreeToItsMirror(root->left_);
	ModifyBinaryTreeToItsMirror(root->right_);
}
void TestModifyBinaryTreeToItsMirror()
{
	printf("-----TestModifyBinaryTreeToItsMirror-----\n");
	const int kCaseNumber = 5;
	vector<BinaryTree<int>> tree(kCaseNumber);
	vector<vector<int>> before_modify = { {}, { 1 }, { 1, 2, 3 }, { 1, 2, 3, 4, 5, 6, 7 }, { 1, 2,
		3, 4, 5, 6, 7, 8 } };
	vector<vector<int>> after_modify = { {}, { 1 }, { 1, 3, 2 }, { 1, 3, 2, 7, 6, 5, 4 }, { 1, 3, 2,
		7, 6, 5, 4, 8 } };
	vector<vector<int>> my_modify(kCaseNumber);
	for(int index = 0; index < kCaseNumber; ++index)
	{
		tree[index].CreateCompleteBinaryTreeByLevel(before_modify[index]);
		ModifyBinaryTreeToItsMirror(tree[index].root());
		my_modify[index] = tree[index].LevelOrder();
		assert(after_modify[index].size() == my_modify[index].size());
		for(int i = 0; i < static_cast<int>(after_modify[index].size()); ++i)
		{
			assert(after_modify[index][i] == my_modify[index][i]);
		}
	}
	printf("All case pass.\n");
}
////////////////////////////////////////////////////////////////////////////////
int main()
{
	TestIsSubTree();
	TestModifyBinaryTreeToItsMirror();

#ifdef TEST_BINARY_TREE
	printf("0: Exit\n"
		"1: CreateCompleteBinaryTreeByLevel\n"
		"2: ConstructBinaryTreeFromPreAndInOrder\n"
		"3: ConstructBinaryTreeFromPostAndInOrder\n");
	int operation;
	while(scanf("%d", &operation) == 1)
	{
		BinaryTree<int> tree;
		switch(operation)
		{
			case 0:
			return 0;
			case 1:
			tree.CreateCompleteBinaryTreeByLevel();
			break;
			case 2:
			tree.ConstructBinaryTreeFromPreAndInOrder();
			break;
			case 3:
			tree.ConstructBinaryTreeFromPostAndInOrder();
			break;
			default:
			return 0;
		}
		tree.PreOrderRecursive();
		tree.PreOrderLoop();
		tree.InOrderRecursive();
		tree.InOrderLoop();
		tree.PostOrderRecursive();
		tree.PostOrderLoop();
		tree.LevelOrder();
		tree.Height();
		tree.NodeCount();
	}
#endif
}
/*
 1 11 1 2 3 4 5 6 7 8 9 10 11
 2 11 1 2 4 5 6 7 3 8 10 9 11 4 2 6 7 5 1 8 10 3 9 11
 3 11 4 7 6 5 2 10 8 11 9 3 1 4 2 6 7 5 1 8 10 3 9 11
 PreOrder:   1 2 4 8 9 5 10 11 3 6 7
 InOrder:    8 4 9 2 10 5 11 1 6 3 7
 PostOrder:  8 9 4 10 11 5 2 6 7 3 1
 LevelOrder: 1 2 3 4 5 6 7 8 9 10 11
 Height:     4
 NodeCount:  11
 PreOrder:   1 2 4 5 6 7 3 8 10 9 11
 InOrder:    4 2 6 7 5 1 8 10 3 9 11
 PostOrder:  4 7 6 5 2 10 8 11 9 3 1
 LevelOrder: 1 2 3 4 5 8 9 6 10 11 7
 Height:     5
 NodeCount:  11
 PreOrder:   1 2 4 5 6 7 3 8 10 9 11
 InOrder:    4 2 6 7 5 1 8 10 3 9 11
 PostOrder:  4 7 6 5 2 10 8 11 9 3 1
 LevelOrder: 1 2 3 4 5 8 9 6 10 11 7
 Height:     5
 NodeCount:  11
 */
