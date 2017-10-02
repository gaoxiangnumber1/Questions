#include "binary_node.h"
template<typename T>
void ConstructCompleteBinaryTreeByLevel(BinaryNode<T> *&root, const vector<T> &data)
{
	if(data.size() <= 0)
	{
		return;
	}
	root = new BinaryNode<T>(data[0]);
	queue<BinaryNode<T>*> node_queue;
	node_queue.push(root);
	int length = static_cast<int>(data.size());
	for(int index = 1; index < length;)
	{
		BinaryNode<T> *node = node_queue.front();
		node_queue.pop();
		node->left_ = new BinaryNode<T>(data[index++]);
		node_queue.push(node->left_);
		if(index < length)
		{
			node->right_ = new BinaryNode<T>(data[index++]);
			node_queue.push(node->right_);
		}
	}
}
template<typename T>
void PreOrderRecursive(BinaryNode<T> *root)
{
	if(root != nullptr)
	{
		Visit(root);
		PreOrderRecursive(root->left_);
		PreOrderRecursive(root->right_);
	}
}
template<typename T>
void PreOrderLoop(BinaryNode<T> *root)
{
	stack<BinaryNode<T>*> my_stack;
	while(root != nullptr || my_stack.empty() == false)
	{
		while(root != nullptr)
		{
			Visit(root);
			my_stack.push(root);
			root = root->left_;
		}
		root = my_stack.top()->right_;
		my_stack.pop();
	}
}
template<typename T>
void InOrderRecursive(BinaryNode<T> *root)
{
	if(root != nullptr)
	{
		InOrderRecursive(root->left_);
		Visit(root);
		InOrderRecursive(root->right_);
	}
}
template<typename T>
void InOrderLoop(BinaryNode<T> *root)
{
	stack<BinaryNode<T>*> my_stack;
	while(root != nullptr || my_stack.empty() == false)
	{
		while(root != nullptr)
		{
			my_stack.push(root);
			root = root->left_;
		}
		root = my_stack.top();
		my_stack.pop();
		Visit(root);
		root = root->right_;
	}
}
template<typename T>
void PostOrderRecursive(BinaryNode<T> *root)
{
	if(root != nullptr)
	{
		PostOrderRecursive(root->left_);
		PostOrderRecursive(root->right_);
		Visit(root);
	}
}
template<typename T>
void PostOrderLoop(BinaryNode<T> *root)
{
	stack<BinaryNode<T>*> my_stack;
	while(root != nullptr || my_stack.empty() == false)
	{
		while(root != nullptr)
		{
			my_stack.push(root);
			root = root->left_;
		}
		if(my_stack.top()->right_ == nullptr) // Leaf
		{
			root = my_stack.top();
			my_stack.pop();
			Visit(root);
			while(my_stack.empty() == false
				&& (my_stack.top()->right_ == nullptr || my_stack.top()->right_ == root))
			{
				root = my_stack.top();
				my_stack.pop();
				Visit(root);
			}
			if(my_stack.empty() == false)
			{
				root = my_stack.top()->right_;
			}
			else
			{
				root = nullptr;
			}
		}
		else
		{
			root = my_stack.top()->right_;
		}
	}
}
template<typename T>
int Height(BinaryNode<T> *root)
{
	if(root == nullptr)
	{
		return 0;
	}
	int left_height = Height(root->left_);
	int right_height = Height(root->right_);
	return left_height > right_height ? left_height + 1 : right_height + 1;
}
template<typename T>
int NodeCount(BinaryNode<T> *root)
{
	if(root == nullptr)
	{
		return 0;
	}
	return NodeCount(root->left_) + NodeCount(root->right_) + 1;
}
//////////////////////////////////////////////////////////////////////
template<typename T>
void ConstructBinaryTreeFromPreAndInOrder(BinaryNode<T> *&root, T *pre, int &pre_index,
	T *in, int in_first, int in_last) // [in_first, in_last)
{
	if(in_first >= in_last)
	{
		return;
	}
	int in_index = in_first;
	for(; in_index < in_last && pre[pre_index] != in[in_index]; ++in_index)
		;
	root = new BinaryNode<T>(pre[pre_index++]);
	ConstructBinaryTreeFromPreAndInOrder(root->left_, pre, pre_index, in, in_first,
		in_index);
	ConstructBinaryTreeFromPreAndInOrder(root->right_, pre, pre_index, in, in_index + 1,
		in_last);
//	int pre_index = 0;
}
void TestConstructBinaryTreeFromPreAndInOrder()
{
	printf("-----TestConstructBinaryTreeFromPreAndInOrder-----\n");
	printf("All case pass.\n");
}
//////////////////////////////////////////////////////////////////////
template<typename T>
void ConstructBinaryTreeFromPostAndInOrder(BinaryNode<T> *&root, T *post, int &post_index,
	T *in, int in_first, int in_last) // [in_last, in_last)
{
	if(in_first >= in_last)
	{
		return;
	}
	int in_index = in_first;
	for(; in_index < in_last && post[post_index] != in[in_index]; ++in_index)
		;
	root = new BinaryNode<T>(post[post_index--]);
	ConstructBinaryTreeFromPostAndInOrder(root->right_, post, post_index, in,
		in_index + 1, in_last);
	ConstructBinaryTreeFromPostAndInOrder(root->left_, post, post_index, in, in_first,
		in_index);
//	int post_index = data_number - 1;
}
void TestConstructBinaryTreeFromPostAndInOrder()
{
	printf("-----TestConstructBinaryTreeFromPostAndInOrder-----\n");
	printf("All case pass.\n");
}
//////////////////////////////////////////////////////////////////////
template<typename T>
vector<T> LevelOrder(BinaryNode<T> *root)
{
	if(root == nullptr) // Negative test
	{
		return vector<T>();
	}
	queue<BinaryNode<T>*> node_queue;
	vector<T> vec;
	node_queue.push(root);
	while(node_queue.empty() == false)
	{
		BinaryNode<T> *node = node_queue.front();
		node_queue.pop();
		//Visit(node);
		vec.push_back(node->data_);
		node->left_ != nullptr ? node_queue.push(node->left_) : void();
		node->right_ != nullptr ? node_queue.push(node->right_) : void();
	}
	return vec;
}
void TestLevelOrder()
{
	printf("-----TestLevelOrder-----\n");
	printf("All case pass.\n");
}
//////////////////////////////////////////////////////////////////////
template<typename T>
void ConstructBinaryTreeFromPreAndPostOrder(BinaryNode<T> *&root)
{
	// See ZuoChengYun P171.
}
void TestConstructBinaryTreeFromPreAndPostOrder()
{
	printf("-----TestConstructBinaryTreeFromPreAndPostOrder-----\n");
	printf("All case pass.\n");
}
//////////////////////////////////////////////////////////////////////
template<typename T>
bool IsSubTree(BinaryNode<T> *large, BinaryNode<T> *small)
{
	if(large == nullptr || small == nullptr) // Negative test
	{
		return small == nullptr ? true : false;
	}
	return (large->data_ == small->data_ && IsSubTree(large->left_, small->left_)
		&& IsSubTree(large->right_, small->right_)) || IsSubTree(large->left_, small)
		|| IsSubTree(large->right_, small); // && or || is short-circuit
}
void TestIsSubTree()
{
	printf("-----TestIsSubTree-----\n");
	BinaryNode<int> *large_null = nullptr, *large_zero, *large_one_to_seven;
	BinaryNode<int> *small_null = nullptr, *small_zero, *small_one, *small_two_four_five,
		*small_three_four_five;
	ConstructCompleteBinaryTreeByLevel(large_zero, { 0 });
	ConstructCompleteBinaryTreeByLevel(large_one_to_seven, { 1, 2, 3, 4, 5, 6, 7 });
	ConstructCompleteBinaryTreeByLevel(small_zero, { 0 });
	ConstructCompleteBinaryTreeByLevel(small_one, { 1 });
	ConstructCompleteBinaryTreeByLevel(small_two_four_five, { 2, 4, 5 });
	ConstructCompleteBinaryTreeByLevel(small_three_four_five, { 3, 4, 5 });
	// Negative test: nullptr
	assert(IsSubTree(large_null, small_null) == true); // nullptr, nullptr
	assert(IsSubTree(large_null, small_zero) == false); // nullptr, non-null
	assert(IsSubTree(large_zero, small_null) == true); // non-null, nullptr
	// Function test.
	assert(IsSubTree(large_zero, small_zero) == true); // 1 node, true
	assert(IsSubTree(large_zero, small_one) == false); // 1 node, false
	assert(IsSubTree(large_one_to_seven, small_two_four_five) == true); // 3 node, true
	assert(IsSubTree(large_one_to_seven, small_three_four_five) == false); // 3 node, false
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
	vector<BinaryNode<int>*> tree(kCaseNumber);
	vector<vector<int>> before_modify = { {}, { 1 }, { 1, 2, 3 }, { 1, 2, 3, 4, 5, 6, 7 },
		{ 1, 2, 3, 4, 5, 6, 7, 8 } };
	vector<vector<int>> after_modify = { {}, { 1 }, { 1, 3, 2 }, { 1, 3, 2, 7, 6, 5, 4 },
		{ 1, 3, 2, 7, 6, 5, 4, 8 } };
	vector<vector<int>> my_modify(kCaseNumber);
	for(int index = 0; index < kCaseNumber; ++index)
	{
		ConstructCompleteBinaryTreeByLevel(tree[index], before_modify[index]);
		ModifyBinaryTreeToItsMirror(tree[index]);
		my_modify[index] = LevelOrder(tree[index]);
		AssertVectorData(after_modify[index], my_modify[index]);
	}
	printf("All case pass.\n");
}
////////////////////////////////////////////////////////////////////////////////
template<typename T>
void FindPathSumInBinaryTreeDFS(BinaryNode<T> *node, vector<int> &path, int sum,
	int expect_sum, Matrix &result)
{
	path.push_back(node->data_);
	sum += node->data_;
	if(node->left_ == nullptr && node->right_ == nullptr && sum == expect_sum)
	{
		result.push_back(path);
	}
	node->left_ != nullptr ? FindPathSumInBinaryTreeDFS(node->left_, path, sum,
									expect_sum, result) : void();
	node->right_ != nullptr ? FindPathSumInBinaryTreeDFS(node->right_, path, sum,
									expect_sum, result) : void();
	path.pop_back();
}
template<typename T>
Matrix FindPathSumInBinaryTree(BinaryNode<T> *root, int expect_sum)
{
	if(root == nullptr) // Negative test.
	{
		return Matrix();
	}
	vector<int> path;
	Matrix result;
	FindPathSumInBinaryTreeDFS(root, path, 0, expect_sum, result);
	return result;
}
void TestFindPathSumInBinaryTree()
{
	printf("-----TestFindPathSumInBinaryTree-----\n");
	BinaryNode<int> *tree;
	ConstructCompleteBinaryTreeByLevel(tree, { 5, 5, 10, -5, 5, 5, -5, 15, 5, 5, 5 });
	vector<int> expect_sum { 5,/*0 path*/10,/*2 path*/20 /*4 path*/};
	vector<Matrix> answer { {},/*0 path*/
	{ { 5, 5, -5, 5 }, { 5, 10, -5 } },/*2 path*/
	{ { 5, 5, -5, 15 }, { 5, 5, 5, 5 }, { 5, 5, 5, 5 }, { 5, 10, 5 } }/*4 path*/};
	for(int i = 0; i < static_cast<int>(expect_sum.size()); ++i)
	{
		Matrix result = FindPathSumInBinaryTree(tree, expect_sum[i]);
		AssertTwoDimensionVectorData(answer[i], result);
	}
	printf("All case pass.\n");
}
//////////////////////////////////////////////////////////////////////
int main()
{
	TestIsSubTree();
	TestModifyBinaryTreeToItsMirror();
	TestFindPathSumInBinaryTree();
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
