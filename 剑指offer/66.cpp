/*
------------------------------Function Test Data------------------------------
normal string

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
NULL pointer || rows <= 0 || cols <= 0
*/

#include <iostream>
using namespace std;

bool Backtrack(char *matrix, int rows, int cols, int row, int col,
               char* str, int &match_length, bool *visit)
{
	// Finish matching:
	if(str[match_length] == 0)
	{
		return true;
	}

	int index = row * cols + col;  // Match position.
	bool match = false;
	if((0 <= row && row <= rows) && (0 <= col && col <= cols)  // In bound.
	        && matrix[index] == str[match_length] // This char match.
	        && visit[index] == false  /* Not visit yet.*/)
	{
		++match_length;  // Match next char.
		visit[index] = true;  // Have visited.

		// Match next char in 4 directions:
		match = Backtrack(matrix, rows, cols, row - 1, col, str, match_length, visit)
		        || Backtrack(matrix, rows, cols, row + 1, col, str, match_length, visit)
		        || Backtrack(matrix, rows, cols, row, col - 1, str, match_length, visit)
		        || Backtrack(matrix, rows, cols, row, col + 1, str, match_length, visit);

		if(match == false)  // Return state to the caller.
		{
			--match_length;
			visit[index] = false;
		}
	}
	return match;
}

bool hasPath(char *matrix, int rows, int cols, char *str)
{
	// Negative data:
	if(!matrix || !str || rows <= 0 || cols <= 0)
	{
		return false;
	}

	int char_amount = rows * cols;
	// Boolean array to indicate which position we have visited.
	bool visit[char_amount];
	// We haven't visited any position at the very begin(false):
	for(int index = 0; index < char_amount; ++index)
	{
		visit[index] = false;
	}

	int match_length = 0;  // Indicate the amount of chars that have matched.
	for(int row = 0; row < rows; ++row)  // Start match from every char.
	{
		for(int col = 0; col < cols; ++col)
		{
			if(Backtrack(matrix, rows, cols, row, col, str, match_length, visit))  // Match core
			{
				return true;
			}
		}
	}
	// Not find match string.
	return false;
}

int main()
{
	while(1)
	{

	}

	return 0;
}
