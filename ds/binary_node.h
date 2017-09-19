#ifndef DS_BINARY_NODE_H_
#define DS_BINARY_NODE_H_
#include "../common_system_header.h"

template<typename T>
struct BinaryNode
{
	BinaryNode(const T &data, BinaryNode<T> *left = nullptr, BinaryNode<T> *right = nullptr,
		int weight = 0) :
		data_(data), left_(left), right_(right), weight_(weight)
	{
	}

	T data_;
	BinaryNode<T> *left_;
	BinaryNode<T> *right_;
	int weight_;
};

template<typename T>
void Delete(BinaryNode<T> *&root)
{
	if(root != nullptr)
	{
		Delete(root->left_);
		Delete(root->right_);
		delete root;
		root = nullptr;
	}
}
template<typename T>
void ConstructBinaryTreeFromPreAndInOrder(BinaryNode<T> *&root, T *pre, int &pre_index, T *in,
	int in_first, int in_last) // [in_last, in_last)
{
	if(in_first < in_last)
	{
		int in_index = in_first;
		for(; in_index < in_last && pre[pre_index] != in[in_index]; ++in_index)
			;
		root = new BinaryNode<T>(pre[pre_index++]);
		ConstructBinaryTreeFromPreAndInOrder(root->left_, pre, pre_index, in, in_first, in_index);
		ConstructBinaryTreeFromPreAndInOrder(root->right_, pre, pre_index, in, in_index + 1,
			in_last);
	}
}
template<typename T>
void ConstructBinaryTreeFromPostAndInOrder(BinaryNode<T> *&root, T *post, int &post_index, T *in,
	int in_first, int in_last) // [in_last, in_last)
{
	if(in_first < in_last)
	{
		int in_index = in_first;
		for(; in_index < in_last && post[post_index] != in[in_index]; ++in_index)
			;
		root = new BinaryNode<T>(post[post_index--]);
		ConstructBinaryTreeFromPostAndInOrder(root->right_, post, post_index, in, in_index + 1,
			in_last);
		ConstructBinaryTreeFromPostAndInOrder(root->left_, post, post_index, in, in_first,
			in_index);
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
vector<T> LevelOrder(BinaryNode<T> *root)
{
	if(root == nullptr) // Negative test
	{
		return vector<T>();
	}
	queue<BinaryNode<T>*> my_queue;
	vector<T> vec;
	my_queue.push(root);
	while(my_queue.empty() == false)
	{
		BinaryNode<T> *node = my_queue.front();
		my_queue.pop();
		//Visit(node);
		vec.push_back(node->data_);
		node->left_ != nullptr ? my_queue.push(node->left_) : void();
		node->right_ != nullptr ? my_queue.push(node->right_) : void();
	}
	return vec;
}
template<typename T>
void Visit(BinaryNode<T> *node)
{
	printf("%d ", node->data_);
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
#endif // DS_BINARY_NODE_H_
