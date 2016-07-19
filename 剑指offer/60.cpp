/*
------------------------------Function Test Data------------------------------
Normal binary tree

--------------------------------Edge Test Data--------------------------------
None

------------------------------Negative Test Data------------------------------
NULL pointer
*/

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > Print(TreeNode* pRoot)
{
	vector<vector<int> > result;
	queue<TreeNode *> print;

	// Negative data:
	if(pRoot == NULL)
	{
		return result;
	}

	vector<int> one_level;  // Use to store one level's nodes
	print.push(pRoot);
	// unprinted_nodes: number of unprinted nodes in current level.
	// next_level_nodes: number of next level nodes.
	int unprinted_nodes = 1, next_level_nodes = 0;

	while(print.empty() == false)
	{
		TreeNode *temp = print.front();
		print.pop();
		--unprinted_nodes;
		// Print:
		one_level.push_back(temp->val);

		if(temp->left)
		{
			print.push(temp->left);
			++next_level_nodes;
		}
		if(temp->right)
		{
			print.push(temp->right);
			++next_level_nodes;
		}
		// Check whether we have printed all current level nodes:
		if(unprinted_nodes == 0)
		{
			result.push_back(one_level);
			one_level.clear();  // Clear this level's nodes.
			unprinted_nodes = next_level_nodes;
			next_level_nodes = 0;
		}
	}
	return result;
}
