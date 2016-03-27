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

vector<int> printMatrix(vector<vector<int> > matrix)
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
		int end_row = total_row - 1 - start;  // the last row we print
		int end_column = total_column - 1 - start;  // the last column we print

		// left -> right, no precondition
		for(int index = start; index <= end_column; ++index)
		{
			result.push_back(matrix[start][index]);
			cout << matrix[start][index] << endl;
		}
		// top -> down, only if there is at least 2 rows
		if(end_row > start)
		{
			for(int index = start + 1; index <= end_row; ++index)
			{
				result.push_back(matrix[index][end_column]);
				cout << matrix[index][end_column] << endl;
			}
		}
		// right -> left, only if there is at least 2 rows and 2 columns
		if(end_row > start && end_column > start)
		{
			for(int index = end_column - 1; index >= start; --index)
			{
				result.push_back(matrix[end_row][index]);
				cout << matrix[end_row][index] << endl;
			}
		}
		// down -> top, only if there is at least 3 rows and 2 columns
		if(end_row - start > 1 && end_column > start)
		{
			for(int index = end_row - 1; index >= start + 1; --index)
			{
				result.push_back(matrix[index][start]);
				cout << matrix[index][start] << endl;
			}
		}

		// finish printing one circle
		++start;
	}

	return result;
}

int main()
{
	vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16},{17, 18, 19, 20}};
	Print(matrix);

	return 0;
}
