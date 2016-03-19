/*
------------------------------Function Test Data------------------------------
normal linked list is ok

---------------------------------Edge Test Data---------------------------------
none

------------------------------Negative Test Data------------------------------
null pointer

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

ListNode *ReverseList(ListNode *pHead)
{
	// negative data: null pointer
	if(pHead == NULL)
	{
		return NULL;
	}

	ListNode *first = pHead, *second = pHead->next;
	// our aim is: second->next = first until second is null pointer
	first->next = NULL;
	while(second)
	{
		ListNode *temp = second->next;
		second->next = first;
		first = second;
		second = temp;
	}
	pHead = first;
	return pHead;
}

int main()
{
	while(1)
	{

	}

	return 0;
}
