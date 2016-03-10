/**
* struct ListNode {
* int val;
*
 struct ListNode *next;
*
 ListNode(int x) :
*
 val(x), next(NULL) {
*
 }
* };
*/
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

/**
* struct ListNode {
*
 int val;
*
 struct ListNode *next;
*
 ListNode(int x) :
*
 val(x), next(NULL) {
*
 }
* };
*/
class Solution
{
public:
	vector<int> result;
	vector<int> printListFromTailToHead(struct ListNode* head)
	{
		if(head != NULL)
		{
			if(head->next)
			{
				printListFromTailToHead(head->next);
			}
			result.push_back(head->val);
		}
		return result;
	}
};

