/*
------------------------------Function Test Data------------------------------
normal tree

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
null pointer
*/

#include <vector>
#include <list>
using namespace std;

struct Node
{
	int data_;
	vector<Node *> next_;  // Each parent node may have many sub-nodes
};

bool GetPath(Node *node, Node *target, list<Node *>& path)
{
	if(!node)  // Null pointer
	{
		return false;
	}

	if(node == target)  // Find the target node
	{
		return true;
	}

	// Search in node's children:
	path.push_back(node);
	int length = node->next_.size();
	bool found = false;
	for(int index = 0; index < length && !found; ++index)
	{
		found = GetPath(node->next_[index], target, path);
	}

	if(!found)  // Not find in the children, remove this parent node from path
	{
		path.pop_back();
		return false;
	}

	return true;  // Find in the children nodes.
}

Node *GetLastCommonNode(list<Node *> &path1, list<Node *> &path2)
{
	Node *result;

	// Traverse the two lists:
	list<Node *>::iterator it1 = path1.begin(), it2 = path2.begin();
	while(it1 != path1.end() && it2 != path2.end())
	{
		if(*it1 == *it2)
		{
			result = *it1;
		}
		++it1;
		++it2;
	}

	return result;
}

Node *GetLastCommonParent(Node *root, Node *node1, Node *node2)
{
	// Negative data:
	if(!root || !node1 || !node2)
	{
		return 0;
	}

	// Get two paths:
	list<Node *> path1, path2;
	GetPath(root, node1, path1);
	GetPath(root, node2, path2);

	// Get the last common parent node:
	return GetLastCommonNode(path1, path2);
}

int main()
{
	Node *root = 0, *node1 = 0, *node2 = 0;
	GetLastCommonParent(root, node1, node2);

	return 0;
}
