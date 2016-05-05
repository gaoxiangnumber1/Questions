/*
------------------------------Function Test Data------------------------------

--------------------------------Edge Test Data--------------------------------

------------------------------Negative Test Data------------------------------

*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	while(1)
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

	return 0;
}
