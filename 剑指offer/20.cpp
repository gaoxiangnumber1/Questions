/*
------------------------------Function Test Data------------------------------
normal matrix

---------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
null pointer

*/
#include<vector>
#include<iostream>
using namespace std;

vector<int> Print(vector<vector<int> > matrix)
{
	int total_row = matrix.size();
	int total_column = total_row > 0 ? matrix[0].size() : 0;
	// negative data
	if(total_row <= 0 || total_column <= 0)
	{
		return vector<int>();
	}
	vector<int> result;
	int start = 0;  // we print each circle begin from [start][start], so start begin from 0.
	// "total_row - 2 * start" is the number of unprinted rows,
	// only if this number is positive, can we continue printing.
	// same as "total_column - 2 * start > 0"
	while(total_row - 2 * start > 0 && total_column - 2 * start > 0)
	{

		// finish printing one circle
		++start;
	}

	return result;
}

int main()
{
	vector<vector<int>> matrix = {{1, 2, 3}, {5, 6, 7}, {9, 10, 11}, {13, 14, 15},{17, 18, 19}};
	Print(matrix);

	return 0;
}
