/*
------------------------------Function Test Data------------------------------
normal

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
empty sequence

*/

#include<vector>
#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
};
？？？？？？？？？？？
void DFS(vector<vector<int> > &result, vector<int> &path, TreeNode *root, int expectNumber, int sum)
{
	path.push_back(root->val);
	sum += root->val;

	if(!root->left && !root->right && sum == expectNumber)  // find a path
	{
		result.push_back(path);
	}
	else if(root->left)
	{
		DFS(result, path, root->left, expectNumber, sum);
	}
	else if(root->right)
	{
		DFS(result, path, root->right, expectNumber, sum);
	}
	// we must delete this root's element before returning to caller
	path.pop_back();
}

vector<vector<int> > FindPath(TreeNode *root, int expectNumber)
{
	vector<vector<int> > result;
	vector<int> path;
	int sum = 0;

	// negative data:
	if(!root)
	{
		return result;
	}
	DFS(result, path, root, expectNumber, sum);
	return result;
}

int main()
{

	return 0;
}
