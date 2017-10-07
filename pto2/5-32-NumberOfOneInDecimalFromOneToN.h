
int NumberOf1Between1AndN_Solution(int n)
{
	// negative data:
	if(n < 1)
	{
		return 0;
	}

	int result = 0;
	for(int num = 1; num <= n; ++num)  // [1, n]
	{
		/*
		we can't directly use num itself since after the following loop,
		num = 0, and ++num, num = 1, so this is a dead loop:
		1 -> 0 -> 1 -> 0 ...
		Don't modify num, use a temporary variable temp!
		*/
		int temp = num;
		int cnt = 0;
		while(temp)
		{
			if((temp % 10) == 1)  // the current least significant bit
			{
				++cnt;
			}
			temp = temp / 10;  // cut the last bit
		}
		result += cnt;
	}
	return result;
}
int Pow(int base, int exponent)
{
	int result = 1;
	while(exponent)
	{
		if(exponent & 0x1)
		{
			result *= base;
		}
		exponent >>= 1;
		base *= base;
	}
	return result;
}
int Recursive(int num, int length)
{
	// terminate condition:
	if(length < 1)
	{
		return 0;
	}
	// edge condition:
	if(length == 1)
	{
		return (num == 0 ? 0 : 1);
	}

	int pow = Pow(10, length - 1);
	if(num < pow)  // num begin with 0(actual_length < length)
	{
		return Recursive(num, length - 1);
	}

	// now, length >= 2
	// assume: num = 21345, length = 5

	/* FIRST PART: [1346, 21345] */
	int first = num / pow;  // the first number, first = 2
	// the count of numbers that begin with 1 and have the same length as num.
	// since first = 2, so first_count = 10000 ([10000, 19999])
	// say, if num = 12345, then first = 1,
	// first_count = 12345 - 10000 + 1 = 2346 ([10000, 12345])
	int first_count = (first == 1 ? (num - pow + 1) : pow);
	// [1346, 21345] -> [1346, 11345] & [11346, 21345]
	// 2(first) * 4(length - 1) * 1000(Pow(10, length - 2))
	int non_first_count = first * (length - 1) * Pow(10, length - 2);

	/* SECOND PART: [1, 1345] */
	int other_count = Recursive(num - first * pow, length - 1);
	return first_count + non_first_count + other_count;
}
int NumberOf1Between1AndN_Solution(int n)
{
	// negative data:
	if(n < 1)
	{
		return 0;
	}

	int length = 1, pow = 10;
	while(n / pow)
	{
		++length;
		pow *= 10;
	}
	return Recursive(n, length);
}
