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

vector<vector<int> > result;  // global variable

void DFS(vector<int> &path, TreeNode *root, int expectNumber, int sum)
{
	path.push_back(root->val);
	sum += root->val;

	if(!(root->left) && !(root->right) && sum == expectNumber)  // find a path
	{
		result.push_back(path);
	}
	else  // NOTE: the next condition can be all satisfied!!!!
	{
		if(root->left)
		{
			DFS(path, root->left, expectNumber, sum);
		}
		if(root->right)
		{
			DFS(path, root->right, expectNumber, sum);
		}
	}
	// we must delete this root's element before returning to caller
	path.pop_back();
}

vector<vector<int> > FindPath(TreeNode *root, int expectNumber)
{
	vector<int> path;
	int sum = 0;

	// negative data:
	if(!root)
	{
		return result;
	}
	DFS(path, root, expectNumber, sum);
	return result;
}

int main()
{

	return 0;
}
