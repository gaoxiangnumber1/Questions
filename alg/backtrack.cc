#include "../common_system_header.h"
////////////////////////////////////////////
const int kBoardSize = 9;
const int kPuzzleSize = kBoardSize * kBoardSize + 1;
bool row_flag[kBoardSize][kBoardSize];
bool column_flag[kBoardSize][kBoardSize];
bool area_flag[kBoardSize][kBoardSize];
void SetFlag(int row, int col, int area, int number, bool value)
{
	row_flag[row][number] = value;
	column_flag[col][number] = value;
	area_flag[area][number] = value;
}
bool IsPlaced(int row, int col, int area, int number)
{
	return row_flag[row][number] || column_flag[col][number] || area_flag[area][number];
}
void InitializeFlag(char (&board)[kBoardSize][kBoardSize])
{
	memset(row_flag, false, sizeof row_flag);
	memset(column_flag, false, sizeof column_flag);
	memset(area_flag, false, sizeof area_flag);
	for(int row = 0; row < kBoardSize; ++row)
	{
		for(int col = 0; col < kBoardSize; ++col)
		{
			if(board[row][col] == '0')
			{
				continue;
			}
			int area = row / 3 * 3 + col / 3;
			int number = board[row][col] - '0' - 1;
			SetFlag(row, col, area, number, true);
		}
	}
}
bool SudokuBacktrack(char (&board)[kBoardSize][kBoardSize], int row, int col)
{
	if(row >= kBoardSize)
	{
		return true;
	}
	if(col >= kBoardSize)
	{
		return SudokuBacktrack(board, row + 1, 0);
	}
	if(board[row][col] != '0')
	{
		return SudokuBacktrack(board, row, col + 1);
	}

	int area = row / 3 * 3 + col / 3;
	for(int number = 0; number < kBoardSize; ++number)
	{
		if(IsPlaced(row, col, area, number) == true)
		{
			continue;
		}
		board[row][col] = static_cast<char>('0' + number + 1);
		SetFlag(row, col, area, number, true);
		if(SudokuBacktrack(board, row, col + 1) == true)
		{
			return true;
		}
		board[row][col] = '0';
		SetFlag(row, col, area, number, false);
	}
	return false;
}
void Sudoku(char *puzzle)
{
	char board[kBoardSize][kBoardSize];
	for(int row = 0; row < kBoardSize; ++row)
	{
		for(int col = 0; col < kBoardSize; ++col)
		{
			board[row][col] = puzzle[row * kBoardSize + col];
		}
	}
	InitializeFlag(board);
	if(SudokuBacktrack(board, 0, 0) == true)
	{
		for(int row = 0; row < kBoardSize; ++row)
		{
			for(int col = 0; col < kBoardSize; ++col)
			{
				puzzle[row * kBoardSize + col] = board[row][col];
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
	char sudoku_puzzle[kCaseNumber][kPuzzleSize] =
		{
			"000000010400000000020000000000050407008000300001090000300400200050100000000806000",
			"000000010400000000020000000000050407008000300001090000300400200050100000000806005",
			"693784512487512936125963874932651487568247391741398625319475268856129743274836159", };
	char sudoku_answer[kCaseNumber][kPuzzleSize] =
		{
			"693784512487512936125963874932651487568247391741398625319475268856129743274836159",
			"\0",
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
		PrintByPermutation(num, digit_number, now_digit_number + 1,
			significant_digit_number, value);
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
void StringPermutationMain(string str, int first, int last, vector<string> &result) // [)
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
			continue;
		}
		swap(str[first], str[index]);
		StringPermutationMain(str, first + 1, last, result);
	}
}
vector<string> StringPermutation(const string &str)
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
	vector<vector<string>> answer { {}, { "a" }, { "ab", "ba" }, { "abc", "acb", "bac",
		"bca", "cab", "cba" } };
	for(int i = 0; i < static_cast<int>(str.size()); ++i)
	{
		AssertVectorData(answer[i], StringPermutation(str[i]));
	}
	printf("All case pass.\n");
}
//////////////////////////////////////////////////////////////////////
void StringSubsetMain(const string &str, int first, int last, bool *exist,
	vector<string> &result)
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
	vector<set<string>> answer { { "" }, { "", "a" }, { "", "a", "b", "ab" }, { "", "a",
		"b", "c", "ab", "ac", "bc", "abc" } };
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
void NQueenMain(int row, int queen_number, vector<int> &row_col, vector<bool> &col_exist,
	vector<bool> &pos_diag_exist, vector<bool> &neg_diag_exist, int &solution_cnt)
{
	if(row == queen_number)
	{
		++solution_cnt;
		return;
	}
	for(int col = 0; col < queen_number; ++col)
	{
		if(col_exist[col] == false && pos_diag_exist[row - col + queen_number] == false
			&& neg_diag_exist[row + col] == false)
		{
			row_col[row] = col;
			col_exist[col] = pos_diag_exist[row - col + queen_number] = neg_diag_exist[row
				+ col] = true;
			NQueenMain(row + 1, queen_number, row_col, col_exist, pos_diag_exist,
				neg_diag_exist, solution_cnt);
			col_exist[col] = pos_diag_exist[row - col + queen_number] = neg_diag_exist[row
				+ col] = false;
		}
	}
}
int NQueen(int queen_number)
{
	if(queen_number <= 0)
	{
		return 0;
	}
	vector<int> row_col(queen_number);
	vector<bool> col_exist(queen_number, false);
	vector<bool> pos_diag_exist(queen_number * 2, false);
	vector<bool> neg_diag_exist(queen_number * 2, false);
	int solution_cnt = 0;
	NQueenMain(0, queen_number, row_col, col_exist, pos_diag_exist, neg_diag_exist,
		solution_cnt);
	return solution_cnt;
}
void TestNQueen()
{
	printf("-----TestNQueen-----\n");
	vector<int> queen_number { -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> answer { 0, 0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724 };
	for(int index = 0; index < static_cast<int>(queen_number.size()); ++index)
	{
		assert(NQueen(queen_number[index]) == answer[index]);
	}
	printf("All Case pass.\n");
}
////////////////////////////////////////////
int main()
{
	TestPrintOneToMaxNDigit();
	TestStringPermutation();
	TestStringSubset();
	TestNQueen();
}
