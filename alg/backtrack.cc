#include "../common_system_header.h"

////////////////////////////////////////////
const int kQueenKindNumber = 3;
const int kMaxQueenNumber = 50;
// [0][column]: false if no queen in this column; otherwise true.
// [1][row + column] and [2][row - column + queen_number] are for 2 kinds of
// diagonals(/ and \): false if no queen in this diagonal; otherwise true.
// (row + column) & (row - column + queen_number) can be calculated by
// formula: y = k*x + b, which y(row), k(1 or -1), x(column) and b is a constant.
// Since row - column can be negative, so we add queen_number to
// guarantee that the index is nonnegative.
bool have_queen[kQueenKindNumber][kMaxQueenNumber * 2 + 10];
// position[row] = column: place queen in [row][column]. Used to print solution.
int position[kMaxQueenNumber];
int solution_number;
void PrintQueen(const int queen_number)
{
	for(int row = 0; row < queen_number; ++row)
	{
		for(int column = 0; column < queen_number; ++column)
		{
			printf("%c ", position[row] == column ? '1' : '0');
		}
		printf("\n");
	}
	printf("\n");
}
void NQueenBacktrack(int row, const int queen_number)
{
	if(row == queen_number)
	{
		//PrintQueen(queen_number);
		++solution_number;
	}
	else
	{
		for(int column = 0; column < queen_number; ++column)
		{
			if(have_queen[0][column] == true || have_queen[1][row + column] == true
				|| have_queen[2][row - column + queen_number] == true)
			{
				continue;
			}
			position[row] = column;
			have_queen[0][column] = have_queen[1][row + column] = have_queen[2][row - column
				+ queen_number] = true;
			NQueenBacktrack(row + 1, queen_number);
			have_queen[0][column] = have_queen[1][row + column] = have_queen[2][row - column
				+ queen_number] = false;
		}
	}
}
void NQueen(int queen_number)
{
	memset(have_queen, false, sizeof have_queen);
	solution_number = 0;
	NQueenBacktrack(0, queen_number);
}
void TestNQueen()
{
	printf("----------TestNQueen----------\n");
	const int kCaseNumber = 10;
	int queen_number[kCaseNumber] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int answer[kCaseNumber] = { 1, 0, 0, 2, 10, 4, 40, 92, 352, 724 };
	for(int index = 0; index < kCaseNumber; ++index)
	{
		NQueen(queen_number[index]);
		if(solution_number != answer[index])
		{
			printf("Case %d Not pass.\n", index);
		}
	}
	printf("All Case pass.\n");
}
////////////////////////////////////////////
const int kBoardSize = 9;
const int kPuzzleSize = kBoardSize * kBoardSize + 1;
bool row_flag[kBoardSize][kBoardSize];
bool column_flag[kBoardSize][kBoardSize];
bool area_flag[kBoardSize][kBoardSize];
void SetFlag(int row, int column, int area, int number, bool value)
{
	row_flag[row][number] = value;
	column_flag[column][number] = value;
	area_flag[area][number] = value;
}
bool IsPlaced(int row, int column, int area, int number)
{
	return row_flag[row][number] || column_flag[column][number] || area_flag[area][number];
}
void InitializeFlag(char (&board)[kBoardSize][kBoardSize])
{
	memset(row_flag, false, sizeof row_flag);
	memset(column_flag, false, sizeof column_flag);
	memset(area_flag, false, sizeof area_flag);
	for(int row = 0; row < kBoardSize; ++row)
	{
		for(int column = 0; column < kBoardSize; ++column)
		{
			if(board[row][column] == '0')
			{
				continue;
			}
			int area = row / 3 * 3 + column / 3;
			int number = board[row][column] - '0' - 1;
			SetFlag(row, column, area, number, true);
		}
	}
}
bool SudokuBacktrack(char (&board)[kBoardSize][kBoardSize], int row, int column)
{
	if(row >= kBoardSize)
	{
		return true;
	}
	if(column >= kBoardSize)
	{
		return SudokuBacktrack(board, row + 1, 0);
	}
	if(board[row][column] != '0')
	{
		return SudokuBacktrack(board, row, column + 1);
	}

	int area = row / 3 * 3 + column / 3;
	for(int number = 0; number < kBoardSize; ++number)
	{
		if(IsPlaced(row, column, area, number) == true)
		{
			continue;
		}
		board[row][column] = static_cast<char>('0' + number + 1);
		SetFlag(row, column, area, number, true);
		if(SudokuBacktrack(board, row, column + 1) == true)
		{
			return true;
		}
		board[row][column] = '0';
		SetFlag(row, column, area, number, false);
	}
	return false;
}
void Sudoku(char *puzzle)
{
	char board[kBoardSize][kBoardSize];
	for(int row = 0; row < kBoardSize; ++row)
	{
		for(int column = 0; column < kBoardSize; ++column)
		{
			board[row][column] = puzzle[row * kBoardSize + column];
		}
	}
	InitializeFlag(board);
	if(SudokuBacktrack(board, 0, 0) == true)
	{
		for(int row = 0; row < kBoardSize; ++row)
		{
			for(int column = 0; column < kBoardSize; ++column)
			{
				puzzle[row * kBoardSize + column] = board[row][column];
			}
		}
		return;
	}
	*puzzle = 0;
}
void TestSudoku()
{
	printf("----------TestSudoku----------\n");
	const int kCaseNumber = 3;
	char sudoku_puzzle[kCaseNumber][kPuzzleSize] = {
		"000000010400000000020000000000050407008000300001090000300400200050100000000806000",
		"000000010400000000020000000000050407008000300001090000300400200050100000000806005",
		"693784512487512936125963874932651487568247391741398625319475268856129743274836159", };
	char sudoku_answer[kCaseNumber][kPuzzleSize] = {
		"693784512487512936125963874932651487568247391741398625319475268856129743274836159", "\0",
		"693784512487512936125963874932651487568247391741398625319475268856129743274836159", };
	for(int index = 0; index < kCaseNumber; ++index)
	{
		Sudoku(sudoku_puzzle[index]);
		if(strcmp(sudoku_puzzle[index], sudoku_answer[index]) != 0)
		{
			printf("Case %d Not pass.\n", index);
		}
	}
	printf("All Case pass.\n");
}
////////////////////////////////////////////
void PrintByPermutation(string &num, int digit_number, int now_digit_number,
	int &significant_digit_number, int &value)
{
	if(now_digit_number == digit_number)
	{
		assert(atoi(&num[digit_number - significant_digit_number]) == value++);
		if(value - 1 == pow(10, significant_digit_number) - 1)
		{
			++significant_digit_number;
		}
		return;
	}
	for(char ch = '0'; ch <= '9'; ++ch)
	{
		num[now_digit_number] = ch;
		PrintByPermutation(num, digit_number, now_digit_number + 1, significant_digit_number,
			value);
	}
}
void PrintOneToMaxNDigit(int digit_number)
{
	if(digit_number <= 0)
	{
		return;
	}
	string num(digit_number, 0);
	int significant_digit_number = 1, value = 0;
	PrintByPermutation(num, digit_number, 0, significant_digit_number, value);
}
void TestPrintOneToMaxNDigit()
{
	printf("----------TestPrintOneToMaxNDigit----------\n");
	for(int digit_number = -1; digit_number <= 6; ++digit_number)
	{
		PrintOneToMaxNDigit(digit_number);
	}
	printf("All case pass.\n");
}
////////////////////////////////////////////
void StringPermutationMain(string &str, int first, int last, vector<string> &result) // [)
{
	if(first == last) // End recursive
	{
		result.push_back(str);
		return;
	}
	for(int index = first; index < last; ++index)
	{
		if(index != first && str[first] == str[index]) // Not swap repeated data.
		{
			// continue; If require.
		}
		swap(str[first], str[index]);
		StringPermutationMain(str, first + 1, last, result);
		swap(str[first], str[index]); // Pass by reference! Need recover.
	}
}
vector<string> StringPermutation(string str)
{
	if(str.size() <= 0) // Negative test.
	{
		return vector<string>();
	}
	vector<string> result;
	StringPermutationMain(str, 0, static_cast<int>(str.size()), result);
	return result;
}
void TestStringPermutation()
{
	printf("-----TestStringPermutation-----\n");
	vector<string> str { "", "a", "ab", "abc" };
	vector<vector<string>> answer { {}, { "a" }, { "ab", "ba" }, { "abc", "acb", "bac", "bca",
		"cba", "cab" } };
	for(int i = 0; i < static_cast<int>(str.size()); ++i)
	{
		AssertVectorData(answer[i], StringPermutation(str[i]));
	}
	printf("All case pass.\n");
}
//////////////////////////////////////////////////////////////////////
void StringSubsetMain(const string &str, int first, int last, bool *exist, vector<string> &result)
{
	if(first == last)
	{
		string tmp;
		for(int index = 0; index < last; ++index)
		{
			exist[index] == true ? tmp += str[index] : tmp;
		}
		result.push_back(tmp);
		return;
	}
	exist[first] = true;
	StringSubsetMain(str, first + 1, last, exist, result);
	exist[first] = false;
	StringSubsetMain(str, first + 1, last, exist, result);
}
vector<string> StringSubset(const string &str)
{
	if(str.size() <= 0) // Negative test
	{
		return vector<string> { "" };
	}
	bool exist[str.size()];
	vector<string> result;
	StringSubsetMain(str, 0, static_cast<int>(str.size()), exist, result);
	return result;
}
void TestStringSubset()
{
	printf("-----TestStringSubset-----\n");
	vector<string> str { "", "a", "ab", "abc" };
	vector<set<string>> answer { { "" }, { "", "a" }, { "", "a", "b", "ab" }, { "", "a", "b", "c",
		"ab", "ac", "bc", "abc" } };
	for(int i = 0; i < static_cast<int>(str.size()); ++i)
	{
		vector<string> vec = StringSubset(str[i]);
		assert(vec.size() == answer[i].size());
		for(int j = 0; j < static_cast<int>(vec.size()); ++j)
		{
			set<string>::iterator it = answer[i].find(vec[j]);
			assert(it != answer[i].end() && *it == vec[j]);
		}
	}
	printf("All case pass.\n");
}
//////////////////////////////////////////////////////////////////////
int main()
{
	TestPrintOneToMaxNDigit();
	TestStringPermutation();
	TestStringSubset();
}
