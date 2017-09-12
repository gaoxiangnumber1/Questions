#include "node.h"
#include <assert.h>
#include <utility>
#include <vector>
#include <stack>
#include <string.h>
using std::swap;
using std::vector;
using std::stack;

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
	void CreateFromArray(const vector<T> &data);
	void Insert(int index, const T &data);
	void Delete(int index);

	bool Empty() const;
	int Size() const;
	Node<T> *FirstNode() const;
	Node<T> *&FirstNodeRef();
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
		Node<T> *next_ = first_->next_;
		delete first_;
		first_ = next_;
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
void LinkedList<T>::CreateFromArray(const vector<T> &data)
{
	for(int index = 0; index < static_cast<int>(data.size()); ++index)
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
Node<T> *&LinkedList<T>::FirstNodeRef()
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
	if(first_ == nullptr)
	{
		return nullptr;
	}
	Node<T> *last = first_;
	for(; last->next_ != nullptr; last = last->next_)
		;
	return last;
}
///////////////////////////////////////////////////////////////////////////
template<typename T>
void PrintLinkedList(Node<T> *first)
{
	int size = 0;
	for(Node<T> *node = first; node != nullptr; node = node->next_, ++size)
	{
		printf("%d ", node->data_);
	}
	printf("node_num=%d\n", size);
}
template<typename T>
void PrintVector(const vector<T> &data)
{
	for(int index = 0; index < static_cast<int>(data.size()); ++index)
	{
		printf("%d ", data[index]);
	}
	printf("\n");
}
template<typename T>
void AssertLinkedListNodeData(Node<T> *first, const vector<T> &data)
{
	int length = 0;
	typename vector<T>::const_iterator it = data.begin();
	for(Node<T> *node = first; node != nullptr; node = node->next_, ++it, ++length)
	{
		assert(node->data_ == *it);
	}
	assert(length == static_cast<int>(data.size()));
}
///////////////////////////////////////////////////////////////////////////
template<typename T>
void PartitionClose(Node<T> *first, Node<T> *&right, Node<T> *&left, Node<T> *last)
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
void QuickSortClose(Node<T> *first, Node<T> *last)
{
	if(first == last) // Only 1 node.
	{
		return;
	}
	// Partition [first, last] into { [first, right] <= [divide] < [left, last] }
	Node<T> *right = first, *left = last;
	PartitionClose(first, right, left, last);
	QuickSortClose(first, right);
	QuickSortClose(left, last);
}
template<typename T>
Node<T> *Partition(Node<T> *first, Node<T> *last)
{
	T pivot = first->data_;
	Node<T> *divide_before = first, *divide = first->next_;
	for(Node<T> *node = first->next_; node != last; node = node->next_)
	{
		if(node->data_ <= pivot)
		{
			node->data_ != divide->data_ ? swap(node->data_, divide->data_) : void(0);
			divide_before = divide;
			divide = divide->next_;
		}
	}
	divide_before->data_ != first->data_ ? swap(divide_before->data_, first->data_) : void(0);
	return divide_before;
}
template<typename T>
void QuickSort(Node<T> *first, Node<T> *last) // [first, last)
{
	if(first == nullptr || first == last || first->next_ == last) // Negative, 0, 1 node
	{
		return;
	}
	Node<T> *divide = Partition(first, last);
	QuickSort(first, divide);
	QuickSort(divide->next_, last);
}
void TestQuickSort()
{
	printf("-----TestQuickSort-----\n");
	vector<vector<int>> data = { { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 },
		{ 0, 2, 4, 6, 8, 9, 7, 5, 3, 1 } };
	for(int index = 0; index < static_cast<int>(data.size()); ++index)
	{
		LinkedList<int> obj;
		obj.CreateFromArray(data[index]);
		QuickSort(obj.FirstNode(), static_cast<Node<int>*>(nullptr));
		AssertLinkedListNodeData(obj.FirstNode(), { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	}
	printf("All case pass.\n");
}
///////////////////////////////////////////////////////////////////////////
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
	printf("-----TestMergeSort-----\n");
	vector<vector<int>> data = { { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 },
		{ 0, 2, 4, 6, 8, 9, 7, 5, 3, 1 } };
	for(int index = 0; index < static_cast<int>(data.size()); ++index)
	{
		LinkedList<int> obj;
		obj.CreateFromArray(data[index]);
		obj.SetFirstNode(MergeSort(obj.FirstNode()));
		AssertLinkedListNodeData(obj.FirstNode(), { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	}
	printf("All case pass.\n");
}
///////////////////////////////////////////////////////////////////////////
template<typename T>
void DeleteNodeInOOne(Node<T> *&head, Node<T> *node)
{
	if(head == nullptr || node == nullptr) // Negative test
	{
		return;
	}
	if(head == node) // Edge test: delete first node.
	{
		head = head->next_;
		delete node;
	}
	else if(node->next_ == nullptr) // Edge test: delete last node.
	{
		Node<T> *before = head;
		for(; before->next_ != node; before = before->next_)
			;
		before->next_ = nullptr;
		delete node;
	}
	else
	{
		Node<T> *after = node->next_;
		node->data_ = after->data_;
		node->next_ = after->next_;
		delete after;
	}
}
void TestDeleteNodeInOOne()
{
	printf("-----TestDeleteNodeInOOne-----\n");
	LinkedList<int> obj;
	// Negative test: nullptr.
	DeleteNodeInOOne(obj.FirstNodeRef(), obj.FirstNode());
	AssertLinkedListNodeData(obj.FirstNode(), {});
	// Edge test: first node.
	obj.CreateFromArray( { 0, 1, 2, 3, 4 });
	DeleteNodeInOOne(obj.FirstNodeRef(), obj.FirstNode());
	AssertLinkedListNodeData(obj.FirstNode(), { 1, 2, 3, 4 });
	// Edge test: last node.
	DeleteNodeInOOne(obj.FirstNodeRef(), obj.LastNode());
	AssertLinkedListNodeData(obj.FirstNode(), { 1, 2, 3 });
	// Function test: middle node.
	DeleteNodeInOOne(obj.FirstNodeRef(), obj.FirstNode()->next_);
	AssertLinkedListNodeData(obj.FirstNode(), { 1, 3 });
	DeleteNodeInOOne(obj.FirstNodeRef(), obj.LastNode());
	AssertLinkedListNodeData(obj.FirstNode(), { 1 });
	DeleteNodeInOOne(obj.FirstNodeRef(), obj.LastNode());
	AssertLinkedListNodeData(obj.FirstNode(), {});
	printf("All case pass.\n");
}
///////////////////////////////////////////////////////////////////////////
template<typename T>
Node<T> *FindKthToTailNode(Node<T> *first, int k)
{
	if(first == nullptr || k <= 0) // Negative test.
	{
		return nullptr;
	}
	Node<T> *slow = first, *fast = first;
	for(int cnt = 1; cnt <= k - 1; ++cnt)
	{
		fast = fast->next_;
		if(fast == nullptr) // Negative test.
		{
			return nullptr;
		}
	}
	for(; fast->next_ != nullptr; fast = fast->next_, slow = slow->next_)
		;
	return slow;
}
void TestFindKthToTailNode()
{
	printf("-----TestFindKthToTailNode-----\n");
	LinkedList<int> obj;
	// Negative test: nullptr, k<=0, k > length
	assert(FindKthToTailNode(obj.FirstNode(), 1) == nullptr);
	obj.CreateFromArray( { 5, 4, 3, 2, 1 });
	assert(FindKthToTailNode(obj.FirstNode(), 0) == nullptr);
	assert(FindKthToTailNode(obj.FirstNode(), 6) == nullptr);
	// Function test: 1<=k<=length
	assert(FindKthToTailNode(obj.FirstNode(), 1)->data_ == 1);
	assert(FindKthToTailNode(obj.FirstNode(), 3)->data_ == 3);
	assert(FindKthToTailNode(obj.FirstNode(), 5)->data_ == 5);
	printf("All case pass.\n");
}
///////////////////////////////////////////////////////////////////////////
template<typename T>
Node<T> *ReverseLinkedList(Node<T> *first)
{
	Node<T> *before = nullptr, *node = first, *after = nullptr;
	while(node != nullptr) // Including Negative and Edge test.
	{
		after = node->next_;
		node->next_ = before;
		before = node;
		node = after;
	}
	return before;
}
void TestReverseLinkedList()
{
	printf("-----TestReverseLinkedList-----\n");
	LinkedList<int> obj;
	// Negative test: nullptr, i.e., 0 node.
	obj.SetFirstNode(ReverseLinkedList(obj.FirstNode()));
	AssertLinkedListNodeData(obj.FirstNode(), {});
	// Edge test: 1 node.
	obj.Insert(obj.Size(), 1);
	obj.SetFirstNode(ReverseLinkedList(obj.FirstNode()));
	AssertLinkedListNodeData(obj.FirstNode(), { 1 });
	// Function tets: 2 nodes.
	obj.Insert(obj.Size(), 2);
	obj.SetFirstNode(ReverseLinkedList(obj.FirstNode()));
	AssertLinkedListNodeData(obj.FirstNode(), { 2, 1 });
	// Function tets: 3 nodes.
	obj.Insert(obj.Size(), 3);
	obj.SetFirstNode(ReverseLinkedList(obj.FirstNode()));
	AssertLinkedListNodeData(obj.FirstNode(), { 3, 1, 2 });
	// Function tets: 4 nodes.
	obj.Insert(obj.Size(), 4);
	obj.SetFirstNode(ReverseLinkedList(obj.FirstNode()));
	AssertLinkedListNodeData(obj.FirstNode(), { 4, 2, 1, 3 });
	// Function tets: 5 nodes.
	obj.Insert(obj.Size(), 5);
	obj.SetFirstNode(ReverseLinkedList(obj.FirstNode()));
	AssertLinkedListNodeData(obj.FirstNode(), { 5, 3, 1, 2, 4 });
	printf("All case pass.\n");
}
///////////////////////////////////////////////////////////////////////////
template<typename T>
// T(n) = O(n) S(n) = O(n)
vector<int> ReversePrintLinkedListStack(Node<T> *first)
{
	if(first == nullptr) // Negative test.
	{
		return vector<int>();
	}

	stack<int> s;
	while(first != nullptr)
	{
		s.push(first->data_);
		first = first->next_;
	}
	vector<int> vec;
	while(s.empty() == false)
	{
		vec.push_back(s.top());
		s.pop();
	}
	return vec;
}
// T(n) = O(n) S(n) = O(n)
vector<int> g_reverse_print_vec;
template<typename T>
vector<int> ReversePrintLinkedListRecursive(Node<T> *first)
{
	if(first == nullptr)
	{
		g_reverse_print_vec.clear();
	}
	else
	{
		ReversePrintLinkedListRecursive(first->next_);
		g_reverse_print_vec.push_back(first->data_);
	}
	return g_reverse_print_vec;
}
void TestReversePrintLinkedList()
{
	printf("-----TestReversePrintLinkedList-----\n");
	Node<int> node3(3);
	Node<int> node2(2, &node3);
	Node<int> node1(1, &node2);
	Node<int> node0(0, &node1);
	vector<int> output1 = { 3 };
	assert(memcmp(output1.data(), ReversePrintLinkedListStack(&node3).data(), output1.size()) == 0);
	assert(
		memcmp(output1.data(), ReversePrintLinkedListRecursive(&node3).data(), output1.size())
			== 0);
	vector<int> output2 = { 3, 2, 1, 0 };
	assert(memcmp(output2.data(), ReversePrintLinkedListStack(&node0).data(), output2.size()) == 0);
	assert(
		memcmp(output2.data(), ReversePrintLinkedListRecursive(&node0).data(), output2.size())
			== 0);
	assert(
		ReversePrintLinkedListStack(static_cast<Node<int>*>(nullptr)).size() == 0
			&& ReversePrintLinkedListRecursive(static_cast<Node<int>*>(nullptr)).size() == 0);
	printf("All case pass.\n");
}
///////////////////////////////////////////////////////////////////////////
int main()
{
	TestQuickSort();
	TestMergeSort();
	TestDeleteNodeInOOne();
	TestFindKthToTailNode();
	TestReverseLinkedList();
	TestReversePrintLinkedList();

#ifdef TEST_LINKED_LIST
	LinkedList<int> obj; // Stack obj's dtor is auto called when scope ends.
	printf("0: Exit\n1: Create\n2: Insert\n3: Delete\n4: Reverse\n");
	int operation, data, index;
	while(scanf("%d", &operation) == 1)
	{
		switch(operation)
		{
			case 0:
			return 0;
			case 1:
			obj.Create();
			PrintLinkedList(obj.FirstNode());
			break;
			case 2:
			scanf("%d %d", &index, &data);
			obj.Insert(index, data);
			PrintLinkedList(obj.FirstNode());
			break;
			case 3:
			scanf("%d", &index);
			obj.Delete(index);
			PrintLinkedList(obj.FirstNode());
			break;
			case 4:
			obj.SetFirstNode(ReverseLinkedList(obj.FirstNode()));
			PrintLinkedList(obj.FirstNode());
			break;
		}
	}
#endif
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
