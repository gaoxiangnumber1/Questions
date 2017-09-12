#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
using std::swap;
using std::vector;

///////////////////////////////////
int EuclidGreatestCommonDivisor(int big, int small)
{
	if(big < small)
	{
		swap(big, small);
	}
	while(small != 0)
	{
		int mod = big % small;
		big = small;
		small = mod;
	}
	return big;
}
void TestEuclidGreatestCommonDivisor()
{
	printf("----------TestEuclidGreatestCommonDivisor----------\n");
	const int kCaseNumber = 5;
	int num[kCaseNumber][2] = { { 100, 9 }, { 1, 55 }, { 11, 1254 }, { 55, 66 }, { 8, 9 } };
	int answer[kCaseNumber] = { 1, 1, 11, 11, 1 };
	for(int index = 0; index < kCaseNumber; ++index)
	{
		if(EuclidGreatestCommonDivisor(num[index][0], num[index][1]) != answer[index])
		{
			printf("Case %d Not pass.\n", index);
		}
	}
	printf("All case pass\n");
}
///////////////////////////////////
int FibonacciON(int n)
{
	if(n <= 1) // Negative and Edge test.
	{
		return (n <= 0 ? 0 : 1);
	}

	int fn1 = 1, fn2 = 0;
	for(int index = 2; index <= n; ++index)
	{
		int fn = fn1 + fn2;
		fn2 = fn1;
		fn1 = fn;
	}
	return fn1;
}
using Matrix = vector<vector<int>>;
Matrix MultiMatrix(const Matrix &lhs, const Matrix &rhs)
{
	assert(lhs[0].size() == rhs.size());
	int total_row = static_cast<int>(lhs.size());
	int total_cnt = static_cast<int>(rhs.size());
	int total_col = static_cast<int>(rhs[0].size());
	Matrix result(total_row, vector<int>(total_col, 0));
	for(int row = 0; row < total_row; ++row)
	{
		for(int col = 0; col < total_col; ++col)
		{
			for(int cnt = 0; cnt < total_cnt; ++cnt)
			{
				result[row][col] += lhs[row][cnt] * rhs[cnt][col];
			}
		}
	}
	return result;
}
Matrix MatrixQuickPower(const Matrix &base, int exp)
{
	assert(exp >= 0);
	Matrix result(base.size(), vector<int>(base[0].size(), 0));
	for(int index = 0; index < static_cast<int>(result.size()); ++index)
	{
		result[index][index] = 1;
	}
	Matrix tmp = base;
	for(; exp != 0; exp >>= 1)
	{
		exp & 1 ? result = MultiMatrix(result, tmp) : result;
		tmp = MultiMatrix(tmp, tmp);
	}
	return result;
}
int FibonacciOLogN(int n)
{
	if(n <= 1)
	{
		return (n <= 0 ? 0 : 1);
	}

	Matrix state = { { 1, 1 }, { 1, 0 } };
	return MatrixQuickPower(state, n - 1)[0][0];
}
// https://www.zhihu.com/question/29215494 Not memorize until need.
int FibonacciOLogN2(int n)
{
	if(n <= 1)
	{
		return (n <= 0 ? 0 : 1);
	}

	int x = 1, y = 1, a = 0, b = 1, tmp = 0;
	for(; n > 0; n >>= 1)
	{
		if(n & 1)
		{
			tmp = a * x + b * y;
			a = x * (b - a) + a * y;
			b = tmp;
		}
		tmp = 2 * x * y - x * x;
		y = x * x + y * y;
		x = tmp;
	}
	return a;
}
int FibonacciO1(int n)
{
	if(n <= 1)
	{
		return (n <= 0 ? 0 : 1);
	}

	const double sqrt5 = sqrt(5);
	return static_cast<int>((pow((1 + sqrt5) / 2, n) - pow((1 - sqrt5) / 2, n)) / sqrt5);
}
void TestFibonacci()
{
	printf("----------TestFibonacci----------\n");
	for(int n = -1; n < 40; ++n)
	{
		assert(
			FibonacciON(n) == FibonacciO1(n) && FibonacciOLogN(n) == FibonacciO1(n)
				&& FibonacciOLogN2(n) == FibonacciO1(n));
	}
	printf("All case pass.\n");
}
///////////////////////////////////
const int kMax = 255;
int prime[kMax];
int prime_count;
void Prime()
{
	bool is_prime[kMax + 1];
	memset(is_prime, true, sizeof is_prime);
	prime_count = 0;
	for(int num = 2; num <= kMax; ++num)
	{
		if(is_prime[num] == true)
		{
			prime[++prime_count] = num;
		}
		for(int index = 1; index <= prime_count && prime[index] * num <= kMax; ++index)
		{
			is_prime[prime[index] * num] = false;
			if(num % prime[index] == 0)
			{
				break;
			}
		}
	}
}
void TestPrime()
{
	printf("----------TestPrime----------\n");
	const int answer[] = { 0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61,
		67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163,
		167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251 };
	Prime();
	for(int index = 1; index <= prime_count; ++index)
	{
		if(prime[index] != answer[index])
		{
			printf("Case %d Not pass.\n", index);
		}
	}
	printf("All case Pass.\n");
}
///////////////////////////////////
bool g_invalid_input = false;
inline bool Equal(double a, double b)
{
	return fabs(a - b) < 1e-6;
}
double QuickPower(double base, int exp)
{
	if(Equal(base, 0) == true && exp < 0) // Negative test.
	{
		g_invalid_input = true;
		return 0;
	}

	double result = 1;
	for(int abs_exp = abs(exp); abs_exp != 0; abs_exp >>= 1)
	{
		abs_exp & 1 ? result *= base : result;
		base *= base;
	}
	return (exp < 0 ? 1 / result : result);
}
void TestQuickPower()
{
	printf("----------TestQuickPower----------\n");
// Negative test: 0^(-1)
	vector<double> base = { -2, 0, 2, 0, -2, 0, 2 };
	vector<int> exp = { -3, -3, -3, 0, 3, 3, 3 };
	vector<double> answer = { -0.125, 0, 0.125, 1, -8, 0, 8 };
	for(int index = 0; index < static_cast<int>(base.size()); ++index)
	{
		assert(QuickPower(base[index], exp[index]) == answer[index]);
	}
	printf("All case Pass.\n");
}
///////////////////////////////////

int main()
{
	TestEuclidGreatestCommonDivisor();
	TestFibonacci();
	TestPrime();
	TestQuickPower();
}
