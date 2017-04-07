/*
------------------------------Function Test Data------------------------------
nonnegative integer

---------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
negative integer

*/

int Fibonacci(int n)  // Return: -1 on input error, nonnegative integer if ok.
{
	// negative data:
	if(n < 0)
	{
		return -1;
	}

	if(n == 0)
	{
		return 0;
	}
	if(n == 1)
	{
		return 1;
	}

	int result_minus_one = 1;  // [n - 1]
	int result_minus_two = 0;  // [n - 2]
	int result = 0;  // [n]

	for(int cnt = 2; cnt <= n; ++cnt)
	{
		result = result_minus_one + result_minus_two;  // [n] = [n - 1] + [n - 2]

		result_minus_two = result_minus_one;  // [n - 2] = [n - 1]
		result_minus_one = result;  // [n - 1] = [n]
	}

	return result;
}
