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

bool Solution(vector<int> sequence, int first, int last)  // verify scope: sequence[first, last]
{
	int root = sequence[last];
	int left_index = first;
	for(; left_index < last; ++left_index)
	{
		if(sequence[left_index] > root)  // now, sequence[left_index] belongs to right subtree
		{
			break;
		}
	}

	// now, left_index = last or sequence[left_index] > root
	int right_index = left_index;
	for(; right_index < last; ++right_index)
	{
		if(sequence[right_index] < root)  // Error: this sequence is not the postorder of BST
		{
			return false;
		}
	}

	// now, we verify each subtree recursively:
	bool left = true;
	if(left_index > first)
	{
		left = Solution(sequence, first, left_index - 1);  // sequence[first, left_index - 1] is the left subtree
	}
	bool right = true;
	if(left_index < last)
	{
		right = Solution(sequence, left_index, last - 1);  // sequence[left_index, last - 1] is the right subtree
	}
	return left && right;
}

bool VerifySequenceOfBST(vector<int> sequence)
{
	int length = sequence.size();

	if(length <= 0)
	{
		return false;
	}

	return Solution(sequence, 0, length - 1);
}

int main()
{

	return 0;
}
