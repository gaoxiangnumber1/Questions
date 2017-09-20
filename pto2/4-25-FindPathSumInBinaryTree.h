../ds/binary_tree.cc
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
		path.push_back(node->data_);
		sum += node->data_;
		if(node->left_ == nullptr && node->right_ == nullptr && sum == expect_sum)
		{
			result.push_back(path);
		}
		node->left_ != nullptr ? FindPathDFS(node->left_, path, sum, expect_sum, result) : void();
		node->right_ != nullptr ? FindPathDFS(node->right_, path, sum, expect_sum, result) : void();
		path.pop_back();
		sum -= node->data_;
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
