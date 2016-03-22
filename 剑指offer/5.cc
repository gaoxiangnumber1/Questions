/*
------------------------------Function Test Data------------------------------
normal linked list is ok

---------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
1. linked list is a null pointer

*/

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

// solution1:
vector<int> printListFromTailToHead1(struct ListNode* head)
{
	vector<int> result;
	while(head)
	{
		result.insert(result.begin(), (*head).val);
		head = (*head).next;
	}

	return result;
}

// solution2:
vector<int> result;
vector<int> printListFromTailToHead(struct ListNode* head)
{
	if(head)
	{
		if(head->next)
		{
			printListFromTailToHead(head->next);
		}
		result.push_back(head->val);
	}

	return result;
}
