/*
------------------------------Function Test Data------------------------------
rows > 0 && cols > 0 && threshold >= 0

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
rows <= 0 || cols <= 0 || threshold < 0
*/

#include <iostream>
using namespace std;

// We don't need pass the following 3 parameters when checking.
int g_rows = 0, g_cols = 0, g_threshold = 0;

void Backtrack(int row, int col, bool reach[][])
{
	if(Check(row, col))
	{
		reach[row][col] = true;
		Backtrack(row - 1, col);
		Backtrack(row + 1, col);
		Backtrack(row, col - 1);
		Backtrack(row, col + 1);
	}
}

bool Check(int row, int col)
{
	// In matrix:
	if((0 =< row && row <= g_rows - 1) && (0 =< col && col <= g_cols - 1))
	{
		// Check sum:
	}
}

int Fun(int threshold, int rows, int cols)
{
	// Negative data:
	if(rows <= 0 || cols <= 0 || threshold < 0)
	{
		return 0;
	}

	// Assign to global variable:
	g_rows = rows;
	g_cols = cols;
	g_threshold = threshold;

	// Use this array to count how many cells that we can reach:
	bool reach[rows][cols];
	for(int row = 0; row < rows; ++row)
	{
		for(int col = 0; col < cols; ++col)
		{
			reach[row][col] = true;
		}
	}

	// Backtrack this matrix from (0, 0)
	Backtrack(0, 0, reach);

	// Count cells number:
	int result = 0;
	for(int row = 0; row < rows; ++row)
	{
		for(int col = 0; col < cols; ++col)
		{
			if(reach[row][col] == true)
			{
				++result;
			}
		}
	}

	return result;
}

int main()
{
	while(1)
	{

	}

	return 0;
}
