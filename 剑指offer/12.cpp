/*
Function Test Data:
1
2
3
4
// you have to wait a VERY long time :
10
20
30
50
60
Edge Test Data:
None
Negative Test Data:
0 -1
*/

#include<iostream>
using namespace std;

bool Increment(char *number, int length)
{
	bool is_overflow = false;  // indicate whether we reach the biggest n-bit number
	int carry_bit = 0;  // 1 if carry bit set, otherwise 0

	// implement number = number + 1:
	for(int index = length - 1; index >= 0; --index)
	{
		int value = number[index] - '0' + carry_bit;
		// (number = number + 1) begins from the least significant bit adding 1
		if(index == length - 1)
		{
			++value;
		}
		if(value < 10)  // no carry bit set, only modify one bit and then break
		{
			number[index] = '0' + value;
			break;
		}
		else  // carry bit set, we need to modify more significant bits
		{
			// carry bit is the most significant bit, i.e., we have reached the biggest n-nit number
			if(index == 0)
			{
				is_overflow = true;
			}
			else
			{
				value -= 10;
				carry_bit = 1;
				number[index] = '0' + value;
			}
		}
	}
	return is_overflow;
}

void Print(char *number, int length)
{
	int index = 0;  // MUST assign value
	for(; number[index] == '0'; ++index);
	// now, number[index] is the first non-zero character, i.e., the begin of actual number
	while(index < length)
	{
		cout << number[index++];
	}
	cout << endl;
}

void Permutation(char *number, int length, int index)
{
	if(index == length - 1)
	{
		Print(number, length);
		return;
	}
	for(int num = 0; num < 10; ++num)
	{
		number[index + 1] = num + '0';
		Permutation(number, length, index + 1);
	}
}

int main()
{
	while(1)
	{
		cout << "Input number of total bits: ";
		int bits_number;
		cin >> bits_number;

		if(bits_number <= 0)  // wrong data
		{
			cout << "Input Error\n";
			return 0;
		}

		char number[bits_number];
		for(int index = 0; index < bits_number; ++index)  // fill the number array with 0
		{
			number[index] = '0';
		}
		for(int index = 0; index < 10; ++index)
		{
			number[0] = index + '0';
			Permutation(number, bits_number, 0);
		}
		/*
		while(! Increment(number, bits_number))
		{
			Print(number, bits_number);
		}
		*/
	}

	return 0;
}
