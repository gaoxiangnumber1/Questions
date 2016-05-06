/*
------------------------------Function Test Data------------------------------
normal array

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
length <= 0

*/

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> multiply(const vector<int> &A)
{
	int length = A.size();

	// Negative data:
	if(length <= 0)
	{
		return vector<int>();
	}

	// result[index] = left[index] * right[index]
	vector<int> result(length), left(length), right(length);
	// Calculate left[] and right[]:
	left[0] = right[length - 1] = 1;
	for(int index = 1; index < length; ++index)
	{
		left[index] = left[index - 1] * A[index - 1];
		right[length - 1 - index] = right[length - index] * A[length - index];
	}

	// Calculate result[]:
	for(int index = 0; index < length; ++index)
	{
		result[index] = left[index] * right[index];
	}
	return result;
}

int main()
{
	while(0)
	{
		cout << "Input length: ";
		int length;
		cin >> length;
		vector<int> A(length), result(length);
		cout << "Input numbers: ";
		long long all = 1;
		for(int index = 0; index < length; ++index)
		{
			cin >> A[index];
			all *= A[index];
		}
		result = multiply(A);
		for(int index = 0; index < length; ++index)
		{
			cout << (result[index] - all / A[index]) << "\n";
		}
	}

	printf("%d\t%d\n", 'G', 'X');

	return 0;
}
