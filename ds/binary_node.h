#ifndef DS_BINARY_NODE_H_
#define DS_BINARY_NODE_H_
#include "../common_system_header.h"
template<typename T>
struct BinaryNode
{
	BinaryNode(const T &data, BinaryNode<T> *left = nullptr, BinaryNode<T> *right =
		nullptr, int weight = 0) :
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
#endif // DS_BINARY_NODE_H_
