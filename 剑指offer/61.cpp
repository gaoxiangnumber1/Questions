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

vector<vector<int> > Print(TreeNode *pRoot)
{
	vector<vector<int> > result;
	// Negative data:
	if(pRoot == NULL)
	{
		return result;
	}

	vector<int> one_level;  // Store one level's all nodes.
	// One stores the current level's nodes; the other stores the next level.
	stack<TreeNode *> nodes_stack[2];
	int current = 0, next = 1;  // Use to index nodes_stack
	nodes_stack[current].push(pRoot);

	while(nodes_stack[current].empty() == false)
	{
		TreeNode *node = nodes_stack[current].top();
		nodes_stack[current].pop();
		one_level.push_back(node->val);

		// Add sub-nodes to next stack:
		if(current == 0)  // First left child, second right child.
		{
			if(node->left)
			{
				nodes_stack[next].push(node->left);
			}
			if(node->right)
			{
				nodes_stack[next].push(node->right);
			}
		}
		else  // First right child, second left child.
		{
			if(node->right)
			{
				nodes_stack[next].push(node->right);
			}
			if(node->left)
			{
				nodes_stack[next].push(node->left);
			}
		}

		if(nodes_stack[current].empty())  // Finish print this level's nodes
		{
			result.push_back(one_level);
			one_level.clear();
			current = 1 - current;  // Exchange 2 stacks.
			next = 1- next;
		}
	}
	return result;
}
