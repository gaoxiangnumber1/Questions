#include "node.h"
#include <assert.h>
#include <utility>
#include <vector>
using std::swap;
using std::vector;

template<typename T>
class LinkedList
{
public:
	LinkedList() :
		first_(nullptr), length_(0)
	{
	}
	~LinkedList();

	void Create();
	void CreateFromArray(T *data, int length);
	void Insert(int index, const T &data);
	void Delete(int index);
	void Reverse();

	bool Empty() const;
	int Size() const;
	Node<T> *FirstNode() const;
	void SetFirstNode(Node<T> *new_first);
	Node<T> *LastNode() const;

private:
	Node<T> *first_;
	int length_;
};

template<typename T>
LinkedList<T>::~LinkedList()
{
	while(Empty() == false)
	{
		Node<T> *next = first_->next_;
		delete first_;
		first_ = next;
	}
}
template<typename T>
void LinkedList<T>::Create()
{
	int data_number, data;
	scanf("%d", &data_number);
	while(data_number-- > 0)
	{
		scanf("%d", &data);
		Insert(Size(), data);
	}
}
template<typename T>
void LinkedList<T>::CreateFromArray(T *data, int length)
{
	for(int index = 0; index < length; ++index)
	{
		Insert(Size(), data[index]);
	}
}
template<typename T>
void LinkedList<T>::Insert(int index, const T &data)
{
	if(index < 0 || index > Size()) // index must be in [0, Size()]
	{
		index = (index < 0 ? 0 : Size());
	}
	Node<T> *new_node = new Node<T>(data);
	if(index == 0) // Insert as the first node.
	{
		new_node->next_ = first_;
		first_ = new_node;
	}
	else
	{
		Node<T> *before_node = first_;
		for(int before_node_index = 0; before_node_index + 1 != index; ++before_node_index)
		{
			before_node = before_node->next_;
		}
		new_node->next_ = before_node->next_;
		before_node->next_ = new_node;
	}
	++length_;
}
template<typename T>
void LinkedList<T>::Delete(int index)
{
	if(Empty() == true) // Can't delete from empty linked list.
	{
		return;
	}
	if(index < 0 || index >= Size()) // index must be in [0, Size() - 1]
	{
		index = (index < 0 ? 0 : Size() - 1);
	}
	if(index == 0)
	{
		Node<T> *new_first = first_->next_;
		delete first_;
		first_ = new_first;
	}
	else
	{
		Node<T> *before_node = first_;
		for(int before_node_index = 0; before_node_index + 1 != index; ++before_node_index)
		{
			before_node = before_node->next_;
		}
		Node<T> *delete_node = before_node->next_;
		before_node->next_ = delete_node->next_;
		delete delete_node;
	}
	--length_;
}
template<typename T>
void LinkedList<T>::Reverse()
{
	if(Empty() == true)
	{
		return;
	}
	Node<T> *before_node = first_, *after_node = first_->next_;
	first_->next_ = nullptr;
	while(after_node != nullptr)
	{
		Node<T> *next_after_node = after_node->next_;
		after_node->next_ = before_node;
		before_node = after_node;
		after_node = next_after_node;
	}
	first_ = before_node;
}
template<typename T>
bool LinkedList<T>::Empty() const
{
	return first_ == nullptr;
}
template<typename T>
int LinkedList<T>::Size() const
{
	return length_;
}
template<typename T>
Node<T> *LinkedList<T>::FirstNode() const
{
	return first_;
}
template<typename T>
void LinkedList<T>::SetFirstNode(Node<T> *new_first)
{
	first_ = new_first;
}
template<typename T>
Node<T> *LinkedList<T>::LastNode() const
{
	Node<T> *last = first_;
	for(int index = 1; index < length_; ++index)
	{
		last = last->next_;
	}
	return last;
}

template<typename T>
void PrintLinkedList(Node<T> *first)
{
	int size = 0;
	for(Node<T> *node = first; node != nullptr; node = node->next_, ++size)
	{
		printf("%d ", node->data_);
	}
	printf("node_number=%d\n", size);
}

template<typename T>
void Partition(Node<T> *first, Node<T> *&right, Node<T> *&left, Node<T> *last)
{
	T pivot = last->data_;
	Node<T> *divide = first;
	for(Node<T> *node = first; node != last; node = node->next_)
	{
		if(node->data_ <= pivot)
		{
			if(node->data_ != divide->data_)
			{
				swap(node->data_, divide->data_);
			}
			right = divide;
			divide = divide->next_;
		}
	}
	if(divide->data_ != last->data_)
	{
		swap(divide->data_, last->data_);
	}
	left = (divide == last ? last : divide->next_); // Adjust 0 node to 1 node to end recursive.
}
template<typename T>
// Sort nodes in [first, last], assume input is valid(at least 1 node).
void QuickSort(Node<T> *first, Node<T> *last)
{
	if(first == last) // Only 1 node.
	{
		return;
	}
	// Partition [first, last] into { [first, right] <= [divide] < [left, last] }
	Node<T> *right = first, *left = last;
	Partition(first, right, left, last);
	QuickSort(first, right);
	QuickSort(left, last);
}
void TestQuickSort()
{
	const int data_length = 10;
	int data[][data_length] = { { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 },
		{ 0, 2, 4, 6, 8, 9, 7, 5, 3, 1 } };
	int data_number = static_cast<int>(sizeof(data) / sizeof(data[0]));
	for(int index = 0; index < data_number; ++index)
	{
		LinkedList<int> object;
		object.CreateFromArray(data[index], data_length);
		QuickSort(object.FirstNode(), object.LastNode());
		PrintLinkedList(object.FirstNode());
	}
}

