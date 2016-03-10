class Solution
{
public:
	vector<int> printListFromTailToHead(struct ListNode* head)
	{
		vector<int> result;
		while(head != NULL)
		{
			result.insert(result.begin(), (*head).val);
			head = (*head).next;
		}
		return result;
	}
};
