/*
------------------------------Function Test Data------------------------------
normal

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
empty string

*/

#include<vector>
#include<iostream>
using namespace std;

std::vector<string> result;

void Recursive(string str, int first, int last)  // get the permutation of str[first, last]
{
	if(first == last)  // no need to swap element, so we get one permutation
	{
		for(int index = 0; index < result.size(); ++index)
		{
			if(result[index] == str)
			{
				return;  // already exist in result
			}
		}
		result.push_back(str);
	}
	else
	{
		for(int index = first; index <= last; ++index)
		{
			swap(str[first], str[index]);  // exchange the first element with all elements one by one
			Recursive(str, first + 1, last);  // get the permutation of str[first + 1, last]
			// if we don't pass string by reference or pointer,
			// we can modify string without recover it.
			//swap(str[first], str[index]);  // recover the exchange
		}
	}
}

vector<string> Permutation(string str)
{
	int length = str.size();
	if(length <= 0)
	{
		return result;
	}
	Recursive(str, 0, length - 1);
	return result;
}

int main()
{
	string str;
	while(1)
	{
		cout << "String: \n";
		cin >> str;
		cout << "Permutation:\n";
		Permutation(str);
		for(int index = 0; index < result.size(); ++index)
		{
			cout << result[index] << "\n";
		}
		result.clear();
	}
	return 0;
}
