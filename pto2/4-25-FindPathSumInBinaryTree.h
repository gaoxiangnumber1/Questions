eclipse ../ds/binary_node.cc
Matrix FindPathSumInBinaryTree(BinaryNode<T> *root, int expect_sum)

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
	using Matrix = vector<vector<int>>;
	void FindPathDFS(TreeNode *node, vector<int> &path, int &sum, const int &expect_sum,
		Matrix &result)
	{
		path.push_back(node->val);
		sum += node->val;
		if(node->left == nullptr && node->right == nullptr && sum == expect_sum)
		{
			result.push_back(path);
		}
		node->left != nullptr ? FindPathDFS(node->left, path, sum, expect_sum, result) : void();
		node->right != nullptr ? FindPathDFS(node->right, path, sum, expect_sum, result) : void();
		path.pop_back();
		sum -= node->val;
	}
	Matrix FindPath(TreeNode *root, int expect_sum)
	{
		if(root == nullptr) // Negative test
		{
			return Matrix();
		}
		vector<int> path;
		int sum = 0;
		Matrix result;
		FindPathDFS(root, path, sum, expect_sum, result);
		return result;
	}
};
