/*
------------------------------Function Test Data------------------------------
Normal array

--------------------------------Edge Test Data--------------------------------
Normal array

------------------------------Negative Test Data------------------------------
Empty array

*/

#include <vector>
#include <iostream>
#include <string>
using namespace std;

static bool Compare(string first, string second)  // Return true if first <= second
{
	string first_second = first + second, second_first = second + first;
	int length = first_second.size();
	for(int index = 0; index < length; ++index)
	{
		if(first_second[index] < second_first[index])
		{
			return true;
		}
		else if(first_second[index] > second_first[index])
		{
			return false;
		}
	}
	// Don't forget first = second
	return true;
	/*
	The compare result is according to the FIRET different letter in the two
	strings, once we find a pair of different letters, there is no need to continue
	check following letters at all!
	Don't forget the condition that two strings are equal! This condition
	can be determined only after comparing all common letters of two strings.
	WRONG codes:
	for(int index = 0; index < length; ++index)
	{
		if(first_second[index] > second_first[index])
		{
			return false;
		}
	}
	return true;
	*/
}

static int Partition(vector<string> &str, int first, int last, bool (*Compare)(string, string))
{
	string pivot = str[last];
	int divide = first;
	for(int index = first; index < last; ++index)
	{
		if(Compare(str[index], pivot))  // Return true if str[index] <= pivot
		{
			swap(str[index], str[divide]);
			++divide;
		}
	}
	swap(str[divide], str[last]);
	return divide;
}

// According to Compare to sort str[first, last]
static void QuickSort(vector<string> &str, int first, int last, bool (*Compare)(string, string))
{
	if(first < last)
	{
		int divide = Partition(str, first, last, Compare);
		QuickSort(str, first, divide - 1, Compare);
		QuickSort(str, divide + 1, last, Compare);
	}
}

string PrintMinNumber(vector<int> numbers)
{
	int length = numbers.size();
	// Negative data:
	if(length <= 0)
	{
		return string();
	}

	// First: convert all integers into string.
	vector<string> str(length);
	for(int index = 0; index < length; ++index)
	{
		int temp = numbers[index];
		str[index] = "";
		while(temp)
		{
			str[index] = (char)(temp % 10 + '0') + str[index];
			temp /= 10;
		}
	}

	// Second: use quick sort to sort the string array according to predicate Compare()
	QuickSort(str, 0, length - 1, Compare);

	// Third: concatenate all strings to produce result
	string result = "";
	for(int index = 0; index < length; ++index)
	{
		result += str[index];
	}

	// Fourth: return result
	return result;
}

int main()
{
	cout << "Input 5 numbers: ";
	vector<int> num(5);
	for(int index = 0; index < 5; ++index)
	{
		cin >> num[index];
	}
	cout << PrintMinNumber(num) << endl;

	return 0;
}
