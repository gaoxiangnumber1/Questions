#include "../common_system_header.h"
//////////////////////////////////////////////////////////////////////
bool FindInTwoDimensionArray(const vector<vector<int>> &data, int target)
{
	if(data.size() <= 0) // Negative test.
	{
		return false;
	}
	int total_row = static_cast<int>(data.size()), total_col =
		static_cast<int>(data[0].size());
	for(int row = 0, col = total_col - 1; row < total_row && col >= 0;)
	{
		if(data[row][col] == target)
		{
			return true;
		}
		data[row][col] < target ? ++row : --col;
	}
	return false;
}
void TestFindInTwoDimensionArray()
{
	printf("-----TestFindInTwoDimensionArray-----\n");
	// Negative TestFindInTwoDimensionArray: empty two dimension array and arbitrary integer.
	// Function TestFindInTwoDimensionArray: nonempty two dimension array and arbitrary integer.
	// 		True: min(-16), between(2, 3), max(30). False: min(-17), between(6, 12), max(31).
	vector<vector<int>> good_vec = { { -16, -7, 0, 8 }, { -15, 3, 10, 20 }, { 1, 4,
		13, 25 }, { 2, 5, 19, 30 } };
	vector<vector<int>> bad_vec;
	vector<vector<int>> test_vec = { { -16, 2, 3, 30 }, { -17, 6, 12, 31 } };
	for(int row = 0; row < static_cast<int>(test_vec.size()); ++row)
	{
		for(int col = 0; col < static_cast<int>(test_vec[row].size()); ++col)
		{
			if(FindInTwoDimensionArray(good_vec, test_vec[row][col]) != (row == 0)
				|| FindInTwoDimensionArray(bad_vec, test_vec[row][col]) != false)
			{
				printf("Case not pass: target = %d\n", test_vec[row][col]);
				assert(0);
			}
		}
	}
	printf("All case pass.\n");
}
//////////////////////////////////////////////////////////////////////
inline bool IsEven(int num)
{
	return (num & 1) == 0;
}
void ReOrderArray(vector<int> &vec)
{
	if(vec.size() <= 0) // Negative test.
	{
		return;
	}
	int length = static_cast<int>(vec.size());
	for(int left = 0, right = length - 1; left < right;)
	{
		for(; left < length && IsEven(vec[left]) == false; ++left)
			;
		for(; right >= 0 && IsEven(vec[right]) == true; --right)
			;
		left < right ? swap(vec[left], vec[right]) : void();
	}
}
void TestReOrderArray()
{
	printf("-----TestReOrderArray-----\n");
	vector<vector<int>> test = { {},/*Negative test*/
	{ 0 }, { 1 }, { 1, 3, 5, 7, 9 }, { 0, 2, 4, 6, 8 }, /*Edge test*/
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 }, { 1, 3, 5, 7,
		9, 0, 2, 4, 6, 8 }/*Function test*/};
	for(int i = 0; i < static_cast<int>(test.size()); ++i)
	{
		ReOrderArray(test[i]);
		int j = 0, length = static_cast<int>(test[i].size());
		for(; j < length && (test[i][j] & 1) == 1; ++j)
			;
		for(; j < length; assert((test[i][j] & 1) == 0), ++j)
			;
	}
	printf("All case pass.\n");
}
//////////////////////////////////////////////////////////////////////
Row ClockwisePrintMatrix(const Matrix &matrix)
{
	if(matrix.size() <= 0) // Negative test
	{
		return Row();
	}
	int total_row = static_cast<int>(matrix.size()), total_col =
		static_cast<int>(matrix[0].size());
	int total_circle = (min(total_row, total_col) + 1) / 2;
	Row seq;
	for(int circle = 1; circle <= total_circle; ++circle)
	{
		int row = circle - 1, col = circle - 1;
		for(; col <= total_col - circle; seq.push_back(matrix[row][col]), ++col)
			;
		for(--col, ++row; row <= total_row - circle;
			seq.push_back(matrix[row][col]), ++row)
			;
		for(--row, --col; circle - 1 != total_row - circle && col >= circle - 1;
			seq.push_back(matrix[row][col]), --col)
			;
		for(++col, --row; circle - 1 != total_col - circle && row > circle - 1;
			seq.push_back(matrix[row][col]), --row)
			;
	}
	return seq;
}
void TestClockwisePrintMatrix()
{
	printf("-----TestClockwisePrintMatrix-----\n");
	vector<Matrix> test { { {} },/* Negative test */
	{ { 1 } },/*only_one_element*/
	{ { 1, 2, 3, 4 } },/*only_one_row*/
	{ { 1 }, { 2 }, { 3 }, { 4 } },/*only_one_col*//* Edge test */
	{ { 1, 2 }, { 3, 4 } }, /*square_4*/
	{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } }, /*square_9*/
	{ { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } }, /*square_16*/
	{ { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } },/*rectangle_3_multi_4*/
	{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } }/*rectangle_4_multi_3*//*Function test*/
	};
	vector<Row> answer = { {}, { 1 }, { 1, 2, 3, 4 }, { 1, 2, 3, 4 }, { 1, 2, 4, 3 },
		{ 1, 2, 3, 6, 9, 8, 7, 4, 5 }, { 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6,
			7, 11, 10 }, { 1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7 }, { 1, 2, 3, 6, 9,
			12, 11, 10, 7, 4, 5, 8 } };
	for(int i = 0; i < static_cast<int>(answer.size()); ++i)
	{
		Row seq = ClockwisePrintMatrix(test[i]);
		AssertVectorData(seq, answer[i]);
	}
	printf("All case pass.\n");
}
//////////////////////////////////////////////////////////////////////
int Partition(vector<int> &arr, int first, int last)
{
	int pivot = arr[first], divide = first + 1;
	for(int index = first + 1; index < last; ++index)
	{
		if(arr[index] <= pivot)
		{
			arr[index] != arr[divide] ? swap(arr[index], arr[divide]) : void();
			++divide;
		}
	}
	arr[--divide] != arr[first] ? swap(arr[divide], arr[first]) : void();
	return divide;
}
int FindKthBigNumberInArray(vector<int> arr, int k)
{
	int length = static_cast<int>(arr.size()), target_divide = length - k;
	for(int first = 0, last = length, divide = -1;
		(divide = Partition(arr, first, last)) != target_divide;
		divide < target_divide ? first = divide + 1 : last = divide)
		;
	return arr[target_divide];
}
int CheckMoreThanHalfNumber(int num, const vector<int> &arr)
{
	int cnt = 0, length = static_cast<int>(arr.size());
	for(int index = 0; index < length; ++index)
	{
		arr[index] == num ? ++cnt : cnt;
	}
	return cnt <= length / 2 ? 0 : num;
}
int FindMoreThanHalfNumberInArrayON2(const vector<int> &arr)
{
	if(arr.size() <= 0) // Negative test
	{
		return 0;
	}
	return CheckMoreThanHalfNumber(
		FindKthBigNumberInArray(arr, static_cast<int>(arr.size()) / 2 + 1), arr);
}
int FindMoreThanHalfNumberInArrayON(const vector<int> &arr)
{
	if(arr.size() <= 0) // Negative test
	{
		return 0;
	}
	int num = 0, cnt = 0;
	for(int index = 0; index < static_cast<int>(arr.size()); ++index)
	{
		cnt == 0 ? num = arr[index] : num;
		num == arr[index] ? ++cnt : --cnt;
	}
	return CheckMoreThanHalfNumber(num, arr);
}
void TestFindMoreThanHalfNumberInArray()
{
	printf("-----TestFindMoreThanHalfNumberInArray-----\n");
	vector<vector<int>> arr { {}, { 1, 2 }, { 1, 2, 3 }, { 2, 1, 2, 3 }, { 2, 2, 2,
		1, 3, 4, 5 }, /*Negative test*/{ 2 }, { 2, 2 }, { 1, 2, 3, 2, 4, 2, 2, 2 }, {
		2, 2, 2, 2, 2, 2, 2, 2 }/*Function test*/};
	vector<int> answer { 0, 0, 0, 0, 0, 2, 2, 2, 2 }, my_answer1, my_answer2;
	for(int index = 0; index < static_cast<int>(arr.size()); ++index)
	{
		my_answer1.push_back(FindMoreThanHalfNumberInArrayON2(arr[index]));
		my_answer2.push_back(FindMoreThanHalfNumberInArrayON(arr[index]));
	}
	AssertVectorData(answer, my_answer1);
	AssertVectorData(answer, my_answer2);
	printf("All case pass.\n");
}
//////////////////////////////////////////////////////////////////////
int FindKthBigNumberInArrayRef(vector<int> &arr, int k)
{
	int length = static_cast<int>(arr.size()), target_divide = length - k;
	for(int first = 0, last = length, divide = -1;
		(divide = Partition(arr, first, last)) != target_divide;
		divide < target_divide ? first = divide + 1 : last = divide)
		;
	return arr[target_divide];
}
vector<int> MinKON2(const vector<int> &arr, int k)
{
	int length = static_cast<int>(arr.size());
	if(length <= 0 || k < 1 || k > length) // Negative test
	{
		return vector<int>();
	}
	vector<int> arr_copy(arr);
	FindKthBigNumberInArrayRef(arr_copy, length - k + 1);
	return vector<int>(arr_copy.begin(), arr_copy.begin() + k);
}
vector<int> MinKONLogN(const vector<int> &arr, int k)
{
	int length = static_cast<int>(arr.size());
	if(length <= 0 || k < 1 || k > length) // Negative test
	{
		return vector<int>();
	}
	priority_queue<int> pq(arr.begin(), arr.begin() + k);
	for(int index = k; index < length; ++index)
	{
		pq.top() > arr[index] ? (pq.pop(), pq.push(arr[index])) : void();
	}
	vector<int> result;
	for(; pq.empty() == false; pq.pop())
	{
		result.push_back(pq.top());
	}
	return result;
}
void TestMinK()
{
	printf("-----TestMinK-----\n");
	vector<int> arr { 0, 2, 4, 6, 8, 9, 7, 5, 3, 1 };
	vector<int> arr_dup { 0, 2, 2, 6, 8, 9, 7, 5, 3, 2 };
	vector<int> k { 0, 11, 1, 3, 5, 10 };
	vector<set<int>> answer { {}, {}, { 0 }, { 0, 1, 2 }, { 0, 1, 2, 3, 4 }, { 0, 2,
		4, 6, 8, 9, 7, 5, 3, 1 } };
	vector<multiset<int>> answer_dup { {}, {}, { 0 }, { 0, 2, 2 }, { 0, 2, 2, 2, 3 },
		{ 0, 2, 2, 6, 8, 9, 7, 5, 3, 2 } };
	for(int i = 0; i < static_cast<int>(k.size()); ++i)
	{
		vector<int> my_answer1 = MinKON2(arr, k[i]);
		vector<int> my_answer2 = MinKONLogN(arr, k[i]);
		vector<int> my_answer_dup1 = MinKON2(arr_dup, k[i]);
		vector<int> my_answer_dup2 = MinKONLogN(arr_dup, k[i]);
		assert(answer[i].size() == my_answer1.size());
		assert(answer[i].size() == my_answer2.size());
		assert(answer_dup[i].size() == my_answer_dup1.size());
		assert(answer_dup[i].size() == my_answer_dup2.size());
		for(int j = 0; j < static_cast<int>(my_answer1.size()); ++j)
		{
			set<int>::iterator it1 = answer[i].find(my_answer1[j]);
			assert(it1 != answer[i].end() && *it1 == my_answer1[j]);
			set<int>::iterator it2 = answer[i].find(my_answer2[j]);
			assert(it2 != answer[i].end() && *it2 == my_answer2[j]);
			multiset<int>::iterator it_dup1 = answer_dup[i].find(my_answer_dup1[j]);
			assert(it_dup1 != answer_dup[i].end() && *it_dup1 == my_answer_dup1[j]);
			multiset<int>::iterator it_dup2 = answer_dup[i].find(my_answer_dup2[j]);
			assert(it_dup2 != answer_dup[i].end() && *it_dup2 == my_answer_dup2[j]);
		}
	}
	printf("All case pass.\n");
}
//////////////////////////////////////////////////////////////////////
int main()
{
	TestFindInTwoDimensionArray();
	TestReOrderArray();
	TestClockwisePrintMatrix();
	TestFindMoreThanHalfNumberInArray();
	TestMinK();
}
