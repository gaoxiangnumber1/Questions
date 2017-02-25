/*
Function Test Data:
-4 -3 -2 -1 0 1 2 3 4 5
2 4 6 8 10 1 3 5 7 9
1 3 5 7 9 2 4 6 8 10

Edge Test Data:
None

Negative Test Data:
1.	the pointer that points to array is NULL
2.	array's size is 0
*/

#include<iostream>
#include<vector>
using namespace std;

bool IsEven(int number)
{
	return (number & 0x1) == 0;
}

void reOrderArray(vector<int> &array, bool (*IsEven)(int))
{
	int length = array.size();
	// negative test data: array's size is 0
	if(length == 0)
	{
		return;
	}

	// function test data:
	int before = 0, after = length - 1;
	while(before < after)
	{
		// exit when array[before] is even:
		for(; before < length && !IsEven(array[before]); ++before);
		// exit when array[after] is odd
		for(; after >= 0 && IsEven(array[after]); --after);

		if(before < after)  // we haven't inspect all numbers
		{
			int temp = array[before];
			array[before] = array[after];
			array[after] = temp;
		}
	}
}

int main()
{
	while(1)
	{
		cout << "Input array's size: ";
		int length;
		cin >> length;
		vector<int> array(length);
		cout << "Input your numbers: ";
		for(int index = 0; index < length; ++index)
		{
			cin >> array[index];
		}
		reOrderArray(array, IsEven);
		cout << "Array after reorder: ";
		for(int index = 0; index < length; ++index)
		{
			cout << array[index] << " ";
		}
		cout << endl;
	}

	return 0;
}

/*
void reOrderArray(vector<int> &array)
{
	int length = array.size();
	int index = 0;
	int odd = -1;

	for(index; index <length ; ++index)
	{
		if(array[index]%2 == 1)
		{
			++odd;
			if(odd != index)
			{
				int tmp = array[index];
				for(int j=index; j>odd; j--)
				{
					array[j] = array[j-1];
				}
				array[odd] = tmp;
			}
		}
	}
}
*/
