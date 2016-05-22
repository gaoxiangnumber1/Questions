/*
------------------------------Function Test Data------------------------------
0 1 2 5 3 5 4 0 2

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
1. NULL pointer
2. length <= 0
3. some elements' value is not in [0, length - 1]

*/

#include <iostream>
using namespace std;

bool duplicate(int numbers[], int length, int *duplication)
{
	// Negative data 1 & 2:
	if(!numbers || length <= 0)
	{
		return false;
	}
	// Negative data 3:
	for(int index = 0; index < length; ++index)
	{
		if(numbers[index] < 0 || numbers[index] > length - 1)
		{
			return false;
		}
	}

	// Up to now, the numbers array is valid.
	for(int index = 0; index < length; ++index)
	{
		while(numbers[index] != index)
		{
			if(numbers[index] == numbers[numbers[index]])  // Find the duplicate number.
			{
				*duplication = numbers[index];
				return true;
			}
			// Swap this 2 numbers:
			int temp = numbers[index];
			numbers[index] = numbers[temp];
			numbers[temp] = temp;
			/*
			WRONG Codes:
			int temp = numbers[index];
			numbers[index] = numbers[numbers[index]];
			numbers[numbers[index]] = temp;
			Reason:
			numbers[index] change in the second clause!!!
			*/
		}
	}
	// No duplicate number found.
	return false;
}

int main()
{
	while(1)
	{
		cout << "Input length: ";
		int length;
		cin >> length;
		int numbers[length];
		cout << "Input numbers: ";
		for(int index = 0; index < length; ++index)
		{
			cin >> numbers[index];
		}
		int duplication;
		if(duplicate(numbers, length, &duplication))
		{
			cout << duplication << endl;
		}
		else
		{
			cout << "Not find.\n";
		}
	}

	return 0;
}
