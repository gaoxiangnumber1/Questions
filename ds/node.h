#ifndef DS_NODE_H_
#define DS_NODE_H_
#include "../common_system_header.h"

template<typename T>
struct Node
{
	Node(const T &data, Node<T> *next = nullptr) :
		data_(data), next_(next)
	{
	}
	T data_;
	Node<T> *next_;
};
template<typename T>
struct RandomNode
{
	RandomNode(const T &data, RandomNode<T> *next = nullptr, RandomNode<T> *random = nullptr) :
		data_(data), next_(next), random_(random)
	{
	}
	T data_;
	RandomNode<T> *next_;
	RandomNode<T> *random_;
};

#endif // DS_NODE_H_
