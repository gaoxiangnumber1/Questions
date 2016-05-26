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

// Get the sum of individual number in this "num".
// e.g.: num = 1234, then return 10(= 1 + 2 + 3 + 4).
int GetSum(int num)
{
	int sum = 0;
	while(num)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

// Check whether we can reach cell[row][col]:
bool Check(int row, int col, bool *reach)
{
	// In matrix and have not reached:
	if((0 <= row && row <= g_rows - 1) && (0 <= col && col <= g_cols - 1) &&
	        (GetSum(row) + GetSum(col) <= g_threshold) &&
	        reach[row * g_cols + col] == false)
	{
		return true;
	}
	return false;
}

int Backtrack(int row, int col, bool *reach)
{
	int result = 0;
	if(Check(row, col, reach))
	{
		reach[row * g_cols + col] = true;
		result = 1 +
		         Backtrack(row - 1, col, reach) +
		         Backtrack(row + 1, col, reach) +
		         Backtrack(row, col - 1, reach) +
		         Backtrack(row, col + 1, reach);
	}
	return result;
}

int movingCount(int threshold, int rows, int cols)
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
	int cell_number = rows * cols;
	bool reach[cell_number];
	for(int index = 0; index < cell_number; ++index)
	{
		reach[index] = false;
	}

	// Backtrack this matrix from (0, 0)
	return Backtrack(0, 0, reach);
}

int main()
{
	while(1)
	{
		int threshold, rows, cols;
		cin >> threshold >> rows >> cols;
		cout << Fun(threshold, rows, cols) << "\n";
	}

	return 0;
}
