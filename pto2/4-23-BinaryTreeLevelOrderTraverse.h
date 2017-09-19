../ds/binary_tree.cc
vector<T> LevelOrder()

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL)
	{
	}
};
class Solution
{
public:
	vector<int> PrintFromTopToBottom(TreeNode *root)
	{
		if(root == nullptr) // Negative test
		{
			return vector<int>();
		}
		queue<TreeNode*> my_queue;
		vector<int> vec;
		my_queue.push(root);
		while(my_queue.empty() == false)
		{
			TreeNode *node = my_queue.front();
			my_queue.pop();
			vec.push_back(node->val);
			node->left != nullptr ? my_queue.push(node->left) : void();
			node->right != nullptr ? my_queue.push(node->right) : void();
		}
		return vec;
	}
};
