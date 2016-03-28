/*
------------------------------Function Test Data------------------------------
normal

---------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
null pointer

*/

#include<queue>
#include<vector>
#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
};

vector<int> Print(TreeNode *root)
{
	vector<int> result;
	queue<TreeNode *> print;

	if(!root)
	{
		return result;
	}

	print.push(root);
	while(!print.empty())
	{
		TreeNode *temp = print.front();
		print.pop();
		result.push_back(temp->val);

		if(temp->left)
		{
			print.push(temp->left);
		}
		if(temp->right)
		{
			print.push(temp->right);
		}
	}

	return result;
}

int main()
{

	return 0;
}