template<typename T>
Node<T> *GetMiddleNode(Node<T> *first)
{
	if(first == nullptr || first->next_ == nullptr || first->next_->next_ == nullptr) // 0/1/2 node
	{
		return first;
	}
	// At least 3 nodes.
	Node<T> *one_step = first->next_, *two_step = first->next_->next_;
	while(two_step->next_ != nullptr && two_step->next_->next_ != nullptr) // Odd/Even nodes.
	{
		one_step = one_step->next_;
		two_step = two_step->next_->next_;
	}
	return one_step;
}
template<typename T>
Node<T> *MergeTwoSortedLinkedList(Node<T> *first, Node<T> *second)
{
	if(first == nullptr || second == nullptr) // Negative test.
	{
		return (first == nullptr ? second : first);
	}

	Node<T> *head = nullptr;
	if(first->data_ <= second->data_)
	{
		head = first;
		first = first->next_;
	}
	else
	{
		head = second;
		second = second->next_;
	}
	Node<T> *node = head;
	while(first != nullptr && second != nullptr)
	{
		if(first->data_ <= second->data_)
		{
			node->next_ = first;
			first = first->next_;
		}
		else
		{
			node->next_ = second;
			second = second->next_;
		}
		node = node->next_;
	}
	node->next_ = (first == nullptr ? second : first);
	return head;
}
template<typename T>
Node<T> *MergeSort(Node<T> *first)
{
	if(first == nullptr || first->next_ == nullptr) // Negative and Edge test.
	{
		return first;
	}

	Node<T> *middle = GetMiddleNode(first);
	Node<T> *middle_next = middle->next_;
	middle->next_ = nullptr; // Temporary separate two sublists.
	return MergeTwoSortedLinkedList(MergeSort(first), MergeSort(middle_next));
}
void TestMergeSort()
{
	vector<vector<int>> data = { { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 },
		{ 0, 2, 4, 6, 8, 9, 7, 5, 3, 1 } };
	for(int index = 0; index < static_cast<int>(data.size()); ++index)
	{
		LinkedList<int> object;
		object.CreateFromArray(data[index].data(), static_cast<int>(data[index].size()));
		object.SetFirstNode(MergeSort(object.FirstNode()));
		PrintLinkedList(object.FirstNode());
	}
}

int main()
{
	LinkedList<int> object; // Stack object's dtor is auto called when scope ends.
	printf("0: Exit\n1: Create\n2: Insert\n3: Delete\n4: Reverse\n"
		"5: QuickSort\n6: TestQuickSort\n7: MergeSort\n8: TestMergeSort\n");
	int operation, data, index;
	while(scanf("%d", &operation) == 1)
	{
		switch(operation)
		{
		case 0:
			return 0;
		case 1:
			object.Create();
			PrintLinkedList(object.FirstNode());
			break;
		case 2:
			scanf("%d %d", &index, &data);
			object.Insert(index, data);
			PrintLinkedList(object.FirstNode());
			break;
		case 3:
			scanf("%d", &index);
			object.Delete(index);
			PrintLinkedList(object.FirstNode());
			break;
		case 4:
			object.Reverse();
			PrintLinkedList(object.FirstNode());
			break;
		case 5:
			QuickSort(object.FirstNode(), object.LastNode());
			PrintLinkedList(object.FirstNode());
			break;
		case 6:
			TestQuickSort();
			break;
		case 7:
			MergeSort(object.FirstNode());
			PrintLinkedList(object.FirstNode());
			break;
		case 8:
			TestMergeSort();
			break;
		}
	}
}
/*
 1 5 1 2 3 4 5
 4
 2 -1 0
 2 0 6
 2 4 7
 2 7 8
 2 9 9
 2 100 10
 4
 3 -1
 3 0
 3 5
 3 7
 3 5
 4
 0
 05 data: 1 2 3 4 5
 05 data: 5 4 3 2 1
 06 data: 0 5 4 3 2 1
 07 data: 6 0 5 4 3 2 1
 08 data: 6 0 5 4 7 3 2 1
 09 data: 6 0 5 4 7 3 2 8 1
 10 data: 6 0 5 4 7 3 2 8 1 9
 11 data: 6 0 5 4 7 3 2 8 1 9 10
 11 data: 10 9 1 8 2 3 7 4 5 0 6
 10 data: 9 1 8 2 3 7 4 5 0 6
 09 data: 1 8 2 3 7 4 5 0 6
 08 data: 1 8 2 3 7 5 0 6
 07 data: 1 8 2 3 7 5 0
 06 data: 1 8 2 3 7 0
 06 data: 0 7 3 2 8 1
 */
