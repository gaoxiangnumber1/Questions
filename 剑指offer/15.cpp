/*
------------------------------Function Test Data------------------------------
k ∈ [1, length]

---------------------------------Edge Test Data--------------------------------
None

------------------------------Negative Test Data------------------------------
for number k:
1.	negative number: -1, -2...
2.	zero: 0
3.	bigger than length

for linked list head:
1.	null pointer
*/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// use space(O(n)) to trade time(O(n))
ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
{
	// negative data: for linked list head: null pointer
	if(pListHead == NULL)
	{
		return NULL;
	}

	vector<ListNode *> array;  // store all nodes of this linked list
	int length = 0;
	ListNode *temp = pListHead;
	while(temp)  // traverse list to get length and store all nodes in array
	{
		++length;
		array.push_back(temp);
		temp = temp->next;
	}

	// negative data: for number k:
	// 1. k < 0: since k is (unsigned int) data type, if we input negative number,
	// the value will be bigger than the biggest signed int number 0x7fffffff,
	// so if k < 0, then (unsigned int)k > 0x7fffffff.
	// 2 & 3: very clear
	if(k > 0x7fffffff || k == 0 || k > length)
	{
		return NULL;
	}

	// now, k ∈ [1, length]. Note array index begin from 0 to length - 1.
	return array[length - k];
}

int main()
{
	while(1)
	{

	}

	return 0;
}
