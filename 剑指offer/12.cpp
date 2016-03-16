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

void Print(char *number, int length)
{
	int index = 0;  // Don't forget make index 0
	for(; index < length && number[index] == '0'; ++index);
	// now, number[index] is the first non-zero character, i.e., the begin of actual number
	// "index < length" MUST be the first predicate, otherwise number[index] may be out of bounds

	if(index == length)  // no valid number(i.e., all zero), no need output
	{
		return;
	}

	while(index < length)
	{
		cout << number[index++];
	}
	cout << " ";
}

bool Increment(char *number, int length)  // return false when the number is the biggest, true otherwise.
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

void Solution1(int bits_number)
{
	cout << "\n----------------------------------------Solution 1 output----------------------------------------\n";
	char number[bits_number];
	for(int index = 0; index < bits_number; ++index)  // fill the number array with 0
	{
		number[index] = '0';
	}
	while(! Increment(number, bits_number))  // Increment implements: number = number + 1
	{
		Print(number, bits_number);
	}
}

void Permutation(char *number, int length, int index)  // number[index] is already set
{
	if(index == length - 1)  // reach the lowest bit, then output the number
	{
		Print(number, length);
		return;
	}
	// assign value(0 - 9) to the next lower bit
	for(int num = 0; num < 10; ++num)
	{
		number[index + 1] = num + '0';
		Permutation(number, length, index + 1);
	}
}

void Solution2(int bits_number)
{
	cout << "\n----------------------------------------Solution 2 output----------------------------------------\n";
	char number[bits_number];
	// Permutation: assign value from the most significant bit to the least significant bit,
	// each time, we first hold higher bits value, then permute next lower bit in [0, 9]
	for(int index = 0; index < 10; ++index)
	{
		number[0] = index + '0';
		Permutation(number, bits_number, 0);
	}
}

int main()
{
	while(1)
	{
		cout << "\nInput number of total bits: ";
		int bits_number;
		cin >> bits_number;

		if(bits_number <= 0)  // wrong data
		{
			cout << "Input Error\n";
			return 0;
		}

		Solution1(bits_number);
		Solution2(bits_number);
	}

	return 0;
}
